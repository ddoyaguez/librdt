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
#include <stdio.h>
#include <stdlib.h>
#include "test_list.h"

#ifndef TEST_LIST_LAUNCHER_LENGTH
#define TEST_LIST_LAUNCHER_LENGTH 512
#endif

int main(int argc, char const *argv[]) {
  int results[TEST_LIST_LAUNCHER_LENGTH];
  int i, k, f;

  fprintf(stdout, "LibRDT test_list_launcher\n");
  fprintf(stdout, "=========================\n\n");
  f = 0;

  fprintf(stdout, " * Executing test_list_create tests...");
  fflush(stdout);
  i = 0;
  memset(results, 0, TEST_LIST_LAUNCHER_LENGTH);
  results[i] = test_list_create_1(); i++;
  results[i] = test_list_create_2(); i++;
  results[i] = test_list_create_3(); i++;
  for (k = 0; k < i; k++) {
    if (results[k] != 1) {
      fprintf(stdout, "\n    test %d failed with return value %d\n", k+1, results[k]);
      f = 1;
    }
  }
  if (!f) {
    fprintf(stdout, "\tOK\n\n");
  } else {
    fprintf(stdout, "\n");
  }

  fprintf(stdout, " * Executing test_list_insert tests...");
  fflush(stdout);
  i = 0;
  memset(results, 0, TEST_LIST_LAUNCHER_LENGTH);
  results[i] = test_list_insert_1(); i++;
  results[i] = test_list_insert_2(); i++;
  results[i] = test_list_insert_3(); i++;
  results[i] = test_list_insert_4(); i++;
  results[i] = test_list_insert_5(); i++;
  results[i] = test_list_insert_6(); i++;
  results[i] = test_list_insert_7(); i++;
  results[i] = test_list_insert_8(); i++;
  for (k = 0; k < i; k++) {
    if (results[k] != 1) {
      fprintf(stdout, "\n    test %d failed with return value %d\n", k+1, results[k]);
      f = 1;
    }
  }
  if (!f) {
    fprintf(stdout, "\tOK\n\n");
  } else {
    fprintf(stdout, "\n");
  }

  fprintf(stdout, " * Executing test_list_remove tests...");
  fflush(stdout);
  i = 0;
  memset(results, 0, TEST_LIST_LAUNCHER_LENGTH);
  results[i] = test_list_remove_1(); i++;
  results[i] = test_list_remove_2(); i++;
  results[i] = test_list_remove_3(); i++;
  results[i] = test_list_remove_4(); i++;
  results[i] = test_list_remove_5(); i++;
  /*results[i] = test_list_remove_6(); i++;*/
  /*results[i] = test_list_remove_7(); i++;*/
  /*results[i] = test_list_remove_8(); i++;*/
  for (k = 0; k < i; k++) {
    if (results[k] != 1) {
      fprintf(stdout, "\n    test %d failed with return value %d\n", k+1, results[k]);
      f = 1;
    }
  }
  if (!f) {
    fprintf(stdout, "\tOK\n\n");
  } else {
    fprintf(stdout, "\n");
  }


  return 0;
}
