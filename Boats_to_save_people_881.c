int numRescueBoats(int* people, int peopleSize, int limit) {
   
    int boats = 0;
    int low = 0;
    int high = peopleSize - 1;

    for (int i=0;i<peopleSize-1;i++){
        for(int j=i+1;j<peopleSize;j++){
            if(people[i]>people[j]){
                int temp = people[i];
                people[i]= people[j];
                people[j]= temp;
            }
        }
    }
    
    while(low<=high){
       if (people[low] + people[high] <= limit ) {
        low++;
       }
       high--;
       
       boats++;

    }
return boats;
}
