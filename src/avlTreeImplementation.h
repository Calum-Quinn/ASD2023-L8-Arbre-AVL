#ifndef ASD_2021_AVL_IMPL_H
#define ASD_2021_AVL_IMPL_H

#include <utility>
#include <algorithm>

template<typename Key>
std::ostream &operator<<(std::ostream & out, avlTree<Key> const & tree) {
   return avl::show_inline(tree.root, out);
}

template<typename Key>
std::istream &operator>>(std::istream& in, avlTree<Key>& tree) {

}

template<typename Key>
avlTree<Key>::avlTree() : root(nullptr) {}

template<typename Key>
void avlTree<Key>::insert(Key const& k) {
   avl::insert_in_subtree(root, k);
}

template<typename Key>
avlTree<Key>::avlTree(avlTree const &other) {
   root = avl::duplicate(other.root);
}

template<typename Key>
avlTree<Key>& avlTree<Key>::operator=(avlTree const &other) {
   if (this != &other) {
      avlTree<Key> temp(other);
      std::swap(root, temp.root);
   }
   return *this;
}

template<typename Key>
avlTree<Key>::~avlTree() {
   avl::destroy(root);
}

template<typename Key>
bool avlTree<Key>::contains(Key const& k) const noexcept {
   return avl::contains(root,k);
}

template<typename Key>
Key const& avlTree<Key>::min() const {
   return avl::giveMinMax(root,avl::LEFT)->key;
}

template<typename Key>
Key const& avlTree<Key>::max() const {
   return avl::giveMinMax(root,avl::RIGHT)->key;
}

template<typename Key>
void avlTree<Key>::erase_min() {
   erase(min());
}

template<typename Key>
void avlTree<Key>::erase_max() {
   erase(max());
}

template<typename Key>
void avlTree<Key>::erase(Key const& k) noexcept {
   avl::erase(root,k);
}

template<typename Key>
unsigned char avlTree<Key>::height() const noexcept {
   avl::height(root);
}

template<typename Key>
std::ostream& avlTree<Key>::show_indented(std::ostream& out) const {
    return avl::show_indented(root, out);
}



#endif //ASD_2021_AVL_IMPL_H
