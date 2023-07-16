#include "io.h"
#include <sys/types.h>

uc storage[1920];
uc memory[0xF800];
uc shy_register[16];
int main() {
  Create_Storage();
  Read_Memory();
}
