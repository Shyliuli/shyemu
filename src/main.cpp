#include "io.h"
using namespace std;

uc memory[0xF800];
int main() {
  Create_Storage();
  Read_Memory();
}
