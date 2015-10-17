#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *file=fopen("D:\\S12\\P1201\\data1.in","r");
	if(file==NULL) return -1;
	float x, sum=0, n=0;
	while(! feof(file))
	{
		fscanf(file, "%f", &x);
		sum += x;
		n ++;
	}
	printf("%.2f", sum/n);
	return 0;
}