#include <stdio.h>

void printArray(int* a,int size){
 for (int i = 0 ; i < size ; i++){
   printf("%d  ",a[i]);
 } 
 printf("\n");
}

void selectionSort(int* a,int size){
for(int i = 0 ; i < 4 ; i++){
  int minIndex = i;
  for(int j = i + 1 ; j < 5 ; j++){
    if(a[i] > a[j]){
      minIndex = j;
    }
  }
  if(minIndex != i){
    int temp = a[i];
    a[i] = a[minIndex];
    a[minIndex] = temp;
  }
  
}
}

int main(){
int a[5] = {23,15,46,25,16};

printf("Initially : ");
printArray(a,5);

selectionSort(a,5);

printf("After Sorting : ");
printArray(a,5);

return 0;
}
