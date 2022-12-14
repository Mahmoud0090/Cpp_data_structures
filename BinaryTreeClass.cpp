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
    int res = 0;
    if(left)
    res = max(res , left->height());

    if(right)
    res = max(res , right->height());

    return res + 1;
  }

  int total_nodes()
  {
    int total = 0;
    if(left)
    total += left->total_nodes();

    if(right)
    total += right->total_nodes();

    return 1 + total;
  }

  int leaf_nodes()
  {
    int leaf = !left && !right;

    if(left)
    leaf += left->leaf_nodes();

    if(right)
    leaf+= right->leaf_nodes();

    return leaf;
  }

  bool is_exists(int value)
  {
    bool res = data == value;
    if(!res && left)
    res = left->is_exists(value);

    if(!res && right)
    res = right->is_exists(value);

    return res;
  }

};
int main()
{
  BinaryTree tree(1);

  tree.add({2, 4, 7}, {'L', 'L', 'L'});
  tree.add({2, 4, 8}, {'L', 'L', 'R'});
  tree.add({2, 5, 9}, {'L', 'R', 'R'});
  tree.add({3, 6, 10}, {'R', 'R', 'L'});
  tree.add({3, 6, 11}, {'R', 'R', 'R'});

  // tree.print_inorder();

  // int x = tree.tree_max();

  bool x = tree.is_exists(90);

  cout << x << endl;

  return 0;
}
