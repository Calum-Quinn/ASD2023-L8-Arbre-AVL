#ifndef ASD_LABS_2021_AVLNODE_H
#define ASD_LABS_2021_AVLNODE_H

namespace avl {

    enum Side {
        LEFT = 0, RIGHT = 1
    };

    template<typename Key>
    struct Node {
        Key const key;
        std::array<Node*, 2> children;
        unsigned char height;

        inline Node*& left() noexcept { return children[LEFT]; }
        inline Node* const& left() const noexcept { return children[LEFT]; }
        inline Node*& right() noexcept { return children[RIGHT]; }
        inline Node* const& right() const noexcept { return children[RIGHT]; }

        static constexpr std::array<Node*, 2> NO_CHILD{nullptr, nullptr};
    };

    template<typename Key>
    void insert_in_subtree(Node<Key>*& r,
                           Key const& k);

    template<typename Key>
    std::ostream&  show_indented(Node<Key> *r,
                       std::ostream &out = std::cout,
                       std::string before = "",
                       bool isright = false);

    template<typename Key>
    std::ostream& show_inline(Node<Key> *r,std::ostream& out);

    template<typename Key>
    void from_string(std::istream& in, Node<Key>*& node);

    template<typename Key>
    unsigned char height(const Node<Key>* const& node);

    template<typename Key>
    void calculateHeight(Node<Key>* const& node);

    template<typename Key>
    Node<Key>* giveMinMax(Node<Key>* node, Side side);

    template<typename Key>
    Node<Key>* duplicate(Node<Key>* other);

    template<typename Key>
    void destroy(Node<Key>* node);
}

#include "avlNodeImplementation.h"

#endif //ASD_LABS_2021_AVLNODE_H