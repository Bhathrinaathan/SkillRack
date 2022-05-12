#include <stdio.h>
#include <stdlib.h>
int countDivisibleByThree(char *str)
{
    int sum=0,count=0,temp;
    for (int i=0;str[i]!='\0';i++)
        sum=sum+(str[i]-'0');
    for (int digit=0;digit<10;digit++)
    {
        for (int i=0;str[i]!='\0';i++)
        {
            if ((str[i]-'0')!=digit){
            temp=sum - (str[i]-'0') + digit;
            if (temp%3==0)
                count++;
            }
        }
    }
    return count;
}
int main()
{
    char str[101];
    scanf("%s", str);
    printf("%d", countDivisibleByThree(str));
    return 0;
}
