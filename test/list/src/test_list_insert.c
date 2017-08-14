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

/*This test makes sure that the insert beginning returns -1 when the first argument is NULL*/
int test_list_insert_1() {
  int ret;

  ret = rdt_list_insert_beginning(NULL, NULL);
  if (ret != -1) {
    return 0;
  }

  return 1;
}

/*This test makes sure that the insert ending returns -1 when the first argument is NULL*/
int test_list_insert_2() {
  int ret;

  ret = rdt_list_insert_ending(NULL, NULL);
  if (ret != -1) {
    return 0;
  }

  return 1;
}

/*This test makes sure that the insert beginning returns -2 when the second argument is NULL*/
int test_list_insert_3() {
  RDTList* list = NULL;
  int ret;

  rdt_list_create(&list);

  ret = rdt_list_insert_beginning(list, NULL);
  if (ret != -2) {
    return 0;
  }

  rdt_list_free(&list);

  return 1;
}

/*This test makes sure that the insert ending returns -2 when the second argument is NULL*/
int test_list_insert_4() {
  RDTList* list = NULL;
  int ret;

  rdt_list_create(&list);

  ret = rdt_list_insert_ending(list, NULL);
  if (ret != -2) {
    return 0;
  }

  rdt_list_free(&list);

  return 1;
}

/*This test makes sure that when the list is empty, the first element is inserted (beginning)*/
int test_list_insert_5() {
  RDTList* list = NULL;
  RDTNode* node = NULL;
  RDTNode* search_node1 = NULL;
  RDTNode* search_node2 = NULL;
  void* data = NULL;
  int ret;
  int pos1 = -1;
  int pos2 = -1;

  rdt_list_create(&list);
  rdt_node_create(&node, tl_copy, tl_free, tl_compare);
  data = tl_generate_string("TeSt");
  rdt_node_set_data(node, data);
  ret = rdt_list_insert_beginning(list, node);
  if (ret != 1) {
    rdt_list_free(&list);
    rdt_node_free(&node);
    return 0;
  }
  search_node1 = rdt_list_search_beginning(list, data, &pos1);
  if (!search_node1) {
    rdt_list_free(&list);
    return -1;
  }
  search_node2 = rdt_list_search_ending(list, data, &pos2);
  if (!search_node2) {
    rdt_list_free(&list);
    return -2;
  }

  if (pos1 != 0) {
    rdt_list_free(&list);
    return -3;
  }

  if (pos1 != pos2) {
    rdt_list_free(&list);
    return -4;
  }

  if (rdt_node_get_parent_structure(node) != list) {
    rdt_list_free(&list);
    return -5;
  }


  rdt_list_free(&list);

  return 1;
}

/*This test makes sure that when the list is empty, the first element is inserted (ending)*/
int test_list_insert_6() {
  RDTList* list = NULL;
  RDTNode* node = NULL;
  RDTNode* search_node1 = NULL;
  RDTNode* search_node2 = NULL;
  void* data = NULL;
  int ret;
  int pos1 = -1;
  int pos2 = -1;

  rdt_list_create(&list);
  rdt_node_create(&node, tl_copy, tl_free, tl_compare);
  data = tl_generate_string("TeSt");
  rdt_node_set_data(node, data);
  ret = rdt_list_insert_ending(list, node);
  if (ret != 1) {
    rdt_list_free(&list);
    rdt_node_free(&node);
    return 0;
  }
  search_node1 = rdt_list_search_beginning(list, data, &pos1);
  if (!search_node1) {
    rdt_list_free(&list);
    return -1;
  }
  search_node2 = rdt_list_search_ending(list, data, &pos2);
  if (!search_node2) {
    rdt_list_free(&list);
    return -2;
  }

  if (pos1 != 0) {
    rdt_list_free(&list);
    return -3;
  }

  if (pos1 != pos2) {
    rdt_list_free(&list);
    return -4;
  }

  if (rdt_node_get_parent_structure(node) != list) {
    rdt_list_free(&list);
    return -5;
  }


  rdt_list_free(&list);

  return 1;
}

