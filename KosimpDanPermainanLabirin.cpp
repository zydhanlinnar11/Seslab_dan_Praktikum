#include <bits/stdc++.h>
using namespace std;

typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
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

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

BSTNode* __bst__remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = __bst__remove(root->right, value);
    else if (value < root->key) 
        root->left = __bst__remove(root->left, value);
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

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%d ", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}

BSTNode* getparent(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key) {
            if(root->left && root->left->key == value) return root;
            root = root->left;
        } else if (value > root->key) {
            if(root->right && root->right->key == value) return root;
            root = root->right;
        }
    }
    return root;
}

typedef pair<int, int> pii;
#define mp(x, y) make_pair(x, y)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    BST set;
    bst_init(&set);
    int k, r;
    cin>>k>>r;
    bst_insert(&set, r);
    map<int, vector<pii>> adjList;
    for(int i=0; i<k-1; i++) {
        int n, j;
        cin>>n>>j;
        bst_insert(&set, n);
        int par = getparent(set._root, n)->key;
        adjList[par].push_back(mp(j, n));
        adjList[n].push_back(mp(j, par));
    }
    int t;
    cin>>t;
    while(t--) {
        int p;
        cin>>p;
        BSTNode * nodeOfP = __bst__search(set._root, p);
        if(nodeOfP == NULL || nodeOfP->right == NULL && nodeOfP->left == NULL) {
            cout<<"0\n";
            continue;
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push(mp(0, p));
        map<int, bool> visited;
        while(!pq.empty()) {
            auto currNode = pq.top();
            pq.pop();
            auto nodeOfCurr = __bst__search(set._root, currNode.second);
            if(nodeOfCurr->right == NULL && nodeOfCurr->left == NULL) {
                cout<<currNode.first<<'\n';
                break;
            }
            for(int i=0; i<adjList[currNode.second].size(); i++) {
                auto dest = mp(adjList[currNode.second][i].first + currNode.first, adjList[currNode.second][i].second);
                if(visited[dest.second]) continue;
                pq.push(dest);
            }
        }
    }
}