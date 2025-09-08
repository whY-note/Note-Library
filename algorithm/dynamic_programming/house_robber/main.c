#include<stdio.h>
#define ANSWER1 1
/*----------Answer--------*/
#if ANSWER1
int max(int a, int b) {
    return a>b? a: b;
}

int rob(int *nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }
    if (numsSize == 1) {
        return max(nums[0],nums[1]);
    }

    // numsSize >= 1
    nums[2] = nums[0] + nums[2];
    for(int i=3; i < numsSize; i++) {
        nums[i] = max(nums[i-2], nums[i-3]) + nums[i];
    }
    int max_money = max(nums[numsSize-2], nums[numsSize-1]);
    return max_money;
}

#endif
/*-------Answer End------*/

int test() {
    int test_array[5] = {2,7,9,3,1};
    if(rob(test_array,5) == 12) {
        printf("correct\n");
        return 1;
    }
    printf("error\n");
    return 0;
}

int main() {
    
    test();
    return 0;
}
