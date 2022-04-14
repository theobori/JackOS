#ifndef __KEYBOARD_DRIVER_H__
    #define __KEYBOARD_DRIVER_H__

    #define NB_CHAR 58

enum BiosKeyboardKey {
    ERROR,                      // Case of problem
    ESC,
    _1,_2,_3,_4,_5,_6,_7,_8,_9,_0,
    MINUS,
    PLUS,
    BACKSPACE,
    TAB,
    Q,W,E,R,T,Y,U,I,O,P,
    LBRACKET, RBRACKET,
    ENTER,
    LCTRL,
    A,S,D,F,G,H,J,K,L,
    SEMICOLON,
    SINGLE_QUOTE,               // '
    ANTI_QUOTE,                 // `
    LSHIFT,
    BACKSLASH,
    Z,X,C,V,B,N,M,
    COMMA,
    DOT,
    SLASH,                      // /
    RSHIFT,
    KEYPAD_STAR,                // ???
    LALT,
    SPC,                        // ???
};

void init_keyboard();
void change_lang(const char *lang);

#endif