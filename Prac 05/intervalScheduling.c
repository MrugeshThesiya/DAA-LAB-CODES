#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Event {
  char name;
  int start;
  int end;
} Event;

void merge(Event* events,int l,int m,int r){
  int n1 = m-l+1;
  int n2 = r-m;
  
  Event L[n1+1];
  Event R[n2+1];
  
  for(int i = 0 ; i < n1 ; i++){
    L[i] = events[l+i];
  }
  
  L[n1].end = INT_MAX;
  
  for(int i = 0 ; i < n2 ; i++){
    R[i] = events[m+1+i];
  }
  
  R[n2].end = INT_MAX;
  
  int i=0,j=0,k=l;
  
  while(k<=r){
    if(L[i].end<R[j].end){
      events[k++] = L[i++];
    }else{
      events[k++] = R[j++];
    }
  }
  
}

void mergeSort(Event* events,int l,int r){
  if(l<r){
    int m = (l+r)/2;
    
    mergeSort(events,l,m);
    mergeSort(events,m+1,r);
    
    merge(events,l,m,r);
  }
}

bool isCompatible(int jobStart , int lastEnd){
  return jobStart >= lastEnd;
}

void schedule(Event* events,int size){
  mergeSort(events,0,size-1);
  
  int lastEnd = 0;
  
  for (int i = 0 ; i < size ; i++){
    if(isCompatible(events[i].start,lastEnd)){
      printf("%c ",events[i].name);
      lastEnd = events[i].end;
    }
  }
}

int main(){
  Event events[] = {
    {'A',1,3},
    {'B',2,5},
    {'C',3,9},
    {'D',6,8}
  };
  
  int size = sizeof(events)/sizeof(Event);
  
  schedule(events,size);
  
  return 0;
}
