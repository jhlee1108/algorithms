#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
    int left, right, x, y;
};

int N, cnt;
node g[10001];
int check[10001];

void in_order(int k, int level) {
    if(g[k].left != -1) in_order(g[k].left, level+1);
    g[k].x = ++cnt; g[k].y = level;
    if(g[k].right != -1) in_order(g[k].right, level+1);
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int k; scanf("%d", &k);
        scanf("%d %d", &g[k].left, &g[k].right);
        check[g[k].left] = check[g[k].right] = 1;
    }

    int root;
    for(int i=1; i<=N; i++)
        if(!check[i]) root = i;

    in_order(root, 1);
    sort(g+1, g+N+1, [] (const node &u, const node &v) {
        if(u.y == v.y) return u.x < v.x;
        return u.y < v.y;
    });

    int max_width = 1;
    int max_level = 1;
    int s = 0, e = 0, prev_level = 1;
    for(int i=2; i<=N; i++) {
        if(g[i].y != prev_level) {
            int width = e - s + 1;

            if(max_width < width) {
                max_width = width;
                max_level = prev_level;
            }

            s = g[i].x;
            prev_level = g[i].y;
        }

        e = g[i].x;
    }

    int width = e - s + 1;
    if(max_width < width) {
        max_width = width;
        max_level = g[N].y;
    }

    printf("%d\n%d\n", max_level, max_width);

    return 0;
}
