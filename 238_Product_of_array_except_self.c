int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* answer = (int*)malloc(numsSize * sizeof(int));
    int* prefix = (int*)malloc(numsSize * sizeof(int));
    int* suffix = (int*)malloc(numsSize * sizeof(int));

    // calculation prefix:
    prefix[0] = 1;
    for (int i = 1; i< numsSize ; i++){
        prefix[i] =  prefix[i-1] * nums[i-1];
    }

    // calculating suffix
    suffix[numsSize - 1] = 1;
    for(int i= numsSize - 2; i >= 0; i--){
         suffix[i] = suffix[i+1] * nums[i+1];
    }
     
    for (int i =0; i< numsSize; i++){

    answer[i] = prefix[i] * suffix[i];
    }

    free(prefix);
    free(suffix);
    return answer;
}
