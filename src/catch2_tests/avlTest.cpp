#define CATCH_CONFIG_FAST_COMPILE
#include "catch_amalgamated.hpp"
#include "../avlTree.h"

#include <sstream>
#include <string>
using namespace std;

avlTree<int> make_easy_test_tree() { // order of insertion requires AVL no balancing
    avlTree<int> tree;
    for(int i : { 6, 3, 9, 2, 4, 7, 10, 1, 5, 8 })
        tree.insert(i);
    return tree;
}

TEST_CASE( "insert", "[avlTree]") {

    SECTION( "Insert into empty tree" ) {
        avlTree<int> tree;
        tree.insert(42);

        ostringstream oss;
        tree.show_indented(oss);
        REQUIRE( oss.str() == "42\n" );
    }

    SECTION( "Insert smaller to the left" ) {
        avlTree<int> tree;
        tree.insert(3);
        tree.insert(2);

        ostringstream oss;
        tree.show_indented(oss);
        REQUIRE( oss.str()  == "3\n"
                                    "|_ 2\n"
                                    "|_ .\n" );
    }

    SECTION( "Insert larger to the right" ) {
        avlTree<int> tree;
        tree.insert(3);
        tree.insert(4);

        ostringstream oss;
        tree.show_indented(oss);
        REQUIRE( oss.str()  == "3\n"
                                    "|_ .\n"
                                    "|_ 4\n" );
    }

    SECTION( "Insert twice has no effect" ) {
        avlTree<int> tree;
        tree.insert(3);
        tree.insert(4);
        tree.insert(4);

        ostringstream oss;
        tree.show_indented(oss);
        REQUIRE( oss.str()  == "3\n"
                                    "|_ .\n"
                                    "|_ 4\n" );
    }

    SECTION( "Easy tree") {
        avlTree<int> tree = make_easy_test_tree();

        ostringstream oss;
        tree.show_indented(oss);
        REQUIRE( oss.str()  == "6\n"
                                    "|_ 3\n"
                                    "|  |_ 2\n"
                                    "|  |  |_ 1\n"
                                    "|  |  |_ .\n"
                                    "|  |_ 4\n"
                                    "|     |_ .\n"
                                    "|     |_ 5\n"
                                    "|_ 9\n"
                                    "   |_ 7\n"
                                    "   |  |_ .\n"
                                    "   |  |_ 8\n"
                                    "   |_ 10\n");
    }
}

TEST_CASE("display_indented", "[avlTree]") {

    SECTION("Empty tree") {
        avlTree<int> tree;

        ostringstream oss;
        tree.show_indented(oss);
        REQUIRE(oss.str() == ".\n");
    }

    SECTION("Easy test tree") {
        avlTree<int> tree = make_easy_test_tree();

        ostringstream oss;
        tree.show_indented(oss);
        REQUIRE(oss.str() == "6\n"
                             "|_ 3\n"
                             "|  |_ 2\n"
                             "|  |  |_ 1\n"
                             "|  |  |_ .\n"
                             "|  |_ 4\n"
                             "|     |_ .\n"
                             "|     |_ 5\n"
                             "|_ 9\n"
                             "   |_ 7\n"
                             "   |  |_ .\n"
                             "   |  |_ 8\n"
                             "   |_ 10\n");
    }
}

TEST_CASE( "operator<<", "[avlTree]") {

    SECTION( "Empty tree" ) {
        avlTree<int> tree;

        ostringstream oss;
        oss << tree;
        REQUIRE( oss.str() == "." );
    }

    SECTION( "Easy test tree" ) {
        avlTree<int> tree = make_easy_test_tree();

        ostringstream oss;
        oss << tree;
        REQUIRE( oss.str() == "6(3(2(1(.,.),.),4(.,5(.,.))),9(7(.,8(.,.)),10(.,.)))" );
    }
}