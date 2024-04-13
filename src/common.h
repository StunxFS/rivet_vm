// Copyright (C) 2024-present Jose Mendoza - All rights reserved. Use of this
// source code is governed by an MIT license that can be found in the LICENSE
// file.

#ifndef RIVET_COMMON_H
#define RIVET_COMMON_H

#define TYPEDEF(kind, name) typedef kind name name

typedef void* rawptr;
typedef char* cstr;

void runtime_error(cstr msg);

#endif
