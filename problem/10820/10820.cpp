#include <iostream>

using namespace std;

int main() {
    string s;

    while(getline(cin, s)) {
        int lower = 0;
        int upper = 0;
        int number = 0;
        int space = 0;

        for(char c : s) {
            if('a' <= c && c <= 'z')
                lower++;
            else if('A' <= c && c <= 'Z')
                upper++;
            else if('0' <= c && c <= '9')
                number++;
            else if(c == ' ')
                space++;
        }

        cout << lower << ' ' << upper << ' ' << number << ' ' << space << '\n';
    }

    return 0;
}
