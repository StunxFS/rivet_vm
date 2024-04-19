// Copyright (C) 2024-present Jose Mendoza - All rights reserved. Use of this
// source code is governed by an MIT license that can be found in the LICENSE
// file.

#ifndef RIVET_RINST_H
#define RIVET_RINST_H

#include "../common/common.h"

TYPEDEF(enum, ROpcode);
TYPEDEF(struct, RInst);

enum ROpcode {
    ROC_NOP = 0,

    ROC_MOV,

    ROC_GOTO,

    ROC_CALL,
    ROC_RETURN,

    ROC_ADD
};

struct RInst {
    ROpcode opcode;
    int16_t arg0;
    int16_t arg1;
    int16_t arg2;
};

#endif
