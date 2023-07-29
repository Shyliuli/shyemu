#include "run.h"
uc storage[1920];
uc memory[0xF800];
uc shy_register[16];
int main() {
  Create_Storage();
  Read_Memory();
  bool is_debug_mode;
  cout << "如果是debug模式，输入1，反之则输入0";
  cin>> is_debug_mode;
  run_program(is_debug_mode);
}
