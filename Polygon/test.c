#include <stdio.h>

int sum(int n) {
    if (n == 0)
        return;
    else
        return n + sum(n - 1);
}

int main() {
    printf("%d", sum(3));
    return 0;
}
