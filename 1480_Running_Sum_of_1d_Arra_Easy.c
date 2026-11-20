int* runningSum(int* nums, int numsSize, int* returnSize) {
int* runSum = (int*)malloc(numsSize * sizeof(int));
*returnSize = numsSize;


runSum[0] = nums[0];

for(int i = 1; i< numsSize; i++){

 runSum[i] = runSum[i-1] + nums[i];  
  }

  return runSum;
}
