#include "memorylist.h" // 包含必要的头文件

extern std::vector<unsigned short> address;

// 加法函数，接受两个地址参数，将这两个地址中的值相加，结果存储在第一个地址中。
inline void adda(unsigned short addr1, unsigned short addr2) {
    address[addr1] = address[addr1] + address[addr2];
}

// 加法函数，接受一个地址和一个数字参数，将这个地址中的值与数字相加，结果也存储在这个地址中。
inline void addn(unsigned short addr1, unsigned short num1) {
    address[addr1] = address[addr1] + num1;
}

// 减法函数，接受两个地址参数，将第一个地址中的值减去第二个地址中的值，结果存储在第一个地址中。
inline void suba(unsigned short addr1, unsigned short addr2) {
    address[addr1] = address[addr1] - address[addr2];
}

// 减法函数，接受一个地址和一个数字参数，将这个地址中的值减去这个数字，结果存储在这个地址中。
inline void subn(unsigned short addr1, unsigned short num1) {
    address[addr1] = address[addr1] - num1;
}

// 乘法函数，接受两个地址参数，将这两个地址中的值相乘，结果存储在第一个地址中。
inline void mula(unsigned short addr1, unsigned short addr2) {
    address[addr1] = address[addr1] * address[addr2];
}

// 乘法函数，接受一个地址和一个数字参数，将这个地址中的值与数字相乘，结果也存储在这个地址中。
inline void muln(unsigned short addr1, unsigned short num1) {
    address[addr1] = address[addr1] * num1;
}

// 除法函数，接受两个地址参数，将第一个地址中的值除以第二个地址中的值，结果存储在第一个地址中。
inline void diva(unsigned short addr1, unsigned short addr2) {
    address[addr1] = address[addr1] / address[addr2];
}

// 除法函数，接受一个地址和一个数字参数，将这个地址中的值除以这个数字，结果存储在这个地址中。
inline void divn(unsigned short addr1, unsigned short num1) {
    address[addr1] = address[addr1] / num1;
}

// 位运算左移函数，接受两个地址参数，将第一个地址中的值左移第二个地址中的值位，结果存储在第一个地址中。
inline void lsa(unsigned short addr1, unsigned short addr2) {
    address[addr1] = address[addr1] << address[addr2];
}

// 位运算左移函数，接受一个地址和一个数字参数，将这个地址中的值左移这个数字位，结果存储在这个地址中。
inline void lsn(unsigned short addr1, unsigned short num1) {
    address[addr1] = address[addr1] << num1;
}

// 位运算右移函数，接受两个地址参数，将第一个地址中的值右移第二个地址中的值位，结果存储在第一个地址中。
inline void lra(unsigned short addr1, unsigned short addr2) {
    address[addr1] = address[addr1] >> address[addr2];
}

// 位运算右移函数，接受一个地址和一个数字参数，将这个地址中的值右移这个数字位，结果存储在这个地址中。
inline void lrn(unsigned short addr1, unsigned short num1) {
    address[addr1] = address[addr1] >> num1;
}

// 位运算与函数，接受两个地址参数，将这两个地址中的值进行与运算，结果存储在第一个地址中。
inline void anda(unsigned short addr1, unsigned short addr2) {
    address[addr1] = address[addr1] & address[addr2];
}

// 位运算与函数，接受一个地址和一个数字参数，将这个地址中的值与这个数字进行与运算，结果存储在这个地址中。
inline void andn(unsigned short addr1, unsigned short num1) {
    address[addr1] = address[addr1] & num1;
}

// 位运算或函数，接受两个地址参数，将这两个地址中的值进行或运算，结果存储在第一个地址中。
inline void ora(unsigned short addr1, unsigned short addr2) {
    address[addr1] = address[addr1] | address[addr2];
}

// 位运算或函数，接受一个地址和一个数字参数，将这个地址中的值与这个数字进行或运算，结果存储在这个地址中。
inline void orn(unsigned short addr1, unsigned short num1) {
    address[addr1] = address[addr1] | num1;
}

// 位运算非函数，接受一个地址参数，将这个地址中的值进行非运算，结果存储在这个地址中。
inline void nota(unsigned short addr1,unsigned short addr2) {
    address[addr1] = ~address[addr1];
}

// 位运算非函数，接受一个地址和一个数字参数，将这个数字进行非运算，结果存储在这个地址中。
inline void notn(unsigned short addr1,unsigned short num1) {
    address[addr1] = num1;
}

// 位运算异或函数，接受两个地址参数，将这两个地址中的值进行异或运算，结果存储在第一个地址中。
inline void xora(unsigned short addr1,unsigned short addr2) {
    address[addr1] = address[addr1] ^ address[addr2];
}

// 位运算异或函数，接受一个地址和一个数字参数，将这个地址中的值与这个数字进行异或运算，结果存储在这个地址中。
inline void xorn(unsigned short addr1,unsigned short num1) {
    address[addr1] = address[addr1] ^ num1;
}

// 跳转函数，如果 `tmp` 为1，将程序计数器（`pc`）设置为第一个地址中的值。
inline void jmpa(unsigned short addr1,unsigned short addr2) {
    if(tmp == 1)
        pc = address[addr1];
}

