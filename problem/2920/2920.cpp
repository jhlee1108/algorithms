#include <cstdio>

int main() {
    int a[8];

    for(int i=0; i<8; i++)
        scanf("%d", &a[i]);

    int state;
    if(a[0] < a[1]) state = 0;
    else state = 1;

    for(int i=1; i<8; i++) {
        if(state == 0 && a[i-1] < a[i]) continue;
        else if(state == 1 && a[i-1] > a[i]) continue;
        state = 2;
    }

    if(state == 0) printf("ascending\n");
    else if(state == 1) printf("descending\n");
    else printf("mixed\n");

    return 0;
}
