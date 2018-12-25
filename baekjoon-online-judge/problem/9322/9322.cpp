#include <iostream>
#include <algorithm>

#define PII pair<int, int>

using namespace std;

PII sp[1000];
int T, N;
string fp[1000], ct[1000], s;

int main() {
    cin >> T;

    while(T--) {
        cin >> N;
        for(int i=0; i<N; i++)
            cin >> fp[i];
        for(int i=0; i<N; i++) {
            cin >> s;
            for(int j=0; j<N; j++)
                if(fp[j] == s) {
                    sp[i] = make_pair(j, i);
                    break;
                }
        }
        for(int i=0; i<N; i++)
            cin >> ct[i];
        
        sort(sp, sp+N);

        for(int i=0; i<N; i++)
            cout << ct[sp[i].second] << ' ';
        cout << '\n';
    }

    return 0;
}
