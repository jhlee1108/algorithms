#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct participant {
    int num, s, c, l;
    participant(int _num, int _s, int _c, int _l) {
        num = _num; s = _s; c = _c; l = _l;
    }
};

int N, S, C, L;
vector<participant> v;

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d %d %d", &S, &C, &L);
        v.push_back(participant(i, S, C, L));
    }

    sort(v.begin(), v.end(), [](const participant &a, const participant &b) {
        if(a.s != b.s) return a.s > b.s;
        if(a.c != b.c) return a.c < b.c;
        return a.l < b.l;
    });

    printf("%d\n", v[0].num);

    return 0;
}
