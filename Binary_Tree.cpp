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
    ifstream inputFile("input2.txt");
    string input;
    string inputFilebmp = "input5.bmp";
    string outputFile = "compressed.bmp";

    if (getline(inputFile, input)) {
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
    convertToBinary(codes, "input2.txt", "output.txt");
    compressBMP(inputFilebmp, outputFile);
    convertToBin(codes, "input2.txt", "output.bin");

    return 0;
}
