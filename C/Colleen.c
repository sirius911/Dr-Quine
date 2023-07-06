#include <stdio.h>
//comment outside

void write(char *str)
{
    printf(str, 10, 34, str);
}

int main(void)
{
    //comment in main
    char *x = "#include <stdio.h>%1$c//comment outside%1$c%1$cvoid write(char *str)%1$c{%1$c    printf(str, 10, 34, str);%1$c}%1$c%1$cint main(void)%1$c{%1$c    //comment in main%1$c    char *x = %2$c%3$s%2$c;%1$c    write(x);%1$c    return 0;%1$c}";
    write(x);
    return 0;
}