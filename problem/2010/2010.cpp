#include <cstdio>

using namespace std;

int N;

int main() {
    scanf("%d", &N);

    int ans = -N+1;
    for(int i=0; i<N; i++) {
        int outlets; scanf("%d", &outlets);
        ans += outlets;
    }

    printf("%d\n", ans);

    return 0;
}
