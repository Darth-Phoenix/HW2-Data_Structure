#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "data.h"

int arr[1000000];

void arr_insert(int key, int idx){
    arr[idx]=key;
    return;
}

void arr_search(int key){
    int idx=0;
    while(arr[idx]!=key){
        idx++;
    }
    return;
}

void arr_build(int n, int *num){
    struct timeval start;
    struct timeval end;
    unsigned long timer;
    gettimeofday(&start, NULL);
    for (int i=0; i<n; i++){
        arr_insert(num[i], i);
    }
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("building time: %ld us (equal %f sec)\n", timer, timer / 1000000.0);
    return;
}

void arr_query(int n, int *num){
    struct timeval start;
    struct timeval end;
    unsigned long timer;
    gettimeofday(&start, NULL);
    for (int i=0; i<n; i++){
        arr_search(num[i]);
    }
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("query time: %ld us (equal %f sec)\n", timer, timer / 1000000.0);
    return;
}