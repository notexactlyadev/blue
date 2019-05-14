PROGRAM = Blue
SOURCE = ${wildcard *.cpp}
OBJS =	${SOURCE: .cpp = .o}
WARNS = -Wall -Wextra -Wshadow -Warray-bounds -pedantic

LINK = -lasan

CXX_FLAGS = -std=c++17 ${WARNS} -g -fsanitize=address

ifeq ($(OS),Windows_NT)
	DETECTED_OS = $(OS)
else
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	DETECTED_OS = Linux
endif
endif

CXX = g++

all: ${PROGRAM}

${PROGRAM}: ${OBJS}
	${CXX} ${CXX_FLAGS} -o "$@" ${OBJS} -lasan

clean:
ifeq ($(DETECTED_OS), Linux)
	${RM} OBJS ${PROGRAM} | true
endif
ifeq ($(DETECTED_OS), Windows_NT)
	del OBJS ${PROGRAM}
endif


