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

/*This test makes sure that when the first parameter is NULL the ret is -1*/
int test_bintree_create_1() {
  int ret;

  ret = rdt_bintree_create(NULL);
  if (ret != -1) {
    return 0;
  }

  return 1;
}

/*This test makes sure that the create function actually allocs memory*/
int test_bintree_create_2() {
  RDTBintree* bintree;
  int ret;

  ret = rdt_bintree_create(&bintree);
  if (ret != 1) {
    return 0;
  }
  if (!bintree) {
    return -1;
  }

  ret = rdt_bintree_free(&bintree);
  if (ret != 1) {
    return -2;
  }
  if (bintree) {
    return -3;
  }

  return 1;
}

/*This test makes sure that the create function makes the element count start in 0*/
int test_bintree_create_3() {
  RDTBintree* bintree;
  int ret;

  ret = rdt_bintree_create(&bintree);
  if (ret != 1) {
    return 0;
  }

  ret = rdt_bintree_count(bintree);
  if (ret) {
    return -1;
  }

  ret = rdt_bintree_free(&bintree);

  return 1;
}
