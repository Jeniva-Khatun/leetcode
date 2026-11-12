int comparison(const void* a, const void* b) {
    int y = *(const int*)a;
    int z = *(const int*)b;

    return (y> z) - (y < z);
}

bool containsDuplicate(int* nums, int numsSize) {

    qsort(nums, numsSize, sizeof(int), comparison);

    for (int i = 0; i < numsSize - 1; i++) {

        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }

    return false;
}
