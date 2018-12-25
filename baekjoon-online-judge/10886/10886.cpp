#include <cstdio>

int N, survey[2];

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int x; scanf("%d", &x);
        survey[x]++;
    }

    puts(survey[0] > survey[1] ? "Junhee is not cute!" : "Junhee is cute!");

    return 0;
}
