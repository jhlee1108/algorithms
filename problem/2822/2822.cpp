#include <cstdio>
#include <algorithm>

using namespace std;

struct problem {
    int score, number;
};

problem p[8];

int main() {
    for(int i=1; i<=8; i++) {
        scanf("%d", &p[i-1].score);
        p[i-1].number = i;
    }

    sort(p, p+8, [] (const problem &u, const problem &v) {
        return u.score > v.score;
    });
    sort(p, p+5, [] (const problem &u, const problem &v) {
        return u.number < v.number;
    });

    int ans = 0;
    for(int i=0; i<5; i++) ans += p[i].score;
    printf("%d\n", ans);
    for(int i=0; i<5; i++) printf("%d ", p[i].number);
    printf("\n");

    return 0;
}
