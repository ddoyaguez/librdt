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
#include "list.h"

struct _RDTList {
  RDTNode* root;
  int count;
};

int rdt_list_create(RDTList** new_list) {
  if (!new_list) {
    return -1;
  }

  (*new_list) = calloc(1, sizeof(RDTList));
  if (!(*new_list)) {
    return 0;
  }

  return 1;
}

int rdt_list_copy(RDTList** destiny_list, RDTList* origin_list) {
  RDTNode* current_node = NULL;
  RDTNode* current_copy = NULL;
  RDTNode* previous_copy = NULL;
  int ret;

  if (!destiny_list) {
    return -1;
  }

  if (!origin_list) {
    return -2;
  }

  if (*destiny_list) {
    return -3;
  }

  if (!origin_list->root || !origin_list->count) {
    return 0;
  }

  ret = rdt_list_create(destiny_list);
  if (ret < 1) {
    return -4;
  }

  current_node = origin_list->root;
  ret = rdt_node_copy(&current_copy, current_node);
  if (ret < 1) {
    return -5;
  }
  (*destiny_list)->root = current_copy;
  previous_copy = current_copy;
  current_copy = NULL;
  current_node = rdt_node_get_right(current_node);
  if (current_node == origin_list->root) {
    return 1;
  }

  do {
    rdt_node_copy(&current_copy, current_node);
    rdt_node_set_left(current_copy, previous_copy);
    rdt_node_set_right(previous_copy, current_copy);
    current_copy = NULL;
    current_node = rdt_node_get_right(current_node);
  } while(current_node != origin_list->root);

  rdt_node_set_left((*destiny_list)->root, previous_copy);
  rdt_node_set_right(previous_copy, (*destiny_list)->root);



  return 1;
}

int rdt_list_free(RDTList** list) {
  RDTNode* root_node = NULL;
  RDTNode* current_node = NULL;
  RDTNode* next_node = NULL;

  if (!list) {
    return -1;
  }

  if (!(*list)) {
    return 0;
  }

  if (!(*list)->root) {
    free(*list);
    (*list) = NULL;
    return 1;
  }

  root_node = (*list)->root;
  current_node = rdt_node_get_right(root_node);

  do {
    next_node = rdt_node_get_right(current_node);
    rdt_node_free(&current_node);
    current_node = next_node;
  } while(root_node != current_node);

  if ((*list)->count > 1) {
    rdt_node_free(&root_node);
  }

  free(*list);
  (*list) = NULL;

  return 1;
}

int rdt_list_insert_beginning(RDTList* list, RDTNode* node) {
  RDTNode* previous_node = NULL;

  if (!list) {
    return -1;
  }

  if (!node) {
    return -2;
  }

  if (!list->root) {
    list->root = node;
    rdt_node_set_left(node, list->root);
    rdt_node_set_right(node, list->root);
    rdt_node_set_parent_structure(node, list);
    list->count++;
    return 1;
  }

  previous_node = rdt_node_get_left(list->root);

  rdt_node_set_left(list->root, node);
  rdt_node_set_right(node, list->root);
  rdt_node_set_left(node, previous_node);
  rdt_node_set_right(previous_node, node);
  list->root = node;


  rdt_node_set_parent_structure(node, list);

  list->count++;
  return 1;
}

int rdt_list_insert_ending(RDTList* list, RDTNode* node) {
  int ret;
  ret = rdt_list_insert_beginning(list, node);
  if (ret == 1) {
    list->root = rdt_node_get_right(list->root);
  }
  return ret;
}

RDTNode* rdt_list_search_beginning(RDTList* list, void* data, int* position) {
  RDTNode* node = NULL;
  RDTCompareHandler function_compare = NULL;
  void* node_data = NULL;
  int ret;
  int i;

  if (!list || !data) {
    return NULL;
  }

  node = list->root;
  i=0;
  do {
    function_compare = rdt_node_get_function_compare(node);
    if (!function_compare) {
      return NULL;
    }
    node_data = rdt_node_get_data(node);
    ret = function_compare(node_data, data);
    if (!ret) {
      if (position) {
        *position = i;
      }
      return node;
    }
    node = rdt_node_get_right(node);
    i++;
  } while (node != list->root);

  return NULL;
}

RDTNode* rdt_list_search_ending(RDTList* list, void* data, int* position) {
  RDTNode* node = NULL;
  RDTCompareHandler function_compare = NULL;
  void* node_data = NULL;
  int ret;
  int i;

  if (!list || !data) {
    return NULL;
  }

  node = list->root;
  i=0;
  do {
    function_compare = rdt_node_get_function_compare(node);
    if (!function_compare) {
      return NULL;
    }
    node_data = rdt_node_get_data(node);
    ret = function_compare(node_data, data);
    if (!ret) {
      if (position) {
        *position = i;
      }
      return node;
    }
    node = rdt_node_get_left(node);
    i++;
  } while (node != list->root);

  return NULL;
}

RDTNode* rdt_list_get(RDTList* list, int pos) {
  RDTNode* node;
  int abspos;

  if (!list) {
    return NULL;
  }

  node = list->root;

  if (pos > 0) {
    abspos = pos;
    while (abspos > 0) {
      node = rdt_node_get_right(node);
      abspos--;
    }
  } else if (pos < 0) {
    abspos = -pos;
    while (abspos > 0) {
      node = rdt_node_get_left(node);
      abspos--;
    }
  }

  return node;
}


int rdt_list_remove(RDTList* list, RDTNode* node) {
  void* parent_structure;
  RDTNode* left_node;
  RDTNode* right_node;

  if (!list) {
    return -1;
  }
  if (!node) {
    return -2;
  }
  if (!(list->count)) {
    return -3;
  }
  parent_structure = rdt_node_get_parent_structure(node);
  if (parent_structure != list) {
    return -4;
  }

  left_node = rdt_node_get_left(node);
  right_node = rdt_node_get_right(node);
  if (list->count == 1 && node == list->root) {
    list->root = NULL;
    list->count--;
    rdt_node_set_parent_structure(node, NULL);
    return 1;
  }

  rdt_node_set_right(left_node, right_node);
  rdt_node_set_left(right_node, left_node);
  if (node == list->root) {
    list->root = right_node;
  }

  rdt_node_set_left(node, NULL);
  rdt_node_set_right(node, NULL);
  rdt_node_set_parent_structure(node, NULL);
  list->count--;

  return 1;
}

int rdt_list_count(RDTList* list) {
  if (!list) {
    return -1;
  }
  return list->count;
}
