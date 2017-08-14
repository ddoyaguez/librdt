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
#include "node.h"
#include "test_node.h"

/*This test makes sure that when the first parameter is NULL the ret is -1*/
int test_node_copy_1() {
  int ret;

  ret = rdt_node_copy(NULL, NULL);
  if (ret != -1) {
    return 0;
  }

  return 1;
}

/*This test makes sure that the second parameter is NULL the ret is -3*/
int test_node_copy_2() {
  RDTNode* node = NULL;
  int ret;

  ret = rdt_node_copy(&node, NULL);
  if (ret != -3) {
    return 0;
  }

  return 1;
}

/*This test makes sure that there will not be possible to copy something
 *in an used pointer*/
int test_node_copy_3() {
  RDTNode* node1 = NULL;
  RDTNode* node2 = NULL;
  int ret;

  ret = rdt_node_create(&node1, tn_copy, tn_free, tn_compare);
  ret = rdt_node_create(&node2, tn_copy, tn_free, tn_compare);

  ret = rdt_node_copy(&node2, node1);
  rdt_node_free(&node1);
  rdt_node_free(&node2);

  if (ret != -2) {
    return 0;
  }

  return 1;
}

/*This test makes sure that the copy works*/
int test_node_copy_4() {
  RDTNode* node1 = NULL;
  RDTNode* node2 = NULL;
  char* data1 = NULL;
  char* data2 = NULL;
  int ret;

  rdt_node_create(&node1, tn_copy, tn_free, tn_compare);
  data1 = calloc(5, sizeof(char));
  data1[0] = 'T'; data1[1] = 'e'; data1[2] = 'S'; data1[3] = 't'; data1[4] = 0;

  rdt_node_set_data(node1, data1);

  ret = rdt_node_copy(&node2, node1);
  if (ret < 1) {
    rdt_node_free(&node1);
    return 0;
  }

  data2 = rdt_node_get_data(node2);
  if (!data2) {
    rdt_node_free(&node1);
    return -1;
  }
  if (tn_compare(data1, data2)) {
    rdt_node_free(&node1);
    rdt_node_free(&node2);
    return -2;
  }

  rdt_node_free(&node1);
  rdt_node_free(&node2);

  return 1;
}
