#include <cstdio>
#include <cmath>

using namespace std;

int score[10];

int main() {
    int ans = 0;
    for(int i=0; i<10; i++)
        scanf("%d", &score[i]);

    for(int i=0; i<10; i++) {
        int psum = 0;
        for(int j=0; j<10; j++) {
            if(abs(psum-100) >= abs(psum+score[j]-100))
                psum += score[j];
            else
                break;
        }
        if(abs(ans-100) > abs(psum-100) || (abs(ans-100) == abs(psum-100) && ans < psum))
            ans = psum;
    }

    printf("%d\n", ans);

    return 0;
}
