#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int p[1001];
    int ans = 0;
    int psum = 0;

    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d", &p[i]);

    sort(p,p+n);

    for(int i=0; i<n; i++) {
        psum += p[i];
        ans += psum;
    }

    printf("%d\n", ans);

    return 0;
}
