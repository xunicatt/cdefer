/**
** Author: xunicatt
** Github: https://github.com/xunicatt
*/

#include "defer.h"

static defer_data_t *__global_defer_data = NULL;

typedef struct defer_data_t {
    void *__ptr;
    free_function_t *__free;
    struct defer_data_t *__next;
} defer_data_t;

void
deferg(
    void *ptr,
    free_function_t *__free
) {
   __global_defer_data = deferl(
        __global_defer_data,
        ptr, 
        __free
    );
}

defer_data_t*
deferl(
    defer_data_t *d,
    void *ptr,
    free_function_t *__free
) {
    defer_data_t *x = (defer_data_t*)malloc(sizeof(defer_data_t));
    x->__ptr = ptr;
    x->__free = __free == NULL ? free : __free;
    x->__next = d;
    return x;
}

void
deferg_free(void) {
    deferl_free(__global_defer_data);
    __global_defer_data = NULL;
}

void
deferl_free(defer_data_t *d) {
    defer_data_t *x = d;

    while(x != NULL) {
        d = d->__next;
        x->__free(x->__ptr);
        free(x);
        x = d;
    }
}
