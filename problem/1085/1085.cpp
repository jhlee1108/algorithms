#include <cstdio>
#include <algorithm>

using namespace std;

int x, y, w, h;

int main() {
    scanf("%d %d %d %d", &x, &y, &w, &h);
    printf("%d\n", min(min(x,w-x), min(y,h-y)));

    return 0;
}
