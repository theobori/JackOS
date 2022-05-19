#include "mouse_intern.h"

/**
 * @brief : wait for mouse to be ready
 * 
 * @param type : type of mouse
 */
void mouse_wait(u8 type)
{
    u32 time_out = 100000;
    if (type == 0) {
        // suspend until status is 1
        while (time_out--) {
            if ((port_byte_in(PS2_CMD_PORT) & 1) == 1) {
                return;
            }
        }
        return;
    } else {
        while (time_out--) {
            if ((port_byte_in(PS2_CMD_PORT) & 2) == 0) {
                return;
            }
        }
    }
}

/**
 * @brief : send command to mouse
 * 
 * @param data : data to send
 */
void mouse_write(u8 data)
{
    mouse_wait(1);
    port_byte_out(PS2_CMD_PORT, 0xD4);
    mouse_wait(1);
    port_byte_out(MOUSE_DATA_PORT, data);
}

/**
 * @brief : read data from mouse
 * 
 * @return u8 : data read
 */
u8 mouse_read()
{
    mouse_wait(0);
    return port_byte_in(MOUSE_DATA_PORT);
}

/**
 * @brief Get the Mouse status t object
 * 
 * @param status_byte : status byte
 * @param status : mouse status
 */
void get_Mouse_status_t(char status_byte, Mouse_status_t *status)
{
    memset(status, 0, sizeof(Mouse_status_t));
    if (status_byte & 0x01)
        status->left_button = 1;
    if (status_byte & 0x02)
        status->right_button = 1;
    if (status_byte & 0x04)
        status->middle_button = 1;
    if (status_byte & 0x08)
        status->always_1 = 1;
    if (status_byte & 0x10)
        status->x_sign = 1;
    if (status_byte & 0x20)
        status->y_sign = 1;
    if (status_byte & 0x40)
        status->x_overflow = 1;
    if (status_byte & 0x80)
        status->y_overflow = 1;
}

/**
 * @brief : print mouse data
 * 
 */
void print_mouse_info()
{
    if (Mouse.status.left_button) {
        GUI.draw_square(0, 0, 100, D_RED);
    }
    if (Mouse.status.right_button) {
        GUI.draw_square(100, 0, 100, D_GREEN);
    }
    if (Mouse.status.middle_button) {
        GUI.draw_square(200, 0, 100, D_BLUE);
    }
}

/**
 * @brief : mouse callback
 * mouse cycle, don't fck understand why it's working
 * don't know how to use it
 * lil bitch
 * 
 * @param r : register
 */
static void mouse_handler(__attribute__((unused))registers_t r)
{
    static u8 mouse_cycle = 0;
    static char mouse_byte[3];

    switch (mouse_cycle) {
        case 0:
            mouse_byte[0] = mouse_read();
            get_Mouse_status_t(mouse_byte[0], &Mouse.status);
            mouse_cycle++;
            break;
        case 1:
            mouse_byte[1] = mouse_read();
            mouse_cycle++;
            break;
        case 2:
            mouse_byte[2] = mouse_read();
            Mouse.x = Mouse.x + mouse_byte[1];
            Mouse.y = Mouse.y - mouse_byte[2];
            if (Mouse.x < 0)
                Mouse.x = 0;
            if (Mouse.y < 0)
                Mouse.y = 0;
            if (Mouse.x > 80)
                Mouse.x = 80 - 1;
            if (Mouse.y > 24)
                Mouse.y = 24 - 1;
            print_mouse_info();
            mouse_cycle = 0;
            break;
    }
}

/**
 * @brief Set the mouse rate object
 * 
 * @param rate : mouse rate
 */
void set_mouse_rate(u8 rate)
{
    u8 status;

    port_byte_out(MOUSE_DATA_PORT, MOUSE_CMD_SAMPLE_RATE);
    status = mouse_read();
    if(status != MOUSE_ACKNOWLEDGE)
        return;
    port_byte_out(MOUSE_DATA_PORT, rate);
    status = mouse_read();
    if(status != MOUSE_ACKNOWLEDGE)
        return;
}

/**
 * @brief : initialize mouse, fucking standard to use,
 * don't understand what's going on
 * /!\ VERY USEFUL CODE DON'T TOUCH /!\
 * /!\ VERY USEFUL CODE DON'T TOUCH /!\
 * /!\ VERY USEFUL CODE DON'T TOUCH /!\
 * It's working and it's not my fault
 * don't ask why please :'(
 * 
 */
void init_mouse()
{
    u8 status;
    Mouse.x = 5;
    Mouse.y = 2;

    mouse_wait(1);
    port_byte_out(PS2_CMD_PORT, 0xA8);
    port_byte_out(MOUSE_DATA_PORT, MOUSE_CMD_MOUSE_ID);
    status = mouse_read();
    set_mouse_rate(10);
    mouse_wait(1);
    port_byte_out(PS2_CMD_PORT, 0x20);
    mouse_wait(0);
    status = (port_byte_in(MOUSE_DATA_PORT) | 2);
    mouse_wait(1);
    port_byte_out(PS2_CMD_PORT, MOUSE_DATA_PORT);
    mouse_wait(1);
    port_byte_out(MOUSE_DATA_PORT, status);
    mouse_write(MOUSE_CMD_SET_DEFAULTS);
    status = mouse_read();
    if (status != MOUSE_ACKNOWLEDGE)
        return;
    mouse_write(MOUSE_CMD_ENABLE_PACKET_STREAMING);
    status = mouse_read();
    if (status != MOUSE_ACKNOWLEDGE)
        return;
    register_interrupt_handler(IRQ(12), mouse_handler);
}
