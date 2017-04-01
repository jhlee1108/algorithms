#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, max_sum;
    int triangle[500][500];
    int max_value[500][500];

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            scanf("%d", &triangle[i][j]);
        }
    }


    max_value[0][0] = triangle[0][0];

    for(int i=1; i<n; i++) {
        for(int j=0; j<=i; j++) {
            if(j-1 < 0)
                max_value[i][j] = max_value[i-1][j] + triangle[i][j];
            else if(j == i)
                max_value[i][j] = max_value[i-1][j-1] + triangle[i][j];
            else
                max_value[i][j] = max(max_value[i-1][j] + triangle[i][j],
                                        max_value[i-1][j-1] + triangle[i][j]);
        }
    }

    max_sum = max_value[n-1][0];

    for(int i=1; i<n; i++) {
        max_sum = max(max_sum, max_value[n-1][i]);
    }

    printf("%d", max_sum);

    return 0;
}

