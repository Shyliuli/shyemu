#include "io.h"

void load_mem(char *filename) {
    // 打开文件以二进制读模式
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        // 文件打开失败
        perror("Failed to open file for reading");
        assert(0);
    }

    // 遍历文件内容并加载到 mem 中
    for (size_t i = 0; i < MEM_SIZE; i++) {
        uint8_t byte1 = 0;  // 高字节
        uint8_t byte2 = 0;  // 低字节

        // 读取高字节
        if (fread(&byte1, sizeof(uint8_t), 1, file) != 1) {
            perror("Error reading high byte from file");
            fclose(file);
            assert(0);
        }

        // 读取低字节
        if (fread(&byte2, sizeof(uint8_t), 1, file) != 1) {
            perror("Error reading low byte from file");
            fclose(file);
            assert(0);
        }

        // 组合成16位值
        uint16_t value = ((uint16_t)byte1 << 8) | byte2;

        // 写入到 mem 中
        mem_write(i, value);
    }

    // 关闭文件
    if (fclose(file) != 0) {
        perror("Error closing file");
        assert(0);
    }

    // 成功完成
}