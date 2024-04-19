// Copyright (C) 2024-present Jose Mendoza - All rights reserved. Use of this
// source code is governed by an MIT license that can be found in the LICENSE
// file.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../common/common.h"
#include "./RStack.h"

RStack RStack_new(usize len) {
    RValue* block = NEW_DYN_ARRAY(RValue, len);
    if (!block) {
        runtimeError("cannot create a new stack");
    }
    return (RStack){
        .block = block,
        .top = block,
        .end = block + len,
        .len = len
    };
}

RStack RStack_from_array(RValue* arr, usize len) {
    RStack rstack = RStack_new(len);
    memcpy(rstack.block, arr, sizeof(RValue) * len);
    return rstack;
}

RValue RStack_get(RStack* self, usize idx) {
    if (idx < 0 || idx >= self->len) {
        runtimeError("access attempt out of stack range (index: %d)", idx);
    }
    return self->block[idx];
}

RValue* RStack_get_ref(RStack* self, usize idx) {
    if (idx < 0 || idx >= self->len) {
        runtimeError("access attempt out of stack range (index: %d)", idx);
    }
    return self->block + idx;
}

void RStack_set(RStack* self, usize idx, RValue value) {
    if (idx < 0 || idx >= self->len) {
        runtimeError("access attempt out of stack range (index: %d)", idx);
    }
    self->block[idx] = value;
}

void RStack_push(RStack* self, RValue value) {
    *(++self->top) = value;
}

RValue RStack_pop(RStack* self) {
    return *(--self->top);
}

void RStack_print(RStack* self) {
    printf("RStack {\n");
    for (usize i = 0; i < self->len; i++) {
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

