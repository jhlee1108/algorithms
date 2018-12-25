#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int a[4];

    for(int i=0; i<4; i++)
        scanf("%d", &a[i]);

    sort(a, a+4);

    printf("%d\n", a[0]*a[2]);

    return 0;
}
