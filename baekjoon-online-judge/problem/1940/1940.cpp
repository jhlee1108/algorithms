#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, num[15000];

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%d", &num[i]);
    
    sort(num, num+N);
    
    int ans = 0, i = 0, j = N-1;
    while(i < j) {
        if(num[i] + num[j] < M) i++;
        else if(num[i] + num[j] > M) j--;
        else { ans++; i++; j--; }
    }

    printf("%d\n", ans);

    return 0;
}
