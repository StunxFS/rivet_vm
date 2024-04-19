// Copyright (C) 2024-present Jose Mendoza - All rights reserved. Use of this
// source code is governed by an MIT license that can be found in the LICENSE
// file.

#include "./RVM.h"
#include "./RFunc.h"

#define IS_REG(value) (((value) & 0x80000000) > 0)
#define ABS(value) CAST(usize, IS_REG(value)? -value : value)

RFrame RFunc_new_frame(RFunc* self) {
    return (RFrame){
        .constant_pool = self->constant_pool,
        .insts = self->insts,
        .insts_size = self->insts_size,
        .pc = 0,
        .stack = RStack_new(self->reg_count),
        .ret_val = RK_NONE
    };
}

void RFrame_run(RFrame* self) {
    for (; self->pc < self->insts_size; self->pc++) {
        RInst inst = self->insts[self->pc];
        switch (inst.opcode) {
            case ROC_NOP: break;

            case ROC_MOV:
                RStack* stack = IS_REG(inst.arg1)? (&self->stack) : (&self->constant_pool);
                RStack_set(&self->stack, ABS(inst.arg0), RStack_get(stack, ABS(inst.arg1)));
                break;

            case ROC_GOTO:
                self->pc = inst.arg0;
                break;

            case ROC_CALL:
                usize func_idx = RValue_toUsize(RStack_get_ref(&self->constant_pool, ABS(inst.arg1)));
                RFrame frame = RFunc_new_frame(
                    &g_rvm->modules[ABS(inst.arg0)].funcs[func_idx]
                );
                RFrame_run(&frame);
                if (!RV_IS_NONE(frame.ret_val)) {
                    RStack_set(&self->stack, ABS(inst.arg2), frame.ret_val);
                }
                break;

            case ROC_RETURN:
                self->ret_val = RStack_get(&self->stack, ABS(inst.arg0));
                break;

            default:
                runtimeError("invalid opcode (%d)", inst.opcode);
                break;
        }
    }
    RStack_print(&self->stack);
}

