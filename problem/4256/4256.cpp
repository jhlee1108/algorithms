#include <cstdio>
#include <cstring>
#include <vector>

#define PII pair<int,int>

using namespace std;

int T, n, preorder[1000], inorder[1000], check[1000];
vector<PII> BT(1001);

void postorder(int root) {
    if(BT[root].first != -1) postorder(BT[root].first);
    if(BT[root].second != -1) postorder(BT[root].second);
    printf("%d ", root);
}

int make_tree(int left, int right) {
    if(left >= right) return -1;
    
    int root = -1;
    for(int i=0; i<n; i++)
        if(!check[i]) {
            check[i] = 1;
            root = preorder[i];
            break;
        }

    if(left+1 == right) return root;

    int mid = -1;
    for(int i=left; i<right; i++)
        if(inorder[i] == root) mid = i;

    BT[root].first = make_tree(left, mid);
    BT[root].second = make_tree(mid+1, right);

    return root;
}

int main() {
    scanf("%d", &T);

    while(T--) {
        scanf("%d", &n);
        memset(check, 0, sizeof(check));
        for(int i=1; i<=n; i++)
            BT[i].first = BT[i].second = -1;
        for(int i=0; i<n; i++)
            scanf("%d", &preorder[i]);
        for(int i=0; i<n; i++)
            scanf("%d", &inorder[i]);

        postorder(make_tree(0, n));
        printf("\n");
    }

    return 0;
}
