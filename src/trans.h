#define uc unsigned char
extern uc command[];//命令
extern uc memory[];//内存
struct Int16Pair {
  unsigned char highByte;
  unsigned char lowByte;
};//int转字节
inline Int16Pair int_to_addr(int input) {
  Int16Pair result;
  result.highByte = input >> 8;
  result.lowByte = input & 0xFF;
  return result;
}
inline int addr_to_int(uc addr1, uc addr2){
    return(int(addr1)*16+int(addr2));
}


inline bool is_not_command(uc commmand){
    if(0x09<command[0]||command[0]<0x20){return false;}
    else {return true;}
 }
inline void address_trans(){
    for(int i=0;i<command[3];i++){
        int memory_addr=addr_to_int(command[1],command[2]);//指向的内存地址
        uc new_command_1=memory[memory_addr-1];
        uc new_command_2=memory[memory_addr];//内存地址所存的值
        command[1]=new_command_1;
        command[2]=new_command_2;
    }
}




