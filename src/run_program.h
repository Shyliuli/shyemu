#include "buildin_function.h"
inline unsigned short addrtype(unsigned short addr1)
{
    unsigned short addr_type;

    if (addr1 >= 0x00 && addr1 <= 0x0F)
        addr_type = 0; // 寄存器
    else if (addr1 >= 0x10 && addr1 <= 0x50)
        addr_type = 1; // 保留空间
    else if (addr1 >= 0x36 && addr1 <= 0xFFFF)
        addr_type = 2; // 内存

    return addr_type;
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
    unsigned short input_type1 = addrtype(input1);
    unsigned short input_type2 = addrtype(input2);
    unsigned short input_type3 = addrtype(input3);

    // 检查参数类型是否符合要求
    if (input_type1 != 1 || input_type2 == 1 || input_type3 == 1)
    {
        // 输出参数错误
        std::cerr << "Error: Invalid parameter types." << std::endl;
        // 调用错误处理函数
        error();
        // 退出程序
        std::exit(EXIT_FAILURE);
    }
    // 定义函数指针类型
    typedef void (*BinaryFunc)(unsigned short, unsigned short);

    // 函数指针数组
    // 据说这么写和写一堆swith一样
    // 就挺神奇的
    // 反正我写不出来
    BinaryFunc binaryFunctions[] = {
        adda, addn, suba, subn, mula, muln, diva, divn,
        lsa, lsn, lra, lrn, anda, andn, ora, orn, nota, notn, xora,xorn, jmpn, equa,
        equn,biga,bign, bigequa,bigequn, smaa,sman,smaequa,smaequn,seta,setn, ina,inn, outa,outn,outaasc,outnasc};

    // 按照函数编号调用对应函数
    if (input1 >= ADDA_FUNC && input1 <= OUTN_FUNC)
    {
        binaryFunctions[input1 - ADDA_FUNC](input2, input3);
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

