#include <iostream>

using namespace std;

int N;
string name;

int main() {
    cin >> N;
    getline(cin, name);

    while(N--) {
        getline(cin, name);

        int score = 0;
        for(int i=0; i<name.size(); i++)
            if('A' <= name[i] && name[i] <= 'Z') score += name[i] - 'A' + 1;

        if(score == 100) cout << "PERFECT LIFE" << '\n';
        else cout << score << '\n';
    }

    return 0;
}
