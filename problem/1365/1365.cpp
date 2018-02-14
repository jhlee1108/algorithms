#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, x;
vector<int> v;

int main() {
    scanf("%d", &N);

    v.push_back(0);
    for(int i=0; i<N; i++) {
        scanf("%d", &x);
        if(v.back() < x) v.push_back(x);
        else *lower_bound(v.begin(), v.end(), x) = x;
    }

    printf("%d\n", N-v.size()+1);

    return 0;
}
