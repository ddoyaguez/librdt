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

/*This test makes sure that when the first parameter is NULL the ret is -1*/
int test_list_create_1() {
  int ret;

  ret = rdt_list_create(NULL);
  if (ret != -1) {
    return 0;
  }

  return 1;
}

/*This test makes sure that the create function actually allocs memory*/
int test_list_create_2() {
  RDTList* list;
  int ret;

  ret = rdt_list_create(&list);
  if (ret != 1) {
    return 0;
  }
  if (!list) {
    return -1;
  }

  ret = rdt_list_free(&list);
  if (ret != 1) {
    return -2;
  }
  if (list) {
    return -3;
  }

  return 1;
}

/*This test makes sure that the create function makes the element count start in 0*/
int test_list_create_3() {
  RDTList* list;
  int ret;

  ret = rdt_list_create(&list);
  if (ret != 1) {
    return 0;
  }

  ret = rdt_list_count(list);
  if (ret) {
    return -1;
  }

  ret = rdt_list_free(&list);

  return 1;
}
