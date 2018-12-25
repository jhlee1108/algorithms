#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int stairs[301];
    int max_point[301];

    scanf("%d", &n);

    stairs[0] = 0;
    for(int i=1; i<=n; i++) {
        scanf("%d", &stairs[i]);
    }

    max_point[0] = 0;
    max_point[1] = stairs[1];
    max_point[2] = stairs[1] + stairs[2];
    for(int i=3; i<=n; i++) {
        max_point[i] = max(max_point[i-2], max_point[i-3] + stairs[i-1]) + stairs[i];
    }

    printf("%d", max_point[n]);

    return 0;
}
