#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int a[9] = {0,};
    int sum = 0;

    for(int i=0; i<9; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    sort(a, a+9);

    for(int i=0; i<8; i++) {
        for(int j=i+1; j<9; j++) {
            int temp = sum;
            temp -= a[i];
            temp -= a[j];
            if(temp == 100)
                for(int k=0; k<9; k++)
                    if(k != i && k != j)
                        printf("%d\n", a[k]);
        }
    }

    return 0;
}
