// Copyright (C) 2024-present Jose Mendoza - All rights reserved. Use of this
// source code is governed by an MIT license that can be found in the LICENSE
// file.

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "./common.h"
#include "./RStack.h"

RStack RStack_new(size_t len) {
    RValue* block = (RValue*)malloc(sizeof(RValue) * len);
    if (!block) {
        runtime_error("cannot create a new stack");
    }
    return (RStack){
        .block = block,
        .top = block,
        .len = len,
        .cap = len
    };
}

void RStack_push(RStack* self, RValue value) {
    *self->top = value;
    self->top++;
}

RValue RStack_pop(RStack* self) {
    return *(--self->top);
}

void RStack_print(RStack* self) {
    printf("RStack {\n");
    for (size_t i = 0; i < self->len; i++) {
        printf("    %ld: %s", i, RValue_toString(self->block + i));
        if (i < self->len - 1) {
            printf(",");
        }
        printf("\n");
    }
    printf("}\n");
}

void RStack_free(RStack* self) {
    free(self->block);
}

