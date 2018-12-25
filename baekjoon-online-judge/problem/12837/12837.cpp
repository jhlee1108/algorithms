#include <cstdio>
#include <cmath>
#include <vector>

#define MAX_N 1000000
#define ll long long

using namespace std;

int N, Q;
int h = (int)ceil(log2(MAX_N));
int tree_size = (1 << (h+1));
vector<ll> tree(tree_size);
vector<ll> v(MAX_N);

void update(int node, int start, int end, int index, ll diff) {
    if(index < start || end < index) return;
    tree[node] += diff;
    if(start != end) {
        update(node*2, start, (start+end)/2, index, diff);
        update(node*2+1, (start+end)/2+1, end, index, diff);
    }
}

ll find_diff(int node, int start, int end, int left, int right) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    return find_diff(node*2, start, (start+end)/2, left, right) + find_diff(node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
    scanf("%d %d", &N, &Q);
    
    int cmd, a, b;
    while(Q--) {
        scanf("%d %d %d", &cmd, &a, &b);
        if(cmd == 1) update(1, 0, N-1, a-1, b);
        else printf("%lld\n", find_diff(1, 0, N-1, a-1, b-1));        
    }

    return 0;
}
