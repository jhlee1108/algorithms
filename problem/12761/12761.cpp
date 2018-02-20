#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int A, B, N, M;
int check[100001];
queue<int> q;

void push_queue(int x, int nx) {
    if(0 <= nx && nx <= 100000 && check[nx] < 0) {
        q.push(nx);
        check[nx] = check[x] + 1;
    }
}

int main() {
    scanf("%d %d %d %d", &A, &B, &N, &M);
    memset(check, -1, sizeof(check));

    q.push(N);
    check[N] = 0;
    int dx[] = {A, -A, B, -B, 1, -1};
    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int i=0; i<6; i++)
            push_queue(x, x + dx[i]);

        for(int i=0; i<4; i++)
            push_queue(x, x * dx[i]);
    }

    printf("%d\n", check[M]);

    return 0;
}
