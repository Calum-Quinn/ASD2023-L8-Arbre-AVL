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
   erase(min());
}

template<typename Key>
void avlTree<Key>::erase_max() {
   erase(max());
}

template<typename Key>
void avlTree<Key>::erase(Key const& k) noexcept {
   if(!this)
      return;
   else if(k < this->key)
      this->left.erase(k);
   else if(k > this->key)
      this->right.erase(k);
   else {
      avl::Node temp = *this;
      if (!this->left)
         this = this->right;
      else if(!this->right)
         this = this->left;
      else {
         avl::Node<Key>* temp2 = avl::giveMin(this->right);
         temp2->right() = this->right;
         temp2->left() = this->left;
         this = temp2;
      }
   }

//   si r == ⌀
//// k est absent
//   sinon, si k < r.clé
//   supprimer (r.gauche, k)
//   sinon, si k > r.clé
//   supprimer (r.droit, k)
//   sinon, // k est trouvé
//      tmp ← r
//   si r.gauche == ⌀
//   r ← r.droit
//   sinon, si r.droit == ⌀
//   r ← r.gauche
//   sinon, // Hibbard
//      m ← sortir_min (r.droit)
//   m.droit ← r.droit
//   m.gauche ← r.gauche
//   r ← m
//   effacer tmp
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
