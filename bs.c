#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "data.h"

int bs_arr[1000000], size;

int cmp(const void *p, const void *q){
    return *(int*)p > *(int*)q;
}

void bs_insert(int key, int idx){
    bs_arr[idx]=key;
    return;
}
 
void bs_search(int key){
    int upper=size;
    int lower=0;
    int mid;
    while(upper-lower!=1){
        mid=(upper+lower)/2;
        if (key > bs_arr[mid]){
            lower=mid;
        }
        else if (key < bs_arr[mid]){
            upper=mid;
        }
        else return;
    }
    return;
}

void bs_build(int n, int *num){
    size=n;
    struct timeval start;
    struct timeval end;
    unsigned long timer;
    gettimeofday(&start, NULL);
    for (int i=0; i<n; i++){
        bs_insert(num[i], i);
    }
    qsort(bs_arr, n, sizeof(int), cmp);
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("building time: %ld us (equal %f sec)\n", timer, timer / 1000000.0);
    return;
}

void bs_query(int n, int *num){
    struct timeval start;
    struct timeval end;
    unsigned long timer;
    gettimeofday(&start, NULL);
    for (int i=0; i<n; i++){
        bs_search(num[i]);
    }
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("query time: %ld us (equal %f sec)\n", timer, timer / 1000000.0);
    return;
}