
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {

    // Number of windows
    *returnSize = numsSize - k + 1;

    // Array to store answers
    int* ans = malloc((*returnSize) * sizeof(int));

    // Deque stores indices
    int* deq = malloc(numsSize * sizeof(int));

    int front = 0;
    int rear = -1;

    for (int i = 0; i < numsSize; i++) {

        // STEP 1: Remove elements outside the window
        while (front <= rear && deq[front] <= i - k) {
            front++;
        }

        // STEP 2: Remove smaller elements from the back
        while (front <= rear && nums[deq[rear]] <= nums[i]) {
            rear--;
        }

        // STEP 3: Insert current index
        deq[++rear] = i;

        // STEP 4: Store maximum of current window
        if (i >= k - 1) {
            ans[i - k + 1] = nums[deq[front]];
        }
    }

    free(deq);

    return ans;
}

