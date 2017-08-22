#include <iostream>
#include <stack>

using namespace std;

stack<char> s;

int main() {
    string input; cin >> input;

    for(int i=0; i<input.size(); i++) {
        char c = input[i];

        switch(c) {
            case '+':
            case '-':
                while (!(s.empty() || s.top() == '(')) {
                    cout << s.top();
                    s.pop();
                }
                s.push(c);
                break;
            case '*':
            case '/':
                while(!(s.empty() || s.top() == '(' || s.top() == '+' || s.top() == '-')) {
                    cout << s.top();
                    s.pop();
                }
            case '(':
                s.push(c);
                break;
            case ')':
                while(s.top() != '(') {
                    cout << s.top();
                    s.pop();
                }
                s.pop();
                break;
            default:
                cout << c;
        }
    }

    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }

    cout << '\n';

    return 0;
}
