#include <cstdio>

int N, M, A[101], B[101];
int score[101];

int main() {
    scanf("%d %d", &N, &M);
    for(int i=1; i<=M; i++)
        scanf("%d", &A[i]);
    
    for(int i=1; i<=M; i++) {
        int target = A[i];
        int X = 0;
        
        for(int j=1; j<=N; j++) {
            scanf("%d", &B[j]);
            if(B[j] == target) score[j]++;
            else X++;
        }

        score[target] += X;
    }

    for(int i=1; i<=N; i++)
        printf("%d\n", score[i]);

    return 0;
}
