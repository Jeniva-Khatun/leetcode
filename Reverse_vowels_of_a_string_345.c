 int isVowel(char c){
     return c == 'a' || c== 'e' || c == 'i' ||c == 'o' ||c == 'u' ||
                c == 'A' || c== 'E' || c == 'I' ||c == 'O' ||c == 'U' ;
    }
char* reverseVowels(char* s) {
    
    int low = 0 ;
    int high = strlen(s) - 1 ;
    
       


    while (low<high){
        while (low < high && !isVowel(s[low])){
            low++;
        }
         while (low < high && !isVowel(s[high])){
            high--;
        }
        if (low < high ){
            int temp = s[low];
            s[low] = s[high];
            s[high]= temp;
            low++;
            high--;
        }

    }
    return s;
}

