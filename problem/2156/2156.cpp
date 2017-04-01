#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int wine[10001];
    int max_wine[10001];

    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        scanf("%d", &wine[i]);

    max_wine[0] = 0;
    max_wine[1] = wine[1];
    max_wine[2] = wine[1] + wine[2];

    for(int i=3; i<=n; i++) {
        max_wine[i] = max(max_wine[i-2] + wine[i], 
                            max(max_wine[i-3] + wine[i-1] + wine[i], 
                                    max_wine[i-1]));
    }

    printf("%d", max_wine[n]);

    return 0;
}
