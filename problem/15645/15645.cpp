#include <cstdio>
#include <algorithm>

using namespace std;

int N, dp_max[100001][3], dp_min[100001][3];

int main() {
    scanf("%d", &N);
    
    int ans_max = 0, ans_min = 1e9;
    for(int i=1; i<=N; i++) {
        scanf("%d %d %d", &dp_max[i][0], &dp_max[i][1], &dp_max[i][2]);
        dp_min[i][0] = dp_max[i][0];
        dp_min[i][1] = dp_max[i][1];
        dp_min[i][2] = dp_max[i][2];
        for(int j=0; j<3; j++) {
            if(j == 0) {
                dp_max[i][j] += max(dp_max[i-1][j], dp_max[i-1][j+1]);
                dp_min[i][j] += min(dp_min[i-1][j], dp_min[i-1][j+1]);
            }
            else if(j == 1) {
                dp_max[i][j] += max(dp_max[i-1][j-1], max(dp_max[i-1][j], dp_max[i-1][j+1]));
                dp_min[i][j] += min(dp_min[i-1][j-1], min(dp_min[i-1][j], dp_min[i-1][j+1]));
            }
            else {
                dp_max[i][j] += max(dp_max[i-1][j-1], dp_max[i-1][j]);
                dp_min[i][j] += min(dp_min[i-1][j-1], dp_min[i-1][j]);
            }
            ans_max = max(dp_max[i][0], max(dp_max[i][1], dp_max[i][2]));
            ans_min = min(dp_min[i][0], min(dp_min[i][1], dp_min[i][2]));
        }
    }

    printf("%d %d\n", ans_max, ans_min);

    return 0;
}
