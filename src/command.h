#ifndef COMMAND_H
#define COMMAND_H
#define PROGRAM_START 0x2000
#include "common.h"
#include "reg.h"
#include "mem.h"
#define COMMAND_START 0x10
void run_command(uint16_t command,uint16_t arg1,uint16_t arg2);
#endif // COMMAND_H