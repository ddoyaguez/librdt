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
#include "test_bintree.h"

/*This test makes sure that the insert returns 0 when the first argument is NULL*/
int test_bintree_insert_1() {
  int ret;

  ret = rdt_bintree_insert(NULL, NULL);
  if (ret != 0) {
    return 0;
  }

  return 1;
}


/*This test makes sure that the insert beginning returns -1 when the second argument is NULL*/
int test_bintree_insert_2() {
  RDTBintree* bintree = NULL;
  int ret;

  rdt_bintree_create(&bintree);

  ret = rdt_bintree_insert(bintree, NULL);
  if (ret != -1) {
    return 0;
  }

  rdt_bintree_free(&bintree);

  return 1;
}


/*This test makes sure that when the bintree is empty, the first element is inserted*/
int test_bintree_insert_3() {
  RDTBintree* bintree = NULL;
  RDTNode* node = NULL;
  RDTNode* search_node = NULL;
  void* data = NULL;
  int ret;

  rdt_bintree_create(&bintree);
  rdt_node_create(&node, tb_copy, tb_free, tb_compare);
  data = tb_generate_string("TeSt");
  rdt_node_set_data(node, data);
  ret = rdt_bintree_insert(bintree, node);
  if (ret != 1) {
    rdt_bintree_free(&bintree);
    rdt_node_free(&node);
    return 0;
  }
  search_node = rdt_bintree_search(bintree, data);
  if (!search_node) {
    rdt_bintree_free(&bintree);
    return -1;
  }

  if (rdt_node_get_parent_structure(node) != bintree) {
    rdt_bintree_free(&bintree);
    return -2;
  }


  rdt_bintree_free(&bintree);

  return 1;
}


/*This test makes sure that when three elements are inserted, the order is OK*/
int test_bintree_insert_4() {
  RDTBintree* bintree = NULL;
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
  rdt_bintree_create(&bintree);
  rdt_node_create(&node1, tb_copy, tb_free, tb_compare);
  rdt_node_create(&node2, tb_copy, tb_free, tb_compare);
  rdt_node_create(&node3, tb_copy, tb_free, tb_compare);
  data1 = tb_generate_string("Test1");
  data2 = tb_generate_string("Test0");
  data3 = tb_generate_string("Test2");
  rdt_node_set_data(node1, data1);
  rdt_node_set_data(node2, data2);
  rdt_node_set_data(node3, data3);

  /*Insertion process*/
  rdt_bintree_insert(bintree, node1);
  rdt_bintree_insert(bintree, node2);
  rdt_bintree_insert(bintree, node3);

  /*Search all the nodes*/
  search_node1 = rdt_bintree_search(bintree, data1);
  search_node2 = rdt_bintree_search(bintree, data2);
  search_node3 = rdt_bintree_search(bintree, data3);

  /*Check if search is OK*/
  if (search_node1 != node1) {
    rdt_bintree_free(&bintree);
    return 0;
  }
  if (search_node2 != node2) {
    rdt_bintree_free(&bintree);
    return -1;
  }
  if (search_node3 != node3) {
    rdt_bintree_free(&bintree);
    return -2;
  }

  /*Check if order is OK (reference is node1)*/
  if (rdt_node_get_left(search_node1) != search_node2) {
    rdt_bintree_free(&bintree);
    return -3;
  }

  if (rdt_node_get_right(search_node1) != search_node3) {
    rdt_bintree_free(&bintree);
    return -4;
  }

  rdt_bintree_free(&bintree);

  return 1;
}
