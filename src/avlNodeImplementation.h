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
            calculateHeight(r);
            restoreBalance(r);
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
   }

   template<typename Key>
   void from_string(std::istream& in, Node<Key>*& out) {
      char c;
      out = new Node<Key>{in.get(c),{nullptr, nullptr},1};
      Node<Key>* n = out;
      while (in.get(c)) {
         if (c == '(') {
            from_string(in, n->left());
            in.get(c);
            from_string(in, n->right());
         }
         else if(c == ')') {
            return;
         }
         else {
            throw std::invalid_argument("Arbre non valide");
         }
      }
   }

   template<typename Key>
   unsigned char height(const Node<Key>* const& node) {
      if (!node)
         return 0;
      else
         return node->height;
   }

   template<typename Key>
   void calculateHeight(Node<Key>*& node) {
      if(node) {
         //Appeler height() -> opérateur ternaire pour initialiser ou retourner height des enfants
         node->height = 1 + std::max(height(node->left()), height(node->right()));
      }
   }

   template<typename Key>
   int balance(Node<Key>* const& node){
      if(!node){
         return 0;
      }
      return height(node->left()) - height(node->right());
   }

    template<typename Key>
    void rotateLeft(Node<Key>*& node){
       Node<Key>* temp = node->right();
       node->right() = temp->left();
       temp->left() = node;
       node = temp;
       calculateHeight(node->left());
       calculateHeight(node);
    }

    template<typename Key>
    void rotateRight(Node<Key>*& node){
       Node<Key>* temp = node->left();
       node->left() = temp->right();
       temp->right() = node;
       node = temp;
       calculateHeight(node->right());
       calculateHeight(node);
    }

    template<typename Key>
    void restoreBalance(Node<Key>*& node){
       if(!node)
          return;

       if(balance(node) < -1){
          if(balance(node->right()) > 0){
             rotateRight(node->right());
          }
          rotateLeft(node);
       }
       else if(balance(node) > 1){
          if(balance(node->left()) < 0){
             rotateLeft(node->left());
          }
          rotateRight(node);
       }
       else{
          calculateHeight(node);
       }
    }

   template<typename Key>
   Node<Key>* giveMinMax(Node<Key>* node, Side side) {
      if (!node) {
         throw std::invalid_argument("Empty Tree");
      }

      if(side) {
         if (node->right()) {
            return giveMinMax(node->right(),side);
         }
      }
      else {
         if (node->left()) {
            return giveMinMax(node->left(),side);
         }
      }
      return node;
   }

   template<typename Key>
   Node<Key>* duplicate(Node<Key>* other) {
      if (!other)
         return nullptr;

      Node<Key>* leftSubTree = duplicate(other->left());
      Node<Key>* rightSubTree = duplicate(other->right());

      return new Node<Key>{other->key, leftSubTree, rightSubTree, other->height};
   }

   template<typename Key>
   void destroy(Node<Key>*& node) {
      if (node) {
         destroy(node->left());
         destroy(node->right());
         delete(node);
         node = nullptr;
      }
   }

   template<typename Key>
   bool contains(Node<Key>* node,Key const& k) {
      if (!k || !node)
         return false;
      else if(k == node->key)
         return true;
      else if(k < node->key)
         return contains(node->left(), k);
      else
         return contains(node->right(), k);
   }

   template<typename Key>
   void erase(Node<Key>*& node, Key const& k) {
      if(!node){
         return;
      }
      else if(k < node->key){
         erase(node->left(),k);
         restoreBalance(node);
         calculateHeight(node);
      }
      else if(k > node->key){
         erase(node->right(),k);
         restoreBalance(node);
         calculateHeight(node);
      }
      else {
         Node<Key>* min;
         Node<Key>* temp = node;
         if (!node->left())
            node = node->right();
         else if (!node->right())
            node = node->left();
         else {
            min = giveMinMax(node, avl::LEFT);
            min->right() = node->right();
            min->left() = node->left();
            node = min;
         }
         delete(temp);

      }
   }
}

#endif //ASD_LABS_2021_AVLNODEIMPLEMENTATION_H