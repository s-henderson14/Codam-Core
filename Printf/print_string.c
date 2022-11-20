#include <stdio.h>

int print_string(char *s)
{
    int i;

    i = 0;
    while(s[i] != '\0')
    {    
        write(1, &s[i], 1);
        i++;
    }
    return (i);
}