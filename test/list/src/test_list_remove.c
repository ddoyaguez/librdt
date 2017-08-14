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
#include "test_list.h"

/*This test makes sure that the remove returns -1 when the first argument is NULL*/
int test_list_remove_1() {
  int ret;

  ret = rdt_list_remove(NULL, NULL);
  if (ret != -1) {
    return 0;
  }

  return 1;
}

/*This test makes sure that the remove returns -2 when the second argument is NULL*/
int test_list_remove_2() {
  RDTList* list = NULL;
  int ret;

  rdt_list_create(&list);

  ret = rdt_list_remove(list, NULL);
  if (ret != -2) {
    return 0;
  }

  return 1;
}

/*This test makes sure that remove returns -3 when trying to remove a node from an empty list*/
int test_list_remove_3() {
  RDTList* list = NULL;
  RDTNode* node = NULL;
  int ret;

  rdt_list_create(&list);
  rdt_node_create(&node, tl_copy, tl_free, tl_compare);

  ret = rdt_list_remove(list, node);
  if (ret != -3) {
    rdt_list_free(&list);
    rdt_node_free(&node);
    return 0;
  }

  rdt_list_free(&list);

  return 1;
}

/*This test makes sure that remove returns -4 when trying to remove a node that does not belong to the list*/
int test_list_remove_4() {
  RDTList* list = NULL;
  RDTNode* node1 = NULL;
  RDTNode* node2 = NULL;
  int ret;

  rdt_list_create(&list);
  rdt_node_create(&node1, tl_copy, tl_free, tl_compare);
  rdt_node_create(&node2, tl_copy, tl_free, tl_compare);
  rdt_list_insert_beginning(list, node1);

  ret = rdt_list_remove(list, node2);
  if (ret != -4) {
    rdt_list_free(&list);
    rdt_node_free(&node1);
    rdt_node_free(&node2);
    return 0;
  }

  rdt_list_free(&list);
  rdt_node_free(&node2);

  return 1;
}

/*This test makes sure that the removal of the root when there is only the root is correct*/
int test_list_remove_5() {
  RDTList* list = NULL;
  RDTNode* node1 = NULL;
  int ret;

  rdt_list_create(&list);
  rdt_node_create(&node1, tl_copy, tl_free, tl_compare);
  rdt_list_insert_beginning(list, node1);

  ret = rdt_list_remove(list, node1);
  if (ret != 1) {
    rdt_list_free(&list);
    return 0;
  }
  if (rdt_list_count(list) != 0) {
    rdt_list_free(&list);
    rdt_node_free(&node1);
    return -1;
  }
  if (rdt_node_get_parent_structure(node1) != NULL) {
    rdt_list_free(&list);
    rdt_node_free(&node1);
    return -2;
  }

  rdt_list_free(&list);
  rdt_node_free(&node1);

  return 1;
}
