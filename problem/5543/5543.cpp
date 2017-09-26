#include <cstdio>

int main() {
    int burger = 10000, drink = 10000;

    for(int i=0; i<3; i++) {
        int x; scanf("%d", &x);
        if(burger > x) burger = x;
    }

    for(int i=0; i<2; i++) {
        int x; scanf("%d", &x);
        if(drink > x) drink = x;
    }

    printf("%d\n", burger+drink-50);

    return 0;
}
