#include <cstdio>
#include <string>
#include <map>

using namespace std;

int T, F, p[200001];
char a[22], b[22];
map<string, int> m;

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

int merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return -p[x];
    p[x] += p[y];
    p[y] = x;
    return -p[x];
}

int main() {
    scanf("%d", &T);

    while(T--) {
        scanf("%d", &F);
        m.clear();

        int n = 0;
        while(F--) {
            scanf("%s %s", a, b);
            string name1 = a;
            string name2 = b;
            if(m.find(name1) == m.end()) {
                m[name1] = n++;
                p[m[name1]] = -1;
            }
            if(m.find(b) == m.end()) {
                m[name2] = n++;
                p[m[name2]] = -1;
            }
            printf("%d\n", merge(m[name1], m[name2]));
        }
    }

    return 0;
}
