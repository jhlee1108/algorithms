#include <cstdio>

int main() {
    int n, input, sum;

    sum = 0;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%1d", &input);
        sum += input;
    }

    printf("%d", sum);

    return 0;
}
