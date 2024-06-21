#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Hàm thêm một nút vào BST
TreeNode* insertBST(TreeNode* root, int value) {
    if (!root) {
        return new TreeNode(value);
    }
    if (value < root->val) {
        root->left = insertBST(root->left, value);
    } else {
        root->right = insertBST(root->right, value);
    }
    return root;
}

// Hàm tìm LCA của hai nút trong BST
TreeNode* findLCA(TreeNode* root, int A, int B) {
    if (!root) return NULL;
    if (root->val > A && root->val > B) {
        return findLCA(root->left, A, B);
    } else if (root->val < A && root->val < B) {
        return findLCA(root->right, A, B);
    }
    return root;
}

// Hàm tìm min và max trên đường đi từ root đến given key
void findMinMaxOnPath(TreeNode* root, int key, int &minVal, int &maxVal) {
    while (root && root->val != key) {
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);
        if (key < root->val) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    // Include the key node itself
    minVal = min(minVal, key);
    maxVal = max(maxVal, key);
}

int main() {
        if(fopen("input.txt", "r")) {
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    
        ios::sync_with_stdio(0);
        cin.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> values(N);
    for (int i = 0; i < N; ++i) {
        cin >> values[i];
    }

    TreeNode* root = NULL;
    for (int value : values) {
        root = insertBST(root, value);
    }

    int A, B;
    cin >> A >> B;


    TreeNode* lca = findLCA(root, A, B);


    int minVal = numeric_limits<int>::max();
    int maxVal = numeric_limits<int>::min();
    // cout << minVal << ' ' << maxVal << endl;
    findMinMaxOnPath(lca, A, minVal, maxVal);
    findMinMaxOnPath(lca, B, minVal, maxVal);

    cout << minVal << " " << maxVal << endl;

    return 0;
}