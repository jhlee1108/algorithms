#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;

    scanf("%d", &n);
    vector<pair<int,int>> v(n);

    for(int i=0; i<n; i++)
        scanf("%d %d", &v[i].second, &v[i].first);

    sort(v.begin(), v.end());

    for(int i=0; i<n; i++)
        printf("%d %d\n", v[i].second, v[i].first);

    return 0;
}