/*This test makes sure that when three elements are inserted, the order is OK (beginning)*/
int test_list_insert_7() {
  RDTList* list = NULL;
  RDTNode* node1 = NULL;
  RDTNode* node2 = NULL;
  RDTNode* node3 = NULL;
  RDTNode* search_node1 = NULL;
  RDTNode* search_node2 = NULL;
  RDTNode* search_node3 = NULL;
  void* data1 = NULL;
  void* data2 = NULL;
  void* data3 = NULL;

  /*Initialization process*/
  rdt_list_create(&list);
  rdt_node_create(&node1, tl_copy, tl_free, tl_compare);
  rdt_node_create(&node2, tl_copy, tl_free, tl_compare);
  rdt_node_create(&node3, tl_copy, tl_free, tl_compare);
  data1 = tl_generate_string("TeSt1");
  data2 = tl_generate_string("TeS2t");
  data3 = tl_generate_string("Te3St");
  rdt_node_set_data(node1, data1);
  rdt_node_set_data(node2, data2);
  rdt_node_set_data(node3, data3);

  /*Insertion process*/
  rdt_list_insert_beginning(list, node1);
  rdt_list_insert_beginning(list, node2);
  rdt_list_insert_beginning(list, node3);

  /*Search all the nodes*/
  search_node1 = rdt_list_search_beginning(list, data1, NULL);
  search_node2 = rdt_list_search_beginning(list, data2, NULL);
  search_node3 = rdt_list_search_beginning(list, data3, NULL);

  /*Check if search is OK*/
  if (search_node1 != node1) {
    rdt_list_free(&list);
    return 0;
  }
  if (search_node2 != node2) {
    rdt_list_free(&list);
    return -1;
  }
  if (search_node3 != node3) {
    rdt_list_free(&list);
    return -2;
  }

  /*Check if order is OK (reference is node2)*/
  if (rdt_node_get_left(node2) != node3) {
    rdt_list_free(&list);
    return -3;
  }
  if (rdt_node_get_right(node2) != node1) {
    rdt_list_free(&list);
    return -4;
  }

  /*Check if order is OK (reference is node1)*/
  if (rdt_node_get_left(node1) != node2) {
    rdt_list_free(&list);
    return -5;
  }
  if (rdt_node_get_right(node1) != node3) {
    rdt_list_free(&list);
    return -6;
  }

  /*Check if order is OK (reference is node3)*/
  if (rdt_node_get_left(node3) != node1) {
    rdt_list_free(&list);
    return -7;
  }
  if (rdt_node_get_right(node3) != node2) {
    rdt_list_free(&list);
    return -8;
  }

  rdt_list_free(&list);

  return 1;
}

/*This test makes sure that when three elements are inserted, the order is OK (ending)*/
int test_list_insert_8() {
  RDTList* list = NULL;
  RDTNode* node1 = NULL;
  RDTNode* node2 = NULL;
  RDTNode* node3 = NULL;
  RDTNode* search_node1 = NULL;
  RDTNode* search_node2 = NULL;
  RDTNode* search_node3 = NULL;
  void* data1 = NULL;
  void* data2 = NULL;
  void* data3 = NULL;

  /*Initialization process*/
  rdt_list_create(&list);
  rdt_node_create(&node1, tl_copy, tl_free, tl_compare);
  rdt_node_create(&node2, tl_copy, tl_free, tl_compare);
  rdt_node_create(&node3, tl_copy, tl_free, tl_compare);
  data1 = tl_generate_string("TeSt1");
  data2 = tl_generate_string("TeS2t");
  data3 = tl_generate_string("Te3St");
  rdt_node_set_data(node1, data1);
  rdt_node_set_data(node2, data2);
  rdt_node_set_data(node3, data3);

  /*Insertion process*/
  rdt_list_insert_ending(list, node1);
  rdt_list_insert_ending(list, node2);
  rdt_list_insert_ending(list, node3);

  /*Search all the nodes*/
  search_node1 = rdt_list_search_ending(list, data1, NULL);
  search_node2 = rdt_list_search_ending(list, data2, NULL);
  search_node3 = rdt_list_search_ending(list, data3, NULL);

  /*Check if search is OK*/
  if (search_node1 != node1) {
    rdt_list_free(&list);
    return 0;
  }
  if (search_node2 != node2) {
    rdt_list_free(&list);
    return -1;
  }
  if (search_node3 != node3) {
    rdt_list_free(&list);
    return -2;
  }

  /*Check if order is OK (reference is node2)*/
  if (rdt_node_get_left(node2) != node1) {
    rdt_list_free(&list);
    return -3;
  }
  if (rdt_node_get_right(node2) != node3) {
    rdt_list_free(&list);
    return -4;
  }

  /*Check if order is OK (reference is node1)*/
  if (rdt_node_get_left(node1) != node3) {
    rdt_list_free(&list);
    return -5;
  }
  if (rdt_node_get_right(node1) != node2) {
    rdt_list_free(&list);
    return -6;
  }

  /*Check if order is OK (reference is node3)*/
  if (rdt_node_get_left(node3) != node2) {
    rdt_list_free(&list);
    return -7;
  }
  if (rdt_node_get_right(node3) != node1) {
    rdt_list_free(&list);
    return -8;
  }

  rdt_list_free(&list);

  return 1;
}
