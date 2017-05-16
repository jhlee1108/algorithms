#include <cstdio>

int main() {
    long long x, y;

    while(scanf("%lld %lld\n", &x, &y) == 2) {
        long long z = (y*100) / x;
        if(z >= 99)
            printf("-1\n");
        else {
            long long i=0;
            long long j=1000000000;

            while(i <= j) {
                long long mid = (i+j)/2;
                long long t = ((y+mid)*100)/(x+mid);
                if(z<t)
                    j = mid-1;
                else
                    i = mid+1;
            }

            printf("%lld\n", i);
        }
    }

    return 0;
}
