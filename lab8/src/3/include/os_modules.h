#ifndef OS_MODULES_H
#define OS_MODULES_H

#include "interrupt.h"
#include "stdio.h"
#include "program.h"
#include "memory.h"
#include "syscall.h"
#include "tss.h"

extern InterruptManager interruptManager;
extern STDIO stdio;
extern ProgramManager programManager;
extern MemoryManager memoryManager;
extern SystemService systemService;
extern TSS tss;

#endif