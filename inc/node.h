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
#ifndef RDT_NODE_H
#define RDT_NODE_H

typedef int (*RDTCopyHandler)(void**, void*);
typedef int (*RDTFreeHandler)(void**);
typedef int (*RDTCompareHandler)(void*, void*);

typedef struct _RDTNode RDTNode;

#include <stdlib.h>

/**
* @brief
* Creates a new empty node
* @param new_node direction of the pointer that will point to the new node
* @param function_copy pointer to the function that will copy the data contained in this node
* @param function_free pointer to the function that will free the data contained in this node
* @param function_compare pointer to the function that will compare the data of the node with other data
*
* @return 0 when fails to allocate memory
* @return -1 when new_node is NULL
* @return -2 when function_copy is NULL
* @return -3 when function_free is NULL
* @return -4 when function_compare is NULL
* @return -5 when fails to allocate memory
* @return 1 when everything OK
*/
int rdt_node_create(RDTNode** new_node, RDTCopyHandler function_copy, RDTFreeHandler function_free, RDTCompareHandler function_compare);

/**
* @brief
* Copies a node
* @param destiny_node direction of the pointer that will point to the copy
* @param origin_node pointer to the node that is going to be copied
*
* @return -1 when destiny_node is NULL
* @return -2 when *destiny_node is not NULL
* @return -3 when origin_node is NULL
* @return -4 when there is no function_copy in the origin_node
* @return -5 when fails to alloc memory for the new node
* @return function_copy return value
*/
int rdt_node_copy(RDTNode** destiny_node, RDTNode* origin_node);

/**
* @brief
* Frees a node
* @param node direction of the pointer to the node that will be free
*
* @return 0 when node is NULL
* @return -1 when *node is NULL
* @return -2 when there is no function_free in the node
* @return function_free return value
*/
int rdt_node_free(RDTNode** node);

/**
* @brief
* Gets the data of a node
* @param node pointer to the node
*
* @return pointer to the data
*/
void* rdt_node_get_data(RDTNode* node);

/**
* @brief
* Gets a pointer to the structure which the node is part of
* @param node pointer to the node
*
* @return pointer to the parent structure
*/
void* rdt_node_get_parent_structure(RDTNode* node);

/**
* @brief
* Sets the data of a node
* @param node pointer to the node
* @param data pointer to the data
*
* @return -1 when node is NULL
* @return -2 when data is NULL
* @return 1 when everything OK
*/
int rdt_node_set_data(RDTNode* node, void* data);

/**
* @brief
* Sets the structure which the node is part of
* @param node the node to set the parent structure
* @param parent_structure the structure that will be the parent of this node
*
* @return 1 when everything OK, -1 if not
*/
int rdt_node_set_parent_structure(RDTNode* node, void* parent_structure);

/**
* @brief
* Gets the node at the left of a node
* @param node pointer to the node
*
* @return pointer to the node at the left
*/
RDTNode* rdt_node_get_left(RDTNode* node);

/**
* @brief
* Gets the node at the right of a node
* @param node pointer to the node
*
* @return pointer to the node at the right
*/
RDTNode* rdt_node_get_right(RDTNode* node);

/**
* @brief
* Sets the node at the left of a node
* @param node pointer to the node
* @param left_node pointer to the node that will be at the left
*
*
*/
void rdt_node_set_left(RDTNode* node, RDTNode* left_node);

/**
* @brief
* Sets the node at the right of a node
* @param node pointer to the node
* @param right_node pointer to the node that will be at the right
*
*
*/
void rdt_node_set_right(RDTNode* node, RDTNode* right_node);

/**
* @brief
* Gets the pointer to a function that will copy the data in the node
* @param node pointer to the node
*
* @return pointer to the copy function
*/
RDTCopyHandler rdt_node_get_function_copy(RDTNode* node);

/**
* @brief
* Gets the pointer to a function that will free the data in the node
* @param node pointer to the node
*
* @return pointer to the free function
*/
RDTFreeHandler rdt_node_get_function_free(RDTNode* node);

/**
* @brief
* Gets the pointer to a function that will compare the data in the node
* @param node pointer to the node
*
* @return pointer to the compare function
*/
RDTCompareHandler rdt_node_get_function_compare(RDTNode* node);

#endif
