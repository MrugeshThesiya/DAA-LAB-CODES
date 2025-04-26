#include <stdio.h>

void printArray(int* a,int size){
 for (int i = 0 ; i < size ; i++){
   printf("%d  ",a[i]);
 } 
 printf("\n");
}

void mergeSort(int* a,int l,int r){
if(l<r){
  int m = (l+r)/2;
  
  mergeSort(a,l,m);
  mergeSort(a,m+1,r);
  
  merge(a,l,m,r);
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
