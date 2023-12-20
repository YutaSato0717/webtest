#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000000000

// 配列から指定された値およびその倍数を0に置き換える関数
void replaceWithZero(long long array[], int size, long long value) {
    for (int i = 0; i < size; i++) {
        if (array[i] % value == 0) {
            array[i] = 0;
        }
    }
}

int main() {
    long  l, r;
    

    int m;
    

    long long* nArray = (long long*)malloc(m * sizeof(long long));
    

    // nの値をm個入力
    for (int i = 0; i < m; i++) {
        if (scanf("%lld", &nArray[i]) != 1) {
            fprintf(stderr, "Invalid input\n");
            free(nArray);  // メモリを解放
            return 1;  // エラーコードを返す
        }
    }

    if (l < 0 || r < 0 || l > r) {
        fprintf(stderr, "Invalid range\n");
        free(nArray);  // メモリを解放
        return 1;  // エラーコードを返す
    }

    long long* array = (long long*)malloc((r - l + 1) * sizeof(long long));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(nArray);  // メモリを解放
        return 1;  // エラーコードを返す
    }

    int size = 0;
    for (long long i = l; i <= r; i++) {
        array[size] = i;
        size++;
    }

    // 各nおよびその倍数を0に置き換え
    for (int i = 0; i < m; i++) {
        replaceWithZero(array, size, nArray[i]);
    }

    // 残った要素の数をカウント
    int remainingElements = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] != 0) {
            remainingElements++;
        }
    }

    // 残った要素の数を出力
    printf("%d\n", remainingElements);

    // メモリを解放
    free(nArray);
    free(array);

    return 0;
}
