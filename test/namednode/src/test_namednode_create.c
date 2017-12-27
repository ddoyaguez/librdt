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
#include "namednode.h"
#include "test_namednode.h"

/*This test makes sure that when the first parameter is NULL the ret is -1*/
int test_namednode_create_1() {
  int ret;

  ret = rdt_namednode_create(NULL, NULL, NULL, NULL, NULL);
  if (ret != -1) {
    return 0;
  }

  return 1;
}

/*This test makes sure that the second parameter is NULL the ret is -2*/
int test_namednode_create_2() {
  RDTNamedNode* node;
  int ret;

  ret = rdt_namednode_create(&node, NULL, NULL, NULL, NULL);
  if (ret != -2) {
    return 0;
  }

  return 1;
}

/*This test makes sure that the third parameter is NULL the ret is -3*/
int test_namednode_create_3() {
  RDTNode* node;
  int ret;

  ret = rdt_namednode_create(&node, tn_copy, NULL, NULL, NULL);
  if (ret != -3) {
    return 0;
  }

  return 1;
}

/*This test makes sure that the fourth parameter is NULL the ret is -4*/
int test_namednode_create_4() {
  RDTNamedNode* node;
  int ret;

  ret = rdt_namednode_create(&node, tn_copy, tn_free, NULL, NULL);
  if (ret != -4) {
    return 0;
  }

  return 1;
}

/*This test makes sure that the fifth parameter is NULL the ret is -5*/
int test_namednode_create_5() {
	RDTNamedNode* node;
	int ret;

	ret = rdt_namednode_create(&node, tn_copy, tn_free, tn_compare, NULL);
    if (ret != -5) {
      return 0;
    }

    return 1;
}


/*This test makes sure that the create function actually allocs memory*/
int test_namednode_create_6() {
  RDTNamedNode* node;
  int ret;

  ret = rdt_namednode_create(&node, tn_copy, tn_free, tn_compare, "TeSt");
  if (ret != 1) {
    return 0;
  }
  if (!node) {
    return -1;
  }

  ret = rdt_namednode_free(&node);
  if (ret != 1) {
    return -2;
  }
  if (node) {
    return -3;
  }

  return 1;
}
