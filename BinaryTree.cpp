#include <iostream>
#include <string>
#include <cassert>
using namespace std;

struct Node
{
    char data;
    Node* left{}; // here it is nullptr by default
    Node* right{};

    Node(char data) :data(data) {};
};

void print_postorder(Node* current)
{
    if (!current)
        return;

    print_postorder(current->left);
    print_postorder(current->right);
    cout << current->data;
}

void print_inorder(Node* current)
{
    if (!current)
        return;

    print_inorder(current->left);
    cout << current->data;
    print_inorder(current->right);
}

void print_in(Node* current)
{
    if(!current)
    return;

    cout<<current->data;
    print_in(current->left);
    print_in(current->right);
}

int main()
{
    Node* plus = new Node('+');
    Node* node2 = new Node('2');
    Node* node3 = new Node('3');

    Node* mul = new Node('*');
    Node* node4 = new Node('4');

    mul->left = plus;
    mul->right = node4;
    plus->left = node2;
    plus->right = node3;

    print_in(mul);
}