#include <stdio.h>
int main()
{
    char *s[64];
    s[1] = "abc";
    s[2] = "fuck";
    s[3] = "apple";
    int i = 1;
    printf("s1 is %s\n", s[i]);
    i++;
    printf("s2 is %s\n", s[i]);
    // while(i <= 3)
    // {
    //     printf("s is %s\n", s[i]);
    //     i++;
    // }
    return 0;

}