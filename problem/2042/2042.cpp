#include <cstdio>
#include <vector>

#define ll long long

using namespace std;

int n, m, k;
vector<ll> s(1000000);
vector<ll> tree(1 << 21);

ll init(int node, int start, int end) {
    if(start == end) return tree[node] = s[start];
    else return tree[node] = init(node*2, start, (start+end)/2) + init(node*2+1, (start+end)/2+1, end);
}

ll sum(int node, int start, int end, int left, int right) {
    if(right < start || left > end) return 0;
    if(right >= end && left <= start) return tree[node];
    return sum(node*2, start, (start+end)/2, left, right) + sum(node*2+1, (start+end)/2+1, end, left, right);
}

void update(int node, int start, int end, int index, ll diff) {
    if(index < start || index > end) return;
    tree[node] += diff;
    if(start != end) {
        update(node*2, start, (start+end)/2, index, diff);
        update(node*2+1, (start+end)/2+1, end, index, diff);
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<n; i++)
        scanf("%lld", &s[i]);

    init(1, 0, n-1);

    for(int i=0; i<m+k; i++) {
        int a; scanf("%d", &a);
        if(a == 1) {
            int b; ll c;
            scanf("%d %lld", &b, &c);
            ll diff = c-s[b-1];
            s[b-1] = c;
            update(1, 0, n-1, b-1, diff);
        }
        else {
            int b, c;
            scanf("%d %d", &b, &c);
            printf("%lld\n", sum(1, 0, n-1, b-1, c-1));
        }
    }

    return 0;
}
