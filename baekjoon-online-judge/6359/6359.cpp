#include <cstdio>

int main() {
    int t, n;
    int room[101] = {0,};

    for(int i=1; i<=100; i++) {
        for(int j=0; j<=100; j+=i) {
            if(room[j] == 0)
                room[j] = 1;
            else
                room[j] = 0;
        }
    }

    scanf("%d", &t);

    while(t--) {
        int ans = 0;

        scanf("%d", &n);

        for(int i=1; i<=n; i++)
            ans += room[i];

        printf("%d\n", ans);
    }

    return 0;
}

