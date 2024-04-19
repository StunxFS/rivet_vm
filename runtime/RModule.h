// Copyright (C) 2024-present Jose Mendoza - All rights reserved. Use of this
// source code is governed by an MIT license that can be found in the LICENSE
// file.

#ifndef RIVET_RMOD_H
#define RIVET_RMOD_H

#include "../common/common.h"
#include "./RFunc.h"
#include "./RValue.h"

TYPEDEF(struct, RModule);

struct RModule {
    RStack constant_pool;
    RFunc* funcs;
    usize funcs_size;
};

#endif
