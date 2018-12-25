#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long a[1000000];

    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%lld", &a[i]);

    sort(a, a+n);

    long long ans = a[0];
    long long x = a[0];
    int count_max = 1;
    int count = 1;
    for(int i=1; i<n; i++) {
        if(x == a[i]) count++;
        else {
            x = a[i];
            count = 1;
        }
        if(count_max < count) {
            count_max = count;
            ans = a[i];
        }
    }

    printf("%lld\n", ans);

    return 0;
}
