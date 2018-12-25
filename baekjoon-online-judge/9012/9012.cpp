#include <iostream>
#include <stack>

using namespace std;

int main() {
    int t; cin >> t;
    
    while(t--) {
        string input; cin >> input;
        stack<char> s;
        int is_vps = true;
        
        for(int i=0; i<input.size(); i++) {
            char c = input[i];

            if(c == '(') s.push(c);
            else {
                if(s.empty()) {
                    is_vps = false;
                    break;
                }

                char top = s.top();
                if(top == '(') s.pop();
                else {
                    is_vps = false;
                    break;
                }
            }
        }

        if(!s.empty()) is_vps = false;

        if(is_vps) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
