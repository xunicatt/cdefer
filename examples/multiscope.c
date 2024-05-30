#include <stdio.h>
#include <defer.h>

void do_allocate(int **arr, int size) {
    *arr = (int *)malloc(sizeof(int) * size);
}

void set_all_to_zero(int *arr, int size) {
    for(int i = 0; i < size; i++)
        arr[i] = 0;
}

int main() {
    int data_array_size = 10;
    int *arr = (int *)malloc(sizeof(int) * data_array_size);
    defergd(arr);

    for(int i = 0; i < 5; i++) {
        int *x = NULL;
        do_allocate(&x, data_array_size);
        defer_data_t *local = deferld(NULL, x);
        set_all_to_zero(x, data_array_size);

        {
            int *y = NULL;
            do_allocate(&y, data_array_size);
            defer_data_t *local = deferld(NULL, y);
            set_all_to_zero(y, data_array_size);
            deferl_free(local);
        }

        deferl_free(local);
    }

    deferg_free();
    getc(stdin);
}