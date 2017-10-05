#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAX_Y 30000

using namespace std;

struct line {
    int x, y1, y2, status;
};

int N;
int h = int(ceil(log2(MAX_Y)));
int tree_size = (1 << (h+1));
vector<line> v;
vector<int> seg(tree_size);
vector<int> cnt(tree_size);

void update(int node, int start, int end, int left, int right, int status) {
    if(right < start || end < left) return;
    else if(left <= start && end <= right) cnt[node] += status;
    else {
        int mid = (start + end) >> 1;
        update(node*2, start, mid, left, right, status);
        update(node*2+1, mid+1, end, left, right, status);
    }

    if(cnt[node]) seg[node] = end - start + 1;
    else {
        if(start == end) seg[node] = 0;
        else seg[node] = seg[node*2] + seg[node*2+1];
    }
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        line l1; l1.x = x1; l1.y1 = y1; l1.y2 = y2-1; l1.status = 1;
        line l2; l2.x = x2; l2.y1 = y1; l2.y2 = y2-1; l2.status = -1;
        v.push_back(l1);
        v.push_back(l2);
    }

    sort(v.begin(), v.end(), [] (const line &u, const line &v) {
        return u.x < v.x;
    });

    update(1, 0, MAX_Y, v[0].y1, v[0].y2, v[0].status);
    int prev = v[0].x;
    int ans = 0;
    for(int i=1; i<v.size(); i++) {
        int dx = v[i].x - prev;
        ans += (dx * seg[1]);
        update(1, 0, MAX_Y, v[i].y1, v[i].y2, v[i].status);
        prev = v[i].x;
    }

    printf("%d\n", ans);

    return 0;
}
