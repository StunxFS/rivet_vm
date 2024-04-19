// Copyright (C) 2024-present Jose Mendoza - All rights reserved. Use of this
// source code is governed by an MIT license that can be found in the LICENSE
// file.

#include "./RValue.h"

usize RValue_toUsize(RValue* self) {
    switch (self->type) {
        case RVT_BOOL:
            return CAST(usize, self->b);
        case RVT_INT8:
            return CAST(usize, self->i8);
        case RVT_INT16:
            return CAST(usize, self->i16);
        case RVT_INT32:
            return CAST(usize, self->i32);
        case RVT_INT64:
            return CAST(usize, self->i64);
    }
    runtimeError("RValue::toUsize: invalid type");
}

cstr RValue_toString(RValue* self) {
    switch (self->type) {
        case RVT_BOOL:
            return (self->b)? "true" : "false";
        case RVT_NONE:
            return "none";
    }
    runtimeError("RValue::toString: unknown RValue type");
}
