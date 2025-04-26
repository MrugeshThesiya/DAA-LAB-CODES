#include <stdio.h>

int main(){
 int a[] = {1,2,3,4,5};
 int length = sizeof(a)/sizeof(a[0]);
 int i;
 int tofind = 6;
 for(i=0;i<length;i++){
  if(tofind == a[i]){
  printf("%d is at index %d.",tofind,i);
  break;
  }
 }
 if(i == length){
   printf("%d was not found.",tofind);
 }
 return 0;
}


