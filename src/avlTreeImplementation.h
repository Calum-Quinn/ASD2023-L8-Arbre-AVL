#ifndef ASD_2021_AVL_IMPL_H
#define ASD_2021_AVL_IMPL_H

#include <utility>
#include <algorithm>

template<typename Key>
std::ostream &operator<<(std::ostream & out, avlTree<Key> const & tree) {
   out << "To be done";
   return out;
}

template<typename Key>
avlTree<Key>::avlTree() : root(nullptr) {}

template<typename Key>
void avlTree<Key>::insert(Key const& k) {
   avl::insert_in_subtree(root, k);
}

template<typename Key>
avlTree<Key>::avlTree(avlTree const &other) {

}

template<typename Key>
avlTree<Key>& avlTree<Key>::operator=(avlTree const &other) {

}

template<typename Key>
avlTree<Key>::~avlTree() {

}

template<typename Key>
bool avlTree<Key>::contains(Key const& k) const noexcept {

//   fonction chercher (r, k)
//   si r est ⌀
//   k n’est pas dans l’arbre
//   sinon, si k == r.clé
//   r est le noeud cherché
//   sinon, si k < r.clé
//   chercher(r.gauche, k)
//   sinon // k > r.clé
//   chercher(r.droit, k)
}

template<typename Key>
Key const& avlTree<Key>::min() const {

}

template<typename Key>
Key const& avlTree<Key>::max() const {

}

template<typename Key>
void avlTree<Key>::erase_min() {

}

template<typename Key>
void avlTree<Key>::erase_max() {

}

template<typename Key>
void avlTree<Key>::erase(Key const& k) noexcept {

}

template<typename Key>
unsigned char avlTree<Key>::height() const noexcept {
//   fonction hauteur (r)
//   si r == ⌀, retourner 0
//   sinon, retourner r.hauteur
//
//   fonction calculer_hauteur (r)
//   si r != ⌀,
//   r.hauteur = 1 + max(hauteur(r.gauche), hauteur(r.droit))
}

template<typename Key>
std::ostream& avlTree<Key>::show_indented(std::ostream& out) const {
    return avl::show_indented(root, out);
}



#endif //ASD_2021_AVL_IMPL_H
