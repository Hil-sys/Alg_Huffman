#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

struct TreeNode {
    int data;
    char data2;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char data2, int data) : data(data), data2(data2), left(nullptr), right(nullptr) {}
};

bool sortNodes(TreeNode* a, TreeNode* b) {
    return a->data < b->data;
}

class BSTree {
public:
    BSTree() : root(nullptr) {}

    TreeNode* BuildTree(const unordered_map<char, int>& freqMap);
    void bincodes(TreeNode* root, string code, unordered_map<char, string>& codes);
    void printcode(const unordered_map<char, string>& codes);
    void compressFile(const string& inputFile, const string& outputFile, const unordered_map<char, string>& codes);
    void decompressFile(const string& inputFile, const string& outputFile, TreeNode* root);
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
}

void BSTree::bincodes(TreeNode* root, string code, unordered_map<char, string>& codes) {
    if (root == nullptr) return;

    if (!root->left && !root->right) {
        codes[root->data2] = code;
    }
    bincodes(root->left, code + "0", codes);
    bincodes(root->right, code + "1", codes);
}

void BSTree::printcode(const unordered_map<char, string>& codes) {
    cout << "Codes:" << endl;
    for (const auto& pair : codes) {
        cout << "'" << pair.first << "' : " << pair.second << endl;
    }
}

void convertToBinary(const unordered_map<char, string>& codes, const string& inputFile, const string& outputFile) {
    // Открываем файл для чтения
    ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл " << inputFile << endl;
        return;
    }

    // Открываем файл для записи
    ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл " << outputFile << endl;
        inFile.close();
        return;
    }

    char ch;
    // Читаем файл посимвольно
    while (inFile.get(ch)) {
        // Ищем символ в карте кодов
        auto it = codes.find(ch);
        if (it != codes.end()) {
            // Если символ найден, записываем его бинарный код в выходной файл
            outFile << it->second;
        }
        else {
            // Если символ не найден, можно записать сообщение об ошибке или пропустить его
            cerr << "Предупреждение: Символ '" << ch << "' не найден в карте кодов." << endl;
        }
    }

    // Закрываем файлы
    inFile.close();
    outFile.close();
}