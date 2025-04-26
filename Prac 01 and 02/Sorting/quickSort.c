#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

void printArray(int* a,int size){
 for (int i = 0 ; i < size ; i++){
   printf("%d  ",a[i]);
 } 
 printf("\n");
}

void swap(int* a , int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int*a,int l,int r){
  int pi = l;
  int i = l+1;
  int j = r;
  while(true){
    while(a[i]<a[pi] && i<=r){
      i++;
    }
    
    while(a[j]>a[pi]){
      j--;
    }
    
    if(i<j){
      swap(&a[i],&a[j]);
    }else{
      swap(&a[pi],&a[j]);
      pi=j;
      break;
    }
  }
  return pi;
}

void quickSort(int*a,int l,int r){
  if(l<r){
    int pi = partition(a,l,r);
    quickSort(a,l,pi-1);
    quickSort(a,pi+1,r);
  }
}

int main(){
int a[] = {10,9,8,7,6,5,4,3,2,1};
int size = sizeof(a)/sizeof(a[0]);
printf("Initially : ");
printArray(a,size);

quickSort(a,0,size-1);

printf("After Sorting : ");
printArray(a,size);

return 0;
}
