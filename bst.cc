#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node *insertBst(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insertBst(root->right, d);
    }
    else
    {
        root->left = insertBst(root->left, d);
    }
    return root;
}
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
Node *miniVal(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
// 10 7 15 6 9 12 20 -1
Node *maxiVal(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
void input(Node *&root)
{
    int n;
    cin >> n;
    while (n != -1)
    {

        root = insertBst(root, n);
        cin >> n;
    }
}
Node *deleteAnyBst(Node *root, int d)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == d)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->left != NULL && root->right != NULL)
        {
            int temp = miniVal(root->right)->data;
            root->data = temp;
            root->right = deleteAnyBst(root->right, temp);
            return root;
        }
    }
    else if (root->data > d)
    {
        root->left = deleteAnyBst(root->left, d);
        return root;
    }
    else
    {
        root->right = deleteAnyBst(root->right, d);
        return root;
    }
}
int main()
{
    Node *root = NULL;
    cout << "Enter data for binary search tree : " << endl;
    input(root);
    levelOrderTraversal(root);
    cout << "Maxi valu is " << maxiVal(root)->data << endl;
    cout << "Mini valu is " << miniVal(root)->data << endl;
    deleteAnyBst(root, 15);
    levelOrderTraversal(root);
}
// yeha pe time complexity O(logn) hogi.