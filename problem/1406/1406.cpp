#include <iostream>
#include <list>

using namespace std;

int main() {
    int n;
    char cmd;
    string input;
    cin >> input;

    list<char> l(input.begin(), input.end());

    cin >> n;
    auto cursor = l.end();

    while(n--) {
        cin >> cmd;

        if(cmd == 'L') {
            if(cursor != l.begin())
                cursor--;
        }

        else if(cmd == 'D') {
            if(cursor != l.end())
                cursor++;
        }

        else if(cmd == 'B') {
            if(cursor != l.begin()) {
                auto temp = cursor;
                cursor--;
                l.erase(cursor);
                cursor = temp;
            }
        }

        else {
            char c;
            cin >> c;
            l.insert(cursor, c);
        }
    }

    for(char c : l)
        cout << c;

    return 0;
}

