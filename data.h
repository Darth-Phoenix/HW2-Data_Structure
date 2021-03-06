#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
struct timeval start;
struct timeval end;
unsigned long timer;
void bst_build(int n, int *num);
void bst_query(int n, int *num);
void bs_build(int n, int *num);
void bs_query(int n, int *num);
void arr_build(int n, int *num);
void arr_query(int n, int *num);
void ll_build(int n, int *num);
void ll_query(int n, int *num);
void hash_build(int n, int *num);
void hash_query(int n, int *num);
int *rand_data(int n);
int *rand_index(int n, int m);