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
#include "bintree.h"

struct _RDTBintree {
  RDTNode* root;
  int count;
};

int rdt_bintree_create(RDTBintree** new_bintree) {
  if (!new_bintree) {
    return -1;
  }

  (*new_bintree) = calloc(1, sizeof(RDTBintree));
  if (!(*new_bintree)) {
    return 0;
  }

  return 1;
}

int rdt_bintree_insert(RDTBintree* bintree, RDTNode* node) {
  RDTNode* current_node = NULL;
  RDTNode* insertion_node = NULL;
  RDTCompareHandler function_cmp = NULL;

  void* current_data = NULL;
  void* node_data = NULL;

  if (!bintree) {
    return 0;
  }

  if (!node) {
    return -1;
  }

  function_cmp = rdt_node_get_function_compare(node);
  if (!function_cmp) {
    return -2;
  }

  if (!bintree->root) {
    bintree->root = node;
    rdt_node_set_parent_structure(node, bintree);
    bintree->count++;
    return 1;
  }

  current_node = bintree->root;
  while (current_node) {
    current_data = rdt_node_get_data(current_node);
    node_data = rdt_node_get_data(node);
    if (function_cmp(node_data, current_data) > 0) {
      insertion_node = rdt_node_get_right(current_node);
      if (!insertion_node) {
        rdt_node_set_right(current_node, node);
        rdt_node_set_parent_structure(node, bintree);
        bintree->count++;
        return 1;
      }
      current_node = insertion_node;
    } else if (function_cmp(node_data, current_data) < 0) {
      insertion_node = rdt_node_get_left(current_node);
      if (!insertion_node) {
        rdt_node_set_left(current_node, node);
        rdt_node_set_parent_structure(node, bintree);
        bintree->count++;
        return 1;
      }
      current_node = insertion_node;
    } else {
      return -3;
    }
  }

  return -4;
}

RDTNode* rdt_bintree_search(RDTBintree* bintree, void* data) {
  RDTNode* current_node = NULL;
  RDTCompareHandler function_cmp = NULL;
  void* current_data = NULL;
  int cmp_result;

  if (!bintree) {
    return NULL;
  }

  if (!data) {
    return NULL;
  }

  current_node = bintree->root;
  function_cmp = rdt_node_get_function_compare(current_node);
  while (current_node) {
    current_data = rdt_node_get_data(current_node);
    cmp_result = function_cmp(data, current_data);
    if (cmp_result == 0) {
      return current_node;
    } else if (cmp_result < 0) {
      current_node = rdt_node_get_left(current_node);
    } else if (cmp_result > 0) {
      current_node = rdt_node_get_right(current_node);
    }
  }

  return NULL;
}

int rdt_bintree_free(RDTBintree** bintree) {
  RDTNode* left_node = NULL;
  RDTNode* right_node = NULL;

  if (!bintree) {
    return 0;
  }
  if (!(*bintree)) {
    return -1;
  }

  left_node = rdt_node_get_left((*bintree)->root);
  right_node = rdt_node_get_right((*bintree)->root);
  rdt_bintree_free_subtree(*bintree, left_node);
  rdt_bintree_free_subtree(*bintree, right_node);
  rdt_node_free(&((*bintree)->root));

  free(*bintree);
  *bintree = NULL;
  return 1;
}

void rdt_bintree_free_subtree(RDTBintree* parent_tree, RDTNode* subtree) {
  RDTNode* left_node = NULL;
  RDTNode* right_node = NULL;

  if (subtree == NULL) {
    return;
  }
  if (rdt_node_get_parent_structure(subtree) != parent_tree) {
    return;
  }

  left_node = rdt_node_get_left(subtree);
  right_node = rdt_node_get_right(subtree);
  rdt_bintree_free_subtree(parent_tree, left_node);
  rdt_bintree_free_subtree(parent_tree, right_node);
  rdt_node_free(&subtree);
}

int rdt_bintree_count(RDTBintree* bintree) {
  if (!bintree) {
    return -1;
  }
  return bintree->count;
}
