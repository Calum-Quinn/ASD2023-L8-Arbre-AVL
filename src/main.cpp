#include <iostream>
#include <sstream>
#include "avlTree.h"

using namespace std;

int main() {

    avlTree<int> t;

    for (int i : { 3, 5, 2, 6, 8, 4, 6, 4, 1 })
    {
        t.insert(i);
        t.show_indented();
        cout << endl;
    }
    cout << t << endl;

   avlTree<int> tree;
   for(int i : { 6, 3, 9, 2, 4, 7, 10, 1, 5, 8 })
      tree.insert(i);
   tree.show_indented();
}