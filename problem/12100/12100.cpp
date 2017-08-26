#include <cstdio>
#include <algorithm>

using namespace std;

int N, map[20][20][6], check[20][20][6];

void move(int direction, int cnt) {
    switch(direction) {
        case 0:
            for(int i=0; i<N; i++) {
                for(int j=N-2; j>=0; j--) {
                    int k = j;
                    while(k+1 < N) {
                        if(map[i][k+1][cnt] == 0) {
                            map[i][k+1][cnt] = map[i][k][cnt];
                            map[i][k][cnt] = 0;
                            k++;
                        }
                        else {
                            if(map[i][k][cnt] == map[i][k+1][cnt] && check[i][k+1][cnt] == 0) {
                                map[i][k+1][cnt] *= 2;
                                map[i][k][cnt] = 0;
                                check[i][k+1][cnt] = 1;
                            }
                            break;
                        }
                    }
                }
            }
            break;

        case 1:
            for(int i=0; i<N; i++) {
                for(int j=1; j<N; j++) {
                    int k = j;
                    while(k-1 >= 0) {
                        if(map[i][k-1][cnt] == 0) {
                            map[i][k-1][cnt] = map[i][k][cnt];
                            map[i][k][cnt] = 0;
                            k--;
                        }
                        else {
                            if(map[i][k][cnt] == map[i][k-1][cnt] && check[i][k-1][cnt] == 0) {
                                map[i][k-1][cnt] *= 2;
                                map[i][k][cnt] = 0;
                                check[i][k-1][cnt] = 1;
                            }
                            break;
                        }
                    }
                }
            }
            break;

        case 2:
            for(int j=0; j<N; j++) {
                for(int i=N-2; i>=0; i--) {
                    int k = i;
                    while(k+1 < N) {
                        if(map[k+1][j][cnt] == 0) {
                            map[k+1][j][cnt] = map[k][j][cnt];
                            map[k][j][cnt] = 0;
                            k++;
                        }
                        else {
                            if(map[k][j][cnt] == map[k+1][j][cnt] && check[k+1][j][cnt] == 0) {
                                map[k+1][j][cnt] *= 2;
                                map[k][j][cnt] = 0;
                                check[k+1][j][cnt] = 1;
                            }
                            break;
                        }
                    }
                }
            }
            break;

        case 3:
            for(int j=0; j<N; j++) {
                for(int i=1; i<N; i++) {
                    int k = i;
                    while(k-1 >= 0) {
                        if(map[k-1][j][cnt] == 0) {
                            map[k-1][j][cnt] = map[k][j][cnt];
                            map[k][j][cnt] = 0;
                            k--;
                        }
                        else {
                            if(map[k][j][cnt] == map[k-1][j][cnt] && check[k-1][j][cnt] == 0) {
                                map[k-1][j][cnt] *= 2;
                                map[k][j][cnt] = 0;
                                check[k-1][j][cnt] = 1;
                            }
                            break;
                        }
                    }
                }
            }
            break;

    }
}

int go(int cnt) {
    int ret = 0;

    if(cnt == 5) { 
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                ret = max(ret, map[i][j][5]);
        return ret;
    }

    for(int t=0; t<4; t++) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                map[i][j][cnt+1] = map[i][j][cnt];
                check[i][j][cnt+1] = 0;
            }
        }
        move(t, cnt+1);
        ret = max(ret, go(cnt+1));
    }

    return ret;
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &map[i][j][0]);

    printf("%d\n", go(0));
    
    return 0;
}
