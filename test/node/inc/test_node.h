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
#ifndef TEST_NODE_H
#define TEST_NODE_H
#include <stdlib.h>
#include <string.h>

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
int tn_copy(void** d, void* o);

/**
* @brief
* Frees a data
* @param d reference to the pointer that points to a data that will be free
*
* @return 0 if d is NULL
* @return 1 if everything OK
*/
int tn_free(void** d);

/**
* @brief
* Compares two data
* @param d first data
* @param o second data
*
* @return 0 if the two data are equal or if one of two is NULL
* @return what strcmp returns
*/
int tn_compare(void* d, void* o);

/*test_node_create.c functions*/
/**
* @brief
* Tests that when the first parameter is NULL the ret is -1
*
* @return 0 on test failure
* @return 1 on test success
*/
int test_node_create_1();

/**
* @brief
* Tests that when the second parameter is NULL the ret is -2
*
* @return 0 on test failure
* @return 1 on test success
*/
int test_node_create_2();

/**
* @brief
* Tests that when the third parameter is NULL the ret is -3
*
* @return 0 on test failure
* @return 1 on test success
*/
int test_node_create_3();

/**
* @brief
* Tests that when the fourth parameter is NULL the ret is -4
*
* @return 0 on test failure
* @return 1 on test success
*/
int test_node_create_4();

/**
* @brief
* Tests that the create function actually allocs memory
*
* @return 0 on rdt_node_create failure (bad return)
* @return -1 on rdt_node_create failure (allocated pointer is NULL)
* @return -2 on rdt_node_free failure (bad return)
* @return -3 on rdt_node_free failure (pointer not NULL)
* @return 1 on test success
*/
int test_node_create_5();

/*test_node_copy.c functions*/
/**
* @brief
* Tests that when the first parameter is NULL the ret is -1
*
* @return 0 on test failure
* @return 1 on test success
*/
int test_node_copy_1();

/**
* @brief
* Tests that when the second parameter is NULL the ret is -2
*
* @return 0 on test failure
* @return 1 on test success
*/
int test_node_copy_2();

/**
* @brief
* Tests that there will not be possible to copy something in an used pointer
*
* @return 0 on test failure
* @return 1 on test success
*/
int test_node_copy_3();

/**
* @brief
* Tests that the copy works
*
* @return 0 on rdt_node_copy failure (bad return)
* @return -1 on rdt_node_get_data failure (null pointer)
* @return -2 on compare copy with original (compare function not 0)
*/
int test_node_copy_4();

#endif
