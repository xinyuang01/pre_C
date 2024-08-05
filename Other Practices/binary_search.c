#include <stdio.h>

int binarySearch(int array[],int target,int low_index,int high_index){
    if(low_index<=high_index){
        int mid_index=(low_index+high_index)/2;
        if(array[mid_index]==target){
            return mid_index;
        }
        else if(array[mid_index]>target){
            return binarySearch(array,target,low_index,mid_index-1);
        }
        else{
            return binarySearch(array,target,mid_index+1,high_index);
        }
    }
    return -1;
}

int main(){
    int array[] = {3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(array) / sizeof(array[0]);
    int x = 10;
    int result = binarySearch(array, x, 0, n - 1);
    if (result == -1)
        printf("Not found");
    else
        printf("Element is found at index %d", result);
}