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
//      Afficher "("
//      pour tout enfant e de r
//      imbriquer(e)
//      si e n’est pas le dernier
//      Afficher ","
//      Afficher ")"
   }


   //Pris des slides 5.1 slide 38
   template<typename Key>
   void from_string(std::istream& in, Node<Key>*& out) {
      char c;
      out = new Node<Key>{in.get(c),{nullptr, nullptr},1};
      Node<Key>* n = out;
      while (in.get(c)) {
         switch (c) {
            case ',':
               n->puine = new Node<Key>{in.get(c), {nullptr, nullptr}, 1};
               n = n->puine;
               break;
            case '(':
               from_string(in, n->left());
               break;
            case ')':
               return;
            default :
               throw std::invalid_argument("Arbre non valide");
         }
      }
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

   template<typename Key>
   Node<Key>* duplicate(Node<Key>* other) {
      if (!other)
         return nullptr;

      Node<Key>* leftSubTree = copy(other->left());
      Node<Key>* rightSubTree = copy(other->left());

      return new Node<Key>{other->key, leftSubTree, rightSubTree, other->height};
   }

   template<typename Key>
   void destroy(Node<Key>* node) {
      if (node) {
         destroy(node->left());
         destroy(node->left());
         delete(node);
         node = nullptr;
      }
   }
}

#endif //ASD_LABS_2021_AVLNODEIMPLEMENTATION_H
