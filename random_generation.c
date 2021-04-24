#include"random_generation.h"
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#define data 1000000

void randomgen()
{
	srand(time(NULL));
	//num
	FILE *fp1=fopen("dataset1.txt","w");
	for(int i=0;i<data;i++){
		fprintf(fp1,"%d\n",rand());
	}

	//string
	int flag,cnt=0;
	char ch[101];
	FILE *fp2=fopen("dataset2.txt","w");
	for(int i=0i;i<data;i++){
		for(int j=0;j<100;j++){
			flag=rand()%2;
			if(flag){
				ch[cnt++]='A'+rand()%26;
			}else
				ch[cnt++]='a'+rand()%26;
		}
		ch[cnt]='\0';
		cnt=0;
		fprintf(fp2,"%s\n",ch);	
	}
}
