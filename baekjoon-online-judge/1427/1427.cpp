#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int x;
    vector<int> v;

    while(scanf("%1d", &x) == 1) {
        v.push_back(x);
    }

    sort(v.begin(), v.end(), greater<int>());

    for(auto a : v)
        printf("%d",a);

    return 0;
}
