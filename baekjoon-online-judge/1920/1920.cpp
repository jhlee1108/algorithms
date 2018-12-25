#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, A[100000];

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);

    sort(A, A+N);

    scanf("%d", &M);
    while(M--) {
        int x; scanf("%d", &x);
        printf("%d\n", binary_search(A, A+N, x));
    }

    return 0;
}
