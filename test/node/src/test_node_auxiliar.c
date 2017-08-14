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
#include "test_node.h"

int tn_copy(void** d, void* o) {
  int len;

  if (!d || !o) {
    return 0;
  }

  len = strlen(o);
  (*d) = calloc(len+1, sizeof(char));
  strcpy((char*)(*d), o);

  return 1;

}

int tn_free(void** d) {
  if (!d) {
    return 0;
  }
  if (*d) {
    free(*d);
  }
  return 1;
}

int tn_compare(void* d, void* o) {
  if (!d || !o) {
    return 0;
  }
  return strcmp((char*)d, (char*)o);
}
