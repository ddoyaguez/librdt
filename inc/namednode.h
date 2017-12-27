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
#ifndef RDT_NAMEDNODE_H
#define RDT_NAMEDNODE_H

typedef struct _RDTNamedNode RDTNamedNode;

#include "node.h"

/**
* @brief
* Creates a new empty node
* @param new_named_node direction of the pointer that will point to the new named node
* @param function_copy pointer to the function that will copy the data contained in this node
* @param function_free pointer to the function that will free the data contained in this node
* @param function_compare pointer to the function that will compare the data of the node with other data
* @param name string with the name of the node
*
* @return 0 when fails to allocate memory
* @return -1 when new_node is NULL
* @return -2 when function_copy is NULL
* @return -3 when function_free is NULL
* @return -4 when function_compare is NULL
* @return -5 when fails to allocate memory
* @return -6 when strlen(name) < 1
* @return -7 when fails to allocate memory
* @return 1 when everything OK
*/
int rdt_namednode_create(RDTNamedNode** new_named_node, RDTCopyHandler function_copy, RDTFreeHandler function_free, RDTCompareHandler function_compare, char* name);

/**
* @brief
* Copies a named node
* @param destiny_node direction of the pointer that will point to the copy
* @param origin_node pointer to the named node that is going to be copied
*
* @return -4 when there is no function_copy in the origin_node
* @return -5 when fails to alloc memory for the new named node
* @return -6 when destiny_node is NULL
* @return -7 when *destiny_node is not NULL
* @return -8 when origin_node is NULL
* @return -9 when the copy fails somehow (call to rdt_node_copy failed)
* @return function_copy return value
*/
int rdt_namednode_copy(RDTNamedNode** destiny_node, RDTNamedNode* origin_node);

/**
* @brief
* Frees a named node
* @param node direction of the pointer to the named node that will be free
*
* @return 0 when inner node is NULL
* @return -1 when *(inner node) is NULL
* @return -2 when there is no function_free in the inner node
* @return -3 when node is NULL
* @return -4 when *node is NULL
* @return function_free return value
*/
int rdt_namednode_free(RDTNamedNode** node);

/**
* @brief
* Gets the inner node of a named node
* @param node pointer to the named node
*
* @return NULL if something went wrong
* @return a pointer to the inner node
*/
RDTNode* rdt_namednode_get_node(RDTNamedNode* node);

/**
* @brief
* Gets the name of a named node
* @param node pointer to the named node
*
* @return NULL if something went wrong
* @return a pointer to the name of the node
*/
char* rdt_namednode_get_name(RDTNamedNode* node);

#endif
