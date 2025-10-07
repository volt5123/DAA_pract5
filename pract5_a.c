#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {

    char A[100];
    char B[100];

    printf("Enter the A sequence: ");
    scanf("%s",&A);

    printf("Enter the B sequence: ");
    scanf("%s",&B);

    int charA_length = strlen(A);
    int charB_length = strlen(B);

    int array[charA_length + 1][charB_length + 1];

    for (int i = 0; i <= charA_length; i++) {
        for (int j = 0; j <= charB_length; j++) {
            array[i][j] = 0;
        }
    }

    for (int i = 1; i <= charA_length; i++) {
        for (int j = 1; j <= charB_length; j++) {
            if (A[i - 1] == B[j - 1]) {
                array[i][j] = array[i - 1][j - 1] + 1;
            } else {
                array[i][j] = max(array[i - 1][j], array[i][j - 1]);
            }
        }
    }

    printf("Array Table:\n");
    for (int i = 0; i <= charA_length; i++) {
        for (int j = 0; j <= charB_length; j++) {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }

    int i = charA_length, j = charB_length;
    char lcs[charA_length + charB_length];
    int index = array[charA_length][charB_length];
    lcs[index] = '\0';

    for (int x = i, y = j; x > 0 && y > 0;) {
    if (A[x - 1] == B[y - 1]) {
        lcs[index - 1] = A[x - 1];
        x--;
        y--;
        index--;
    } else if (array[x - 1][y] > array[x][y - 1]) {
        x--;
    } else {
        y--;
    }
}

    printf("\nLongest Common Subsequence is %s and the length is %d.\n", lcs ,strlen(lcs));

    return 0;
}
