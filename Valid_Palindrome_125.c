bool isPalindrome(char* s) {
   int low = 0;
   int high = strlen(s)-1;

   while (low < high){
    while(low<high && !isalnum(s[low])){
        low++;
 }
    while (low<high && !isalnum(s[high]) ){
         high--; 
}
     if  ( tolower(s[low]) != tolower(s[high])){
    return false ;
 }
   low++;
    high--;
 }
   return true;

}

