#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int k;

int main() {
    scanf("%d", &k);
    for(int i=0; i<k; i++) {
        int a; scanf("%d", &a);
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    printf("%d\n", v[0]*v[v.size()-1]);

    return 0;
}
