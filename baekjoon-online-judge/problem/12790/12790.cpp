#include <cstdio>
#include <algorithm>

using namespace std;

int T;

int main() {
    scanf("%d", &T);

    while(T--) {
        int hp, mp, atk, def;
        scanf("%d %d %d %d", &hp, &mp, &atk, &def);

        int item_hp, item_mp, item_atk, item_def;
        scanf("%d %d %d %d", &item_hp, &item_mp, &item_atk, &item_def);
        
        hp = max(hp+item_hp, 1);
        mp = max(mp+item_mp, 1);
        atk = max(atk+item_atk, 0);
        def += item_def;

        printf("%d\n", hp+5*mp+2*atk+2*def);
    }

    return 0;
}
