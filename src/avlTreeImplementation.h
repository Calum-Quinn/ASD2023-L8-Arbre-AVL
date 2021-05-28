#ifndef ASD_2021_AVL_IMPL_H
#define ASD_2021_AVL_IMPL_H

#include <utility>
#include <algorithm>

template<typename Key>
avlTree<Key>::avlTree() : root(nullptr) {
}

template<typename Key>
avlTree<Key>::~avlTree() {
    // a completer
}

template<typename Key>
void avlTree<Key>::insert(Key const& k) {
    avl::insert_in_subtree(root, k);
}

template<typename Key>
std::ostream& avlTree<Key>::show_indented(std::ostream& out) const {
    return avl::show_indented(root, out);
}

#endif //ASD_2021_AVL_IMPL_H
