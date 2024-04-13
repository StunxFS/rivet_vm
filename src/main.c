// Copyright (C) 2024-present Jose Mendoza - All rights reserved. Use of this
// source code is governed by an MIT license that can be found in the LICENSE
// file.

#include "./RStack.h"
#include "./RValue.h"

int main(int argc, char** argv) {
    RStack rs = RStack_new(10);
    {
        RStack_push(&rs, RK_TRUE);
        RStack_push(&rs, RK_TRUE);
        RStack_push(&rs, RK_TRUE);
        RStack_push(&rs, RK_TRUE);
        RStack_push(&rs, RK_TRUE);
        RStack_print(&rs);
    }
    RStack_free(&rs);
    return 0;
}

