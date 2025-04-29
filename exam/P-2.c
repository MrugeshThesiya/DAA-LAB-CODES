#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int getLargestElementIndex(int* p,int start, int size){
  int l = start;
  int largest = -1;
  for(int i = start ; i < size ; i++){
    if(p[i] != -1 && p[i] >= largest){
      l = i;
      largest = p[i];
    }
  }
  return largest == -1 ? -1 : l;
}

int getSmallestElementIndex(int* p, int size){
  int s = 0;
  int smallest = INT_MAX;
  for(int i = 0 ; i < size ; i++){
    if(p[i] != -1 && p[i] <= smallest){
      s = i;
      smallest = p[i];
    }
  }
  return smallest == INT_MAX ? -1 : s;
}

int calcMaxProfit(int* p,int size){
  int s;
  int l;
  int profit = 0;
    while(true){
      s = getSmallestElementIndex(p,size);
      
        if(s == -1){
          break;
        }
        
      l = getLargestElementIndex(p,s+1,size);
        if(l == -1){
          p[s]=-1;
          continue;
        }
      profit = profit + p[l]-p[s];
      p[l] = -1;
      p[s] = -1;
  }
  return profit;
}

int main(){
  //int P[] = {10,15,7,20,5,25,30,12,18,22};
  int P[] = {6,5,4,3,2,1};
  int size = sizeof(P)/sizeof(P[0]);
  
  int maxProfit = calcMaxProfit(P,size);
  
  printf("\nThe Maximum profit is %d .",maxProfit);
  
  return 0;
}
