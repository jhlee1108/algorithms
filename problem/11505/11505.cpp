#include <cstdio>
#include <cmath>
#include <vector>

#define MOD 1000000007
#define ll long long

using namespace std;

int h = (int)ceil(log2(1000000));
int tree_size = (1 << (h + 1));
vector<ll> tree(tree_size);
vector<ll> v(1000000);

ll init(int node, int s, int e) {
    if(s == e) return tree[node] = v[s];
    return tree[node] = (init(node*2, s, (s+e)/2) * init(node*2+1, (s+e)/2+1, e)) % MOD;
}

ll update(int node, int s, int e, int k, ll x) {
    if(k < s || e < k) return tree[node];
    if(s != e) {
        return tree[node] = (update(node*2, s, (s+e)/2, k, x) * update(node*2+1, (s+e)/2+1, e, k, x)) % MOD;
    }
    return tree[node] = x;
}

ll mul(int node, int s, int e, int l, int r) {
    if(l > e || s > r) return 1;
    if(e <= r && l <= s) return tree[node];
    return (mul(node*2, s, (s+e)/2, l, r) * mul(node*2+1, (s+e)/2+1, e, l ,r)) % MOD;
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for(int i=0; i<n; i++)
        scanf("%lld", &v[i]);

    init(1, 0, n-1);

    for(int i=0; i<m+k; i++) {
        int a; scanf("%d", &a);
        if(a == 1) {
            int b; ll c;
            scanf("%d %lld", &b, &c);
            update(1, 0, n-1, b-1, c);
            v[b-1] = c;
        }
        else {
            int b, c; scanf("%d %d", &b, &c);
            ll ans = mul(1, 0, n-1, b-1, c-1);
            printf("%lld\n", ans);
        }
    }

    return 0;
}
