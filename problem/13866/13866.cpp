#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int level[4];

int main() {
    for(int i=0; i<4; i++)
        scanf("%d", &level[i]);
    
    sort(level, level+4);

    printf("%d\n", abs((level[0]+level[3]) - (level[1]+level[2])));

    return 0;
}
