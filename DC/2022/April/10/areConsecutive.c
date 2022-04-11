#include <stdio.h>
#include <stdlib.h>
int areConsecutive(char *str)
{
    
    int len=strlen(str);
    int mid=len/2,val1=0,val2=0;
    if (str[mid]=='0')
        mid++;
    for (int i=0;i<mid;i++)
    {
        val1=val1*10 + (str[i]-'0');
    }
    for (int i=mid;i<len;i++)
    {
        val2=val2*10 + (str[i]-'0');
    }
    if (abs(val2-val1)==1)
        return 1;
    return 0;
}
int main()
{
    char str[101];
    scanf("%s", str);
    printf("%d", areConsecutive(str));
    return 0;
}
