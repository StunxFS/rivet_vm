// Copyright (C) 2024-present Jose Mendoza - All rights reserved. Use of this
// source code is governed by an MIT license that can be found in the LICENSE
// file.

#ifndef RIVET_RSTACK_H
#define RIVET_RSTACK_H

#include <stddef.h>

#include "./common.h"
#include "./RValue.h"

TYPEDEF(struct, RStack);

struct RStack {
    RValue* block;
    RValue* top;
    size_t len;
    size_t cap;
};

RStack RStack_new(size_t len);
void RStack_push(RStack* self, RValue value);
RValue RStack_pop(RStack* self);
void RStack_print(RStack* self);
void RStack_free(RStack* self);

#endif
