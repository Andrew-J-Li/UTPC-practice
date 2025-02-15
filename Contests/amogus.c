#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char arr[n][11];
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    for (int i = 0; i < n; i++) {
        int len = strlen(arr[i]);
        arr[i][len - 1] = '\0';
        arr[i][len - 2] = 'i';
        printf("%s\n", arr[i]);
    }
}