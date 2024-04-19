// Copyright (C) 2024-present Jose Mendoza - All rights reserved. Use of this
// source code is governed by an MIT license that can be found in the LICENSE
// file.

#include <stdlib.h>

#include "./RVM.h"
#include "./RValue.h"

int main(int argc, char** argv) {
    RVM* rvm = NEW(RVM);
    if (!rvm) {
        runtimeError("cannot create the virtual machine");
    }
    g_rvm = rvm;
    RStack constant_pool = RStack_from_array(
        (RValue[]){ RK_TRUE, RK_FALSE, RK_INT8(1) }, 3
    );
    *rvm = (RVM){
        .modules_size = 1,
        .modules = (RModule[]){
            (RModule){
                .constant_pool = constant_pool,
                .funcs_size = 2,
                .funcs = (RFunc[]){
                    (RFunc){
                        .constant_pool = constant_pool,
                        .reg_count = 10,
                        .insts = (RInst[]){
                            { ROC_MOV, 0, 0, 0 },
                            { ROC_MOV, 1, 1, 0 },
                            { ROC_CALL, 0, 2, 5 }
                        },
                        .insts_size = 3
                    },
                    (RFunc){
                        .constant_pool = constant_pool,
                        .reg_count = 5,
                        .insts = (RInst[]){
                            { ROC_MOV, 0, 0, 0 },
                            { ROC_MOV, 1, 1, 0 },
                            { ROC_RETURN, 1 }
                        },
                        .insts_size = 3
                    }
                }
            }
        }
    };
    RFrame frame = RFunc_new_frame(&rvm->modules[0].funcs[0]);
    RFrame_run(&frame);
    free(rvm);
    return 0;
}

