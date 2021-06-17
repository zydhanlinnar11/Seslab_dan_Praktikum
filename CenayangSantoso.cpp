#include <bits/stdc++.h>
using namespace std;

/* Node structure */

struct BSTNode {
    BSTNode *left, *right;
    int key;
};

/* uniqueBST */

struct BST {
    // Member
    BSTNode *_root;
    unsigned int _size;

    // Function
    void init() {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;
        
        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value) {
        if (!find(value)) {
            _root = __insert(_root, value);
            _size++;
        }
    }

    void remove(int value) {
        if (find(value)) {
            _root = __remove(_root, value);
            _size++;
        }
    }

    void traverseInorder() {
        __inorder(_root);
    }

    // void traversePreorder() {
    //     __preorder(_root);
    // }

    void traversePostorder() {
        __postorder(_root);
    }

    void removee(set<int> &nodeval) {
        if(this->_root == NULL) return;
        BSTNode * root = this->_root;
        if (!root)
            return;
    
        queue<BSTNode *> q;
        q.push(root);
    
        while (!q.empty()) {
            int n = q.size();
            
            for(int i = 1; i <= n; i++)
            {
                BSTNode * temp = q.front();
                q.pop();
                if (i == 1 || i == n)
                    nodeval.erase(temp->key);
                if (temp->left != NULL)
                    q.push(temp->left);
                    
                if (temp->right != NULL)
                    q.push(temp->right);
            }
        }
        this->__preordermod(nodeval, this->_root);
    }

private:
    // Utility Function
    BSTNode* __createNode(int value) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    
    BSTNode* __search(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode* __insert(BSTNode *root, int value) {
        if (root == NULL)
            return __createNode(value);
        
        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);
        
        return root;
    }

    BSTNode* __findMinNode(BSTNode *node) {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        
        return currNode;
    }

    BSTNode* __remove(BSTNode *root, int value) {
        if (root == NULL) return NULL;

        if (value > root->key) 
            root->right = __remove(root->right, value);
        else if (value < root->key) 
            root->left = __remove(root->left, value);
        else {

            if (root->left == NULL) {
                BSTNode *rightChild = root->right;
                free(root);
                return rightChild;
            }
            else if (root->right == NULL) {
                BSTNode *leftChild = root->left;
                free(root);
                return leftChild;
            }

            BSTNode *temp = __findMinNode(root->right);
            root->key     = temp->key;
            root->right   = __remove(root->right, temp->key);
        }
        return root;
    }

    void __inorder(BSTNode *root) {
        if (root) {
            __inorder(root->left);
            printf("%d ", root->key);
            __inorder(root->right);
        }
    }

    void __postorder(BSTNode *root) {
        if (root) {
            __postorder(root->left);
            __postorder(root->right);
            printf("%d ", root->key);
        }
    }

    void __preordermod(set<int> &nodeval, BSTNode *root) {
        if (root) {
            // printf("%d ", root->key);
            __preordermod(nodeval, root->left);
            __preordermod(nodeval, root->right);
            if(root->left == NULL && root->right == NULL && nodeval.find(root->key) != nodeval.end()) nodeval.erase(root->key);
        }
    }

    void _removeleft(set<int> &nodeval, BSTNode * root) {
        if(nodeval.find(root->key) != nodeval.end())
            nodeval.erase(root->key);
        if(root->left) _removeleft(nodeval, root->left);
    }

    void _removeright(set<int> &nodeval, BSTNode * root) {
        if(nodeval.find(root->key) != nodeval.end())
            nodeval.erase(root->key);
        if(root->right) _removeright(nodeval, root->right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    set<int> nodeval;
    BST set;
    set.init();
    for(int i=0; i<n; i++) {
        int tmp;
        cin>>tmp;
        nodeval.insert(tmp);
        set.insert(tmp);   
    }
    set.removee(nodeval);
    if(nodeval.size() == 0) {
        cout<<"Yah, gk ada posisi yang aman :(\n";
    } else {
        int it = 0;
        for(auto i=nodeval.begin(); i != nodeval.end(); i++, it++) {
            cout<<*i<<" \n"[it == nodeval.size() - 1];
        }
    }
}