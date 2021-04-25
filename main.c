#include"sort.h"
#include"sortw.h"
#include"random_generation.h"
#include<stdio.h>
#include<string.h>
#include<sys/time.h>
#include<stdlib.h>
#define data 500000
int main()
{
	randomgen();

	struct timeval startq;
	struct timeval endq;
	unsigned long differq;
	struct timeval startm;
	struct timeval endm;
	unsigned long differm;
	struct timeval starth;
	struct timeval endh;
	unsigned long differh;

	struct timeval startqw;
	struct timeval endqw;
	unsigned long differqw;
	struct timeval startmw;
	struct timeval endmw;
	unsigned long differmw;
	struct timeval starthw;
	struct timeval endhw;
	unsigned long differhw;

	int *num=(int*)malloc(sizeof(int)*data);
	int *nums=(int*)malloc(sizeof(int)*data);
	FILE *fp1=fopen("dataset1.txt","r");
	for(int i=0;i<data;i++){
		fscanf(fp1,"%d",&num[i]);
	}
	for(int i=0;i<data;i++){
		nums[i]=num[i];
	}
	gettimeofday(&startq,NULL);
	quicksort(nums,0,data-1);
	gettimeofday(&endq,NULL);
	printf("QUICKSORT!!!!!!!!!!!!!!!!!!!!!!\n");
	for(int i=data-3;i<data;i++){
		printf("%d\n",nums[i]);
	}



	for(int i=0;i<data;i++){
		nums[i]=num[i];
	}
	gettimeofday(&startm,NULL);
	mergesort(nums,0,data-1);
	gettimeofday(&endm,NULL);
	printf("MERGESORT!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	for(int i=data-3;i<data;i++){
		printf("%d\n",nums[i]);
	}
	


	for(int i=0;i<data;i++){
		nums[i]=num[i];
	}
	gettimeofday(&starth,NULL);
	heapsort(nums,data);
	gettimeofday(&endh,NULL);
	printf("HEAPSORT!!!!!!!!!!!!!!!!!!!!!!\n");
	for(int i=data-3;i<data;i++){
		printf("%d\n",nums[i]);
	}

	free(nums);
	free(num);
	


//----------------------------------------------------
	char *numw[data];
	//char *numsw[data];
	for(int i=0;i<data;i++){
		numw[i]=(char*)malloc(sizeof(char)*100);
	//	numsw[i]=(char*)malloc(sizeof(char)*100);
	}
	
	FILE *fp2=fopen("dataset2.txt","r");
	
	for(int i=0;i<data;i++){
		fscanf(fp2,"%s",numw[i]);
	}	


/*	for(int i=0;i<data;i++){
		numsw[i]=numw[i];
	}
*/	gettimeofday(&startqw,NULL);
	quicksortw(numw,0,data-1);
	gettimeofday(&endqw,NULL);
	printf("QUICKSORTW!!!!!!!!!!!!!!!!!!!!!!\n");
	for(int i=data-3;i<data;i++){
		printf("%s\n",numw[i]);
	}

for(int i=0;i<data;i++){
		fscanf(fp2,"%s",numw[i]);
	}

/*	for(int i=0;i<data;i++){
		numsw[i]=numw[i];
	}
*/	gettimeofday(&startmw,NULL);
	mergesortw(numw,0,data-1);
	gettimeofday(&endmw,NULL);	
	printf("MERGESORTW!!!!!!!!!!!!!!!!!!!!!!\n");
	for(int i=data-3;i<data;i++){
		printf("%s\n",numw[i]);
	}

for(int i=0;i<data;i++){
		fscanf(fp2,"%s",numw[i]);
	}

/*	for(int i=0;i<data;i++){
		numsw[i]=numw[i];
	}
*/	gettimeofday(&starthw,NULL);
	heapsortw(numw,data);
	gettimeofday(&endhw,NULL);
	printf("HEAPSORTW!!!!!!!!!!!!!!!!!!!!!!\n");
	for(int i=data-3;i<data;i++){
		printf("%s\n",numw[i]);
	}




	printf("\n");
	differq=1000000*(endq.tv_sec-startq.tv_sec)+endq.tv_usec-startq.tv_usec;
	printf("quicksort: %f sec\n",differq/1000000.0);
	differm=1000000*(endm.tv_sec-startm.tv_sec)+endm.tv_usec-startm.tv_usec;
	printf("mergesort: %f sec\n",differm/1000000.0);
	differh=1000000*(endh.tv_sec-starth.tv_sec)+endh.tv_usec-starth.tv_usec;
	printf("heapsort: %f sec\n",differh/1000000.0);

	printf("\n");
	differqw=1000000*(endqw.tv_sec-startqw.tv_sec)+endqw.tv_usec-startqw.tv_usec;
	printf("quicksort: %f sec\n",differqw/1000000.0);
	differmw=1000000*(endmw.tv_sec-startmw.tv_sec)+endmw.tv_usec-startmw.tv_usec;
	printf("mergesort: %f sec\n",differmw/1000000.0);
	differhw=1000000*(endhw.tv_sec-starthw.tv_sec)+endhw.tv_usec-starthw.tv_usec;
	printf("heapsort: %f sec\n",differhw/1000000.0);

	
	return 0;
}
