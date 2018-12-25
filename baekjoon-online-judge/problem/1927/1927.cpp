#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, input;
    priority_queue<int, vector<int>, greater<int>> q;

    cin >> n;

    while(n--) {
        cin >> input;

        if(input == 0) {
            if(q.empty())
                cout << 0 << '\n';
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        }

        else
            q.push(input);
    }

    return 0;
}

