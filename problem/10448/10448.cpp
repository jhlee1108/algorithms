#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    vector<int> v;

    for(int i=1; (i*(i+1))/2<=1000; i++)
        v.push_back((i*(i+1))/2);

    while(t--) {
        int x; scanf("%d", &x);
        bool is_tri = false;
        
        for(int i=0; i<v.size(); i++) {
            for(int j=0; j<v.size(); j++) {
                for(int k=0; k<v.size(); k++) {
                    if(v[i] + v[j] + v[k] > x) break;
                    if(v[i] + v[j] + v[k] == x) is_tri = true;
                    if(is_tri) break;
                }
                if(is_tri) break;
            }
            if(is_tri) break;
        }

        puts(is_tri ? "1" : "0");
    }

    return 0;
}
