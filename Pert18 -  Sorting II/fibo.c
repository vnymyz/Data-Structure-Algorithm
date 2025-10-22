#include <stdio.h>

int main() {
    int n, first = 0, second = 1, next;

    printf("Enter how many Fibonacci numbers you want: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (int i = 0; i < n; i++) {
        if (i <= 1)
            next = i;  // for the first two numbers: 0 and 1
        else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }

    printf("\n");
    return 0;
}
