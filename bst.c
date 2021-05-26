#include "data.h"

struct tnode{
    int data;
    struct tnode *l_child;
    struct tnode *r_child;
}*BST=NULL;

void bst_insert(int key){
    struct tnode *p, *q=BST, *parent;
    p=(struct tnode*)malloc(sizeof(struct tnode));
    p->data=key;
    p->l_child=NULL;
    p->r_child=NULL;
    if (BST==NULL){
        BST=p;
        return;
    }
    while (q!=NULL){
        parent=q;
        if (key > q->data){
            q=q->r_child;
        }
        else{
            q=q->l_child;
        }
    }   
    if (key > parent->data){
        parent->r_child=p;
        return;
    }
    parent->l_child=p;
    return;
}

void bst_search(int key){
    struct tnode *q=BST;
    while (q->data!=key){
        if (key > q->data){
            q=q->r_child;
        }
        else {
            q=q->l_child;
        }
    }
    return;
}

void bst_build(int n, int *num){
    gettimeofday(&start, NULL);
    for (int i=0; i<n; i++){
        bst_insert(num[i]);
    }
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("building time: %ld us (equal %f sec)\n", timer, timer / 1000000.0);
    return;
}

void bst_query(int n, int *num){
    gettimeofday(&start, NULL);
    for (int i=0; i<n; i++){
        bst_search(num[i]);
    }
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("query time: %ld us (equal %f sec)\n", timer, timer / 1000000.0);
    return;
}