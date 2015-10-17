#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 65535
//#define DEBUGING
int main()
{
	FILE *file1=fopen("D:\\S12\\P1202\\file1.txt","r");
	FILE *file2=fopen("D:\\S12\\P1202\\file2.txt","r");
	if(file1==NULL) return -1;
	if(file2==NULL) return -1;
	char buffer1[MAX_STRING_LENGTH+1];
	char buffer2[MAX_STRING_LENGTH+1];
	int lineID=0;
	while(233)
	{
		lineID++;

		if(feof(file1) && feof(file2))//均到达文件尾
		{
			puts("same");
			return 0;
		}
		else if(!feof(file1) && !feof(file2))//均未到达文件尾
		{
			fgets(buffer1, MAX_STRING_LENGTH, file1);
			fgets(buffer2, MAX_STRING_LENGTH, file2);
			//处理gets末尾\n问题
			if(buffer1[strlen(buffer1)-1] == '\n')buffer1[strlen(buffer1)-1]=0;
			if(buffer2[strlen(buffer2)-1] == '\n')buffer2[strlen(buffer2)-1]=0;
#ifdef DEBUGING
			printf("FILE 1 LINEID %d\n", lineID);
			puts(buffer1);
			puts("*");
			printf("FILE 2 LINEID %d\n", lineID);
			puts(buffer2);
			puts("*");
#endif
			if(strcmp(buffer1, buffer2))
			{
				printf("%d", lineID);
				return 0;
			}
		}
		else//其中一个到达了文件尾
		{
			printf("%d",lineID);
			return 0;
		}
	}
	return 0;
}