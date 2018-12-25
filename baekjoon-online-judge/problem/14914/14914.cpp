#include <cstdio>
#include <algorithm>

using namespace std;

int a, b;

int main() {
    scanf("%d %d", &a, &b);

    for(int i=1; i<=min(a,b); i++)
        if(a % i == 0 && b % i == 0)
            printf("%d %d %d\n", i, a/i, b/i);

    return 0;
}
