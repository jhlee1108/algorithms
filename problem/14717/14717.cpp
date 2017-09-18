#include <cstdio>
#include <algorithm>

using namespace std;

int A, B, cards[11];

int main() {
    fill(cards, cards+11, 2);
    scanf("%d %d", &A, &B);
    cards[A]--; cards[B]--;

    int my_score = (A == B ? A*10 : (A+B)%10);
    int cnt = 0;
    for(int i=1; i<11; i++) {
        if(cards[i] > 0) {
            cards[i]--;
            for(int j=1; j<11; j++) {
                if(cards[j] > 0) {
                    int score = (i == j ? i*10 : (i+j)%10);
                    if(my_score > score) {
                        if(cards[i] == 1 && cards[j] == 2) cnt += 2;
                        else cnt++;
                    }
                }
            }
            cards[i]++;
        }
    }

    printf("%.3f\n", float(cnt)/153.0);

    return 0;
}
