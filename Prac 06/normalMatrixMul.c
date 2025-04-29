#include <stdio.h>

void printMatrix(int M[][3]){
  for(int i = 0 ; i < 3 ; i++){
    for(int j = 0 ; j < 3 ; j++){
      printf("%d ",M[i][j]);
    }
    printf("\n");
  }
}

void matrixMultiplication(int ans [3][3] , int M[3][3]){
  for(int i = 0 ; i < 3 ; i++){
    for(int j = 0 ; j < 3 ; j++){
      ans[i][j] = 0;
      for(int k = 0 ; k < 3 ; k++){
        ans[i][j] = ans[i][j] + M[i][k]*M[k][j];
      }
    }
  }
}

int main(){
  int matrix1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  
  int ans[3][3];
  
  matrixMultiplication(ans,matrix1);
  
  printMatrix(ans);
  
  return 0;
}
