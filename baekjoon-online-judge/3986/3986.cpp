#include <iostream>
#include <stack>

using namespace std;

stack<char> s;

int main() {
    int n; cin >> n;
    int ans = 0;

    while(n--) {
        string input; cin >> input;
        while(!s.empty()) s.pop();
        
        for(int i=0; i<input.size(); i++) {
            if(!s.empty() && s.top() == input[i]) s.pop();
            else s.push(input[i]);
        }

        if(s.empty()) ans++;
    }

    cout << ans << '\n';

    return 0;
}
