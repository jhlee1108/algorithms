#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAX_N 100000
#define PII pair<int,int>

using namespace std;

int N;
int h = (int)ceil(log2(MAX_N));
int tree_size = (1 << (h+1));
vector<int> tree(tree_size);
vector<PII> v;

int init(int node, int start, int end) {
    if(start == end) return tree[node] = 1;
    return tree[node] = init(node*2, start, (start+end)/2) + init(node*2+1, (start+end)/2+1, end);
}

void update(int node, int start, int end, int index, int diff) {
    if(index < start || end < index) return;
    tree[node] += diff;
    if(start != end) {
        update(node*2, start, (start+end)/2, index, diff);
        update(node*2+1, (start+end)/2+1, end, index, diff);
    }
}

int number_of_swap(int node, int start, int end, int left, int right) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    return number_of_swap(node*2, start, (start+end)/2, left, right) + number_of_swap(node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
    scanf("%d", &N);
    
    int num;
    for(int i=0; i<N; i++) {
        scanf("%d", &num);
        v.push_back(make_pair(num, i));
    }

    sort(v.begin(), v.end());
    init(1, 0, N-1);

    int i = 0, j = v.size()-1;
    for(int k=0; k<N; k++) {
        if(k % 2 == 0) {
            printf("%d\n", number_of_swap(1, 0, N-1, 0, v[i].second)-1);
            update(1, 0, N-1, v[i].second, -1);
            i++;
        }
        else {
            printf("%d\n", number_of_swap(1, 0, N-1, v[j].second, N-1)-1);
            update(1, 0, N-1, v[j].second, -1);
            j--;
        }
    }

    return 0;
}
