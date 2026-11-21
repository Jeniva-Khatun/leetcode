int* shuffle(int* nums, int numsSize, int n, int* returnSize){

    int *ans = (int*)malloc(numsSize *sizeof(int));
    *returnSize = numsSize;

    for(int i = 0; i< n; i++){

        ans[2*i] = nums[i]; //for x value
        ans[2*i + 1] = nums[i + n]; //for y value

    }

    return ans;

}
