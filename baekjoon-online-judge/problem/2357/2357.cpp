#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAX_VALUE 1000000000
#define MIN_VALUE 1
#define MAX_N 100000
#define PII pair<int,int>

using namespace std;

int N, M;
int h = (int)ceil(log2(MAX_N));
int tree_size = 1 << (h+1);
vector<PII> tree(tree_size);
vector<int> v(MAX_N);

void init(int node, int start, int end) {
    if(start == end) {
        tree[node].first = tree[node].second = v[start];
        return;
    }
    int mid = (start + end) / 2;
    init(node*2, start, mid);
    init(node*2+1, mid+1, end);
    tree[node].first = min(tree[node*2].first, tree[node*2+1].first);
    tree[node].second = max(tree[node*2].second, tree[node*2+1].second);
}

PII find_min_max(int node, int start, int end, int left, int right) {
    if(left > end || right < start) {
        PII ret;
        ret.first = MAX_VALUE;
        ret.second = MIN_VALUE;
        return ret;
    }
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    PII left_child = find_min_max(node*2, start, mid, left, right);
    PII right_child = find_min_max(node*2+1, mid+1, end, left, right);
    PII ret;
    ret.first = min(left_child.first, right_child.first);
    ret.second = max(left_child.second, right_child.second);
    return ret;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%d", &v[i]);
    
    init(1, 0, N-1);
    while(M--) {
        int a, b; scanf("%d %d", &a, &b);
        PII res = find_min_max(1, 0, N-1, a-1, b-1);
        printf("%d %d\n", res.first, res.second);
    }

    return 0;
}
