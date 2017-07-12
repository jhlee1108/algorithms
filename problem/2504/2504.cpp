#include <iostream>
#include <stack>

using namespace std;

int main() {
    string input; cin >> input;
    stack<char> s;
    stack<int> t;
    int ans = 0;

    for(int i=0; i<input.size(); i++) {
        char c = input[i];
        int ps = 0;

        if(c == '(' || c == '[') {
            s.push(c);
            t.push(1);
        }

        else {
            if(s.empty()) {
                ans = 0;
                break;
            }

            if(c == ')' && s.top() == '(') {
                while(t.top() != 1) {
                    ps += t.top();
                    t.pop();
                }
                if(ps == 0) ps = 2;
                else ps *= 2;
                s.pop();
                t.pop();
                t.push(ps);
            }

            else if(c == ']' && s.top() == '[') {
                while(t.top() != 1) {
                    ps += t.top();
                    t.pop();
                }
                if(ps == 0) ps = 3;
                else ps *= 3;
                s.pop();
                t.pop();
                t.push(ps);
            }

            else {
                ans = 0;
                break;
            }
        }
    }

    if(!s.empty()) ans = 0;
    else {
        while(!t.empty()) {
            ans += t.top();
            t.pop();
        }
    }

    cout << ans << '\n';

    return 0;
}
