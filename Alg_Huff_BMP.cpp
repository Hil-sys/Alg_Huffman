#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct ColorFrequency {
    uint32_t color;
    int count;
};


bool compareColorFrequency(const ColorFrequency& a, const ColorFrequency& b) {
    return a.count < b.count;
}

int main() {
    ifstream inputFile("input.bmp", ios::binary);
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }


    inputFile.seekg(54);

    unordered_map<uint32_t, int> frequencyMap;
    uint8_t pixel[3];


    while (inputFile.read(reinterpret_cast<char*>(pixel), sizeof(pixel))) {
        uint32_t color = (pixel[2] << 16) | (pixel[1] << 8) | pixel[0];
        frequencyMap[color]++;
    }

    inputFile.close(); 

    vector<ColorFrequency> colorFrequencies;
    for (const auto& pair : frequencyMap) {
        colorFrequencies.push_back({ pair.first, pair.second });
    }

    sort(colorFrequencies.begin(), colorFrequencies.end(), compareColorFrequency);

    cout << "Color Frequencies (sorted):\n";
    for (const auto& freq : colorFrequencies) {
        cout << freq.color << ": " << freq.count << endl;
    }

    return 0;
}
