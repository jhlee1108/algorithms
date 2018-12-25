#include <cstdio>

int A, B, V;

int main() {
    scanf("%d %d %d", &A, &B, &V);
    
    int h = V - A;
    int ans = h / (A - B);
    if(h % (A - B) > 0) ans++;
    printf("%d\n", ans+1);

    return 0;
}
