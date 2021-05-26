#include <string.h>
#include "data.h"

int main(int argc, char **argv){
    int i=1, d, q;
    int *list, *target;
    char *ptr;
    while(i<argc){
        if (strcmp(argv[i], "-d")==0){
            i++;
            d=(int)strtod(argv[i], &ptr);
            list=rand_data(d);
        }
        else if (strcmp(argv[i], "-q")==0){
            i++;
            q=(int)strtod(argv[i], &ptr);
            target=rand_index(d, q);
            for (int i=0; i<q; i++){
                target[i]=list[target[i]];
            }
        }
        else if (strcmp(argv[i], "-bst")==0){
            printf("bst:\n");
            bst_build(d, list);
            bst_query(q, target);
            printf("\n");
        }
        else if (strcmp(argv[i], "-bs")==0){
            printf("bs:\n");
            bs_build(d, list);
            bs_query(q, target);
            printf("\n");
        }
        else if (strcmp(argv[i], "-arr")==0){
            printf("arr:\n");
            arr_build(d, list);
            arr_query(q, target);
            printf("\n");
        }
        else if (strcmp(argv[i], "-ll")==0){
            printf("ll:\n");
            ll_build(d, list);
            ll_query(q, target);
            printf("\n");
        }
        else if (strcmp(argv[i], "-hash")==0){
            printf("hash:\n");
            hash_build(d, list);
            hash_query(q, target);
            printf("\n");
        }
        i++;
    }
}