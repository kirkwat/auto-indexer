//
// Created by watso on 9/28/2020.
//
#include "catch.hpp"
//#include "DSList.h"
#include "DSVector.h"

TEST_CASE("LinkedList and vector class", "[linkedListAndVector]"){
    /*
    SECTION("Linked list creation and push back"){
        DSList<int> list1;
        list1.push_back(1);
        REQUIRE(list1.getSize() == 1);
        list1.push_back(1);
        REQUIRE(list1.getSize() == 2);
    }

    SECTION("Linked list with pointer data types"){
        DSList<int *> list2;
        list2.push_back(new int(10));
        REQUIRE(list2.getSize() == 1);
    }

    SECTION("Linked list accessor"){
        DSList<int> list3;
        list3.push_back(2);
        list3.push_back(4);
        list3.push_back(6);
        list3.push_back(8);
        REQUIRE(list3.at(0) == 2);
        REQUIRE(list3.at(1) == 4);
        REQUIRE(list3.at(2) == 6);
        REQUIRE(list3.at(3) == 8);
    }

    SECTION("Linked list nodes connection"){
        DSList<int> list4;
        list4.push_back(3);
        list4.push_back(6);
        list4.push_back(9);
        list4.push_back(12);
        REQUIRE(list4.getNext(2)==list4.nodeAt(3));
        REQUIRE(list4.getPrevious(3)==list4.nodeAt(2));
    }

    SECTION("Linked list insert after function"){
        DSList<int> list5;
        list5.push_back(1);
        list5.push_back(3);
        list5.push_back(5);
        list5.push_back(7);
        list5.InsertAfter(2,4);
        REQUIRE(list5.getSize() == 5);
        REQUIRE(list5.at(0) == 1);
        REQUIRE(list5.at(1) == 3);
        REQUIRE(list5.at(2) == 5);
        REQUIRE(list5.at(3) == 4);
        REQUIRE(list5.at(4) == 7);
    }

    SECTION("Linked list remove function"){
        DSList<int> list6;
        list6.push_back(2);
        list6.push_back(4);
        list6.push_back(6);
        list6.push_back(8);
        list6.removeAt(2);
        REQUIRE(list6.getSize() == 3);
        REQUIRE(list6.at(0) == 2);
        REQUIRE(list6.at(1) == 4);
        REQUIRE(list6.at(2) == 8);
    }
    */
    SECTION("Vector creation and push back"){
        DSVector<int> list1;
        list1.push_back(1);
        REQUIRE(list1.size() == 1);
        list1.push_back(1);
        REQUIRE(list1.size() == 2);
    }

    SECTION("Vector accessor"){
        DSVector<int> list2;
        list2.push_back(2);
        list2.push_back(4);
        list2.push_back(6);
        list2.push_back(8);
        REQUIRE(list2[0] == 2);
        REQUIRE(list2[1] == 4);
        REQUIRE(list2[2] == 6);
        REQUIRE(list2[3] == 8);
    }

    SECTION("Linked list remove function"){
        DSVector<int> list6;
        list6.push_back(2);
        list6.push_back(4);
        list6.push_back(6);
        list6.push_back(8);
        list6.remove(2);
        REQUIRE(list6.size() == 3);
        REQUIRE(list6[0] == 2);
        REQUIRE(list6[1] == 4);
        REQUIRE(list6[2] == 8);
    }

    SECTION("Vector resize when reaching full capacity"){
        DSVector<int> list3;
        list3.push_back(2);
        list3.push_back(4);
        list3.push_back(6);
        list3.push_back(8);
        REQUIRE(list3.getCapacity()==5);
        REQUIRE(list3[0] == 2);
        REQUIRE(list3[1] == 4);
        REQUIRE(list3[2] == 6);
        list3.push_back(10);
        list3.push_back(12);
        list3.push_back(14);
        list3.push_back(16);
        REQUIRE(list3.getCapacity()==10);
        REQUIRE(list3[5] == 12);
        REQUIRE(list3[6] == 14);
        REQUIRE(list3[7] == 16);
    }

    SECTION("Vector copy assignment"){
        DSVector<int> list4;
        list4.push_back(3);
        list4.push_back(6);
        list4.push_back(9);
        list4.push_back(12);
        DSVector<int> list5=list4;
        REQUIRE(list5[0] == 3);
        REQUIRE(list5[1] == 6);
        REQUIRE(list5[2] == 9);
        REQUIRE(list5[3] == 12);
    }
}