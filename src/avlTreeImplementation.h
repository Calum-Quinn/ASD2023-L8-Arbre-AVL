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

   if (!k)
      return false;
   else if(k == this->key)
      return true;
   else if(k < this->key)
      return this->left.contains(k);
   else
      return this->right.contains(k);

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
   if (this->left)
      return this->left.min();
   else
      return this->key;

//   si r.gauche != ⌀
//   retourner min(r.gauche)
//   sinon
//   retourner r
}

template<typename Key>
Key const& avlTree<Key>::max() const {
   if (this->right)
      return this->right.min();
   else
      return this->key;
}

template<typename Key>
void avlTree<Key>::erase_min() {
   if (!this)
      return;
   else if(this->left)
      this->left.erase_min();
   else {
      avl::Node temp = this->right;
      delete(this);
      this = &temp;
   }

//   si r == ⌀
//   signaler erreur
//   sinon, si r.gauche != ⌀
//   supprimer_min (r.gauche)
//   sinon, // r est le minimum
//      d ← r.droit
//   effacer r
//   r ← d
}

template<typename Key>
void avlTree<Key>::erase_max() {
   if (!this)
      return;
   else if(this->right)
      this->right.erase_max();
   else
      delete(this);
}

template<typename Key>
void avlTree<Key>::erase(Key const& k) noexcept {

}

template<typename Key>
unsigned char avlTree<Key>::height() const noexcept {
   if (!this)
      return 0;
   else
      return this->height();

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
