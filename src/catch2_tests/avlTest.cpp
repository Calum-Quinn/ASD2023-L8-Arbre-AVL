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



//-----------------------------------------------------------------------------------------

//------------------------------------Nos tests--------------------------------------------

//-----------------------------------------------------------------------------------------



TEST_CASE("avlTree", "[avlTree]") {
   SECTION("Empty tree") {
      avlTree<int> tree;

      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == ".\n");
   }

   SECTION("Two empty trees") {
      avlTree<int> tree1;
      avlTree<int> tree2;

      ostringstream oss;
      tree1.show_indented(oss);
      tree2.show_indented(oss);
      REQUIRE(oss.str() == ".\n"
                           ".\n");
   }
}

TEST_CASE("avlTree(avlTree const &other)", "[avlTree]") {

   SECTION("Empty tree") {
      avlTree<int> tree;
      avlTree<int> copied(tree);

      ostringstream oss;
      copied.show_indented(oss);
      REQUIRE(oss.str() == ".\n");
   }

   SECTION("Easy tree") {
      avlTree<int> easy = make_easy_test_tree();
      avlTree<int> tree(easy);

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

TEST_CASE("operator=", "[avlTree]") {

   SECTION("Empty tree to empty") {
      avlTree<int> empty;
      avlTree<int> tree;

      tree = empty;

      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == ".\n");
   }

   SECTION("Easy tree to empty") {
      avlTree<int> easy = make_easy_test_tree();
      avlTree<int> tree;

      tree = easy;

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

   SECTION("Easy tree to not empty") {
      avlTree<int> easy = make_easy_test_tree();
      avlTree<int> tree;
      tree.insert(4);
      tree.insert(7);
      tree.insert(2);

      tree = easy;

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

   SECTION("Empty tree to itself") {
      avlTree<int> tree;

      tree = tree;

      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == ".\n");
   }

   SECTION("Easy tree to itself") {
      avlTree<int> easy = make_easy_test_tree();

      easy = easy;

      ostringstream oss;
      easy.show_indented(oss);
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


TEST_CASE("erase min", "[avlTree]") {

   SECTION("Empty tree") {
      avlTree<int> tree;

      REQUIRE_THROWS(tree.erase_min());

   }

   SECTION("Easy tree") {
      avlTree<int> easy = make_easy_test_tree();

      easy.erase_min();

      ostringstream oss;
      easy.show_indented(oss);
      REQUIRE( oss.str()  == "6\n"
                             "|_ 3\n"
                             "|  |_ 2\n"
                             "|  |_ 4\n"
                             "|     |_ .\n"
                             "|     |_ 5\n"
                             "|_ 9\n"
                             "   |_ 7\n"
                             "   |  |_ .\n"
                             "   |  |_ 8\n"
                             "   |_ 10\n");
   }

   SECTION("One element tree") {
      avlTree<int> tree;
      tree.insert(3);

      tree.erase_min();

      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == ".\n");
   }

   SECTION("Two element tree") {
      avlTree<int> tree;
      tree.insert(3);
      tree.insert(2);

      tree.erase_min();

      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == "3\n");
   }

   SECTION("Two element tree, min is root") {
      avlTree<int> tree;
      tree.insert(1);
      tree.insert(2);

      tree.erase_min();

      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == "2\n");
   }
}

TEST_CASE("erase max", "[avlTree]") {

   SECTION("Empty tree") {
      avlTree<int> tree;

      REQUIRE_THROWS(tree.erase_max());

   }

   SECTION("Easy tree") {
      avlTree<int> easy = make_easy_test_tree();

      easy.erase_max();

      ostringstream oss;
      easy.show_indented(oss);
      REQUIRE( oss.str() == "6\n"
                          "|_ 3\n"
                          "|  |_ 2\n"
                          "|  |  |_ 1\n"
                          "|  |  |_ .\n"
                          "|  |_ 4\n"
                          "|     |_ .\n"
                          "|     |_ 5\n"
                          "|_ 8\n"
                          "   |_ 7\n"
                          "   |_ 9\n");
   }

   SECTION("One element tree") {
      avlTree<int> tree;
      tree.insert(3);

      tree.erase_max();

      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == ".\n");
   }

   SECTION("Two element tree") {
      avlTree<int> tree;
      tree.insert(2);
      tree.insert(3);

      tree.erase_max();

      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == "2\n");
   }

   SECTION("Two element tree, max is root") {
      avlTree<int> tree;
      tree.insert(2);
      tree.insert(1);

      tree.erase_max();

      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == "1\n");
   }
}

