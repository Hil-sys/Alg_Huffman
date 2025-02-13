#include <iostream>
#include <string>

using namespace std;

// Структура для узла дерева Хаффмана
struct Node {
    char character;
    int frequency;
    Node* left, * right;
};
