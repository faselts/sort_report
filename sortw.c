#include"sortw.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swapw(char **array,int a, int b) {
  	char *t = array[a];
 	array[a] = array[b];
  	array[b] = t;
}

int partitionw(char **array, int low, int high){
    	char *pivot=(char*)malloc(sizeof(char)*100);
	pivot = array[high];
    	int i = (low - 1);
    	for (int j = low; j < high; j++){
            	if(strcmp(array[j],pivot)<=0){		
	                i++;
	                swapw(array,i, j);
	        }
        }
    	swapw(array,i + 1,high);
    	return (i + 1);
}
void quicksortw(char **array, int low, int high){
    	if (low < high){
            	int pi = partitionw(array, low, high);
            	quicksortw(array, low, pi - 1);
           	quicksortw(array, pi + 1, high);
        }
}


void mergew(char **arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    char *L[n1];
    char *M[n2];
    for(int k=0;k<n1;k++){
	L[k]=(char*)malloc(sizeof(char)*100);
    }
    for(int k=0;k<n2;k++){
	M[k]=(char*)malloc(sizeof(char)*100);
    }

    for(int i = 0; i < n1; i++)
    {
        L[i] = arr[p+i];
    }
    for (int j = 0; j < n2; j++)
    {
        M[j] = arr[q + 1 + j];
    }
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2) 
    {
        if (strcmp(L[i],M[j])<=0)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}
void mergesortw(char **arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesortw(arr, l, m);
        mergesortw(arr, m + 1, r);
        mergew(arr, l, m, r);
    }
}











void heapifyw(char **arr, int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && strcmp(arr[left],arr[largest])>0)
      largest = left;

    if (right < n && strcmp(arr[right],arr[largest])>0)
      largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {

      swapw(arr,i, largest);

      heapifyw(arr, n, largest);
    }
  }

  // Main function to do heap sort
void heapSortw(char **arr, int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--){

      heapifyw(arr, n, i);

}    

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
	
      swapw(arr,0, i);

      // Heapify root element to get highest element at root again
      heapifyw(arr, i, 0);
    }
  }

void heapsortw(char **arr,int n){
	heapSortw(arr,n);
}
