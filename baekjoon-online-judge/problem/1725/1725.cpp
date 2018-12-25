#include <cstdio>
#include <algorithm>

#define ll long long

using namespace std;

ll a[100000];

ll hist(int s, int e) {
    if(s == e) return 0;
    if(s+1 == e) return a[s];

    int mid = (s + e) / 2;
    ll ret = max(hist(s, mid), hist(mid, e));
    ll h = a[mid];
    ll w = 1;
    int left = mid, right = mid;

    while(right-left <= e-s) {
        ll lh = s < left ? min(h, a[left-1]) : -1;
        ll rh = right < e-1 ? min(h, a[right+1]) : -1;

        if(lh > rh) {
            left--;
            h = lh;
        }

        else {
            right++;
            h = rh;
        }

        w++;
        ret = max(ret, w*h);
    }

    return  ret;
}

int main() {
    int n; scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%lld", &a[i]);

    ll ans = hist(0, n);

    printf("%lld\n", ans);

    return 0;
}
