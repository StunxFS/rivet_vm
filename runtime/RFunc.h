// Copyright (C) 2024-present Jose Mendoza - All rights reserved. Use of this
// source code is governed by an MIT license that can be found in the LICENSE
// file.

#ifndef RIVET_RFUNC_H
#define RIVET_RFUNC_H

#include "../common/common.h"
#include "./RInst.h"
#include "./RStack.h"

TYPEDEF(struct, RFunc);
TYPEDEF(struct, RFrame);

struct RFunc {
    RStack constant_pool;
    RInst* insts;
    usize insts_size;
    usize reg_count;
};

struct RFrame {
    usize modules_size;
    RStack constant_pool;
    RInst* insts;
    usize insts_size;
    usize pc;
    RStack stack;
    RValue ret_val;
};

RFrame RFunc_new_frame(RFunc* self);
void RFrame_run(RFrame* self);

#endif
