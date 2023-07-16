#include <fstream>
#include <iostream>
#define uc unsigned char
using namespace std;
extern uc memory[];

inline void Read_Memory() {
  ifstream infile("./memory.sfs", ios::binary);
  infile.read(reinterpret_cast<char *>(memory), 0xF800);
  infile.close();
}

inline void Create_Storage() {
  ofstream outfile("./storage.sfs", ios::binary);
  uc buffer[1920] = {0};
  outfile.write(reinterpret_cast<char *>(buffer), 1920);
  outfile.close();
}

