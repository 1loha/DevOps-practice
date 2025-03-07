#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int size;
    char term;
    printf("n = ");
    if(scanf("%d%c", &size, &term) != 2 || term != '\n') {
        fprintf(stderr, "Invalid size\n");
        return 1;
    }
    if (size <= 0) {
        fprintf(stderr, "Invalid size\n");
        return 1;
    }

    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
	if(scanf("%d%c", &arr[i], &term) != 2 || term != '\n') {
		fprintf(stderr, "Invalid input\n");
		fflush(stderr);
		free(arr);
		return 1;
	}
    }

    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
