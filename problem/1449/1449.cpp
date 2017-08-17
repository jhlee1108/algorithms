#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
    int n, l; scanf("%d %d", &n, &l);

    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    
    int ans = 1;
    int min_x = v[0];
    for(int i=1; i<v.size(); i++) {
        if(v[i] - min_x + 1 <= l) continue;
        ans++;
        min_x = v[i];
    }

    printf("%d\n", ans);

    return 0;
}
