#include"trans.h"
#include "build_in_command.h"
using namespace std;
extern uc memory;
    uc command[7];
inline void run(), run_debug(),run_command();
inline  void run_program(bool is_debug_mode){
    if(is_debug_mode) {run_debug();}
    else{run();}
}
inline void run(){
    command_start:
    for(int i = 0; i < 7; i++) command[i] = memory[i];
    if is_not_command(command[0]){//判断是否为命令
        cout << "Error: Invalid command!\n";
        return;
    }
    
    run_command();//command是全局变量不用传参
    goto command_start;
    
}
inline void run_debug(){

}

inline void run_command() {
    switch (command[0]) {
        case 0x10: add(); break;//均在build_
        case 0x11: sub(); break;
        case 0x12: sl(); break;
        case 0x13: rl(); break;
        case 0x14: and_shy(); break;
        case 0x15: or_shy(); break;
        case 0x16: xor_shy(); break;
        case 0x17: nor_shy(); break;
        case 0x18: mov(); break;
        case 0x19: reset(); break;
        case 0x1A: cpe(); break;
        case 0x1B: in(); break;
        case 0x1C: out(); break;
        case 0x1D: jmp(); break;
        case 0x1E: equ(); break;
        case 0x1F: set(); break;
        default: std::cout << "Unknown command: " << command[0] << std::endl;
    }
}