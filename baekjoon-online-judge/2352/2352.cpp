#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

int main() {
    scanf("%d", &n);
    
    int ans = 0;
    v.push_back(-1);
    while(n--) {
        int x; scanf("%d", &x);
        if(v.back() < x) {
            v.push_back(x);
            ans++;
        }
        else {
            auto it = lower_bound(v.begin(), v.end(), x);
            *it = x;
        }
    }

    printf("%d\n", ans);

    return 0;
}
