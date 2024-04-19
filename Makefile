# Copyright (C) 2024-present Jose Mendoza - All rights reserved. Use of this
# source code is governed by an MIT license that can be found in the LICENSE
# file.

CC=gcc

generate-parser:
	../owl/owl -c assembler/grammar.owl -o assembler/parser.h

build-rvm:
	$(CC) runtime/** common/** -o bin/rvm

build-asm: generate-parser
	$(CC) assembler/**.c common/** -o bin/rasm
