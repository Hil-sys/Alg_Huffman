#include <iostream>
#include <string>

using namespace std;

// ��������� ��� ���� ������ ��������
struct Node {
    char character;
    int frequency;
    Node* left, * right;
};
