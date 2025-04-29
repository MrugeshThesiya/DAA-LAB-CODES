#include <stdio.h>

void SelectionSort(int a[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(a[j]<a[i]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(int i=0;i<size;i++){
        printf("%d\t",a[i]);
    }
}
int main(){
    int size;
    printf("Size of Array : ");
    scanf("%d", &size);
    int a[size];    
    for (int i = 0; i < size; i++){
        printf("Enter  %d element of array : ",i+1);
        scanf("%d", &a[i]);
    }
    SelectionSort(a,size);
    return 0;
}