#include "command.h"

// 命令函数声明
void adda(uint16_t a1, uint16_t a2);
void addn(uint16_t a1, uint16_t a2);
void suba(uint16_t a1, uint16_t a2);
void subn(uint16_t a1, uint16_t a2);
void mula(uint16_t a1, uint16_t a2);
void muln(uint16_t a1, uint16_t a2);
void diva(uint16_t a1, uint16_t a2);
void divn(uint16_t a1, uint16_t a2);
void lsa(uint16_t a1, uint16_t a2);
void lsn(uint16_t a1, uint16_t a2);
void rsa(uint16_t a1, uint16_t a2);
void rsn(uint16_t a1, uint16_t a2);
void anda(uint16_t a1, uint16_t a2);
void andn(uint16_t a1, uint16_t a2);
void ora(uint16_t a1, uint16_t a2);
void orn(uint16_t a1, uint16_t a2);
void nota(uint16_t a1, uint16_t a2);
void notn(uint16_t a1, uint16_t a2);
void xora(uint16_t a1, uint16_t a2);
void xorn(uint16_t a1, uint16_t a2);
void jmpa(uint16_t a1, uint16_t a2);
void jmpn(uint16_t a1, uint16_t a2);
void equa(uint16_t a1, uint16_t a2);
void equn(uint16_t a1, uint16_t a2);
void biga(uint16_t a1, uint16_t a2);
void bign(uint16_t a1, uint16_t a2);
void bigequa(uint16_t a1, uint16_t a2);
void bigequn(uint16_t a1, uint16_t a2);
void smaa(uint16_t a1, uint16_t a2);
void sman(uint16_t a1, uint16_t a2);
void smaequa(uint16_t a1, uint16_t a2);
void smaeuqn(uint16_t a1, uint16_t a2);
void seta(uint16_t a1, uint16_t a2);
void setn(uint16_t a1, uint16_t a2);
void ina(uint16_t a1, uint16_t a2);
void inn(uint16_t a1, uint16_t a2);
void inaasc(uint16_t a1, uint16_t a2);
void innasc(uint16_t a1, uint16_t a2);
void outa(uint16_t a1, uint16_t a2);
void outn(uint16_t a1, uint16_t a2);
void outaasc(uint16_t a1, uint16_t a2);
void outnasc(uint16_t a1, uint16_t a2);

// 命令表（函数指针数组）
void (*commands_table[42])(uint16_t, uint16_t) = {
    adda, addn, suba, subn, mula, muln, diva, divn, lsa, lsn,
    rsa, rsn, anda, andn, ora, orn, nota, notn, xora, xorn,
    jmpa, jmpn, equa, equn, biga, bign, bigequa, bigequn,
    smaa, sman, smaequa, smaeuqn, seta, setn, ina,
    inn, inaasc, innasc, outa, outn, outaasc, outnasc
};

// 数学运算
void adda(uint16_t a1, uint16_t a2) { mem_write(a1, mem_read(a1) + mem_read(a2)); }
void addn(uint16_t a1, uint16_t a2) { mem_write(a1, mem_read(a1) + a2); }
void suba(uint16_t a1, uint16_t a2) { mem_write(a1, mem_read(a1) - mem_read(a2)); }
void subn(uint16_t a1, uint16_t a2) { mem_write(a1, mem_read(a1) - a2); }
void mula(uint16_t a1, uint16_t a2) { mem_write(a1, mem_read(a1) * mem_read(a2)); }
void muln(uint16_t a1, uint16_t a2) { mem_write(a1, mem_read(a1) * a2); }
void diva(uint16_t a1, uint16_t a2) { 
    uint16_t divisor = mem_read(a2);
    mem_write(a1, divisor ? mem_read(a1) / divisor : 0); 
}
void divn(uint16_t a1, uint16_t a2) { 
    mem_write(a1, a2 ? mem_read(a1) / a2 : 0); 
}

