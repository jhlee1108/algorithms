#include <cstdio>
#include <vector>

using namespace std;

int k, ans;
vector<int> v;

int main() {
    scanf("%d", &k);
    
    v.push_back(0);
    int n;
    while(scanf("%d", &n) == 1) {
        v.push_back(n);
        ans += n;
    }

    for(int i=v.size()-1; i>0; i-=2) {
        int diff, max_value;

        if(v[i] > v[i-1]) {
            diff = v[i] - v[i-1];
            max_value = v[i];
        }

        else {
            diff = v[i-1] - v[i];
            max_value = v[i-1];
        }

        v[(i-1)/2] += max_value;
        ans += diff;
    }

    printf("%d\n", ans);

    return 0;
}
