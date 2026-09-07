int maxArea(int* height, int heightSize) {
    int low = 0;
    int high = heightSize - 1;
    int max = 0;

    while (low < high) {
        int h;

        if (height[low] < height[high])
            h = height[low];
        else
            h = height[high];

        int width = high - low;
        int area = h * width;

        if (area > max)
            max = area;

        // Move the pointer with smaller height
        if (height[low] < height[high])
            low++;
        else
            high--;
    }

    return max;
}
