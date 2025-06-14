#include <iostream>
using namespace std;
#define T 3
class BTreeNode {
    int *keys; 
    int t; 
    BTreeNode **C; 
    int n; 
    bool leaf; 
    public:
    BTreeNode(bool leaf);
    void traverse();
    BTreeNode *search(int k);
    void insertNonFull(int k);
    void splitChild(int i, BTreeNode *y);
    friend class BTree;
};
class BTree {
    BTreeNode *root; 
    int t; 
    public:
    BTree() { root = NULL; t = T; }
    void traverse() { if (root != NULL) root->traverse(); }
    BTreeNode* search(int k) { return (root == NULL) ? NULL : root->search(k); }
    void insert(int k);
};
BTreeNode::BTreeNode(bool leaf1) {
    t = T;
    leaf = leaf1;
    keys = new int[2 * t - 1];
    C = new BTreeNode *[2 * t];
    n = 0;
}
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) 
    {
        if (!leaf)
            C[i]->traverse();
        cout << " " << keys[i];
    }   
    if (!leaf)
        C[i]->traverse();
}
BTreeNode *BTreeNode::search(int k) 
{
    int i = 0;
    while (i < n && k > keys[i])
        i++;
        if (keys[i] == k)
            return this;
    if (leaf)
        return NULL;
    return C[i]->search(k);
}

void BTreeNode::insertNonFull(int k) 
{
    int i = n - 1;
    if (leaf) 
    {
        while (i >= 0 && keys[i] > k) 
        {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        n = n + 1;
    } 
    else 
    {
    while (i >= 0 && keys[i] > k)
        i--;
    if (C[i + 1]->n == 2 * t - 1) 
    {
        splitChild(i + 1, C[i + 1]);
        if (keys[i + 1] < k)
        i++;
    }
    C[i + 1]->insertNonFull(k);
    }
}
void BTreeNode::splitChild(int i, BTreeNode *y) 
{
    BTreeNode *z = new BTreeNode(y->leaf);
    z->n = t - 1;
    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];
    if (!y->leaf) 
    {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }
    y->n = t - 1;
    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];
    C[i + 1] = z;
    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];
    keys[i] = y->keys[t - 1];
    n = n + 1;
}
void BTree::insert(int k) 
{
    if (root == NULL) 
    {
        root = new BTreeNode(true);
        root->keys[0] = k;
        root->n = 1;
    } 
    else 
    {
    if (root->n == 2 * t - 1) 
    {
        BTreeNode *s = new BTreeNode(false);
        s->C[0] = root;
        s->splitChild(0, root);
        int i = 0;
        if (s->keys[0] < k)
            i++;
        s->C[i]->insertNonFull(k);
        root = s;
    } 
    else
        root->insertNonFull(k);
    }
}
int main()
{
    BTree t;
    int choice, key;
    while(true)
    {
        cout<<"\n\nB-Tree Operations:\n";
        cout<<"1. Insert\n";
        cout<<"2. Search\n";
        cout<<"3. Traverse\n";
        cout<<"4. Exit\n";
        cout<<"\nEnter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"\nEnter key to insert: ";
            cin>>key;
            t.insert(key);
            break;

            case 2:
            cout<<"\nEnter key to search: ";
            cin>>key;
            if (t.search(key)!=NULL)
                cout<<"\n"<<key<<" is present in B-Tree.\n";
            else 
                cout<<"\n"<<key<<" is not present in B-Tree.\n";
            break;

            case 3:
            cout<<"\nTraversal of the B-Tree:\n";
            t.traverse();
            cout<<endl;
            break;

            case 4:
            exit(0);
            default:
            cout<<"\nInvalid choice! Please enter a valid option.\n";
        }
    }
}
