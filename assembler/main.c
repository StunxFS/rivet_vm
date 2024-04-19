// Copyright (C) 2024-present Jose Mendoza - All rights reserved. Use of this
// source code is governed by an MIT license that can be found in the LICENSE
// file.

#include "../common/common.h"
#include "./parser.h"

struct owl_tree* create_tree_from_file(const char* file) {
    FILE* f = fopen(file, "r");
    if (!f) {
        panic("failed to open the file %s", file);
    }
    struct owl_tree* tree = owl_tree_create_from_file(f);
    fclose(f);
    /*struct source_range range;
    switch (owl_tree_get_error(tree, &range)) {
        case ERROR_NONE: break; // fine
        case ERROR_INVALID_FILE:
            panic("error: invalid file `%s`", file);
        default:
            panic("%s: error at range %zu..%zu", file, range.start, range.end);
    }*/
    return tree;
}

int main(int argc, char** argv) {
    struct owl_tree* tree = create_tree_from_file(argv[1]);
    owl_tree_print(tree);
    owl_tree_destroy(tree);
    return 0;
}

