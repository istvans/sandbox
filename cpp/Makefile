NAME ?= tag
TOOL ?= clang
TOOL_FLAGS ?=
RUN_ARGS ?=

BINARY = ${NAME}.exe
SOURCE = ${NAME}.cpp
MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
MAKEFILE_DIR := $(dir $(MAKEFILE_PATH))
BIN_PATH := ${MAKEFILE_DIR}/${BINARY}

ifeq (${TOOL}, clang)
    COMPILER = clang++ -std=c++14 -Weverything -Werror -Wno-c++98-compat ${TOOL_FLAGS}
    BUILD = ${COMPILER} ${SOURCE} -o ${BINARY}
else ifeq (${TOOL}, gcc)
    COMPILER = g++ -std=c++14 -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy \
    -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs \
    -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo \
    -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused ${TOOL_FLAGS}
    BUILD = ${COMPILER} ${SOURCE} -o ${BINARY}
else ifeq (${TOOL}, msvc)
    BUILD = C:/Windows/System32/cmd.exe /c "vcvars64.bat && cl.exe /std:c++14 /W4 /WX ${TOOL_FLAGS} \
    /EHsc ${SOURCE} /Fe:${BINARY}"
else
    $(error ${TOOL} is not a supported compiler tool chain (choose from clang, gcc or msvc))
endif

${BINARY}: ${SOURCE}
	${BUILD}

.PHONY: build
build: ${BINARY}

.PHONY: run
run:
	${BIN_PATH} ${RUN_ARGS}

.PHONY: build_and_run
build_and_run: build
	${MAKE} run

.PHONY: clean
clean:
	rm -f ${BINARY}

.PHONY: clean_all
clean_all:
	rm -f *.exe

.DEFAULT_GOAL := build_and_run
