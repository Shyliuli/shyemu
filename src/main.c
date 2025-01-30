#include "common.h"
#include "io.h"
#include "cpu.h"
int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: shyemu <filename>\n");
        printf("no file input!n");
        return 1;
    }
    mem_init();
    load_mem(argv[1]);
    run();
    return 0;

}