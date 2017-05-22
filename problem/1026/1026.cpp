#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> a;
    vector<int> b;

    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }

    for(int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        b.push_back(x);
    }

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());

    int s = 0;
    for(int i=0; i<n; i++)
        s += (a[i]*b[i]);

    printf("%d\n", s);

    return 0;
}
