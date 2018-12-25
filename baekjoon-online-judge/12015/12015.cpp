#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define PII pair<int,int>
#define MAX_N 1000000

using namespace std;

int N, A;
int h = (int)ceil(log2(MAX_N));
int tree_size = (1 << (h+1));
vector<int> tree(tree_size);
vector<PII> v;

int find_LIS(int node, int start, int end, int left, int right) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    return max(find_LIS(node*2, start, (start+end)/2, left, right), find_LIS(node*2+1, (start+end)/2+1, end, left, right));
}

void update(int node, int start, int end, int index) {
    if(index < start || end < index) return;
    else if(start == end) tree[node] = find_LIS(1, 0, N-1, 0, index) + 1;
    else {
        update(node*2, start, (start+end)/2, index);
        update(node*2+1, (start+end)/2+1, end, index);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &A);
        v.push_back(make_pair(A, i));
    }

    sort(v.begin(), v.end(), [](const PII &a, const PII &b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    for(int i=0; i<N; i++)
        update(1, 0, N-1, v[i].second);

    printf("%d\n", tree[1]);

    return 0;
}
