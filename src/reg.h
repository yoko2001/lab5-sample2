#ifndef __REG_H__
#define __REG_H__
#include"domain.h"
enum {EAX, EBX, ECX, EDX, ESI, EDI, ESP, EBP};

extern domain_elem* X86Regs[];

//current usedregs, regs we are useing in current inst
//clear it before generating an inst
extern bool UsedRegs[];
void StoreVar(domain_elem* reg, domain_elem* v);
domain_elem* GetReg();
void SwapReg(domain_elem* reg);

domain_elem* CreateReg(std::string* name, std::string* iname, int no);
#endif