#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int L, A, B, C, D;

int main() {
    scanf("%d %d %d %d %d", &L, &A, &B, &C, &D);
    printf("%d\n", int(L - max(ceil(double(A)/C), ceil(double(B)/D))));
    return 0;
}
