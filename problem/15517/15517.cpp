#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAX_N 1000000
#define PII pair<int,int>

using namespace std;

int N, ans[MAX_N];
vector<PII> v;
int h = (int)ceil(log2(MAX_N));
int tree_size = (1 << (h+1));
vector<int> seg(tree_size);

int init(int node, int start, int end) {
    if(start == end) return seg[node] = 1;
    return seg[node] = init(node*2, start, (start+end)/2) + init(node*2+1, (start+end)/2+1, end);
}

void update(int node, int start, int end, int index) {
    if(index < start || end < index) return;
    else if(start == end) seg[node] = 0;
    else {
        update(node*2, start, (start+end)/2, index);
        update(node*2+1, (start+end)/2+1, end, index);
        seg[node] = seg[node*2] + seg[node*2+1];
    }
}

int sum(int node, int start, int end, int left, int right) {
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return seg[node];
    return sum(node*2, start, (start+end)/2, left, right) + sum(node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int x; scanf("%d", &x);
        v.push_back(make_pair(x, i));
    }

    init(1, 0, N-1);

    sort(v.begin(), v.end(), [](const PII &a, const PII &b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });

    for(int i=0; i<N; i++) {
        update(1, 0, N-1, v[i].second);
        ans[v[i].second] = sum(1, 0, N-1, 0, v[i].second);
    }

    for(int i=0; i<N; i++)
        printf("%d\n", ans[i]);

    return 0;
}
