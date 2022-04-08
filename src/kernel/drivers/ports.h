#ifndef __PORTS_H__
    #define __PORTS_H__

    #define REG_SCREEN_CTRL 0x3d4
    #define REG_SCREEN_DATA 0x3d5

unsigned char port_byte_in(unsigned short port);
void port_byte_out(unsigned short port, unsigned char data);

#endif 
