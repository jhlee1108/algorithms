#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAX_L 100000
#define PII pair<int,int>

using namespace std;

int L;
int h = (int)ceil(log2(MAX_L));
int tree_size = (1 << (h+1));
vector<int> tree(tree_size);
vector<PII> p;

int find_max(int node, int start, int end, int left, int right) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    return max(find_max(node*2, start, (start+end)/2, left, right), find_max(node*2+1, (start+end)/2+1, end, left, right));
}

void update(int node, int start, int end, int index) {
    if(index < start || end < index) return;
    else if(start == end) tree[node] = find_max(1, 0, L-1, 0, index) + 1;
    else {
        update(node*2, start, (start+end)/2, index);
        update(node*2+1, (start+end)/2+1, end, index);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }
}

int main() {
    while(scanf("%d", &L) == 1) {
        p.clear();
        fill(tree.begin(), tree.end(), 0);

        for(int i=0; i<L; i++) {
            int price; 
            scanf("%d", &price);
            p.push_back(make_pair(price, i));
        }

        sort(p.begin(), p.end(), [](const PII &a, const PII &b) {
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });

        for(int i=0; i<L; i++)
            update(1, 0, L-1, p[i].second);
    
        printf("%d\n", tree[1]);
    }

    return 0;
}
