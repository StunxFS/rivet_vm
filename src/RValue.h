// Copyright (C) 2024-present Jose Mendoza - All rights reserved. Use of this
// source code is governed by an MIT license that can be found in the LICENSE
// file.

#ifndef RIVET_RV_H
#define RIVET_RV_H

#include "./common.h"

TYPEDEF(struct, RValue);
TYPEDEF(enum, RValueType);

enum RValueType {
    RVT_NONE = 0,
    RVT_BOOL,
    RVT_INT8,
    RVT_INT16,
    RVT_INT32,
    RVT_INT64,
};

#define RK_NONE ((RValue){ .type = RVT_NONE })
#define RK_TRUE ((RValue){ .b = true, .type = RVT_BOOL })
#define RK_FALSE ((RValue){ .b = false, .type = RVT_BOOL })

#define _RK_INT(bits, val) ((RValue){ .i##bits = (val), .type = RVT_INT##bits })
#define RK_INT8(val) _RK_INT(8, val)
#define RK_INT16(val) _RK_INT(16, val)
#define RK_INT32(val) _RK_INT(32, val)
#define RK_INT64(val) _RK_INT(64, val)

#define _RV_IS_TYPE(rval, type) ((rval).type == RVT_##type)
#define RV_IS_NONE(rval) ((rval).type == RVT_NONE)
#define RV_IS_BOOL(rval) ((rval).type == RVT_BOOL)
#define RV_IS_INT(rval) (((rval).type >= RVT_INT8) && ((rval).type <= RVT_INT64))
#define RV_IS_INT8(rval) _RV_IS_TYPE(rval, INT8)
#define RV_IS_INT16(rval) _RV_IS_TYPE(rval, INT16)
#define RV_IS_INT32(rval) _RV_IS_TYPE(rval, INT32)
#define RV_IS_INT64(rval) _RV_IS_TYPE(rval, INT64)

struct RValue {
    union {
        bool b;
        int8_t i8;
        int16_t i16;
        int32_t i32;
        int64_t i64;
    };
    RValueType type;
};

usize RValue_toUsize(RValue* self);
cstr RValue_toString(RValue* self);

#endif
