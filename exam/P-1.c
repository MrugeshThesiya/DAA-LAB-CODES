#include <stdio.h>

typedef struct asset {
  int i;
  int c_i;
  int q_i;
  float r_i;
} a;

void merge(a* assets,int l,int m,int r){
  int n1 = m-l+1;
  int n2 = r-m;
  
  a L[n1];
  a R[n2];
  
  for(int i = 0 ; i < n1 ; i++){
    L[i] = assets[l+i];
  }
  
  L[n1].r_i = 0;
  L[n1].c_i = 1;
  
  for(int j = 0 ; j < n2 ; j++){
    R[j] = assets[m+1+j];
  }
  
  R[n2].r_i  = 0;
  R[n2].c_i = 1;
  
  int i = 0 , j = 0,k = l;
  while(k<=r){
    float lProfit = L[i].r_i/L[i].c_i;
    float rProfit = R[j].r_i/R[j].c_i;
    if(lProfit > rProfit){
    
      assets[k++]=L[i++];
      
    } else{
    
      assets[k++]=R[j++];
      
    }
  }
}

void mergeSort(a* assets,int l,int r){
  if(l<r){
    int m = (l+r)/2;
  
    mergeSort(assets,l,m);
    mergeSort(assets,m+1,r);
  
    merge(assets,l,m,r);
  }
}

int getAvailableIndex(a* a,int size){
  int index = 0;
  while(a[index].q_i==0 && index < size){
    index = index + 1 ;
  }
  return index >= size ? -1 : index;
}

float calcMaxReturns(a* assets,int size,int b , int t){
  mergeSort(assets,0,size-1);
  float maxreturns = 0;
  for(int i = 0 ; i < t ; i++){
    int index = getAvailableIndex(assets,size);
    if(index == -1){
      break;
    }
    if(b - assets[index].c_i < 0 ){
      continue;
    }
    b = b - assets[index].c_i;
    assets[index].q_i =  assets[index].q_i - 1;
    maxreturns = maxreturns + assets[index].c_i*assets[index].r_i*(t-i);
  }
  return maxreturns;
}

int main(){
  a assets[] = {
    {1,20,5,1.5},
    {2,50,2,1.8},
    {3,10,4,2.1},
    {4,30,3,1.1},
    {5,20,2,0.5}
  };
  int size = sizeof(assets)/sizeof(assets[0]);
  int b = 300;
  int t = 12;
  
  float maxReturns = calcMaxReturns(assets,size,b,t);
  
  printf("The Max Returns after %d months is %.2f ",t,maxReturns);
  return 0;
}
