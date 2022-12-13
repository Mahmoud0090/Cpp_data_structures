#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

class BinaryTree
{
private:
  int data;
  BinaryTree *left{};
  BinaryTree *right{};

public:
  BinaryTree(int data) : data(data){};

  void print_inorder()
  {
    if (left)
      left->print_inorder();
    cout << data << " ";
    if (right)
      right->print_inorder();
  }

  void add(vector<int> values, vector<char> direction)
  {
    assert(values.size() == direction.size());
    BinaryTree *current = this;

    // iterate on the path and create all necessary nodes
    for (int i = 0; i < (int)values.size(); ++i)
    {
      if (direction[i] == 'L')
      {
        if (!current->left)
          current->left = new BinaryTree(values[i]);

        else
          assert(current->left->data == values[i]);

        current = current->left;
      }
      else
      {
        if (!current->right)
          current->right = new BinaryTree(values[i]);
        else
          assert(current->right->data == values[i]);

        current = current->right;
      }
    }
  }

  int tree_max()
  {
    int max_value = this->data;

    if (left)
    {
      max_value = max(max_value, left->tree_max());
    }
    if (right)
    {
      max_value = max(max_value, right->tree_max());
    }

    return max_value;
  }

  int height()
  {
    BinaryTree *tree = this;
    if (!tree)
      return 0;

    int leftheight = tree->left->height();
    int rightheight = tree->right->height();

    return max(leftheight, rightheight) + 1;
  }

  int total_nodes()
  {
    BinaryTree *tree = this;
    if (!tree)
      return 0;
    return 1 + tree->left->total_nodes() + tree->right->total_nodes();
  }

  int leaf_nodes()
  {
    BinaryTree *tree = this;

    if (!tree)
      return 0;

    if (!tree->left && !tree->right)
      return 1;

    return tree->left->leaf_nodes() + tree->right->leaf_nodes();
  }

  bool is_exists(int value)
  {
    BinaryTree *tree = this;

    if (!tree)
      return false;

    if (tree->data == value)
      return true;
    // return true;

    return (tree->left->is_exists(value) || tree->right->is_exists(value));
  }

  /*bool is_perfect()
  {
    // recursive way
    // formula based way
   
  }*/

};
int main()
{
  BinaryTree tree(1);

  tree.add({2, 4, 7}, {'L', 'L', 'L'});
  tree.add({2, 4, 8}, {'L', 'L', 'R'});
  tree.add({2, 5, 9}, {'L', 'R', 'R'});
  tree.add({3, 6, 10}, {'R', 'R', 'L'});
  tree.add({3, 6, 11, 56}, {'R', 'R', 'R', 'R'});

  // tree.print_inorder();

  // int x = tree.tree_max();

  bool x = tree.is_exists(7);

  cout << x << endl;

  return 0;
}
