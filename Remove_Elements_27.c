int removeElement(int* nums, int numsSize, int val) {
  int read =0;
  int write = 0;
  while(read<numsSize){
    if(nums[read] != val){
        nums[write] = nums[read];
        write++;
    
    }
    read++;

  }
  return write;

}