// 跳转函数，如果 `tmp` 为1，将程序计数器（`pc`）设置为第一个数字参数。
inline void jmpn(unsigned short num1,unsigned short num2) {
    if(tmp == 1)
        pc = num1;
}

// 等于比较函数，接受两个地址参数，如果这两个地址中的值相等，就将 `tmp` 设置为1，否则设置为0。
inline void equa(unsigned short addr1, unsigned short addr2) {
    tmp = (address[addr1] == address[addr2]) ? 1 : 0;
}

// 等于比较函数，接受一个地址和一个数字参数，如果这个地址中的值等于这个数字，就将 `tmp` 设置为1，否则设置为0。
inline void equn(unsigned short addr1, unsigned short num1) {
    tmp = (address[addr1] == num1) ? 1 : 0;
}

// 大于比较函数，接受两个地址参数，如果第一个地址中的值大于第二个地址中的值，就将 `tmp` 设置为1，否则设置为0。
inline void biga(unsigned short addr1, unsigned short addr2) {
    tmp = (address[addr1] > address[addr2]) ? 1 : 0;
}

// 大于比较函数，接受一个地址和一个数字参数，如果这个地址中的值大于这个数字，就将 `tmp` 设置为1，否则设置为0。
inline void bign(unsigned short addr1, unsigned short num1) {
    tmp = (address[addr1] > num1) ? 1 : 0;
}

// 大于等于比较函数，接受两个地址参数，如果第一个地址中的值大于等于第二个地址中的值，就将 `tmp` 设置为1，否则设置为0。
inline void bigequa(unsigned short addr1, unsigned short addr2) {
    tmp = (address[addr1] >= address[addr2]) ? 1 : 0;
}

// 大于等于比较函数，接受一个地址和一个数字参数，如果这个地址中的值大于等于这个数字，就将 `tmp` 设置为1，否则设置为0。
inline void bigequn(unsigned short addr1, unsigned short num1) {
    tmp = (address[addr1] >= num1) ? 1 : 0;
}

// 小于比较函数，接受两个地址参数，如果第一个地址中的值小于第二个地址中的值，就将 `tmp` 设置为1，否则设置为0。
inline void smaa(unsigned short addr1, unsigned short addr2) {
    tmp = (address[addr1] < address[addr2]) ? 1 : 0;
}

// 小于比较函数，接受一个地址和一个数字参数，如果这个地址中的值小于这个数字，就将 `tmp` 设置为1，否则设置为0。
inline void sman(unsigned short addr1, unsigned short num1) {
    tmp = (address[addr1] < num1) ? 1 : 0;
}

// 小于等于比较函数，接受两个地址参数，如果第一个地址中的值小于等于第二个地址中的值，就将 `tmp` 设置为1，否则设置为0。
inline void smaequa(unsigned short addr1, unsigned short addr2) {
    tmp = (address[addr1] <= address[addr2]) ? 1 : 0;
}

// 小于等于比较函数，接受一个地址和一个数字参数，如果这个地址中的值小于等于这个数字，就将 `tmp` 设置为1，否则设置为0。
inline void smaequn(unsigned short addr1, unsigned short num1) {
    tmp = (address[addr1] <= num1) ? 1 : 0;
}

// 设置函数，接受两个地址参数，将第二个地址中的值设置为第一个地址中的值。
inline void seta(unsigned short addr1, unsigned short addr2) {
    address[addr1] = address[addr2];
}

// 设置函数，接受两个数字参数，将第二个数字设置为第一个地址中的值。
inline void setn(unsigned short num1, unsigned short num2) {
    address[num1] = num2;
}

// 输入函数，接受一个地址参数，将用户输入的值存储在这个地址中。
inline void ina(unsigned short addr1, unsigned short addr2) {
    cin >> address[addr1];
}

// 输入函数，接受一个数字参数，但它不会做任何操作，只是打印出一个错误信息，因为按照规定，不能直接将输入值传给实际数。
inline void inn(unsigned short num1, unsigned short num2) {
    cout << "你为什么要用inn？？？？您想把输入值传给实际数？" << endl;
    cout << "Why are you use 'inn' for input？？？？ Do you want to pass an input value to a real number？" << endl;
}

// 输出函数，接受一个地址参数，输出这个地址中的值。
inline void outa(unsigned short addr1, unsigned short addr2) {
    cout << address[addr1];
}

// 输出函数，接受一个数字参数，直接输出这个数字。
inline void outn(unsigned short num1, unsigned short num2) {
    cout << num1;
}
inline void outaasc(unsigned short addr1, unsigned short addr2) {
    if (address[addr1] <= 128) {
    cout<<(char)address[addr1];
}
    else
    cout<<"你在试图输出一个ascii,但是输出值大于128！！！";//中文
    cout<<"You are trying to output an ascii, but the output value is greater than 128!!!";//English
}
inline void outnasc(unsigned short num1, unsigned short num2) {
    if (num1 <= 128) {
    cout<<(char)num1;
}
    else
    cout<<"你在试图输出一个ascii,但是输出值大于128！！！";//中文
    cout<<"You are trying to output an ascii, but the output value is greater than 128!!!";//English
}
