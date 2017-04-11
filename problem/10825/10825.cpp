#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Person {
    string name;
    int kor, eng, math;
};

bool cmp(const Person &a, const Person &b) {
    if(a.kor > b.kor)
        return true;
    else if(a.kor == b.kor) {
        if(a.eng < b.eng)
            return true;
        else if(a.eng == b.eng) {
            if(a.math > b.math)
                return true;
            else if(a.math == b.math)
                return a.name < b.name;
        }
    }

    return false;
}


int main() {
    int n;

    cin >> n;
    vector<Person> v(n);

    for(int i=0; i<n; i++)
        cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;

    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<n; i++)
        cout << v[i].name << '\n';

    return 0;
}
