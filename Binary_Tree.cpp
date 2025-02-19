#include <iostream>
#include <string>
#include "BSTree.h"
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
    
    int main() {
        ifstream inputFile("input.txt");
        string input;
        if (getline(inputFile, input)) {
            cout << "Считанная строка: " << input << endl;
        }
        inputFile.close();

        unordered_map<char, int> datamap;

        for (char ch : input) {
            datamap[ch]++;
        }

        TreeNode* root = buildTree(datamap);

        unordered_map<char, string> codes;
        bincodes(root, "", codes);

        printcode(codes);

        return 0;
    }