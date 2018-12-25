#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, t;
    int v[4][100002];
    int max_value[4][100002];
    int sum = 0;

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        for(int i=1; i<3; i++) {
            for(int j=1; j<=n; j++)
                scanf("%d", &v[i][j]);
        }

        for(int j=1; j<=n; j++) {
            for(int i=1; i<3; i++) {
                if(i == 1)
                    max_value[i][j] = max(max_value[i+1][j-1] + v[i][j], max_value[i][j-1]);
                else
                    max_value[i][j] = max(max_value[i-1][j-1] + v[i][j], max_value[i][j-1]);
            }
        }

        printf("%d\n", max(max_value[1][n], max_value[2][n]));
        
    }

    return 0;
}
