#include <cstdio>
#include <vector>
#include <algorithm>

#define PII pair<int,int>

using namespace std;

int t, n;
vector<PII> v;
vector<int> tree(1 << 18);

void update(int node, int s, int e, int index) {
    if(index < s || e < index) return;
    tree[node]++;
    if(s != e) {
        update(node*2, s, (s+e)/2, index);
        update(node*2+1, (s+e)/2+1, e, index);
    }
}

int sum(int node, int s, int e, int l, int r) {
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return tree[node];
    return sum(node*2, s, (s+e)/2, l, r) + sum(node*2+1, (s+e)/2+1, e, l, r);
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        v.clear();
        fill(tree.begin(), tree.end(), 0);

        for(int i=0; i<n; i++) {
            int x, y; scanf("%d %d", &x, &y);
            v.push_back(make_pair(x, y));
        }

        sort(v.begin(), v.end(), [](PII &a, PII &b) {
            return a.second < b.second;
        });

        int index = 0;
        int arr_index[75000];
        for(int i=0; i<n; i++) {
            if(i > 0 && v[i-1].second != v[i].second) index++;
            arr_index[i] = index;
        }

        for(int i=0; i<n; i++)
            v[i].second = arr_index[i];

        sort(v.begin(), v.end(), [](PII &a, PII &b) {
            if(a.first == b.first) return a.second > b.second;
            else return a.first < b.first;
        });

        long long ans = 0;
        for(int i=0; i<n; i++) {
            ans += sum(1, 0, index, v[i].second, index);
            update(1, 0, index, v[i].second);
        }

        printf("%lld\n", ans);
    }

    return 0;
}
