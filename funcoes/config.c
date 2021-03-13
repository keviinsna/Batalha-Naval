#include <stdio.h>
#include <stdlib.h>

#ifdef __WIN32__
    #include <windows.h>    
#else
    #include <stdio_ext.h>
    #include <unistd.h>
#endif

void limpa_tela(){
    #ifdef __WIN32__
        system("cls");
    #else
        system("clear");
    #endif
}

void limpa_buffer(){
    #ifdef __WIN32__
        fflush(stdin);
    #else
        __fpurge(stdin);
    #endif
}

void muda_config_windows(){
    #ifdef __WIN32__
        system("chcp 65001");
    #endif
}

void delay(int i){
    #ifdef __WIN32__
        Sleep(i*1000);
    #else 
        sleep(i);
    #endif
}