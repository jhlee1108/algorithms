#include <cstdio>

int N, candy[100000];

int main() {
    while(1) {
        scanf("%d", &N);
        if(N == 0) break;

        for(int i=0; i<N; i++)
            scanf("%d", &candy[i]);

        int cnt = 0;
        bool is_end = false;
        while(!is_end) {
            is_end = true;
            int x = candy[0]/2 + candy[N-1]/2;
            if(x % 2 == 1) x++;
            for(int i=0; i<N-1; i++) {
                candy[i] = candy[i]/2 + candy[i+1]/2;
                if(candy[i] % 2 == 1) candy[i]++;
                if(candy[i] != x) is_end = false;
            }
            candy[N-1] = x;
            cnt++;
        }

        printf("%d %d\n", cnt, candy[1]);
    }

    return 0;
}
