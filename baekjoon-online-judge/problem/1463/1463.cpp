#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, min_prev;
    int min_count[1000001];
    
    scanf("%d", &n);

    min_count[1] = 0;
    min_count[2] = 1;
    min_count[3] = 1;

    for(int i=4; i<=n; i++) {
        min_prev = min_count[i-1];
        if(i%3 == 0)
            min_prev = min(min_prev, min_count[i/3]);
        if(i%2 == 0)
            min_prev = min(min_prev, min_count[i/2]);

        min_count[i] = min_prev + 1;
    }

    printf("%d", min_count[n]);

    return 0;
}
