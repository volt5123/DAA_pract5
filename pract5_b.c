#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char S[100];
    printf("Enter the string: ");
    scanf("%s", S);

    int n = strlen(S);
    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (S[i - 1] == S[j - 1] && i != j) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    printf("\nDP Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }

    int index = dp[n][n];
    char lrs[index + 1];
    lrs[index] = '\0';

    int i = n, j = n;
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i - 1][j - 1] + 1 && S[i - 1] == S[j - 1] && i != j) {
            lrs[index - 1] = S[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("\nLongest Repeating Subsequence is %s and length is %d\n", lrs, strlen(lrs));

    return 0;
}
