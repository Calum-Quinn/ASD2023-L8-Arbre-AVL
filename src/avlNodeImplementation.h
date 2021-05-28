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
}

#endif //ASD_LABS_2021_AVLNODEIMPLEMENTATION_H
