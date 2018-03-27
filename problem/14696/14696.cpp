#include <cstdio>
#include <cstring>

int N, a, b, d, da[5], db[5];

int main() {
    scanf("%d", &N);

    while(N--) {
        memset(da, 0, sizeof(da));
        memset(db, 0, sizeof(db));
        
        scanf("%d", &a);
        while(a--) {
            scanf("%d", &d);
            da[d]++;
        }

        scanf("%d", &b);
        while(b--) {
            scanf("%d", &d);
            db[d]++;
        }

        if(da[4] != db[4]) puts(da[4] > db[4] ? "A" : "B");
        else if(da[3] != db[3]) puts(da[3] > db[3] ? "A" : "B");
        else if(da[2] != db[2]) puts(da[2] > db[2] ? "A" : "B");
        else if(da[1] != db[1]) puts(da[1] > db[1] ? "A" : "B");
        else puts("D");
    }

    return 0;
}
