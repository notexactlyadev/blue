PROGRAM = Blue
SOURCE = ${wildcard *.cpp}
OBJS =	${SOURCE: .cpp = .o}
WARNS = -Wall -Wextra -Wshadow -Warray-bounds -pedantic

CXX_FLAGS = -std=c++17 ${WARNS} -g
RM = del
CXX = g++

all: ${PROGRAM}

${PROGRAM}: ${OBJS}
	${CXX} ${CXX_FLAGS} -o "$@" ${OBJS}

clean:
	${RM} OBJS ${PROGRAM}.exe


