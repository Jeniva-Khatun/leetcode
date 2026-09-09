int trap(int* height, int heightSize) {
    int  low = 0;
    int  high = heightSize-1;

    int lowMax = 0;
    int highMax = 0;
    int water = 0 ;

    while (low<high){
        if (height[low]<height[high]){
            if (height[low]>lowMax){
                lowMax = height[low];
            } else {
                water += lowMax - height[low];
            }
            low++;
        }
         else {
            if (height[high]>highMax){
                  highMax = height[high];
            } else {
                 water += highMax - height[high];
            }
            high--;
         }

    }

return water ;

}
