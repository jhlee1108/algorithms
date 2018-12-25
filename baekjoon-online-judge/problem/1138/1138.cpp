#include <cstdio>

int N, cnt[11];

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", &cnt[i]);

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            if(cnt[j] == 0) {
                printf("%d ", j);
                for(int k=1; k<=j; k++)
                    cnt[k]--;
                break;
            }

    return 0;
}
