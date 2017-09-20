#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, box;
vector<int> v;

int main() {
    scanf("%d", &N);

    int ans = 0;
    v.push_back(-1);
    for(int i=0; i<N; i++) {
        scanf("%d", &box);
        if(v.back() < box) {
            v.push_back(box);
            ans++;
        }
        else {
            auto it = lower_bound(v.begin(), v.end(), box);
            *it = box;
        }
    }

    printf("%d\n", ans);

    return 0;
}
