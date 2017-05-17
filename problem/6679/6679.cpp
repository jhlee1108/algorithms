#include <cstdio>

int main() {
    for(int i=1000; i<=9999; i++) {
        int x = i/1000 + (i%1000)/100 + (i%100)/10 + (i%10);
        int y = i/1728 + (i%1728)/144 + (i%144)/12 + (i%12);
        int z = i/4096 + (i%4096)/256 + (i%256)/16 + (i%16);
        if(x == y && y == z)
            printf("%d\n", i);
    }

    return 0;
}
