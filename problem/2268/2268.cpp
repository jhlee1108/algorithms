#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAX_N 1000000
#define ll long long

using namespace std;

int N, M;
int h = (int)ceil(log2(MAX_N));
int tree_size = (1 << (h+1));
vector<ll> tree(tree_size);

void Modify(int node, int start, int end, int index, ll var) {
    if(index < start || end < index) return;
    else if(start == end) tree[node] = var;
    else {
        Modify(node*2, start, (start+end)/2, index, var);
        Modify(node*2+1, (start+end)/2+1, end, index, var);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

ll Sum(int node, int start, int end, int left, int right) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    return Sum(node*2, start, (start+end)/2, left, right) + Sum(node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
    scanf("%d %d", &N, &M);

    int cmd, i, j;
    ll k;
    while(M--) {
        scanf("%d", &cmd);
        if(cmd == 0) {
            scanf("%d %d", &i, &j);
            printf("%lld\n", Sum(1, 0, N-1, min(i,j)-1, max(i,j)-1));
        }
        else {
            scanf("%d %lld", &i, &k);
            Modify(1, 0, N-1, i-1, k);
        }
    }

    return 0;
}
