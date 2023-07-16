#include <iostream>
#include <stdexcept>
using namespace std;
inline void run(), run_debug();
inline  void run_program(bool is_debug_mode){
    if(is_debug_mode) {run_debug();}
    else{run();}
}
inline void run(){

}
inline void run_debug(){

}
