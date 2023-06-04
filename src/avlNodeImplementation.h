#ifndef ASD_LABS_2021_AVLNODEIMPLEMENTATION_H
#define ASD_LABS_2021_AVLNODEIMPLEMENTATION_H

#include "avlNode.h"

namespace avl {

    template<typename Key>
    void insert_in_subtree(Node <Key>*& r, Key const& k) {
        if (r == nullptr) {
            r = new Node<Key>{k, Node<Key>::NO_CHILD, 1};
        } else if (k == r->key) {
            return;
        } else {
            Side s = k < r->key ? LEFT : RIGHT;
            insert_in_subtree(r->children[s], k);
        }
    }

    template<typename Key>
    std::ostream& show_indented(Node<Key> *r,
                       std::ostream &out,
                       std::string before,
                       bool isright) {
        out << before;
        if(not r) {
            out << ".\n";
        } else {
            if(not before.empty()) {
                before[before.size() - 2] = ' ';
                if (isright) {
                    before[before.size() - 3] = ' ';
                }
            }
            out << r->key << std::endl;
            if(r->children != Node<Key>::NO_CHILD) {
                for (Side s : {LEFT, RIGHT}) {
                    show_indented(r->children[s], out, before + "|_ ", s);
                }
            }
        }
        return out;
    }

   template<typename Key>
   std::ostream& show_inline(Node<Key> *r,std::ostream& out) {
      if (!r)
         return out << ".";
      out << r->key;
      out << "(";
      show_inline(r->left(),out);
      out << ",";
      show_inline(r->right(),out);
      out << ")";

      return out;

//      si r != ⌀
//      Afficher r.etiquette
//      si degré(r) > 0
//      Afficher "("
//      pour tout enfant e de r
//      imbriquer(e)
//      si e n’est pas le dernier
//      Afficher ","
//      Afficher ")"
   }

   template<typename Key>
   unsigned char height(const Node<Key>* const& node) {
      if (!node)
         return 0;
      else
         return node->height();

//   si r == ⌀, retourner 0
//   sinon, retourner r.hauteur
   }

   template<typename Key>
   void calculateHeight(Node<Key>* const& node) {
      if(node) {
         node->height = 1 + max(node->left()->height, node->right()->height);
      }
//   fonction calculer_hauteur (r)
//   si r != ⌀,
//   r.hauteur = 1 + max(hauteur(r.gauche), hauteur(r.droit))
   }

   template<typename Key>
   Node<Key>* giveMin(Node<Key>*& node) {
      if (node->left()) {
         return giveMin(node->left());
      }
      else {
         Node<Key>* temp = node;
         node = node->right();
         return temp;
      }
   }
}

#endif //ASD_LABS_2021_AVLNODEIMPLEMENTATION_H
