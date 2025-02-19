#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

struct TreeNode
{
    int data;
    char data2;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char data2, int data) : data(data), data2(data2), left(nullptr), right(nullptr) {}
};

// Сортировка
bool sortNodes(TreeNode* a, TreeNode* b) {
    return a->data < b->data;
}

TreeNode* buildTree(const unordered_map<char, int>& freqMap) {
    vector<TreeNode*> nodes;

    // Добавление в массив (вектор)
    for (const auto& pair : freqMap) {
        nodes.push_back(new TreeNode(pair.first, pair.second));
    }

    // Построение дерева Хаффмана
    while (nodes.size() > 1) {
        // Сортировка
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
}

// Функция для генерации бинарных кодов :)
void bincodes(TreeNode* root, string code, unordered_map<char, string>& codes) {
    if (root == nullptr) return;

    if (!root->left && !root->right) {
        codes[root->data] = code;
    }
    bincodes(root->left, code + "0", codes);
    bincodes(root->right, code + "1", codes);
}

void printcode(const unordered_map<char, string>& codes) {
    cout << "Codes:" << endl;
    for (const auto& pair : codes) {
        cout << "'" << pair.first << "' : " << pair.second << endl;
    }
}


//class BSTree
//{
//public:
//    // constructors
//    BSTree(): root(nullptr) {}
//    BSTree(TreeNode* rootNode): root(rootNode) {}
//    
//    // member functions
//    void Print();
//    void Insert(int val, char val2);
//    
//private:
//    TreeNode* root;
//    std::string SubTreeAsString(TreeNode* node);  // Helper method for Print()
//    void Insert(int val, char val2, TreeNode* node); // Helper method for Insert(int val)
//};
//
//void BSTree::Print(){
//    if(this->root == nullptr){
//        std::cout << "{}" << std::endl;
//    } else{
//        std::cout << this->root->aleft->data2 << std::endl;
//    }
//}
//
///// Print the subtree starting at '*node'
//std::string BSTree::SubTreeAsString(TreeNode* node){
//    std::string leftStr = (node->left == nullptr) ? "" : (SubTreeAsString(node->left) + "<--");
//    std::string rightStr = (node->right == nullptr) ? "" : ("-->" + SubTreeAsString(node->right));
//    std::string result = leftStr + std::to_string(node->data2) + rightStr;
//    return result;
//}
//
///// Insert a new value into the tree
//void BSTree::Insert(int val, char val2) {
//    if(root == nullptr){
//        this->root = new TreeNode(val);
//    } else{
//        this->Insert(val, val2, this->root);
//    }
//}
///// Insert a new value into the subtree starting at node
//void BSTree::Insert(int val, char val2, TreeNode* node) {
//    // Check if val is < or > this node's value
//    if(val <= (node->data)/2){
//        if(node->left == nullptr){
//            // Make a new node as the left child of this node
//            node->left = new TreeNode(val2);
//            node->right = new TreeNode(node->data- val);
//        } else{
//            // Recursively call Insert() on this node's left child
//            this->Insert(val, val2, node->right);
//        }
//    } else{
//        if(node->right == nullptr){
//            // Make a new node as the right child of this node
//            node->right = new TreeNode(val2);
//            node->left = new TreeNode(node->data- val);
//        } else{
//            // Recursively call Insert() on this node's right child
//            this->Insert(val, val2, node->left);
//        }
//    }
//}