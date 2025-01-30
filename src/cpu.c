#include "cpu.h"
void run_once();
// 定义一个名为run的函数，用于执行循环操作
void run(){
    // 使用while循环，当reg_nx不等于0时，继续执行循环体
    while(reg_nx == 0){
        // 调用run_once函数，执行一次操作
        run_once();
    }
}
void run_once(){
    uint16_t command = mem_read(reg_pc+PROGRAM_START);
    uint16_t arg_1 = mem_read(reg_pc+PROGRAM_START+1);
    uint16_t arg_2 = mem_read(reg_pc+PROGRAM_START+2);
    run_command(command, arg_1, arg_2);
    reg_pc += 3;
}
