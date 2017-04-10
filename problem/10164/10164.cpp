#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m, k;
    int a[16][16];
    
    cin >> n >> m >> k;

    if(k == 0) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(i == 1)
                    a[i][j] = 1;
                else if(j == 1)
                    a[i][j] = 1;
                else
                    a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }
    }

    else {
        int y = ceil(float(k)/m);
        int x = k - m*(y-1);

        for(int i=1; i<=y; i++) {
            for(int j=1; j<=x; j++) {
                if(i == 1)
                    a[i][j] = 1;
                else if(j == 1)
                    a[i][j] = 1;
                else
                    a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }

        for(int i=y; i<=n; i++) {
            for(int j=x; j<=m; j++) {
                if(i == y)
                    a[i][j] = a[y][x];
                else if(j == x)
                    a[i][j] = a[y][x];
                else
                    a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }
    }

    cout << a[n][m] << endl;

    return 0;
}
