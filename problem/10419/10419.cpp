#include <cstdio>

int T, d;

int main() {
    scanf("%d", &T);

    while(T--) {
        scanf("%d", &d);
           
        for(int i=1; i<=d; i++)
            if(i+i*i > d) {
                printf("%d\n", i-1);
                break;
            }
    }

    return 0;
}

