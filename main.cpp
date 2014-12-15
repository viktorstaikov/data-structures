#include "binary_search_tree.h"

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello, World!" << endl;
    BinarySearchTree bs = BinarySearchTree();

    cout << "Input:" << endl;
    int n, e;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> e;
        bs.Insert(e);
    }

    cout << "Print:" << endl;
    bs.Print();

    // cout << "Contains:" << endl;
    // cin >> n;
    // cout << bs.Contains(n) << endl;

    cout << "Delete:" << endl;
    cin >> n;
    cout << bs.Delete(n) << endl;

    cout << "Print:" << endl;
    bs.Print();

    // cout << "Min:" << endl;
    // cout << bs.Min() << endl;

    // cout << "Max:" << endl;
    // cout << bs.Max() << endl;

    return 0;
}