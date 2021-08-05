#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[]="PERTISTH SINGH";
    for(int i=0;a[i]!='\0';i++)
    {
        a[i]=a[i]+32;
    }
    printf("%s",a);
    return 0;
}
