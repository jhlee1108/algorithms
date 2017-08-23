#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<string> dq;

int main() {
    int t; cin >> t;

    while(t--) {
        while(!dq.empty()) dq.pop_front();
        string command; cin >> command;
        int n; cin >> n;
        string arr; cin >> arr;

        string number = "";
        for(int i=1; i<arr.size(); i++) {
            if(number.size() != 0 && (arr[i] == ',' || arr[i] == ']')) {
                dq.push_back(number);
                number = "";
            }
            else number += arr[i];
        }
        
        bool rev = false;
        for(int i=0; i<command.size(); i++) {
            char c = command[i];

            if(c == 'R')
                rev = !rev;

            else {
                if(dq.size() == 0) {
                    dq.push_back("error");
                    break;
                }
                if(rev) dq.pop_back();
                else dq.pop_front();
            }
        }

        if(dq.size() == 1 && dq.front() == "error") cout << "error";
        else {
            string ans = "";
            ans += '[';
            if(rev) reverse(dq.begin(), dq.end());
            while(!dq.empty()) {
                ans += (dq.front() + ',');
                dq.pop_front();
            }
            if(ans.size() == 1) ans += ']';
            else ans[ans.size()-1] = ']';
            cout << ans;
        }
        cout << '\n';
    }

    return 0;
}
