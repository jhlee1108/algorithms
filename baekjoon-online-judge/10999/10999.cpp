#include <cstdio>
#include <cmath>
#include <vector>

#define MAX_SIZE 1000000
#define ll long long

using namespace std;

int n, m, k;
int h = (int)ceil(log2(MAX_SIZE));
int tree_size = (1 << (h + 1));
vector<ll> a(MAX_SIZE);
vector<ll> lazy(tree_size);
vector<ll> tree(tree_size);

ll init(int node, int s, int e) {
    if(s == e) return tree[node] = a[s];
    return tree[node] = init(node*2, s, (s+e)/2) + init(node*2+1, (s+e)/2+1, e);
}

void propagate(int node, int s, int e) {
    if(lazy[node] != 0) {
        tree[node] += (e-s+1)*lazy[node];
        if(s != e) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
    }
    lazy[node] = 0;
}

void update(int node, int s, int e, int l, int r, ll diff) {
    propagate(node, s, e);
    if(s > r || l > e) return;
    if(e <= r && l <= s) {
        tree[node] += (e-s+1)*diff;
        if(s != e) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    update(node*2, s, (s+e)/2, l, r, diff);
    update(node*2+1, (s+e)/2+1, e, l, r, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll sum(int node, int s, int e, int l, int r) {
    propagate(node, s, e);
    if(s > r || l > e) return 0;
    if(e <= r && l <= s) return tree[node];
    return sum(node*2, s, (s+e)/2, l, r) + sum(node*2+1, (s+e)/2+1, e, l ,r);
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<n; i++)
        scanf("%lld", &a[i]);

    init(1, 0, n-1);

    for(int i=0; i<m+k; i++) {
        int t1; scanf("%d", &t1);
        if(t1 == 1) {
            int t2, t3; ll t4;
            scanf("%d %d %lld", &t2, &t3, &t4);
            update(1, 0, n-1, t2-1, t3-1, t4);
        }
        else {
            int t2, t3;
            scanf("%d %d", &t2, &t3);
            printf("%lld\n", sum(1, 0, n-1, t2-1, t3-1));
        }
    }

    return 0;
}
