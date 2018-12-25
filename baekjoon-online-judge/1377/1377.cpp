#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<pair<int,int>> v;

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(make_pair(x,i));
    }

    stable_sort(v.begin(), v.end());

    int ans = 0;
    for(int i=0; i<n; i++)
        if(ans < v[i].second - i)
            ans = v[i].second - i;

    printf("%d\n", ans+1);

    return 0;

}
