#include <iostream>

#define MIN(A, B) A < B ? A : B

using namespace std;

string A, B;

int main() {
    cin >> A >> B;
    int ans = 1e9;

    for(int i=0; i<=B.size()-A.size(); i++) {
        int cnt = 0;
        for(int j=0; j<A.size(); j++)
            if(A[j] != B[j+i]) cnt++;
        ans = MIN(ans, cnt);
    }

    cout << ans << '\n';

    return 0;
}
