 #include <iostream>
 #define uc unsigned char
inline bool is_not_command(uc commmand){
    if(0x09<command<0x20){return false;}
    else {return true;}
 }
