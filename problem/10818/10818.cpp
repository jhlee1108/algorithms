#include <cstdio>

int main() {
    int n, input;
    int max = -1000000;
    int min = 1000000;

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &input);
        if(input > max) max = input;
        if(input < min) min = input;
    }
    
    printf("%d %d", min, max);

    return 0;
}
