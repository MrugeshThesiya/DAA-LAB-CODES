#include <stdio.h>
#include <limits.h>

void printArray(int* a,int size){
 for (int i = 0 ; i < size ; i++){
   printf("%d  ",a[i]);
 } 
 printf("\n");
}

void merge(int* a,int l,int m,int r){
  int n1 = m-l+1;
  int n2 = r-m;
  
  int L[n1+1];
  int R[n2+1];
  
  for(int i = 0 ; i < n1 ; i++){
    L[i] = a[l+i];
  }
  
  L[n1] = INT_MAX;
  
  for(int j = 0 ; j < n2 ; j++){
    R[j] = a[m+j+1];
  }
  
  R[n2] = INT_MAX;
  
  int i = 0 , j = 0,k = l;
  while(k<=r){
  
    if(L[i]<R[j]){
    
      a[k++]=L[i++];
      
    } else{
    
      a[k++]=R[j++];
      
    }
  }
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
int a[] = {10,9,8,7,6,5,4,3,2,1};
int size = sizeof(a)/sizeof(a[0]);
printf("Initially : ");
printArray(a,size);

mergeSort(a,0,size-1);

printf("After Sorting : ");
printArray(a,size);

return 0;
}
