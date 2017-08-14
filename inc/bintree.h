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
#ifndef RDT_BINTREE_H
#define RDT_BINTREE_H

typedef struct _RDTBintree RDTBintree;

#include <stdlib.h>
#include "node.h"

/**
* @brief
* Creates a new binary search tree
* @param new_bintree reference to the pointer that will point to the new binary tree
*
* @return -1 when new_bintree is NULL
* @return 0 when fails to allocate memory
* @return 1 when everything OK
*/
int rdt_bintree_create(RDTBintree** new_bintree);

/**
* @brief
* Inserts a node into the bintree
* @param bintree pointer to the binary tree
* @param node pointer to the node
*
* @return 0 when bintree is NULL
* @return -1 when node is NULL
* @return -2 when node has no comparation function
* @return -3 when data is in the tree
* @return 1 when everything is OK
*/
int rdt_bintree_insert(RDTBintree* bintree, RDTNode* node);

/**
* @brief
* Searches a data from the bintree and returns the node that contains such data
* @param bintree pointer to the binary tree
* @param data pointer to the data
*
* @return NULL if error ocurred
* @return pointer to the node that contains the data if it's inside the tree
*/
RDTNode* rdt_bintree_search(RDTBintree* bintree, void* data);

/**
* @brief
* Frees memory occupied by the tree and all its nodes
* @param bintree reference to the pointer that points to a bintree
*
* @return 0 if bintree is NULL
* @return -1 if (*bintree) is NULL
* @return 1 if everything OK
*/
int rdt_bintree_free(RDTBintree** bintree);

/*Auxiliar function used by rdt_bintree_free*/
void rdt_bintree_free_subtree(RDTBintree* parent_tree, RDTNode* subtree);

/**
* @brief
* Counts the number of elements in the bintree
* @param bintree pointer to the bintree
*
* @return -1 when bintree is NULL
* @return the number of elements in the bintree
*/
int rdt_bintree_count(RDTBintree* bintree);

#endif
