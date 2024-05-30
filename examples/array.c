#include <stdio.h>
#include <defer.h>

int main() {
    size_t rows = 0, cols = 0;
    int **arr = NULL;

    printf("Enter size of a 2D matrix(rows, cols): ");
    scanf("%d %d", &rows, &cols);
    arr = (int**)malloc(sizeof(int*) * rows);
    deferg(arr, NULL);

    for(size_t i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(sizeof(int) * cols);
        deferg(arr[i], NULL);
    }

    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < cols; j++) {
            printf("[%zu][%zu]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        puts("\n");
    }

    deferg_free();
}