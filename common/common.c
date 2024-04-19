// Copyright (C) 2024-present Jose Mendoza - All rights reserved. Use of this
// source code is governed by an MIT license that can be found in the LICENSE
// file.

#define __STDC_WANT_LIB_EXT2__ 1

#include <err.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#include "../common/common.h"

void println(const cstr msg, ...) {
    char* m = NULL;
    va_list ap;
    va_start(ap, msg);
    int retval = vasprintf(&m, msg, ap);
    va_end(ap);
    if (retval == -1) {
        err(EXIT_FAILURE, "println: `malloc` failed");
    }
    fprintf(stdout, "%s\n", m);
}


void panic(const cstr msg, ...) {
    char* m = NULL;
    va_list ap;
    va_start(ap, msg);
    int retval = vasprintf(&m, msg, ap);
    va_end(ap);
    if (retval == -1) {
        err(EXIT_FAILURE, "panic: `malloc` failed");
    }
    fprintf(stderr, "[rivet-panic] %s\n", m);
    exit(101);
}

void runtimeError(const cstr msg, ...) {
    char* m = NULL;
    va_list ap;
    va_start(ap, msg);
    int retval = vasprintf(&m, msg, ap);
    va_end(ap);
    if (retval == -1) {
        err(EXIT_FAILURE, "runtimeError: `malloc` failed");
    }
    fprintf(stderr, "[rivet-runtime_error] %s\n", m);
    exit(EXIT_FAILURE);
}

