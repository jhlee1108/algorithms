#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, input;
    int max_sum = INT_MIN;
    int sum = 0;

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &input);

        if(sum < 0)
            sum = input;
        else
            sum = sum + input;

        max_sum = max(max_sum, sum);
    }

    printf("%d", max_sum);

    return 0;
}

