#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int isFloatString(char *S)
{
    int i=0;
    while (S[i+1]!=NULL){
        if (!(isdigit(S[i]) || S[i]=='.')){
            return 0;}
        i++;
    }return 1;
}
int dotInToken(char *S)
{
    int i=0;
    while (S[i+1]!='\0'){
        if (S[i]=='.')
            return 1;
        i++;
    }return 0;
}
double getTotalPrice(char *str)
{
    double amount=0.0;
    const char delim[1]=" ";
    char *token;
    token=strtok(str,delim);
    while (token!=NULL)
    {
        if (isFloatString(token) && dotInToken(token))
        {
            if (token[strlen(token)- 1]=='.')
                token[strlen(token)- 1]='\0';
            amount+=atof(token);
        }
        token=strtok(NULL,delim);
    }
    return amount;
}
int main()
{
    char str[101];
    scanf("%[^\n\r]", str);
    double totalPrice = getTotalPrice(str);
    printf("%.2lf", totalPrice);
    return 0;
}
