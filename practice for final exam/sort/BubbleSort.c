#include<stdio.h>

int main(){
    int size;
    printf("Size of Array : ");
    scanf("%d", &size);
    int a[size];    
    for (int i = 0; i < size; i++){
        printf("Enter  %d element of array : ",i+1);
        scanf("%d", &a[i]);
    }
    for(int i=0;i<size;i++){
        for (int j=0;j<size-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=0;i<size;i++){
        printf("%d\t",a[i]);
    }
}