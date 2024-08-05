#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    //slow pointer for indicating the place to change element, and count for indicating how many elements are there.
    int slow=0,count=1;
    for(int fast=1;fast<numsSize;fast++){
        if(nums[slow]==nums[fast]){
            continue;
        } else {
            nums[++slow]=nums[fast];
            count++;
        }
    }
    return count;
}

int main(){
    
    int nums[10]={0,0,1,1,1,2,2,3,3,4};
    int numsSize=10;
    int result=removeDuplicates(nums,numsSize);
    printf("The result is:%d",result);
}

