#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

class Tree {
private:
    ll val;
    Tree *left, *right;

public:
    Tree(ll value) {
        this->val = value;
        this->left = this->right = NULL;
    }

    Tree *insert(ll value, Tree *root)
    {
        if (root == NULL)
            return new Tree(value);

        if (value < root->val)
            root->left = insert(value, root->left);
        else
            root->right = insert(value, root->right);
        return root;
    }

    bool searchBST(Tree *root, int val)
    {
        if (!root)
            return false;
        if (root->val == val)
            return true;
        return searchBST(root->val > val ? root->left : root->right, val);
    }

    void preorder(Tree *root)
    {
        if (root == NULL)
            return;
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Tree *root)
    { // gives sorted order in case of a BST
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    void postorder(Tree *root)
    {
        if (root == NULL)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }

    void levelOrder(Tree *root)
    { // uses queue for levels BFS
        queue<Tree *> q;
        q.push(root);
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
    }

    void levelOrder2(Tree *root){
        queue<Tree *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                auto node = q.front();
                q.pop();
                cout << node->val << " ";
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            cout<<"\n";
        }
    }

    void leftView(Tree *root)
    {
        queue<Tree *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size(); // store
            for (int i = 1; i <= n; i++)
            {
                auto node = q.front();
                q.pop();
                if (i == 1) // if it is 1st node of the level
                    cout << node->val << " ";
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
    }

    void rightView(Tree *root)
    {
        queue<Tree *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 1; i <= n; i++)
            {
                auto node = q.front();
                q.pop();
                if (i == n) // if it is last node of the level
                    cout << node->val << " ";
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
    }

    void topView(Tree *root)
    { // concept of Horizontal distance root->left (-1) root->right (+1)
        map<int, int> mp;
        queue<pair<Tree *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto nodehd = q.front();
            q.pop();
            int hd = nodehd.second;
            auto node = nodehd.first;
            if (mp.count(hd) == 0)
                mp[hd] = node->val;
            if (node->left)
            {
                q.push({node->left, hd - 1});
            }
            if (node->right)
            {
                q.push({node->right, hd + 1});
            }
        }
        for (auto it : mp)
            cout << it.second << " ";
    }

    void bottomView(Tree *root)
    { // concept of Horizontal distance root->left (-1) root->right (+1)
        map<int, int> mp;
        queue<pair<Tree *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto nodehd = q.front();
            q.pop();
            int hd = nodehd.second;
            auto node = nodehd.first;
            mp[hd] = node->val;
            if (node->left)
            {
                q.push({node->left, hd - 1});
            }
            if (node->right)
            {
                q.push({node->right, hd + 1});
            }
        }
        for (auto it : mp)
            cout << it.second << " ";
    }

    int deepestLeavesSum(Tree *root)
    {
        queue<Tree *> q;
        q.push(root);
        int levelSum = 0;
        while (!q.empty())
        {
            levelSum = 0; // resets the sum to 0 for each level except tha last one
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Tree *node = q.front();
                q.pop();
                levelSum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return levelSum;
    }

    int height(Tree *root)
    {
        if (root == NULL)
            return 0;
        int l = height(root->left);
        int r = height(root->right);
        return 1 + max(l, r);
    }

    vector<vector<int>> verticalTraversal(Tree *root)
    {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<Tree *, pair<int, int>>> todo;

        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        todo.push({root, {0, 0}});
        while (!todo.empty())
        {
            auto p = todo.front();
            todo.pop();
            Tree *node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(node->val);
            if (node->left)
            {
                todo.push({node->left, {x - 1, y + 1}});
            }
            if (node->right)
            {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }

        for (auto &p : nodes)
        {
            vector<int> col;
            for (auto &q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Tree *root = NULL;
    root = root->insert(7, root);
    root = root->insert(2, root);
    root = root->insert(8, root);
    root = root->insert(1, root);
    root = root->insert(5, root);
    // root=root->insert(9,root);

    // cout<<root->searchBST(root, 6)<<endl;
    // cout<<root->searchBST(root, 7)<<endl;

    // DFS Traversals
    //  root->preorder(root);
    //  cout<<endl;
    //  root->inorder(root);
    //  cout<<endl;
    //  root->postorder(root);
    //  cout<<endl;

    // BFS
    root->levelOrder(root);
    cout<<endl<<endl;
    root->levelOrder2(root);
    // cout << endl;
    // root->leftView(root);
    // cout<<endl;
    // root->rightView(root);
    // cout<<endl;
    // root->topView(root);
    // cout<<endl;
    // root->bottomView(root);
    // cout<<endl;
    // cout<<root->height(root);
    // cout<<endl;
    // cout<<root->deepestLeavesSum(root)<<endl;

    // vector<vector<int>> ans = root->verticalTraversal(root);
    // for(auto i:ans){
    //     for(auto j:i)
    //         cout<<j<<" ";
    // }
}