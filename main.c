#include"sort.h"
#include"random_generation.h"
#include<stdio.h>
#include<string.h>
#include<sys/time.h>
#include<stdlib.h>
#define data 100000
int main()
{
	randomgen();
	int *num=(int*)malloc(sizeof(int)*data);
	int *nums=(int*)malloc(sizeof(int)*data);
	char *numsw[data];
	for(int i=0;i<data;i++){
		numsw[i]=(char*)malloc(sizeof(char)*100);
	}
	FILE *fp1=fopen("dataset1.txt","r");
	FILE *fp2=fopen("dataset2.txt","r");

	for(int i=0;i<data;i++){
		fscanf(fp1,"%d",&num[i]);
	}
	struct timeval startq;
	struct timeval endq;
	unsigned long differq;
	struct timeval startm;
	struct timeval endm;
	unsigned long differm;
	struct timeval starth;
	struct timeval endh;
	unsigned long differh;

	for(int i=0;i<data;i++){
		nums[i]=num[i];
	}
	gettimeofday(&startq,NULL);
	quicksort(nums,0,data);
	gettimeofday(&endq,NULL);
	printf("QUICKSORT!!!!!!!!!!!!!!!!!!!!!!\n");
	for(int i=1;i<=5;i++){
		printf("%d\n",nums[i]);
	}



	for(int i=0;i<data;i++){
		nums[i]=num[i];
	}
	gettimeofday(&startm,NULL);
	mergesort(nums,0,data-1);
	gettimeofday(&endm,NULL);
	printf("MERGESORT!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	for(int i=0;i<5;i++){
		printf("%d\n",nums[i]);
	}
	


	for(int i=0;i<data;i++){
		nums[i]=num[i];
	}
	gettimeofday(&starth,NULL);
	heapsort(nums,data);
	gettimeofday(&endh,NULL);
	printf("HEAPSORT!!!!!!!!!!!!!!!!!!!!!!\n");
	for(int i=0;i<5;i++){
		printf("%d\n",nums[i]);
	}

	printf("\n");
	differq=1000000*(endq.tv_sec-startq.tv_sec)+endq.tv_usec-startq.tv_usec;
	printf("quicksort: %f sec\n",differq/1000000.0);
	differm=1000000*(endm.tv_sec-startm.tv_sec)+endm.tv_usec-startm.tv_usec;
	printf("mergesort: %f sec\n",differm/1000000.0);
	differh=1000000*(endh.tv_sec-starth.tv_sec)+endh.tv_usec-starth.tv_usec;
	printf("heapsort: %f sec\n",differh/1000000.0);
	
	return 0;
}
