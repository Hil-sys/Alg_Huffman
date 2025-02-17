#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;
    Node(T value) : data(value), left(NULL), right(NULL) {}
};


template <typename T>
class BinaryTree {
private:
    Node<T>* root;
    bool searchRecursive(Node<T>* current, T value) {
        if (current == NULL) return false;
        if (current->data == value) return true;
        return searchRecursive(current->left, value) || searchRecursive(current->right, value);
    }
public:
    BinaryTree() : root(NULL) {}
    void insertNode(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (root == NULL) {
            root = newNode;
            return;
        }

        queue<Node<T>*> q;
        q.push(root);

        while (!q.empty()) {
            Node<T>* current = q.front();
            q.pop();

            if (current->left == NULL) {
                current->left = newNode;
                return;
            } else {
                q.push(current->left);
            }

            if (current->right == NULL) {
                current->right = newNode;
                return;
            } else {
                q.push(current->right);
            }
        }
    }
    bool search(T value) {
        return searchRecursive(root, value);
    }
};

int main() {
    BinaryTree<int> tree;
    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(5);
    tree.insertNode(6);

    cout << "Searching for 7: " << (tree.search(7) ? "Found" : "Not Found") << endl;
    cout << "Searching for 6: " << (tree.search(6) ? "Found" : "Not Found") << endl;

    return 0;
}
