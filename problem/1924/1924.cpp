#include <cstdio>

int main() {
    int x, y;
    int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int n = 0;

    scanf("%d %d", &x, &y);
    
    for(int i=2; i<=x; i++) {
        n += month[i-1];
    }

    n += (y-1);

    switch(n%7) {
        case 0:
            printf("MON");
            break;
        case 1:
            printf("TUE");
            break;
        case 2:
            printf("WED");
            break;
        case 3:
            printf("THU");
            break;
        case 4:
            printf("FRI");
            break;
        case 5:
            printf("SAT");
            break;
        case 6:
            printf("SUN");
            break;
        default:
            break;
    }

    return 0;
}
