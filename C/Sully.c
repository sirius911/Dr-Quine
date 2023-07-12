#include <stdio.h>
#include <stdlib.h>

/*
    comment
*/

int main()
{
    int i = 5;
    int j = i - 1;
    if (i < 0)
        return 0;
    char str[] = "#include <stdio.h>%2$c#include <stdlib.h>%2$c%2$c/*%2$c    comment%2$c*/%2$c%2$cint main()%2$c{%2$c    int i = %3$d;%2$c    int j = i - 1;%2$c    if (i < 0)%2$c        return 0;%2$c    char str[] = %4$c%1$s%4$c;%2$c    char fname[16];%2$c    sprintf(fname, %4$cSully_%5$cd.c%4$c, i);%2$c%2$c    FILE *file = fopen(fname, %4$cw%4$c);%2$c    fprintf(file, str, str, 10, j, 34, 37);%2$c    fclose(file);%2$c    char exec[64];%2$c    sprintf(exec, %4$cgcc -Wall -Wextra -Werror Sully_%5$c1$d.c -o Sully_%5$c1$d%4$c, i);%2$c    system(exec);%2$c%2$c    sprintf(exec, %4$c./Sully_%5$cd%4$c, i);%2$c    system(exec);%2$c    return 0;%2$c}";
    char fname[16];
    sprintf(fname, "Sully_%d.c", i);

    FILE *file = fopen(fname, "w");
    fprintf(file, str, str, 10, j, 34, 37);
    fclose(file);
    char exec[64];
    sprintf(exec, "gcc -Wall -Wextra -Werror Sully_%1$d.c -o Sully_%1$d", i);
    system(exec);

    sprintf(exec, "./Sully_%d", i);
    system(exec);
    return 0;
}