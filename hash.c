#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "data.h"
#define TABLE_SIZE 100000

struct hnode{
    int data;
    struct hnode *next;
}*hash[TABLE_SIZE], *last[TABLE_SIZE];

void hash_insert(int key, int idx){
    struct hnode *p=(struct hnode*)malloc(sizeof(struct hnode));
    p->data=key;
    p->next=NULL;
    if (hash[idx]==NULL){
        hash[idx]=p;
        last[idx]=p;
    }
    last[idx]->next=p;
    last[idx]=p;
    return;
}

void hash_search(int key, int idx){
    struct hnode *q=hash[idx];
    while(q->data!=key){
        q=q->next;
    }
    return;
}

void hash_build(int n, int *num){
    int idx;
    struct timeval start;
    struct timeval end;
    unsigned long timer;
    for (int i=0; i<TABLE_SIZE; i++){
        hash[i]=NULL;
    }
    gettimeofday(&start, NULL);
    for (int i=0; i<n; i++){
        idx=num[i]%TABLE_SIZE;
        hash_insert(num[i], idx);
    }
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("building time: %ld us (equal %f sec)\n", timer, timer / 1000000.0);
    return;
}

void hash_query(int n, int *num){
    int idx;
    struct timeval start;
    struct timeval end;
    unsigned long timer;
    gettimeofday(&start, NULL);
    for (int i=0; i<n; i++){
        idx=num[i]%TABLE_SIZE;
        hash_search(num[i], idx);
    }
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("query time: %ld us (equal %f sec)\n", timer, timer / 1000000.0);
    return;
}