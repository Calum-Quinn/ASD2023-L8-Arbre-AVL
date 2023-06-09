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

//Choses à tester

//[[nodiscard]] unsigned char height() const noexcept;

TEST_CASE("avlTree", "[avlTree]") {
   SECTION("Empty tree") {
      avlTree<int> tree;

      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == ".\n");
   }
}

TEST_CASE("avlTree(avlTree const &other)", "[avlTree]") {

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

   SECTION("easy tree") {
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

   SECTION("one element tree") {
      avlTree<int> tree;
      tree.insert(3);

      tree.erase_min();

      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == ".\n");
   }

   SECTION("two element tree") {
      avlTree<int> tree;
      tree.insert(3);
      tree.insert(2);

      tree.erase_min();

      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == "3\n");
   }

   SECTION("two element min root tree") {
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

   SECTION("easy tree") {
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
                          "|_ 9\n"
                          "   |_ 7\n"
                          "   |  |_ .\n"
                          "   |  |_ 8");
   }

   SECTION("one element tree") {
      avlTree<int> tree;
      tree.insert(3);

      tree.erase_max();

      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == ".\n");
   }

   SECTION("two element tree") {
      avlTree<int> tree;
      tree.insert(3);
      tree.insert(2);

      tree.erase_max();

      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == "3\n");
   }

   SECTION("two element min root tree") {
      avlTree<int> tree;
      tree.insert(1);
      tree.insert(2);

      tree.erase_max();

      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == "1\n");
   }
}

TEST_CASE("Destructor", "[avlTree]"){
   SECTION("Empty tree"){
      avlTree<int> tree;
      ostringstream oss;
      tree.show_indented(oss);
      REQUIRE(oss.str() == ".\n");
   }
}

TEST_CASE("min", "[avlTree]") {

   SECTION("Easy tree") {
      avlTree<int> tree = make_easy_test_tree();
      REQUIRE(tree.min() == 1);
   }

   SECTION("Throws empty tree") {
		avlTree<int> tree;
		REQUIRE_THROWS(tree.min());
   }
}

TEST_CASE("max", "[avlTree]") {

   SECTION("Easy tree") {
      avlTree<int> tree = make_easy_test_tree();
      REQUIRE(tree.max() == 10);
   }

   SECTION("Throws empty tree") {
      avlTree<int> tree;
      REQUIRE_THROWS(tree.max());
   }
}

TEST_CASE("contains", "[avlTree]") {

   SECTION("Empty tree") {
      avlTree<int> tree;

      REQUIRE(tree.contains(5) == false);
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
                            "   |  |_ 8");
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
      REQUIRE(oss.str() == "1\n");
   }
}