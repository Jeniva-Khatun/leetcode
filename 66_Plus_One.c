/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {

int i = digitsSize -1;
while (i>=0){
    if(digits[i]<9){
        digits[i]++;
        *returnSize=digitsSize;
        return digits;
    }
    digits[i]=0;
    i--;
}  
int *result= malloc((digitsSize+1)*sizeof(int));
result[0]=1;
int j=1;
while(j<=digitsSize){
    result[j]=0;
    j++;
}

*returnSize=digitsSize+1;
return result;
    
}
