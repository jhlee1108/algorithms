#include <cstdio>
#include <algorithm>

using namespace std;

int A, B, C, D, P;

int main() {
    scanf("%d %d %d %d %d", &A, &B, &C, &D, &P);
    int X = A * P;
    int Y = C < P ? B + (P-C)*D : B;

    printf("%d\n", min(X, Y));

    return 0;
}
