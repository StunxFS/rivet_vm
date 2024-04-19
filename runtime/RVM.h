// Copyright (C) 2024-present Jose Mendoza - All rights reserved. Use of this
// source code is governed by an MIT license that can be found in the LICENSE
// file.

#ifndef RIVET_VM_H
#define RIVET_VM_H

#include "../common/common.h"
#include "./RModule.h"

TYPEDEF(struct, RVM);

extern RVM* g_rvm;

struct RVM {
    RModule* modules;
    usize modules_size;
};

#endif
