#include <iostream>
#include <string>
#include "BSTree.h"
#include "T.h"
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
struct Frequency {
    char character;
    int count;
};

bool compareFrequency(const Frequency& a, const Frequency& b) {
    return a.count < b.count; 
}

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream inputFile("input.txt");
    unordered_map<char, int> frequencyMap;
    char ch;

    while (inputFile.get(ch)) {
        frequencyMap[ch]++;
    }

    inputFile.close();

    vector<Frequency> frequencies;
    for (const auto& pair : frequencyMap) {
        frequencies.push_back({ pair.first, pair.second });
    }

    sort(frequencies.begin(), frequencies.end(), compareFrequency);

    cout << "Character Frequencies (sorted):\n";
    for (const auto& freq : frequencies) {
        cout << freq.character << ": " << freq.count << endl;
    }

    int MAXSIZE = 50, MAXVAL = 1275;
    int* a = (int*)malloc(MAXSIZE *sizeof(int));
    func(a, MAXSIZE);
    BSTree myTree;
    myTree.Insert(MAXVAL);
    for (int i=MAXSIZE-1; i>0;i-- ){
        myTree.Insert(a[i]);
    };
    myTree.Print();
    
    return 0;
}