#include <cstdio>
#include <algorithm>

using namespace std;

int H, W, height[500], lmax[500], rmax[500];

int main() {
    scanf("%d %d", &H, &W);
    for(int i=0; i<W; i++)
        scanf("%d", &height[i]);

    lmax[0] = height[0];
    rmax[W-1] = height[W-1];
    for(int i=1; i<W; i++) {
        lmax[i] = max(lmax[i-1], height[i]);
        rmax[W-i-1] = max(rmax[W-i], height[W-i-1]);
    }

    int ans = 0;
    for(int i=1; i<W-1; i++)
        ans += max(min(lmax[i], rmax[i]) - height[i], 0);

    printf("%d\n", ans);

    return 0;
}
