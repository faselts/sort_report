#include"sort.h"
#include<stdio.h>
#define OFFSET 1
void swap(int *a, int *b) {
  	int t = *a;
 	*a = *b;
  	*b = t;
}

int partition(int array[], int low, int high){
    	int pivot = array[high];
    	int i = (low - 1);
    	for (int j = low; j < high; j++){
            	if(array[j] <= pivot){		
	                i++;
	                swap(&array[i], &array[j]);
	        }
        }
    	swap(&array[i + 1], &array[high]);
    	return (i + 1);
}
void quicksort(int array[], int low, int high){
    	if (low < high){
            	int pi = partition(array, low, high);
            	quicksort(array, low, pi - 1);
           	quicksort(array, pi + 1, high);
        }
}


void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];
    for(int i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
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
        if (L[i] <= M[j])
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
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}



  void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
      largest = left;

    if (right < n && arr[right] > arr[largest])
      largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }

  // Main function to do heap sort
  void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);

      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }

void heapsort(int arr[],int n){
	heapSort(arr,n);
}

