#include <iostream>
#include <cstring>

using namespace std;

int T, acnt[26], bcnt[26];
string A, B;

int main() {
    cin >> T;

    while(T--) {
        memset(acnt, 0, sizeof(acnt));
        memset(bcnt, 0, sizeof(bcnt));
        cin >> A >> B;
        
        for(int i=0; i<A.size(); i++)
            acnt[A[i]-'a']++;
        for(int i=0; i<B.size(); i++)
            bcnt[B[i]-'a']++;

        bool is_anagram = true;
        for(int i=0; i<26; i++)
            if(acnt[i] != bcnt[i]) is_anagram = false;

        if(is_anagram) cout << A << " & " << B << " are anagrams.\n";
        else cout << A << " & " << B << " are NOT anagrams.\n";
    }

    return 0;
}
