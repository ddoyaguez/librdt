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

#include <string.h>
#include "namednode.h"

struct _RDTNamedNode {
	char* name;
	RDTNode* node;
};

int rdt_namednode_create(RDTNamedNode** new_named_node, RDTCopyHandler function_copy, RDTFreeHandler function_free, RDTCompareHandler function_compare, char* name) {
	RDTNode* new_node = NULL;
	int ret;
	int nl;

	if (!new_named_node) {
		return -1;
	}

	ret = rdt_node_create(&new_node, function_copy, function_free, function_compare);
	if (ret < 1) {
		return ret;
	}

	if (!name) {
		rdt_node_free(&new_node);
		return -5;
	}

	nl = strlen(name);
	if (nl < 1) {
		rdt_node_free(&new_node);
		return -5;
	}

	(*new_named_node) = calloc(1, sizeof(RDTNamedNode));
	if (!(new_named_node)) {
		rdt_node_free(&new_node);
		return 0;
	}

	(*new_named_node)->name = calloc(nl + 1, sizeof(char));
	if (!(*new_named_node)->name) {
		rdt_node_free(&new_node);
		free(new_named_node);
		return -6;
	}

	memmove((*new_named_node)->name, name, nl);
	(*new_named_node)->node = new_node;

	return 1;
}

int rdt_namednode_copy(RDTNamedNode** destiny_node, RDTNamedNode* origin_node) {
	RDTNode* node_copy = NULL;
	RDTCopyHandler function_copy = NULL;
	RDTFreeHandler function_free = NULL;
	RDTCompareHandler function_compare = NULL;
	int ret;
	int ret2;

	if (!destiny_node) {
		return -6;
	}

	if (*(destiny_node)) {
		return -7;
	}

	if (!origin_node) {
		return -8;
	}

	ret = rdt_node_copy(&node_copy, origin_node->node);
	if (ret < 1) {
		return -9;
	}

	function_copy = rdt_node_get_function_copy(origin_node->node);
	function_free = rdt_node_get_function_free(origin_node->node);
	function_compare = rdt_node_get_function_compare(origin_node->node);

	ret2 = rdt_namednode_create(destiny_node, function_copy, function_free, function_compare, origin_node->name);
	if (ret2 < 1) {
		if (node_copy) {
			rdt_node_free(&node_copy);
			return -10;
		}
	}

	rdt_node_free(&((*destiny_node)->node));
	(*destiny_node)->node = node_copy;

	return ret;
}

int rdt_namednode_free(RDTNamedNode** node) {
	int ret;

	if (!node) {
		return -3;
	}

	if (!(*node)) {
		return -4;
	}

	if ((*node)->name) {
		free((*node)->name);
	}
	ret = rdt_node_free(&((*node)->node));
	free(*node);
	*node = NULL;

	return ret;
}

RDTNode** rdt_namednode_get_node(RDTNamedNode* node) {
	if (!node) {
		return NULL;
	}
	return &(node->node);
}

char* rdt_namednode_get_name(RDTNamedNode* node) {
	if (!node) {
		return NULL;
	}
	return node->name;
}
