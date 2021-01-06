#include"output.h"
static void EmitStrings(){
    
}

static void EmitFunctions(TreeNode* prog){

}

void SetupReg(){
    X86Regs[EAX] = CreateReg(new std::string("eax"), 
    new std::string("[eax]"), EAX);
    X86Regs[EAX] = CreateReg(new std::string("ebx"), 
    new std::string("[ebx]"), EBX);
    X86Regs[EAX] = CreateReg(new std::string("ecx"), 
    new std::string("[ecx]"), ECX);
    X86Regs[EAX] = CreateReg(new std::string("edx"), 
    new std::string("[edx]"), EDX);
    X86Regs[EAX] = CreateReg(new std::string("esi"), 
    new std::string("[esi]"), ESI);
    X86Regs[EAX] = CreateReg(new std::string("edi"), 
    new std::string("[edi]"), EDI);
}