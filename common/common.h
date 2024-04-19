// Copyright (C) 2024-present Jose Mendoza - All rights reserved. Use of this
// source code is governed by an MIT license that can be found in the LICENSE
// file.

#ifndef RIVET_COMMON_H
#define RIVET_COMMON_H

#include <stdbool.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdlib.h>

#define TYPEDEF(kind, name) typedef kind name name
#define CAST(T, value) ((T)(value))
#define NEW(T) ((T*)malloc(sizeof(T)))
#define NEW_DYN_ARRAY(T, len) ((T*)malloc(sizeof(T) * len))

typedef size_t usize;
typedef void* rawptr;
typedef char* cstr;

void println(const cstr msg, ...);
void panic(const cstr msg, ...);
void runtimeError(const cstr msg, ...);

#endif