TEST_CASE("Destructor", "[avlTree]"){
   SECTION("Empty tree"){
      avlTree<int> tree;
      tree.~avlTree();

      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == ".\n");
   }

   SECTION("Easy tree"){
      avlTree<int> tree = make_easy_test_tree();
      tree.~avlTree();

      ostringstream oss;
      tree.show_indented(oss);

      for (int i = 1; i <= 10; ++i) {
         REQUIRE(!tree.contains(i));
      }
      REQUIRE(oss.str() == ".\n");
   }
}

TEST_CASE("min", "[avlTree]") {
   SECTION("Empty tree") {
      avlTree<int> tree;
      REQUIRE_THROWS(tree.min());
   }

   SECTION("Easy tree") {
      avlTree<int> tree = make_easy_test_tree();
      REQUIRE(tree.min() == 1);
   }

   SECTION("Min is root") {
      avlTree<int> tree;
      tree.insert(3);
      tree.insert(6);
      tree.insert(17);
      REQUIRE(tree.min() == 3);
   }
}

TEST_CASE("max", "[avlTree]") {
   SECTION("Empty tree") {
      avlTree<int> tree;
      REQUIRE_THROWS(tree.max());
   }

   SECTION("Easy tree") {
      avlTree<int> tree = make_easy_test_tree();
      REQUIRE(tree.max() == 10);
   }

   SECTION("Max is root") {
      avlTree<int> tree;
      tree.insert(17);
      tree.insert(3);
      tree.insert(6);
      REQUIRE(tree.max() == 17);
   }
}

TEST_CASE("contains", "[avlTree]") {

   SECTION("Empty tree") {
      avlTree<int> tree;

      for (int i = 0; i <= 10 ; ++i) {
         REQUIRE(tree.contains(i) == false);
      }
   }

   SECTION("Key not in tree") {
      avlTree<int> tree = make_easy_test_tree();

      REQUIRE(tree.contains(36) == false);
   }

   SECTION("Key in tree") {
      avlTree<int> tree = make_easy_test_tree();

      REQUIRE(tree.contains(5) == true);
   }
}


TEST_CASE("erase", "[avlTree]") {

   SECTION("Empty tree") {
      avlTree<int> tree;

      tree.erase(2);

      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == ".\n");

   }

   SECTION("easy tree") {
      avlTree<int> easy = make_easy_test_tree();

      easy.erase(2);

      ostringstream oss;
      easy.show_indented(oss);
      REQUIRE( oss.str() == "6\n"
                            "|_ 3\n"
                            "|  |_ 1\n"
                            "|  |_ 4\n"
                            "|     |_ .\n"
                            "|     |_ 5\n"
                            "|_ 9\n"
                            "   |_ 7\n"
                            "   |  |_ .\n"
                            "   |  |_ 8\n"
                            "   |_ 10\n");
   }

   SECTION("One element tree") {
      avlTree<int> tree;
      tree.insert(3);

      tree.erase(3);

      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == ".\n");
   }

   SECTION("Two element tree, delete last element") {
      avlTree<int> tree;
      tree.insert(3);
      tree.insert(2);

      tree.erase(2);

      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == "3\n");
   }

   SECTION("Two elements, delete first element") {
      avlTree<int> tree;
      tree.insert(2);
      tree.insert(3);

      tree.erase(2);

      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == "3\n");
   }
}

TEST_CASE("height", "[avlTree]") {

   SECTION("Empty tree") {
      avlTree<int> tree;
      REQUIRE(tree.height() == 0);
   }

   SECTION("Easy tree") {
      avlTree<int> tree = make_easy_test_tree();
      REQUIRE(tree.height() == 4);
   }

   SECTION("One element in tree") {
      avlTree<int> tree;
      tree.insert(1);

      REQUIRE(tree.height() == 1);
   }

   SECTION("Two elements and one deleted in tree") {
      avlTree<int> tree;
      tree.insert(1);
      tree.insert(2);
      REQUIRE(tree.height() == 2);

      tree.erase(1);
      REQUIRE(tree.height() == 1);
   }
}