// 位运算
void lsa(uint16_t a1, uint16_t a2) { mem_write(a1, mem_read(a1) << mem_read(a2)); }
void lsn(uint16_t a1, uint16_t a2) { mem_write(a1, mem_read(a1) << a2); }
void rsa(uint16_t a1, uint16_t a2) { mem_write(a1, mem_read(a1) >> mem_read(a2)); }
void rsn(uint16_t a1, uint16_t a2) { mem_write(a1, mem_read(a1) >> a2); }
void anda(uint16_t a1, uint16_t a2) { mem_write(a1, mem_read(a1) & mem_read(a2)); }
void andn(uint16_t a1, uint16_t a2) { mem_write(a1, mem_read(a1) & a2); }
void ora(uint16_t a1, uint16_t a2) { mem_write(a1, mem_read(a1) | mem_read(a2)); }
void orn(uint16_t a1, uint16_t a2) { mem_write(a1, mem_read(a1) | a2); }
void nota(uint16_t a1, uint16_t a2) { mem_write(a1, ~mem_read(a1)); }
void notn(uint16_t a1, uint16_t a2) {} // 无效命令
void xora(uint16_t a1, uint16_t a2) { mem_write(a1, mem_read(a1) ^ mem_read(a2)); }
void xorn(uint16_t a1, uint16_t a2) { mem_write(a1, mem_read(a1) ^ a2); }

// 控制流
void jmpa(uint16_t a1, uint16_t a2) { 
    if (reg_ox) { 
        reg_pc = mem_read(a1); 
        reg_ox = 0; 
    } 
}
void jmpn(uint16_t a1, uint16_t a2) { 
    if (reg_ox) { 
        reg_pc = a1; 
        reg_ox = 0; 
    } 
}

// 比较运算
void equa(uint16_t a1, uint16_t a2) { reg_ox = (mem_read(a1) == mem_read(a2)) ? 1 : 0; }
void equn(uint16_t a1, uint16_t a2) { reg_ox = (mem_read(a1) == a2) ? 1 : 0; }
void biga(uint16_t a1, uint16_t a2) { reg_ox = (mem_read(a1) > mem_read(a2)) ? 1 : 0; }
void bign(uint16_t a1, uint16_t a2) { reg_ox = (mem_read(a1) > a2) ? 1 : 0; }
void bigequa(uint16_t a1, uint16_t a2) { reg_ox = (mem_read(a1) >= mem_read(a2)) ? 1 : 0; }
void bigequn(uint16_t a1, uint16_t a2) { reg_ox = (mem_read(a1) >= a2) ? 1 : 0; }
void smaa(uint16_t a1, uint16_t a2) { reg_ox = (mem_read(a1) < mem_read(a2)) ? 1 : 0; }
void sman(uint16_t a1, uint16_t a2) { reg_ox = (mem_read(a1) < a2) ? 1 : 0; }
void smaequa(uint16_t a1, uint16_t a2) { reg_ox = (mem_read(a1) <= mem_read(a2)) ? 1 : 0; }
void smaeuqn(uint16_t a1, uint16_t a2) { reg_ox = (mem_read(a1) <= a2) ? 1 : 0; }

// 数据操作
void seta(uint16_t a1, uint16_t a2) { mem_write(a1, mem_read(a2)); }
void setn(uint16_t a1, uint16_t a2) { mem_write(a1, a2); }

// 输入/输出
void ina(uint16_t a1, uint16_t a2) { 
    uint16_t val; 
    scanf("%hu", &val); 
    mem_write(a1, val); 
}
void inn(uint16_t a1, uint16_t a2) {} // 无效命令
void inaasc(uint16_t a1, uint16_t a2) { 
    char c; 
    scanf("%c", &c); 
    mem_write(a1, (uint16_t)c); 
}
void innasc(uint16_t a1, uint16_t a2) {} // 无效命令

void outa(uint16_t a1, uint16_t a2) { printf("%hu", mem_read(a1)); }
void outn(uint16_t a1, uint16_t a2) { printf("%hu", a1); }
void outaasc(uint16_t a1, uint16_t a2) { 
    uint16_t val = mem_read(a1); 
    if (val <= 0xFF){
        char c = (char)val;
        printf("%c",c);
    }; 
}
void outnasc(uint16_t a1, uint16_t a2) { 
    if (a1 <= 0xFF){
        char c = (char)a1;
        printf("%c",c);
    }; 
}
void run_command(uint16_t command,uint16_t arg1,uint16_t arg2){
    commands_table[command-COMMAND_START](arg1,arg2);
    }

