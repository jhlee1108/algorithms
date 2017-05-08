#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int prime[10000];
int d[10000];
int dx[4];

void bfs(int x) {
    queue<int> q;
    q.push(x);
    d[x] = 1;

    while(!q.empty()) {
        x = q.front();
        q.pop();

        dx[3] = x/1000;
        dx[2] = (x%1000)/100;
        dx[1] = (x%100)/10;
        dx[0] = x%10;

        for(int i=0; i<4; i++) {
            for(int j=0; j<10; j++) {
                int nx = x - dx[i]*pow(10,i) + j*pow(10,i);

                if(1000 <= nx && nx < 10000) {
                    if(prime[nx] == 0 && d[nx] == 0) {
                        q.push(nx);
                        d[nx] = d[x] + 1;
                    }
                }
            }
        }
    }
}

int main() {
    int t;

    for(int i=2; i<10000; i++) {
        if(prime[i] == 1)
            continue;
        for(int j=i+i; j<10000; j+=i)
            prime[j] = 1;
    }

    scanf("%d", &t);

    while(t--) {
        memset(d, 0, sizeof(d));
        int a, b, ans;
        scanf("%d %d", &a, &b);
        
        bfs(a);
        ans = d[b];
        if(ans == 0)
            printf("Impossible\n");
        else
            printf("%d\n", ans-1); 
    }

    return 0;
}
