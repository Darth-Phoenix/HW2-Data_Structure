#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "data.h"

struct tnode{
    int data;
    struct tnode *l_child;
    struct tnode *r_child;
}*BST=NULL;

struct tnode *bst_insert(struct tnode *t, int key){
    if (t==NULL){
        struct tnode *p=(struct tnode*)malloc(sizeof(struct tnode));
        p->data=key;
        p->l_child=NULL;
        p->r_child=NULL;
        return p;
    }
    if (key > t->data){
        t->r_child=bst_insert(t->r_child, key);
    }
    else{
        t->l_child=bst_insert(t->l_child, key);
    }
    return t;
}

void bst_search(struct tnode *t, int key){
    if (t->data==key){
        return;
    }
    if (key > t->data){
        bst_search(t->r_child, key);
    }
    else {
        bst_search(t->l_child, key);
    }
}

void bst_build(int n, int *num){
    struct timeval start;
    struct timeval end;
    unsigned long timer;
    gettimeofday(&start, NULL);
    for (int i=0; i<n; i++){
        BST=bst_insert(BST, num[i]);
    }
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("building time: %ld us (equal %f sec)\n", timer, timer / 1000000.0);
    return;
}

void bst_query(int n, int *num){
    struct timeval start;
    struct timeval end;
    unsigned long timer;
    gettimeofday(&start, NULL);
    for (int i=0; i<n; i++){
        bst_search(BST, num[i]);
    }
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("query time: %ld us (equal %f sec)\n", timer, timer / 1000000.0);
    return;
}