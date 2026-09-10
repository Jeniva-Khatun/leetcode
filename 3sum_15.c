int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int** threeSum(int* nums, int numsSize,
               int* returnSize, int** returnColumnSizes)
{
    
    qsort(nums, numsSize, sizeof(int), compare);

    
    int **result = malloc(numsSize * numsSize * sizeof(int *));
    *returnColumnSizes = malloc(numsSize * numsSize * sizeof(int));

    *returnSize = 0;

  
    for (int i = 0; i < numsSize - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int low = i + 1;
        int high= numsSize - 1;

        while (low < high)
        {
            int sum = nums[i] + nums[low] + nums[high];

            if (sum == 0)
            {
                result[*returnSize] = malloc(3 * sizeof(int));

                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[low];
                result[*returnSize][2] = nums[high];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while (low < high &&
                       nums[low ] == nums[low + 1])
                {
                    low ++;
                }
                while (low < high &&
                       nums[high] == nums[high- 1])
                {
                    high--;
                }

               low ++;
              high--;
            }
            else if (sum < 0)
            {
                low ++;
            }
            else
            {
                high--;
            }
        }
    }

    return result;
}
