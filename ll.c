#include "data.h"

struct lnode{
    int data;
    struct lnode *next;
}*LL=NULL, *prev=NULL;

void ll_insert(int key){
    struct lnode *p;
    p=(struct lnode*)malloc(sizeof(struct lnode));
    p->data=key;
    p->next=NULL;
    if (LL==NULL){   
        LL=p;    
        prev=p;
        return;
    }
    prev->next=p;
    prev=p;
    return;
}

void ll_search(int key){
    struct lnode *q=LL;
    while(q->data!=key){
        q=q->next;
    }
    return;
}

void ll_build(int n, int *num){
    gettimeofday(&start, NULL);
    for (int i=0; i<n; i++){
        ll_insert(num[i]);
    }
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("building time: %ld us (equal %f sec)\n", timer, timer / 1000000.0);
    return;
}

void ll_query(int n, int *num){
    gettimeofday(&start, NULL);
    for (int i=0; i<n; i++){
        ll_search(num[i]);
    }
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("query time: %ld us (equal %f sec)\n", timer, timer / 1000000.0);
    return;
}