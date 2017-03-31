#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int rgb[3][1001];
    int rgb_min[3][1001];
    int n;

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d %d %d", &rgb[0][i], &rgb[1][i], &rgb[2][i]);
    }

    rgb_min[0][0] = rgb[0][0];
    rgb_min[1][0] = rgb[1][0];
    rgb_min[2][0] = rgb[2][0];
    for(int i=1; i<n; i++) {
        rgb_min[0][i] = min(rgb_min[1][i-1] + rgb[0][i], rgb_min[2][i-1] + rgb[0][i]);
        rgb_min[1][i] = min(rgb_min[0][i-1] + rgb[1][i], rgb_min[2][i-1] + rgb[1][i]);
        rgb_min[2][i] = min(rgb_min[0][i-1] + rgb[2][i], rgb_min[1][i-1] + rgb[2][i]);
    }

    printf("%d", min(rgb_min[0][n-1], min(rgb_min[1][n-1], rgb_min[2][n-1])));

    return 0;
}
    
