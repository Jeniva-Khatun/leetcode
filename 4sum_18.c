/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int maxresult = numsSize * numsSize ;
    int** result = malloc(maxresult * sizeof(int*));
    *returnColumnSizes = malloc(maxresult * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i<numsSize - 1; i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]>nums[j]){
                int temp = nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
        }
    }
    for (int i = 0; i < numsSize - 3; i++) {
         if (i > 0 && nums[i] == nums[i - 1])
            continue;

          for (int j = i + 1; j < numsSize - 2; j++) {
             if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = numsSize - 1;


            while (left < right) {

                long long sum = (long long)nums[i]
                              + nums[j]
                              + nums[left]
                              + nums[right];
                
                if (sum == target) {

                    result[*returnSize] = malloc(4 * sizeof(int));

                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[left];
                    result[*returnSize][3] = nums[right];              

                   (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    left++;
                    right--;

                     while (left < right &&
                           nums[left] == nums[left - 1])
                        left++;

                    while (left < right &&
                           nums[right] == nums[right + 1])
                        right--;

                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
    }

    return result;
}
