void reverseString(char* s, int sSize) {
 int low=0;
 int high = sSize-1;

while (low<high){
    char temp = s[low];
    s[low] = s[high] ;
    s[high] = temp ;
    low++;
    high--;
}

}
