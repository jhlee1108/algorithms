#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

struct cmp {
    bool operator() (int a, int b) {
        if(abs(a) == abs(b)) return a > b;
        else return abs(a) > abs(b);
    }
};

int N, x;
priority_queue<int, vector<int>, cmp> pq;

int main() {
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &x);
        if(x == 0) {
            if(pq.size() == 0) {
                printf("0\n");
                continue;
            }
            printf("%d\n", pq.top());
            pq.pop();
        }
        else pq.push(x);
    }

    return 0;
}
