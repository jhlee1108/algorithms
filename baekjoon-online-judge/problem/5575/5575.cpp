#include <cstdio>

int sh, sm, ss, eh, em, es;

int main() {
    for(int t=0; t<3; t++) {
        scanf("%d %d %d %d %d %d", &sh, &sm, &ss, &eh, &em, &es);
        if(es - ss < 0) {
            es += 60;
            sm++;
        }
        int ans_s = es - ss;

        if(em - sm < 0) {
            em += 60;
            sh++;
        }
        int ans_m = em - sm;
        int ans_h = eh - sh;
        printf("%d %d %d\n", ans_h, ans_m, ans_s);
    }

    return 0;
}
