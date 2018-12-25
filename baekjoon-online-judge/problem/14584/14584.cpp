#include <iostream>
#include <vector>

using namespace std;

string cryptograph;
vector<string> dict;
int N;

int main() {
    cin >> cryptograph;
    cin >> N;
    for(int i=0; i<N; i++) {
        string s; cin >> s;
        dict.push_back(s);
    }

    bool is_correct = false;
    for(int i=0; i<26; i++) {
        for(int j=0; j<dict.size(); j++) {
            if(cryptograph.find(dict[j]) != string::npos) {
                cout << cryptograph << '\n';
                is_correct = true;
                break;
            }
        }

        if(is_correct) break;

        for(int j=0; j<cryptograph.size(); j++) {
            cryptograph[j] = ((cryptograph[j] - 'a' + 1) % 26) + 'a';
        }
    }

    return 0;
}
