#include <cstdio>
#include <cmath>
#include <vector>

#define MAX_N 100000
#define ll long long

using namespace std;

ll b;
int N, Q, x, y, a;
int h = (int)ceil(log2(MAX_N));
int tree_size = (1 << (h+1));
vector<ll> tree(tree_size);
vector<ll> v(MAX_N);

ll init(int node, int start, int end) {
    if(start == end) return tree[node] = v[start];
    return tree[node] = init(node*2, start, (start+end)/2) + init(node*2+1, (start+end)/2+1, end);
}

void update(int node, int start, int end, int index, ll diff) {
    if(index < start || end < index) return;
    else if(start == end) tree[node] = diff;
    else {
        update(node*2, start, (start+end)/2, index, diff);
        update(node*2+1, (start+end)/2+1, end, index, diff);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

ll psum(int node, int start, int end, int left, int right) {
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    return psum(node*2, start, (start+end)/2, left, right) + psum(node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
    scanf("%d %d", &N, &Q);
    for(int i=0; i<N; i++)
        scanf("%lld", &v[i]);
    
    init(1, 0, N-1);

    while(Q--) {
        scanf("%d %d %d %lld", &x, &y, &a, &b);
        printf("%lld\n", psum(1, 0, N-1, min(x,y)-1, max(x,y)-1));
        update(1, 0, N-1, a-1, b);
    }

    return 0;
}
