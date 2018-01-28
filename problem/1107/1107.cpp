#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M, broken_button[10];

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++) {
        int t; scanf("%d", &t);
        broken_button[t] = 1;
    }

    int ans = abs(100 - N);
    for(int i=0; i<=1000000; i++) {
        int t = i, cnt = 0;
        bool is_possible = true;
        while(1) {
            if(broken_button[t % 10]) {
                is_possible = false;
                break;
            }
            t /= 10;
            cnt++;
            if(t == 0) break;
        }
        if(is_possible) ans = min(ans, cnt + abs(i - N));
    }

    printf("%d\n", ans);

    return 0;
}
