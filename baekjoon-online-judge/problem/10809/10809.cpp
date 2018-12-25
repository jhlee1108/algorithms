#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string input;

    cin >> input;

    for(char c='a'; c<='z'; c++) {
        auto it = find(input.begin(), input.end(), c);
        
        if(it == input.end())
            cout << "-1 ";
        else
            cout << it - input.begin() << ' ';
    }

    return 0;
}
