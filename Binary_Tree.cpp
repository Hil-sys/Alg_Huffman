#include <iostream>
#include <string>
#include "BSTree.h"
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");
    BSTree myTree;
    ifstream inputFile("input.txt");
    string input;
    if (getline(inputFile, input)) {
        cout << "Input: " << input << endl;
    }
    inputFile.close();

    unordered_map<char, int> datamap;



    for (char ch : input) {
        datamap[ch]++;
    }

    TreeNode* root = myTree.BuildTree(datamap);

    unordered_map<char, string> codes;
    myTree.bincodes(root, "", codes);

    myTree.printcode(codes);
    convertToBinary(codes, "input.txt", "output.txt");

    return 0;
}
