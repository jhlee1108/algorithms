#include <cstdio>
#include <map>

using namespace std;

int n, x, y;
map<int, int> X, Y;

int main() {
    scanf("%d", &n);
    
    int ans = 0;
    while(n--) {
        scanf("%d %d", &x, &y);
        X[x]++;
        Y[y]++;
        if(X[x] == 2) ans++;
        if(Y[y] == 2) ans++;
    }

    printf("%d\n", ans);

    return 0;
}
