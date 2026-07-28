int search(int* nums, int numsSize, int target) {
  int high=numsSize-1,low=0,mid;
  while (low<=high){
    mid=low+(high-low)/2;
  if (nums[mid]==target){
    return mid ;
  } 
  else if (nums[mid]<target){
    low=mid+1;
  }
  else {
    high=mid-1;
  }
  }
  return -1;
}
