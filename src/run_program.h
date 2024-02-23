#include "buildin_function.h"
unsigned short addrtrans(unsigned short addr1, unsigned short times) {
    for (unsigned short i = 0; i < times; ++i) {
        // 检查索引是否越界
        if (addr1 >= address.size()) {
            std::cerr << "Index out of bounds: " << addr1 << std::endl;
            return 0;  // 或者其他错误处理
        }
        // 使用当前值作为下一个索引
        addr1 = address[addr1];
    }
    return addr1;
}


// 错误处理函数
inline void error()
{
    // 实现错误处理逻辑
    // 例如：输出错误信息，记录日志等
}

/*
0x00-0x0F: 寄存器，返回0
0x10-0x35: 保留空间（用于命令等），返回1
0x36-0xFFFF: 内存，返回2
其中
0x10-0x1FF: 变量存储
0x2000-0xFFFF: 程序
*/

// 根据输入的地址类型调用相应的函数
inline void run(unsigned short input1, unsigned short input2, unsigned short input3)
{
    // 定义函数指针类型
    typedef void (*BinaryFunc)(unsigned short, unsigned short);

    // 函数指针数组
    // 据说这么写和写一堆swith一样
    // 就挺神奇的
    // 反正我写不出来
    BinaryFunc binaryFunctions[] = {
        adda, addn, suba, subn, mula, muln, diva, divn,
        lsa, lsn, lra, lrn, anda, andn, ora, orn, nota, notn, xora,xorn, jmpa,jmpn, equa,
        equn,biga,bign, bigequa,bigequn, smaa,sman,smaequa,smaequn,seta,setn, ina,inn, outa,outn,outaasc,outnasc};

    // 按照函数编号调用对应函数
    if (input1 >= ADDA_FUNC && input1 <= OUTNASC_FUNC)
    {
        binaryFunctions[(input1 - ADDA_FUNC)-1](input2, input3);
    } 
    else
    {
        std::cerr << "Error: Invalid parameter types." << std::endl;
        // 调用错误处理函数
        error();
        // 退出程序
        std::exit(EXIT_FAILURE);
    }
    /*按照函数编号调用对应函数
     内建函数编号从0x10开始*/
}




inline void run_program() {
    unsigned short index = CODE_FROM;
    while (true) {
        // 检查是否有足够的元素来进行后续操作
        if (index + 4 >= address.size()) {
            std::cerr << "Insufficient elements for operation at index " << index << std::endl;
            break;
        }

        // 检查 address[index] 是否为0
        if (address[index] == 0) {
            break;
        }

        // 运行 run 函数
        run(address[index],
            addrtrans(address[index + 1], address[index + 2]),
            addrtrans(address[index + 3], address[index + 4]));

        // 更新 index
        index += 5;
    }
}