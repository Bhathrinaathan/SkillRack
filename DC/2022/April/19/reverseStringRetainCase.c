#include <stdio.h>
#include <stdlib.h>
void reverseStringRetainCase(char *str)
{
    char left;
    int pos=0,tlen,start=0;
    for (int i=0;str[i]!='\0';i++)
    {
        while(str[i]!=' ' && str[i]!='\0')
            i++;
        for (int j=start,k=i-1;j<k;j++,k--)
        {
            left=str[j];
            if (isupper(str[j]))
                str[j]=toupper(str[k]);
            else
                str[j]=tolower(str[k]);
                
            if (isupper(str[k]))
                str[k]=toupper(left);
            else    
                str[k]=tolower(left);
        }
        start=i+1;
    }
}
int main()
{
    char str[1001];
    scanf("%[^\n]", str);
    reverseStringRetainCase(str);
    if(str[0] == '\0' || str[0] == ' ')
    {
        printf("String is empty\n");
    }
    printf("%s", str);
    return 0;
}
