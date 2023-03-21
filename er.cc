#include <iostream>
#include <queue>
using namespace std;
class Node
{ // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
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
Node *createTree(Node *root)
{
    int data;
    cout << "Enter data " << endl;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data left side of " << data << endl;
    root->left = createTree(root->left);
    cout << "Enter data right side of " << data << endl;
    root->right = createTree(root->right);
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
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);

    preOrder(root->right);
}
void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);

    postOrder(root->right);
    cout << root->data << " ";
}
void CreateLevelOrder(Node *&root)
{
    queue<Node *> q;
    cout << "Enter data for root nood " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << "Enter data left side for " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }
        cout << "Enter data right side for " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}
int main()
{
    Node *root = NULL;
    // root = createTree(root);
    CreateLevelOrder(root);
    levelOrderTraversal(root);
    // cout << "Inorder is ";
    // inOrder(root);
    // cout << endl
    //      << "Preorder is ";
    // preOrder(root);
    // cout << endl
    //      << "Postorder is ";
    // postOrder(root);
}