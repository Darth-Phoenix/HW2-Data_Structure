#include <stdio.h>
#include <stdlib.h>
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

void bst_search(int key){
    struct tnode *q=BST;
    while(q->data!=key){
        if (key > q->data){
            q=q->r_child;
        }
        else {
            q=q->l_child;
        }
    }
    return;
}

	
void inorder(struct tnode *t){
    if (t==NULL) return;
    inorder(t->l_child);
    printf("%d\n", t->data);
    inorder(t->r_child);
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
        bst_search(num[i]);
    }
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("query time: %ld us (equal %f sec)\n", timer, timer / 1000000.0);
    return;
}