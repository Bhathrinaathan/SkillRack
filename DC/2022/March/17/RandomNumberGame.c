#include<stdio.h>
#include<stdlib.h>
int main()
{ 
	int X,N; 
	scanf("%d",&N); 
	int randArr[N],t; 
	for (int i=0;i<N;i++) 
		scanf("%d",&randArr[i]); 
	scanf("%d",&X); 
	t=X; 
	for (int i=0;i<N;i++) 
		if (randArr[i]==X) 
			X*=2; 
	if (t==X) 
		printf("%d",0); 
	else 
		printf("%d",X);
}
