#include <iostream>
#include <stack>

using namespace std;

stack<double> s;
int n;
double x[26];

double calculate(double a, double b, char op) {
    double ret = 0;

    switch(op) {
        case '+':
            ret = a + b;
            break;
        case '-':
            ret = a - b;
            break;
        case '*':
            ret = a * b;
            break;
        case '/':
            ret = a / b;
            break;
    }

    return ret;
}

int main() {
    cin >> n;
    string input; cin >> input;
    for(int i=0; i<n; i++)
        cin >> x[i];

    for(int i=0; i<input.size(); i++) {
        char c = input[i];

        if('A' <= c && c <= 'Z') s.push(x[c-'A']);
        else {
            double b = s.top(); s.pop();
            double a = s.top(); s.pop();
            s.push(calculate(a, b, c));
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << s.top() << '\n';

    return 0;
}
