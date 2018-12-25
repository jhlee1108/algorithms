#include <cstdio>
#include <cstring>

using namespace std;

struct Trie {
    Trie *go[10];
    bool output, goexist;

    Trie() {
        memset(go, 0, sizeof(go));
        output = goexist = false;
    }

    ~Trie() {
        for(int i=0; i<10; i++)
            if(go[i]) delete go[i];
    }

    bool insert(const char *key) {
        if(*key == '\0') {
            output = true;
            return goexist;
        }

        int next = *key - '0';

        if(!go[next]) go[next] = new Trie;
        goexist = true;
        
        return output || go[next]->insert(key+1);
    }
};

int main() {
    int t, n;

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);
        
        Trie *root = new Trie;
        bool result = true;

        while(n--) {
            char tel[11];
            scanf("%s", tel);
            if(result && root->insert(tel)) result = false;
        }

        puts(result ? "YES" : "NO");
        delete root;
    }
    
    return 0;
}
