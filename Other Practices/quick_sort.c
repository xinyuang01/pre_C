#include <stdio.h>

void swap(int* a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[], int low, int high){
    int pivot=arr[low];
    printf("The pivot=%d\n",pivot);
    int i=low;
    int j=high;
    //i: Start searching from the left, and tries to find the one larger than pivot
    //j: Start searching from the right, and tries to find the one smaller than pivot
    while(i<j){
        while(arr[i]<=pivot && i<high){
            i++;
        }

        while(arr[j]>=pivot && j>low){
            j--;
        }
        
        //Found the i and j so swap them
        if(i<j){
            swap(&arr[i],&arr[j]);
            printf("Inside i<j swapped index i=%d and j=%d\n",i,j);
        }
    }
    swap(&arr[low],&arr[j]);
    printf("Outside I swapped low=%d and j=%d\n",low,j);
    return j;
    
}

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) { 
        // call Partition function to find Partition Index 
        int partitionIndex = partition(arr, low, high); 
  
        // Recursively call quickSort() for left and right 
        // half based on partition Index 
        quickSort(arr, low, partitionIndex - 1); 
        quickSort(arr, partitionIndex + 1, high); 
    } 
} 

int main(){
    
    int arr[] = { 19, 17, 15, 12, 16, 18, 4, 11, 13 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // printing the original array 
    printf("Original array: "); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    }
    printf("\n"); 
  
    // calling quickSort() to sort the given array 
    quickSort(arr, 0, n - 1); 
  
    // printing the sorted array 
    printf("\nSorted array: "); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    }
    return 0;
}