#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data.h"
#define MAX_NUM 100000000

int a[MAX_NUM];

int *rand_data(int n){
    for (int i=0; i<MAX_NUM; i++){
        a[i]=i;
    }
    srand(time(NULL));
    int *list, temp, num;
    list=(int*)malloc(sizeof(int)*n);
    for (int i=0; i<n; i++){
        num=rand()%MAX_NUM;
        temp=a[num];
        a[num]=a[i];
        a[i]=temp;
    }
    for (int i=0; i<n; i++){      
        list[i]=a[i];
    }
    return list;
}

int *rand_index(int n, int m){
    for (int i=0; i<n; i++){
        a[i]=i;
    }
    srand(time(NULL));
    int num, *list, temp;
    list=(int*)malloc(sizeof(int)*m);
    for (int i=0; i<m; i++){
        num=rand()%n;
        temp=a[num];
        a[num]=a[i];
        a[i]=temp;
    }
    for (int i=0; i<m; i++){
        list[i]=a[i];
    }
    return list;
}