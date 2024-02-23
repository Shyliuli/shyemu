#include "memorylist.h" // 包含必要的头文件
#include <fstream>
#include <iostream>
#include <vector>

// 假设 address 是一个全局变量，类型为 std::vector<unsigned short>
extern std::vector<unsigned short> address;

void read_file(const std::string &filename) {
    // 以二进制模式打开文件进行读取
    std::ifstream file(filename, std::ios::binary);
    
    // 检查文件是否成功打开
    if (!file.is_open()) {
        std::cerr << "打开文件错误: " << filename << std::endl;
        return;
    }
    
    // 清空address向量并预留65535个元素的空间
    address.clear();
    address.reserve(65535);

    // 从文件中读取数据到向量
    unsigned short val;
    while (file.read(reinterpret_cast<char*>(&val), sizeof(val))) {
        address.push_back(val);
    }

    // 检查读取过程中是否出错
    if (!file.eof() && !file) {
        std::cerr << "从文件读取错误: " << filename << std::endl;
    }

    // 关闭文件
    file.close();
}
