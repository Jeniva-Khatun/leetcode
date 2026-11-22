int findNumbers(int* nums, int numsSize) {
    
    int result = 0;
    for(int i = 0; i<numsSize ; i++){
        int digits = 0;
        int n = nums[i];
        while (n > 0){
            digits++;
            n = n/ 10;

        }
        if (digits % 2 == 0) result++;
    }
    return result;
}
