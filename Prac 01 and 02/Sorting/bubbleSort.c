#include <stdio.h>
#include <stdbool.h>

void printArray(int* a,int size){
 for (int i = 0 ; i < size ; i++){
   printf("%d  ",a[i]);
 } 
 printf("\n");
}

void bubbleSort(int* a,int size){
for(int i = size-1 ; i > 0 ; i--){
  bool swapped = false;
  for(int j = 0 ; j < i ; j++){
    if(a[j] > a[j+1]){
      int temp = a[j];
      a[j] = a[j+1];
      a[j+1] = temp;
      swapped = true;
    }
  }
  if(!swapped){
    break;
  }
}
}

int main(){
int a[5] = {23,15,46,25,16};

printf("Initially : ");
printArray(a,5);

bubbleSort(a,5);

printf("After Sorting : ");
printArray(a,5);

return 0;
}
