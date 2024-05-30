#include <stdio.h>
#include <defer.h>

int main() {
    int size = 10;
    int *arr = malloc(sizeof(int) * size);
    deferg(arr, NULL);

    for(int i = 1; i <= size; i++)
        arr[i-1] = i * 2;
        
    deferg_free();
    return 0;
}