
    int key;
    for(int i=1; i<6;i++){
    key=array[i];
    int j=i-1;
    while(j>=0 && array[j]>key){ //suppose array of size 6 unsorted exists

        array[j+1]=array[j];
        j--;
    }
    array[j+1]=key;
    }