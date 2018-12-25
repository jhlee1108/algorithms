#include <cstdio>
#include <cmath>

using namespace std;

int N, M;
int card[101];

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%d", &card[i]);

    int ans = 0;
    for(int i=0; i<N-2; i++)
        for(int j=i+1; j<N-1; j++)
            for(int k=j+1; k<N; k++) {
                int sum = card[i] + card[j] + card[k];
                if(sum <= M && ans < sum)
                    ans = sum;
            }

    printf("%d\n", ans);

    return 0;
}
