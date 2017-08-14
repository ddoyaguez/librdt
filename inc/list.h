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
#ifndef RDT_LIST_H
#define RDT_LIST_H

typedef struct _RDTList RDTList;

#include <stdlib.h>
#include "node.h"

/**
* @brief
* Creates a new empty list
* @param new_list direction of the pointer that will point to the new list
*
* @return 0 when not enough memory
* @return -1 when new_list is NULL
* @return 1 when everything OK
*/
int rdt_list_create(RDTList** new_list);

/**
* @brief
* Copies a list
* @param destiny_list direction of the pointer that will point to the copy of the list
* @param origin_list pointer that points to the original list
*
* @return 0 when origin_list has no elements
* @return -1 when destiny_list is NULL
* @return -2 when origin_list is NULL
* @return -3 when *destiny_list is not NULL
* @return -4 when not enough memory to create the destiny_list
* @return -5 when fails to copy a node
* @return 1 when everything OK
*/
int rdt_list_copy(RDTList** destiny_list, RDTList* origin_list);

/**
* @brief
* Frees a list and all it's attached nodes
* @param list direction of the pointer that points to the list that will be free
*
* @return 0 when *list is NULL
* @return -1 when list is NULL
* @return 1 when everything OK
*/
int rdt_list_free(RDTList** list);

/**
* @brief
* Inserts a node into a list, making the inserted node the root
* @param list pointer to the list
* @param node pointer to the node that will be inserted in the list
*
* @return -1 when list is NULL
* @return -2 when node is NULL
* @return 1 when everything OK
*/
int rdt_list_insert_beginning(RDTList* list, RDTNode* node);

/**
* @brief
* Inserts a node into a list, making the inserted node be at the left of the root
* @param list pointer to the list
* @param node pointer to the node that will be inserted in the list
*
* @return -1 when list is NULL
* @return -2 when node is NULL
* @return 1 when everything OK
*/
int rdt_list_insert_ending(RDTList* list, RDTNode* node);

/**
* @brief
* Searches for a specific data in the list. Starting by the root and moving to the right
* @param list pointer to the list
* @param data pointer to the data
* @param position pointer to an int that will indicate the distance of the node to the root
*
* @return the node that contains the data if it's in the list or NULL if not
*/
RDTNode* rdt_list_search_beginning(RDTList* list, void* data, int* position);

/**
* @brief
* Searches for a specific data in the list. Starting by the root and moving to the left
* @param list pointer to the list
* @param data pointer to the data
* @param position pointer to an int that will indicate the distance of the node to the root
*
* @return the node that contains the data if it's in the list or NULL if not
*/
RDTNode* rdt_list_search_ending(RDTList* list, void* data, int* position);

/**
* @brief
* Gets a node in a specific position in the list. 0 is the root
* A positive value of pos will get the pos-th node at the right of the root
* A negative value of pos will get the pos-th node at the left of the root
* @param list pointer to the list
* @param pos offset
*
* @return the wanted node
*/
RDTNode* rdt_list_get(RDTList* list, int pos);

/**
* @brief
* Removes a specific node in the list
* @param list pointer to the list
* @param node pointer to the node
*
* @return -1 when list is NULL
* @return -2 when node is NULL
* @return -3 when there are no elements in the list
* @return -4 when the node does not belong to the list
* @return 1 when everything OK
*/
int rdt_list_remove(RDTList* list, RDTNode* node);

/**
* @brief
* Counts the number of elements in the list
* @param list pointer to the list
*
* @return -1 when list is NULL
* @return the number of elements in the list
*/
int rdt_list_count(RDTList* list);

#endif
