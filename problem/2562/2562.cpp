#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>

#define PII pair<int,int>

using namespace std;

vector<PII> v;
int n;

int main() {
    for(int i=0; i<9; i++) {
        scanf("%d", &n);        
        v.push_back(make_pair(n, i));
    }

    sort(v.begin(), v.end(), greater<PII>());

    printf("%d\n%d\n", v[0].first, v[0].second+1);

    return 0;
}
