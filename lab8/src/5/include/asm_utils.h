#ifndef ASM_UTILS_H
#define ASM_UTILS_H

#include "os_type.h"

extern "C" void asm_hello_world();
extern "C" void asm_lidt(uint32 start, uint16 limit);
extern "C" void asm_unhandled_interrupt();
extern "C" void asm_halt();
extern "C" void asm_out_port(uint16 port, uint8 value);
extern "C" void asm_in_port(uint16 port, uint8 *value);
extern "C" void asm_enable_interrupt();
extern "C" void asm_time_interrupt_handler();
extern "C" int asm_interrupt_status();
extern "C" void asm_disable_interrupt();
extern "C" void asm_switch_thread(void *cur, void *next);
extern "C" void asm_atomic_exchange(uint32 *reg, uint32 *mem);
extern "C" void asm_init_page_reg(int *directory);
extern "C" int asm_system_call(int index, int first = 0, int second = 0, int third = 0, int forth = 0, int fifth = 0);
extern "C" int asm_system_call_handler();
extern "C" int asm_add_global_descriptor(int low, int high);
extern "C" void asm_ltr(int tr);
extern "C" void asm_start_process(int stack);
extern "C" void asm_update_cr3(int address);

#endif