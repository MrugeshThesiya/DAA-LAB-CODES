#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    char name[50];
    float profit;
    float weight;
} item;

void main(){
    item items[] = {{"Item-1", 10, 2}, {"Item-2", 5, 3}, {"Item-3", 15, 5}, {"Item-4", 7, 7}, {"Item-5", 6, 1}, {"Item-6", 18, 4}, {"Item-7", 3, 1}};
    int l = sizeof(items)/sizeof(items[0]);
    int i;
    int knapsack_weight = 10;

    int compare(const void *a, const void *b) {
        const item *item1 = (const item *)a;
        const item *item2 = (const item *)b;

        float ratio1 = item1->profit/item1->weight;
        float ratio2 = item2->profit/item2->weight;

        if(ratio1 - ratio2 > 0) return -1;
        if(ratio1 - ratio2 < 0) return 1;
        return 0;
    }

    qsort(items,l,sizeof(item),compare);

    int currentWeight = 0;
    int maxProfit = 0;

    for(i=0;i<l;i++){
        if(currentWeight + items[i].weight <= knapsack_weight){
            currentWeight += items[i].weight;
            maxProfit+= items[i].profit;
        }
        else{
            float fraction = (knapsack_weight - currentWeight)/items[i].weight;
            maxProfit += fraction*items[i].profit;
            break;
        }
    }

    // for(i = 0 ; i < l ; i++){
    //     printf("Name : %s , Profit : %.2f , Weight : %.2f \n",items[i].name,items[i].profit,items[i].weight);
    // }

    printf("Maximum possible profit is %d given a knapsack weight of %d .",maxProfit,knapsack_weight);
}