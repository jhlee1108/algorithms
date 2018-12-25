#include <cstdio>
#include <algorithm>

using namespace std;

int N, num[500000], cnt[8001];

int main() {
    scanf("%d", &N);

    int sum = 0;
    int max_cnt = 0;
    for(int i=0; i<N; i++) {
        scanf("%d", &num[i]);
        sum += num[i];
        cnt[num[i]+4000]++;
        max_cnt = max(max_cnt, cnt[num[i]+4000]);
    }

    sort(num, num+N);

    int k = 0;
    int max_cnt_num;
    for(int i=0; i<=8000; i++) {
        if(cnt[i] == max_cnt) {
            k++;
            max_cnt_num = i-4000;
            if(k == 2) break;
        }
    }

    printf("%.0lf\n%d\n%d\n%d\n", (double)sum/(double)N, num[N/2], max_cnt_num, num[N-1] - num[0]);

    return 0;
}
