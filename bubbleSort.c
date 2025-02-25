#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;  // указатель для выделения памяти под массив
    int size;  // размер массива

    // Ввод количества элементов массива
    printf("n = ");
    if(scanf("%d", &size)!=1)
    {
      printf("Invalid input!");
      return 1;
    }
    if (size <= 0) {  // Размер массива должен быть положительным
        fprintf(stderr, "Invalid size\n");
        return 1;
    }

    arr = (int *)malloc(size * sizeof(int));  // выделение памяти под массив
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Заполнение массива
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
        if(scanf("%d", &arr[i]) != 1)
        {
          printf("Invalid input");
          return 1;
        }
    }

    int temp;  // временная переменная для обмена элементов местами

    // Сортировка массива пузырьком
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {  // меняем элементы местами
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Вывод отсортированного массива на экран
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);  // освобождение памяти
    return 0;
}
