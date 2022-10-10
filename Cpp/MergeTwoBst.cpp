// Program to merge two BSTs

#include <bits/stdc++.h>
using namespace std;

// Structure of a BST Node
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int data = 0)
    {
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Function to merge two BSTs
vector<int> mergeTwoBST(Node *root1, Node *root2)
{
    vector<int> res;
    stack<Node *> s1, s2;
    while (root1 || root2 || !s1.empty() || !s2.empty())
    {
        while (root1)
        {
            s1.push(root1);
            root1 = root1->left;
        }
        while (root2)
        {
            s2.push(root2);
            root2 = root2->left;
        }
        if (s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val))
        {
            root1 = s1.top();
            s1.pop();
            res.push_back(root1->val);
            root1 = root1->right;
        }
        else
        {
            root2 = s2.top();
            s2.pop();
            res.push_back(root2->val);
            root2 = root2->right;
        }
    }
    return res;
}

// Function to build a BST from the given array;
void insertBST(Node *root, vector<int> bst)
{
    for (int i = 1; i < bst.size(); i++)
    {
        Node *tp = root;
        while (tp != nullptr)
        {
            if (tp->val == bst[i])
                break;
            else if (tp->val < bst[i])
            {
                if (tp->right == nullptr)
                {
                    tp->right = new Node(bst[i]);
                    break;
                }
                else
                    tp = tp->right;
            }
            else
            {
                if (tp->left == nullptr)
                {
                    tp->left = new Node(bst[i]);
                    break;
                }
                else
                    tp = tp->left;
            }
        }
    }
}

// Function to print Inorder Transversal.
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Main Function
int main()
{
    vector<int> bst1 = {5, 3, 6, 2, 4}, bst2 = {2, 1, 3, 7, 6};
    Node *root1 = nullptr, *root2 = nullptr;
    root1 = new Node(bst1[0]);
    root2 = new Node(bst2[0]);
    insertBST(root1, bst1);
    insertBST(root2, bst2);
    // inorder(root1);
    // cout << endl;
    // inorder(root2);
    // cout << endl;
    vector<int> ans = mergeTwoBST(root1, root2);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}
