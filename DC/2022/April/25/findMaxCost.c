#include <stdio.h>
#include <stdlib.h>

struct Box
{
    int pens;
    int pencils;
    int erasers;
};
int findMaxCost(int N, struct Box boxes[])
{
    int maxCost=0,temp;
    for (int i=0;i<N;i++)
    {
        temp=boxes[i].pens*10 + boxes[i].pencils*5 + boxes[i].erasers*3;
        if (temp>maxCost)
            maxCost=temp;
    }
    return maxCost;
}
int main()
{
    int N;
    scanf("%d", &N);
    struct Box boxes[N];
    for(int index = 0; index < N; index++)
    {
        scanf("%d %d %d", &boxes[index].pens, &boxes[index].pencils, &boxes[index].erasers);
    }
    printf("%d", findMaxCost(N, boxes));
    return 0;
}
