#include<stdio.h>
#define size 10

void IMM(int x[][size],int y[][size],int z[][size],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            z[i][j]=0;
            for(int k=0;k<n;k++){
                z[i][j]=z[i][j]+(x[i][k]*y[k][j]);
            }
        }
    }
} 
int main(){
    int n;
    printf("Enter size of matrix (n x n): ");
    scanf("%d", &n);

    int x[size][size],y[size][size],z[size][size];

    printf("Enter elements of matrix X:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d,%d element of x",i+1,j+1);
            scanf("%d", &x[i][j]);
        }
    }

    printf("Enter elements of matrix Y:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d,%d element of y",i+1,j+1);
            scanf("%d", &y[i][j]);
        }
    }

    IMM(x, y, z, n);

    printf("Resultant matrix Z:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", z[i][j]);
        }
        printf("\n");
    }
    return 0;
}