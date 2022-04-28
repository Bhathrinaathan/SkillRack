#include<stdio.h>
#include<stdlib.h>

int main()
{
    char S[1001],P[1001]; 
    scanf("%s\n%s",S,P);
    int index=0,upperP=0,upperS=0,count=0;
    for (int i=0;i<strlen(P);i++){
        if (isupper(P[i]))
            upperP++;}
    for (int i=0;i<strlen(S);i++){
        if (isupper(S[i]))
            upperS++;}
    if (upperS>upperP)
    {   printf("NO");return;    }
    for (int i=0;i<strlen(S);i++)
    {
        if (S[i]==P[index])
        {
            index++;
            count++;
        }
        else if (isupper(S[i]))
        {
            printf("NO");return;
        }
    }
    if (count==strlen(P))
    {
        printf("YES");
        return;
    }
    printf("NO");
}
