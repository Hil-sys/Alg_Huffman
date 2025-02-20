#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
struct TreeNode
{
    int data;
    char data2;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char data2, int data) : data(data), data2(data2), left(nullptr), right(nullptr) {}
};

bool sortNodes(TreeNode* a, TreeNode* b) {
    return a->data < b->data;
}

class BSTree
{
public:
   BSTree(): root(nullptr) {}

   TreeNode* BuildTree(const unordered_map<char, int>& freqMap);
   void bincodes(TreeNode* root, string code, unordered_map<char, string>& codes);
   void printcode(const unordered_map<char, string>& codes);
private:
   TreeNode* root;
};

TreeNode* BSTree::BuildTree(const unordered_map<char, int>& freqMap) {
    vector<TreeNode*> nodes;

    for (const auto& pair : freqMap) {
        nodes.push_back(new TreeNode(pair.first, pair.second));
    }

    while (nodes.size() > 1) {
        sort(nodes.begin(), nodes.end(), sortNodes);

        TreeNode* left = nodes[0];
        TreeNode* right = nodes[1];

        TreeNode* newNode = new TreeNode('\0', left->data + right->data);
        newNode->left = left;
        newNode->right = right;

        nodes.erase(nodes.begin(), nodes.begin() + 2);
        nodes.push_back(newNode);
    }

    return nodes[0];
};

void BSTree::bincodes(TreeNode* root, string code, unordered_map<char, string>& codes) {
    if (root == nullptr) return;

    if (!root->left && !root->right) {
        codes[root->data] = code;
    }
    bincodes(root->left, code + "0", codes);
    bincodes(root->right, code + "1", codes);
};

void BSTree::printcode(const unordered_map<char, string>& codes) {
    cout << "Codes:" << endl;
    for (const auto& pair : codes) {
        cout << "'" << pair.first << "' : " << pair.second << endl;
    }
};