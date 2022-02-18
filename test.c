#include <stdio.h>

void func(int a)
{
    printf("%d\n", a);
}

int main(void)
{
    void (*ptrFunc)() = &func(1);
    ptrFunc();
    return 0;
}