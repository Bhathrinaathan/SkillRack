#include<stdio.h>
#include<stdlib.h>
int NameSorted(char S1[],int i,char S2[],int j,int index)
{
    if (S1[index]=='\0')
        return i;
    if (S2[index]=='\0')
        return j;
    if (tolower(S1[index])==tolower(S2[index]))
        NameSorted(S1,i,S2,j,index + 1);
    else if (tolower(S1[index])<tolower(S2[index]))
        return i;
    else if (tolower(S1[index])>tolower(S2[index]))
        return j;
}
int DurationOfWork(int inHr,int inMin,int outHr,int outMin)
{
    int duration=(outMin - inMin);
    duration+=(outHr - inHr)*60;
    return duration;
}
void swap(int* X,int* Y)
{
    int temp=*X;
    *X=*Y;
    *Y=temp;
}
int main()
{
    int N,max;
    scanf("%d",&N);
    int inMin[N],inHr[N],outHr,outMin,Duration[N];
    char Name[N][12],temp[12];
    for (int i=0;i<N;i++)
    {
        scanf("%s %d:%d %d:%d",Name[i],&inHr[i],&inMin[i],&outHr,&outMin);
        Duration[i]=DurationOfWork(inHr[i],inMin[i],outHr,outMin);
    }
    for (int i=0;i<N;i++)
    {
        max=i;
        for (int j=i;j<N;j++)
        {
            if (Duration[j]>Duration[max])
                max=j;
            if (Duration[j]==Duration[max] && inHr[j]<inHr[max])
                max=j;
            if (Duration[j]==Duration[max] && inHr[j]==inHr[max] && inMin[j]<inMin[max])
                max=j;
            if (Duration[j]==Duration[max] && inHr[j]==inHr[max] && inMin[j]==inMin[max])
                max=NameSorted(Name[j],j,Name[max],max,0);
        }
        swap(&Duration[i],&Duration[max]);
        swap(&inHr[i],&inHr[max]);
        swap(&inMin[i],&inMin[max]);
        temp[0]='\0';
        strcpy(temp,Name[i]);
        strcpy(Name[i],Name[max]);
        strcpy(Name[max],temp);
    }
    for (int i=0;i<N;i++)
        printf("%s\n",Name[i]);
}
