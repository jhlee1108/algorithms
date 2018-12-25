#include <iostream>

using namespace std;

string A, B, op;

int main() {
    cin >> A >> op >> B;

    if(op == "*") {
        cout << 1;
        for(int i=0; i<A.size()+B.size()-2; i++)
            cout << 0;
    }

    else {
        if(A.size() == B.size()) {
            A[0] = '2';
            cout << A;
        }
        
        else {
            if(A.size() > B.size()) {
                A[A.size() - B.size()] = '1';
                cout << A;
            }

            else {
                B[B.size() - A.size()] = '1';
                cout << B;
            }
        }
    }

    cout << '\n';

    return 0;
}
