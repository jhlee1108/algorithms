#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int n;
int a[1001];

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);

    sort(a, a+n, greater<int>());

    for(int i=0; i<=n; i++) {
        if(a[i] <= i) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}
