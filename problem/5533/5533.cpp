#include <cstdio>
#include <cstring>

int N;
int score[200][4];
int cnt[101];

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d %d %d", &score[i][0], &score[i][1], &score[i][2]);
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<N; j++)
            cnt[score[j][i]]++;
        for(int j=0; j<N; j++)
            if(cnt[score[j][i]] == 1) score[j][3] += score[j][i];
        memset(cnt, 0, sizeof(cnt));
    }

    for(int i=0; i<N; i++)
        printf("%d\n", score[i][3]);

    return 0;
}
