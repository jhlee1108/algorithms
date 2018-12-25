#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, m;
    queue<int> q;

    cin >> n >> m;
    
    for(int i=1; i<=n; i++)
        q.push(i);

    cout << '<';

    while(n--) {
        for(int i=1; i<m; i++) {
            q.push(q.front());
            q.pop();
        }

        cout << q.front();
        q.pop();

        if(!q.empty())
            cout << ", ";

    }

    cout << '>';

    return 0;
}

