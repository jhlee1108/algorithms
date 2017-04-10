#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b, c;
    int max_point[2][3] = {0,};
    int min_point[2][3] = {0,};

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> a >> b >> c;

        max_point[i%2][0] = max(max_point[(i+1)%2][0], 
                                    max_point[(i+1)%2][1]) + a;
        max_point[i%2][1] = max(max_point[(i+1)%2][0], 
                                    max(max_point[(i+1)%2][1], max_point[(i+1)%2][2])) + b;
        max_point[i%2][2] = max(max_point[(i+1)%2][1], 
                                    max_point[(i+1)%2][2]) + c;

        min_point[i%2][0] = min(min_point[(i+1)%2][0], 
                                    min_point[(i+1)%2][1]) + a;
        min_point[i%2][1] = min(min_point[(i+1)%2][0], 
                                    min(min_point[(i+1)%2][1], min_point[(i+1)%2][2])) + b;
        min_point[i%2][2] = min(min_point[(i+1)%2][1], 
                                    min_point[(i+1)%2][2]) + c;
    }

    int ans_max = max(max_point[(n-1)%2][0], 
                        max(max_point[(n-1)%2][1], max_point[(n-1)%2][2]));
    int ans_min = min(min_point[(n-1)%2][0], 
                        min(min_point[(n-1)%2][1], min_point[(n-1)%2][2]));
    
    cout << ans_max << ' ' << ans_min << endl;

    return 0;
}
