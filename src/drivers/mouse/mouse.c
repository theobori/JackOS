#include "mouse_intern.h"

void mouse_write(u8 data) {
    // sending write command
    // mouse_wait(1);
    port_byte_out(PS2_CMD_PORT, 0xD4);
    // mouse_wait(1);
    // finally write data to port
    port_byte_out(MOUSE_DATA_PORT, data);
}

void mouse_handler(__attribute__((unused))registers_t r) {
    int i, j;

    if (m_status.left_button) {
        i = 100;
        j = 100;
    } else if (m_status.right_button) {
        i = 200;
        j = 200;
    } else if (m_status.middle_button) {
        i = 300;
        j = 300;
    } else {
        i = 0;
        j = 0;
    }
    for (int a = i; a < i + 100; a++) {
        for (int b = j; b < j + 100; b++) {
            GUI.put_pixel(a, b, D_LIGHT_RED);
        }
    }
}

/**
 * available rates 10, 20, 40, 60, 80, 100, 200
 */
void set_mouse_rate(u8 rate) {
    u8 status;

    port_byte_out(MOUSE_DATA_PORT, MOUSE_CMD_SAMPLE_RATE);
    status = port_byte_in(MOUSE_DATA_PORT);
    if(status != MOUSE_ACKNOWLEDGE) {
        // printf("error: failed to send mouse sample rate command\n");
        return;
    }
    port_byte_out(MOUSE_DATA_PORT, rate);
    status = port_byte_in(MOUSE_DATA_PORT);
    if(status != MOUSE_ACKNOWLEDGE) {
        // printf("error: failed to send mouse sample rate data\n");
        return;
    }
}

void init_mouse() {
    u8 status;

    g_mouse_x_pos = 5;
    g_mouse_y_pos = 2;

    port_byte_out(PS2_CMD_PORT, 0xA8);
    port_byte_out(MOUSE_DATA_PORT, MOUSE_CMD_MOUSE_ID);
    status = port_byte_in(MOUSE_DATA_PORT);
    set_mouse_rate(10);
    port_byte_out(PS2_CMD_PORT, 0x20);
    status = (port_byte_in(MOUSE_DATA_PORT) | 2);
    port_byte_out(PS2_CMD_PORT, MOUSE_DATA_PORT);
    port_byte_out(MOUSE_DATA_PORT, status);
    mouse_write(MOUSE_CMD_SET_DEFAULTS);
    port_byte_in(MOUSE_DATA_PORT);
    mouse_write(MOUSE_CMD_ENABLE_PACKET_STREAMING);
    port_byte_in(MOUSE_DATA_PORT);
    register_interrupt_handler(IRQ(12), mouse_handler);
}

