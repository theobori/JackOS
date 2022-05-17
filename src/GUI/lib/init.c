#include "init.h"

/**
 * @brief Get the vbe mode info object
 * 
 * @param mode : mode number
 * @param mode_info : pointer to mode info object
 */
static void get_vbe_mode_info(u16 mode, VBE20_MODEINFOBLOCK *mode_info)
{
    registers_16_t in = {0}, out = {0};
    // set specific value 0x4F00 in ax to get vbe mode info into some other bios memory area
    in.ax = 0x4f01;
    in.cx = mode; // set mode info to get
    in.di = BIOS_CONVENTIONAL_MEMORY + 1024;  // address pointer, different than used in get_vbe_info()
    int86(0x10, &in, &out);  // call video interrupt 0x10
    // copy vbe mode info data to parameter mode_info
    memcpy(mode_info, (void *)BIOS_CONVENTIONAL_MEMORY + 1024, sizeof(VBE20_MODEINFOBLOCK));
}

/**
 * @brief find the VBE mode by resolution X & Y
 * 
 * @param width : resolution X
 * @param height : resolution Y
 * @param bpp : bits per pixel
 * @return u32 : mode number
 */
static u32 vbe_find_mode(u32 width, u32 height, u32 bpp)
{
    // iterate through video modes list
    u16 *mode_list = (u16 *) g_vbe_infoblock.VideoModePtr;
    u16 mode = *mode_list++;

    while (mode != 0xffff) {                    // 0xffff is the end of the list
        get_vbe_mode_info(mode, &vbe_mode_info);
        if (vbe_mode_info.XResolution == width && vbe_mode_info.YResolution == height && vbe_mode_info.BitsPerPixel == bpp)
            return (mode);
        mode = *mode_list++;
    }
    return (-1);
}

/**
 * @brief : set vbe mode
 * 
 * @param mode : vbe mode
 */
static void vbe_set_mode(u32 mode)
{
    registers_16_t in = {0}, out = {0};
    // set any given mode, mode is to find by resolution X & Y
    in.ax = 0x4F02;
    in.bx = mode;
    int86(0x10, &in, &out);  // call video interrupt 0x10 to set mode
}

/**
 * @brief Get the vbe info object
 * 
 * @return int : 1 if success, 0 if fail
 */
static int get_vbe_info()
{
    registers_16_t in = {0}, out = {0};
    in.ax = 0x4F00;                                                                                 // set specific value 0x4F00 in ax to get vbe info into bios memory area
    in.di = BIOS_CONVENTIONAL_MEMORY;                                                               // set address pointer to BIOS_CONVENTIONAL_MEMORY where vbe info struct will be stored
    int86(0x10, &in, &out);                                                                         // call video interrupt 0x10
    memcpy(&g_vbe_infoblock, (void *)BIOS_CONVENTIONAL_MEMORY, sizeof(VBE20_INFOBLOCK));            // copy vbe info data to our global variable g_vbe_infoblock
    return (out.ax == 0x4F);
}

/**
 * @brief Initialize VESA/VBE mode
 * 
 * @param width : width of the screen
 * @param height : height of the screen
 * @param bpp : bits per pixel
 * @return int : 0 if success, -1 if failed
 */
static int vesa_init(u32 width, u32 height, u32 bpp)
{
    bios32_init();
    if (!get_vbe_info())
        return (-1);
    GUI.g_selected_mode = vbe_find_mode(width, height, bpp);
    if (GUI.g_selected_mode == -1)
        return (-1);
    GUI.g_width = vbe_mode_info.XResolution;
    GUI.g_height = vbe_mode_info.YResolution;
    GUI.g_vbe_buffer = (u32 *)vbe_mode_info.PhysBasePtr;
    vbe_set_mode(GUI.g_selected_mode);
    return (0);
}

/**
 * @brief init_gui for Daniel's GUI
 * 
 * @param this : the gui
 */
void init_daniel()
{
    GUI.g_selected_mode = -1;
    GUI.put_pixel = &daniel_putpixel;
    GUI.draw_square = &daniel_draw_square;
    GUI.draw_char = &daniel_draw_char_at_pos;
    GUI.g_vbe_buffer = 0;
    GUI.g_width = 0;
    GUI.g_height = 0;

    vesa_init(800, 600, 32);
}