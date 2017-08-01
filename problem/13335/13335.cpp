#include <cstdio>
#include <vector>

using namespace std;

int n, w, l;
vector<pair<int,int>> v;

int main() {
    scanf("%d %d %d", &n, &w, &l);

    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        v.push_back(make_pair(x, 0));
    }

    int ans = 0;
    int front = 0;
    int rear = 0;
    int sum = 0;

    do {
        ans++;

        if(v[front].second == w) {
            sum -= v[front].first;
            front++;
        }

        if(rear < v.size()) {
            if(sum + v[rear].first <= l) {
                sum += v[rear].first;
                rear++;
            }
        }

        for(int i=front; i<rear; i++)
            v[i].second++;

    } while(front != rear);

    printf("%d\n", ans);

    return 0;
}
