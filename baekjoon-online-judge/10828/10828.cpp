#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, x;
    string cmd;
    stack<int> s;

    cin >> n;

    while(n--) {
        cin >> cmd;

        if(cmd == "push") {
            cin >> x;
            s.push(x);
        }

        else if(cmd == "pop") {
            if(s.size() != 0) {
                cout << s.top() << '\n';
                s.pop();
            }
            else
                cout << -1 << '\n';
        }

        else if(cmd == "size") {
            cout << s.size() << '\n';
        }

        else if(cmd == "empty") {
            cout << s.empty() << '\n';
        }

        else {
            if(s.size() != 0)
                cout << s.top() << '\n';
            else
                cout << -1 << '\n';
        }
    }

    return 0;
}
