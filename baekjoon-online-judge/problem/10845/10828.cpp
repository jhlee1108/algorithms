#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, x;
    string cmd;
    queue<int> q;

    cin >> n;

    while(n--) {
        cin >> cmd;

        if(cmd == "push") {
            cin >> x;
            q.push(x);
        }

        else if(cmd == "pop") {
            if(!q.empty()) {
                cout << q.front() << '\n';
                q.pop();
            }
            else
                cout << -1 << '\n';
        }

        else if(cmd == "size") {
            cout << q.size() << '\n';
        }

        else if(cmd == "empty") {
            cout << q.empty() << '\n';
        }

        else if(cmd == "front") {
            if(!q.empty())
                cout << q.front() << '\n';
            else
                cout << -1 << '\n';
        }

        else {
            if(!q.empty())
                cout << q.back() << '\n';
            else
                cout << -1 << '\n';
        }
    }

    return 0;
}
