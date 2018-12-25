#include <cstdio>
#include <queue>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> q;
    int n, k;

    scanf("%d %d", &n, &k);
    while(n--) {
        int x;
        scanf("%d", &x);
        q.push(x);
    }

    for(int i=0; i<k-1; i++)
        q.pop();

    printf("%d\n", q.top());

    return 0;
}
