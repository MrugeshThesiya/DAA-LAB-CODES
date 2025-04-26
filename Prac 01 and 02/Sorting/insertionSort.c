#include <stdio.h>

void printArray(int* a,int size){
 for (int i = 0 ; i < size ; i++){
   printf("%d  ",a[i]);
 } 
 printf("\n");
}

void insertionSort(int* a,int size){
 for (int i = 1 ; i < size ; i++){
    for (int j = i ; j >=1 ; j-- ){
      if(a[j]<a[j-1]){
        int temp = a[j-1];
        a[j-1] = a[j];
        a[j] = temp;
      }else{
        break;
      }
    }
 }
}

void insertionSortShifting(int* a,int size){
 for (int i = 1 ; i < size ; i++){
    int key = a[i];
    int j = i - 1;
    
    while(j>=0 && a[j]>key){
      a[j+1] = a[j];
      j--;
    }
    
    a[j+1] = key;
}

}

int main(){
int a[5] = {23,15,46,25,16};
printf("Initially : ");
printArray(a,5);

insertionSortShifting(a,5);

printf("After Sorting : ");
printArray(a,5);

return 0;
}
