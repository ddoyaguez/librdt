/*
---
Copyright 2017 David Doyaguez Sanchez (daviddoyaguez@gmail.com)
---
This file is part of LibRDT.

    LibRDT is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    LibRDT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with LibRDT.  If not, see <http://www.gnu.org/licenses/>.
---
*/
#ifndef TEST_LIST_H
#define TEST_LIST_H
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*Auxiliar functions*/
/**
* @brief
* Copies a data (allocs memory)
*
* @param d reference to the pointer that will point to the copied data
* @param o pointer to the data that will be copied
*
* @return 0 if any parameter is NULL
* @return 1 if everything OK
*/
int tl_copy(void** d, void* o);

/**
* @brief
* Frees a data
* @param d reference to the pointer that points to a data that will be free
*
* @return 0 if d is NULL
* @return 1 if everything OK
*/
int tl_free(void** d);

/**
* @brief
* Compares two data
* @param d first data
* @param o second data
*
* @return 0 if the two data are equal or if one of two is NULL
* @return what strcmp returns
*/
int tl_compare(void* d, void* o);

/**
* @brief
* Generates a dinamic memory allocated string
* @param s string to malloc
*
* @return pointer to the new allocated string
*/
char* tl_generate_string(char* s);

/*test_list_create.c functions*/
/**
* @brief
* Tests if passing NULL to rdt_list_create produces -1
*
* @return 0 on test failure
* @return 1 on test success
*/
int test_list_create_1();

/**
* @brief
* Tests if memory is well free
*
* @return 0 on rdt_list_create failure (bad return)
* @return -1 on rdt_list_create failure (not alloc memory)
* @return -2 on rdt_list_free failure (bad return)
* @return -3 on rdt_list_free failure (free pointer not NULL)
* @return 1 on test success
*/
int test_list_create_2();

/**
* @brief
* Test makes sure that the create function makes the element count start in 0
*
* @return 0 on rdt_list_create failure (bad return)
* @return -1 on rdt_list_count failure (count not zero)
* @return 1 on test success
*/
int test_list_create_3();

/*test_list_insert.c functions*/
/**
* @brief
* Tests if passing NULL to rdt_list_insert_beginning arguments produces -1
*
* @return 0 on test failure
* @return 1 on test success
*/
int test_list_insert_1();

/**
* @brief
* Tests if passing NULL to rdt_list_insert_ending arguments produces -1
*
* @return 0 on test failure
* @return 1 on test success
*/
int test_list_insert_2();

/**
* @brief
* Tests if passing NULL to rdt_list_insert_beginning second argument produces -2
*
* @return 0 on test failure
* @return 1 on test success
*/
int test_list_insert_3();

/**
* @brief
* Tests if passing NULL to rdt_list_insert_ending second argument produces -2
*
* @return 0 on test failure
* @return 1 on test success
*/
int test_list_insert_4();

/**
* @brief
* Tests that when the list is empty, the first element is inserted (beginning)
*
* @return 0 on rdt_list_insert_beginning failure (bad return)
* @return -1 on rdt_list_search_beginning failure (element not found)
* @return -2 on rdt_list_search_ending failure (element not found)
* @return -3 on rdt_list_search_ending failure (position not zero)
* @return -4 on search failure (element not the same on beginning and ending)
* @return -5 on rdt_node_get_parent_structure failure (node not part of list)
* @return 1 on test success
*/
int test_list_insert_5();

/**
* @brief
* Tests that when the list is empty, the first element is inserted (ending)
*
* @return 0 on rdt_list_insert_ending failure (bad return)
* @return -1 on rdt_list_search_beginning failure (element not found)
* @return -2 on rdt_list_search_ending failure (element not found)
* @return -3 on rdt_list_search_ending failure (position not zero)
* @return -4 on search failure (element not the same on beginning and ending)
* @return -5 on rdt_node_get_parent_structure failure (node not part of list)
* @return 1 on test success
*/
int test_list_insert_6();

/**
* @brief
* Tests that when three elements are inserted, the order is OK (beginning)
*
* @return 0 on search element 1 failure (element not found)
* @return -1 on search element 2 failure (element not found)
* @return -2 on search element 3 failure (element not found)
* @return -3 on order failure (node 3 is not at the left of node 2)
* @return -4 on order failure (node 1 is not at the right of node 2)
* @return -5 on order failure (node 2 is not at the left of node 1)
* @return -6 on order failure (node 3 is not at the right of node 1)
* @return -7 on order failure (node 1 is not at the left of node 3)
* @return -8 on order failure (node 2 is not at the right of node 3)
* @return 1 on test success
*/
int test_list_insert_7();

/**
* @brief
* Tests that when three elements are inserted, the order is OK (ending)
*
* @return 0 on search element 1 failure (element not found)
* @return -1 on search element 2 failure (element not found)
* @return -2 on search element 3 failure (element not found)
* @return -3 on order failure (node 1 is not at the left of node 2)
* @return -4 on order failure (node 3 is not at the right of node 2)
* @return -5 on order failure (node 3 is not at the left of node 1)
* @return -6 on order failure (node 2 is not at the right of node 1)
* @return -7 on order failure (node 2 is not at the left of node 3)
* @return -8 on order failure (node 1 is not at the right of node 3)
* @return 1 on test success
*/
int test_list_insert_8();

/*test_list_remove.c functions*/
/**
* @brief
* Tests if passing NULL to rdt_list_remove arguments produces -1
*
* @return 0 on test failure
* @return 1 on test success
*/
int test_list_remove_1();

/**
* @brief
* Tests if passing NULL to rdt_list_remove second argument produces -2
*
* @return 0 on test failure
* @return 1 on test success
*/
int test_list_remove_2();

/**
* @brief
* Tests that remove returns -3 when trying to remove a node from an empty list
*
* @return 0 on test failure
* @return 1 on test success
*/
int test_list_remove_3();

/**
* @brief
* Tests that remove returns -4 when trying to remove a node that does not belong to the list
*
* @return 0 on test failure
* @return 1 on test success
*/
int test_list_remove_4();

/**
* @brief
* Tests that the removal of the root when there is only the root is correct
*
* @return 0 on rdt_list_remove failure (bad return)
* @return -1 on rdt_list_count failure (bad count)
* @return -2 on rdt_node_get_parent_structure failure (not NULL)
* @return 1 on test success
*/
int test_list_remove_5();

#endif
