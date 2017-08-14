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
#ifndef TEST_BINTREE_H
#define TEST_BINTREE_H
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "bintree.h"

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
int tb_copy(void** d, void* o);

/**
* @brief
* Frees a data
* @param d reference to the pointer that points to a data that will be free
*
* @return 0 if d is NULL
* @return 1 if everything OK
*/
int tb_free(void** d);

/**
* @brief
* Compares two data
* @param d first data
* @param o second data
*
* @return 0 if the two data are equal or if one of two is NULL
* @return what strcmp returns
*/
int tb_compare(void* d, void* o);

/**
* @brief
* Generates a dinamic memory allocated string
* @param s string to malloc
*
* @return pointer to the new allocated string
*/
char* tb_generate_string(char* s);

/*test_bintree_create.c functions*/
/**
* @brief
* Tests if passing NULL to rdt_bintree_create produces -1
*
* @return 0 on test failure
* @return 1 on test success
*/
int test_bintree_create_1();

/**
* @brief
* Tests if memory is well free
*
* @return 0 on rdt_bintree_create failure (bad return)
* @return -1 on rdt_bintree_create failure (not alloc memory)
* @return -2 on rdt_bintree_free failure (bad return)
* @return -3 on rdt_bintree_free failure (free pointer not NULL)
* @return 1 on test success
*/
int test_bintree_create_2();

/**
* @brief
* Test makes sure that the create function makes the element count start in 0
*
* @return 0 on rdt_bintree_create failure (bad return)
* @return -1 on rdt_bintree_count failure (count not zero)
* @return 1 on test success
*/
int test_bintree_create_3();

/*test_list_insert.c functions*/
/**
* @brief
* Tests if passing NULL to rdt_bintree_insert arguments produces 0
*
* @return 0 on test failure
* @return 1 on test success
*/
int test_bintree_insert_1();

/**
* @brief
* Tests if passing NULL to rdt_bintree_insert second argument produces -1
*
* @return 0 on test failure
* @return 1 on test success
*/
int test_bintree_insert_2();

/**
* @brief
* Tests that when the bintree is empty, the first element is inserted
*
* @return 0 on rdt_bintree_insert failure (bad return)
* @return -1 on rdt_bintree_search failure (not found element)
* @return -3 on rdt_node_get_parent_structure failure (bad return)
* @return 1 on test success
*/
int test_bintree_insert_3();

/**
* @brief
* Tests that when three elements are inserted, the order is OK
*
* @return 0 on search first element introduced failure (bad return)
* @return -1 on search second element introduced failure (bad return)
* @return -2 on search third element introduced failure (bad return)
* @return -3 on order failure (node at left of 1st introduced is not 2nd introduced)
* @return -4 on order failure (node at right of 1st introduced is not 3rd introduced)
* @return 1 on test success
*/
int test_bintree_insert_4();

#endif
