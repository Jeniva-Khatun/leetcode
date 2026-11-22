int* sortedSquares(int* nums, int numsSize, int* returnSize) {

    int* result = malloc(numsSize * sizeof(int));
    *returnSize = numsSize ;
    
    int left = 0, right = numsSize - 1, pos = numsSize -1;
    
    while(left <= right){
        int l = nums[left] * nums[left];
        int r = nums[right] * nums[right];

        if(r > l){
            result[pos] = r;
            pos--;
            right--;
        }
        else {
            result[pos] = l;
            pos--;
            left++;
        }
    }

     return result;
    
    
}
