struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data): data(data), left(nullptr), right(nullptr) {}
};

class BSTree
{
public:
    // constructors
    BSTree(): root(nullptr) {}
    BSTree(TreeNode* rootNode): root(rootNode) {}
    
    // member functions
    void Print();
    void Insert(int val);
    void Create(int* arr, int size, int flag);
    void FirstCreate(int val1, int val2);
    
private:
    TreeNode* root;
    std::string SubTreeAsString(TreeNode* node);  // Helper method for Print()
    void Insert(int val, TreeNode* node); // Helper method for Insert(int val)
};

void BSTree::Print(){
    if(this->root == nullptr){
        std::cout << "{}" << std::endl;
    } else{
        std::cout << this->SubTreeAsString(this->root) << std::endl;
    }
}

/// Print the subtree starting at '*node'
std::string BSTree::SubTreeAsString(TreeNode* node){
    std::string leftStr = (node->left == nullptr) ? "{}" : SubTreeAsString(node->left);
    std::string rightStr = (node->right == nullptr) ? "{}" : SubTreeAsString(node->right);
    std::string result = "{" + std::to_string(node->data) + ", " + leftStr + ", " + rightStr + "}";
    return result;
}

/// Insert a new value into the tree
void BSTree::Insert(int val) {
    if(root == nullptr){
        this->root = new TreeNode(val);
    } else{
        this->Insert(val, this->root);
    }
}

/// Insert a new value into the subtree starting at node
void BSTree::Insert(int val, TreeNode* node) {
    // Check if val is < or > this node's value
    if(val < node->data){
        if(node->left == nullptr){
            // Make a new node as the left child of this node
            node->left = new TreeNode(val);
        } else{
            // Recursively call Insert() on this node's left child
            this->Insert(val, node->left);
        }
    } else{
        if(node->right == nullptr){
            // Make a new node as the right child of this node
            node->right = new TreeNode(val);
        } else{
            // Recursively call Insert() on this node's right child
            this->Insert(val, node->right);
        }
    }
}

void BSTree::Create(int* arr, int size, int flag){
    root = new TreeNode(arr[0]+arr[1]);
    root->left = new TreeNode(arr[0]);
    root->right = new TreeNode(arr[1]);
    arr[0] = arr[0]+arr[1];
    if (size > 1){
        for (int i = flag+1; i<=size; i++){
            arr[i-flag] =arr[i]; 
        }
    Create(arr, size-1, flag+1);
    }
}