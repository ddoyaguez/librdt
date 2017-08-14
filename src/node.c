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

struct _RDTNode {
  void* data;

  void* parent_structure;

  RDTNode* left;
  RDTNode* right;

  RDTCopyHandler function_copy;
  RDTFreeHandler function_free;
  RDTCompareHandler function_compare;

};

int rdt_node_create(RDTNode** new_node, RDTCopyHandler function_copy, RDTFreeHandler function_free, RDTCompareHandler function_compare) {
  if (!new_node) {
    return -1;
  }

  if (!function_copy) {
    return -2;
  }

  if (!function_free) {
    return -3;
  }

  if (!function_compare) {
    return -4;
  }

  (*new_node) = calloc(1, sizeof(RDTNode));
  if (!(*new_node)) {
    return 0;
  }

  (*new_node)->function_copy = function_copy;
  (*new_node)->function_free = function_free;
  (*new_node)->function_compare = function_compare;

  return 1;
}

int rdt_node_copy(RDTNode** destiny_node, RDTNode* origin_node) {
  RDTCopyHandler function_copy = NULL;
  void* data_copy = NULL;
  int ret;
  int ret2;

  if (!destiny_node) {
    return -1;
  }

  if (*(destiny_node)) {
    return -2;
  }

  if (!origin_node) {
    return -3;
  }

  if (!origin_node->function_copy) {
    return -4;
  }

  function_copy = origin_node->function_copy;
  ret = function_copy(&data_copy, origin_node->data);

  ret2 = rdt_node_create(destiny_node, origin_node->function_copy, origin_node->function_free, origin_node->function_compare);
  if (ret2 < 1) {
    if (data_copy) {
      origin_node->function_free(data_copy);
      return -5;
    }
  }

  (*destiny_node)->data = data_copy;
  (*destiny_node)->left = origin_node->left;
  (*destiny_node)->right = origin_node->right;

  return ret;

}

int rdt_node_free(RDTNode** node) {
  RDTFreeHandler function_free = NULL;
  int ret;

  if (!node) {
    return 0;
  }

  if (!(*node)) {
    return -1;
  }

  if (!(*node)->function_free) {
    return -2;
  }

  function_free = (*node)->function_free;
  ret = function_free(&((*node)->data));

  free(*(node));
  (*node) = 0;

  return ret;
}

void* rdt_node_get_data(RDTNode* node) {
  if (!node) {
    return NULL;
  }

  return node->data;
}

void* rdt_node_get_parent_structure(RDTNode* node) {
  if (!node) {
    return NULL;
  }

  return node->parent_structure;
}

int rdt_node_set_data(RDTNode* node, void* data) {
  if (!node) {
    return -1;
  }
  if (!data) {
    return -2;
  }

  node->data = data;

  return 1;
}

int rdt_node_set_parent_structure(RDTNode* node, void* parent_structure) {
  if (!node) {
    return -1;
  }

  node->parent_structure = parent_structure;

  return 1;
}

RDTNode* rdt_node_get_left(RDTNode* node) {
  if (!node) {
    return NULL;
  }
  return node->left;
}

RDTNode* rdt_node_get_right(RDTNode* node) {
  if (!node) {
    return NULL;
  }
  return node->right;
}

void rdt_node_set_left(RDTNode* node, RDTNode* left_node) {
  if (!node) {
    return;
  }
  node->left = left_node;
}

void rdt_node_set_right(RDTNode* node, RDTNode* right_node) {
  if (!node) {
    return;
  }
  node->right = right_node;
}

RDTCopyHandler rdt_node_get_function_copy(RDTNode* node) {
  if (!node) {
    return NULL;
  }
  return node->function_copy;
}

RDTFreeHandler rdt_node_get_function_free(RDTNode* node) {
  if (!node) {
    return NULL;
  }
  return node->function_free;
}

RDTCompareHandler rdt_node_get_function_compare(RDTNode* node) {
  if (!node) {
    return NULL;
  }
  return node->function_compare;
}
