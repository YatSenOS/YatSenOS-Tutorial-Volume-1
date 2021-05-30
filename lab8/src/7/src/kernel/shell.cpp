#include "shell.h"
#include "asm_utils.h"
#include "syscall.h"
#include "stdio.h"

Shell::Shell()
{
    initialize();
}

void Shell::initialize()
{
}

void Shell::run()
{
    move_cursor(0, 0);
    for(int i = 0; i < 25; ++i ) {
        for(int j = 0; j < 80; ++j ) {
            printf(" ");
        }
    }
    move_cursor(0, 0);

    printLogo();

    move_cursor(7, 26);
    printf("Welcome to SUMMER Project!\n");
    printf("        https://gitee.com/nelsoncheung/sysu-2021-spring-operating-system/\n\n");
    printf("  SUMMER is an OS course project.\n\n"
           "  Proposed and led by\n"
           "           Prof. PengFei Chen.\n\n"
           "  Developed by\n"
           "           Prof. PengFei Chen,\n"
           "           HPC and AI students in grade 2019,\n"
           "           HongYang Chen,\n"
           "           WenXin Xie,\n"
           "           YuZe Fu,\n"
           "           Nelson Cheung.\n\n"
           );
    

    asm_halt();
}

void Shell::printLogo()
{
    move_cursor(0, 19);
    printf(" ____  _   _ __  __ __  __ _____ ____\n");
    move_cursor(1, 19);
    printf("/ ___|| | | |  \\/  |  \\/  | ____|  _ \\\n");
    move_cursor(2, 19);
    printf("\\___ \\| | | | |\\/| | |\\/| |  _| | |_) |\n");
    move_cursor(3, 19);
    printf(" ___) | |_| | |  | | |  | | |___|  _ <\n");
    move_cursor(4, 19);
    printf("|____/ \\___/|_|  |_|_|  |_|_____|_| \\_\\\n");
}