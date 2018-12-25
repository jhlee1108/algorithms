#include <cstdio>

struct draw {
    char map[5][7];
};

int N;
draw d[50];

int main() {
    scanf("%d\n", &N);

    for(int i=0; i<N; i++)
        for(int j=0; j<5; j++)
            for(int k=0; k<7; k++)
                scanf("%c\n", &d[i].map[j][k]);

    int min_cnt = 1e9, n1 = 0, n2 = 0;
    for(int i=0; i<N-1; i++)
        for(int j=i+1; j<N; j++) {
            int cnt = 0;
            for(int k=0; k<5; k++)
                for(int l=0; l<7; l++)
                    if(d[i].map[k][l] != d[j].map[k][l])
                        cnt++;
            if(min_cnt > cnt) {
                min_cnt = cnt;
                n1 = i < j ? i : j;
                n2 = i > j ? i : j;
            }
        }

    printf("%d %d\n", n1+1, n2+1);

    return 0;
}
