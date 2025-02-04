#include "apue.h"
#include <termios.h>

int main(void){
    struct termios term;

    if (tcgetattr(STDIN_FILENO, &term) <0 ){
        err_sys("tcgetattr error");
    }

    switch (term.c_cflag & CSIZE)
    {
    case CS5:
        printf("5 bits/bytes\n");
        break;
    case CS6:
        printf("6 bits/bytes\n");
        break;
    case CS7:
        printf("7 bit/bytes\n");
        break;
    case CS8:
        printf("8 bit/bytes\n");
        break;
    default:
        printf("unknow bit/bytes");
    }

    term.c_cflag &= ~CSIZE;
    term.c_cflag |= CS5;
    // 立即更改
    if(tcsetattr(STDIN_FILENO, TCSANOW, &term) <0 ){
        err_sys("tcsetattr error");
    }

    exit(0);
    
}