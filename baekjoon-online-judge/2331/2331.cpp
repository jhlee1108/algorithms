#include <cstdio>
#include <cmath>

int main() {
    int a, p, u, v, w, x, y, z;
    int sequence[237000] = {0};
    int sequence_number = 1;

    scanf("%d %d", &a, &p);

    while(true) {
        if(sequence[a] != 0)
            break;

        sequence[a] = sequence_number++;
        u = pow(a/100000, p);
        v = pow((a%100000)/10000, p);
        w = pow((a%10000)/1000, p);
        x = pow((a%1000)/100, p);
        y = pow((a%100)/10, p);
        z = pow(a%10, p);
        a = u + v + w + x + y + z;
    }

    printf("%d", sequence[a]-1);

    return 0;
}

