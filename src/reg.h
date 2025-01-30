#ifndef REG_H
#define REG_H
#include "common.h"
#include "mem.h"
#define REG_NUM 16
#define reg_ax mem[0]
#define reg_bx mem[1]
#define reg_cx mem[2]
#define reg_dx mem[3]
#define reg_ex mem[4]
#define reg_fx mem[5]
#define reg_gx mem[6]
#define reg_hx mem[7]
#define reg_ix mem[8]
#define reg_jx mem[9]
#define reg_kx mem[10]
#define reg_lx mem[11]
#define reg_mx mem[12]
#define reg_pc mem[12]
#define reg_nx mem[13]
#define reg_end mem[13]
#define reg_ox mem[14]
#define reg_px mem[15]
#endif