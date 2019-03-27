PROGRAM = Blue
SOURCE = ${wildcard *.cpp}
OBJS =	${SOURCE: .cpp = .o}
WARNS = -Wall -Wextra -Wshadow -Warray-bounds -pedantic

CXX_FLAGS = -std=c++17 ${WARNS} -g

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
	${CXX} ${CXX_FLAGS} -o "$@" ${OBJS}

clean:
ifeq ($(DETECTED_OS), Linux)
	rm -r ${RM} OBJS ${PROGRAM} | true
endif
ifeq ($(DETECTED_OS), Windows_NT)
	del OBJS ${PROGRAM}
endif


