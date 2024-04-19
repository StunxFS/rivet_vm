// Copyright (C) 2024-present Jose Mendoza - All rights reserved. Use of this
// source code is governed by an MIT license that can be found in the LICENSE
// file.

#ifndef RIVET_RSTACK_H
#define RIVET_RSTACK_H

#include <stddef.h>

#include "../common/common.h"
#include "./RValue.h"

TYPEDEF(struct, RStack);

struct RStack {
    RValue* block;
    RValue* top;
    RValue* end;
    usize len;
};

RStack RStack_new(usize len);
RStack RStack_from_array(RValue* arr, usize len);
RValue RStack_get(RStack* self, usize idx);
RValue* RStack_get_ref(RStack* self, usize idx);
void RStack_set(RStack* self, usize idx, RValue value);
void RStack_push(RStack* self, RValue value);
RValue RStack_pop(RStack* self);
void RStack_print(RStack* self);
void RStack_free(RStack* self);

#endif
