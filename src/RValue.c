// Copyright (C) 2024-present Jose Mendoza - All rights reserved. Use of this
// source code is governed by an MIT license that can be found in the LICENSE
// file.

#include "./RValue.h"

cstr RValue_toString(RValue* self) {
    switch (self->type) {
    case RVT_BOOL:
        return (self->b)? "true" : "false";
    case RVT_NONE:
    default:
        return "none";
    }
}
