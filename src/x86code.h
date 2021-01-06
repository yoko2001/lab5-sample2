#ifndef __X86CODE__
#define __X86CODE__

enum{
    X86_MOVI1,
    X86_MOVI4,
};
char* x86code[] = {
    "mov %b0, %b1",
    "mov %d0, %d1",
};

#endif