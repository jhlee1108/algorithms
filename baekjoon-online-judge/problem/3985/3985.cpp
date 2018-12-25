#include <cstdio>

int L, N, P, K, cake[1001];

int main() {
    scanf("%d %d", &L, &N);

    int expect_cnt = 0, actual_cnt = 0;
    int expect_id = 0, actual_id = 0;
    for(int i=1; i<=N; i++) {
        scanf("%d %d", &P, &K);
        
        if(K-P+1 > expect_cnt) {
            expect_cnt = K-P+1;
            expect_id = i;
        }
        
        int cnt = 0;
        for(int j=P; j<=K; j++)
            if(cake[j] == 0) {
                cake[j] = i;
                cnt++;
            }
        
        if(cnt > actual_cnt) {
            actual_cnt = cnt;
            actual_id = i;
        }
    }

    printf("%d\n%d\n", expect_id, actual_id);

    return 0;
}
