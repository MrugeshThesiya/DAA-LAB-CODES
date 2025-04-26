#include <stdio.h>
#include <stdbool.h>

void printArray(int* a,int size){
 for (int i = 0 ; i < size ; i++){
   printf("%d  ",a[i]);
 } 
}

void takeInputInArray(int* a,int size){
   for (int i = 0 ; i < size ; i++){
  printf("Enter element %d : ", i+1);
  scanf("%d",&a[i]);
 }
}

void binarySearch(int* a,int size,int searchElement){
printf("Searching %d... \n",searchElement);
  int start = 0;
  int end = size - 1;
  int m ;
  bool flag = true;
  while(start <= end){
   m = (end - start )/2 + start ;
   if(searchElement == a[m]){
     printf("%d is at index %d.",searchElement,m);
     flag = false;
     break;
   }else if(searchElement > a[m]){
     start = m + 1 ;
   }else if(searchElement < a[m]){
     end = m - 1;
   }
  }
  
  if(flag){
   printf("%d was not found in the array.",searchElement);
  }
}

int main(){
 int a[100];
 int size;
 int searchElement;
 printf("Enter the size of the array (should be less than 100) : ");
 scanf("%d", &size);
 printf("Enter the elements of the array of size %d. \n",size);

 takeInputInArray(a,size);
 
 printf("Which element do you want to find ? ");
 scanf("%d",&searchElement);
 
 binarySearch(a,size,searchElement);

 return 0;
}
