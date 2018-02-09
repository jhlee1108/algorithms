#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int na, nb, x;
set<int> A, B, result;

int main() {
    scanf("%d %d", &na, &nb);
    for(int i=0; i<na; i++) {
        scanf("%d", &x);
        A.insert(x);
    }
    for(int i=0; i<nb; i++) {
        scanf("%d", &x);
        B.insert(x);
    }

    set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(result, result.end()));
    printf("%d\n", int(result.size()));

    return 0;
}
