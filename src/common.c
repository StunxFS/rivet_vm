// Copyright (C) 2024-present Jose Mendoza - All rights reserved. Use of this
// source code is governed by an MIT license that can be found in the LICENSE
// file.

#include <stdio.h>
#include <stdlib.h>

#include "./common.h"

void runtime_error(cstr msg) {
    fprintf(stderr, "[RUNTIME ERROR] %s\n", msg);
    abort();
}

