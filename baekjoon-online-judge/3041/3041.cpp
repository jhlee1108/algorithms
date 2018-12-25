#include <cstdio>
#include <cmath>

using namespace std;

char c;
int x, y, ans;

int main() {
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++) {
            scanf("%c\n", &c);
            if(c != '.') {
                x = (c - 'A') % 4;
                y = (c - 'A') / 4;
                ans += (abs(x - j) + abs(y - i));
            }
        }
    
    printf("%d\n", ans);

    return 0;
}
