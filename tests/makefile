SRCS       := $(wildcard *.cpp)
PRGS       := $(patsubst %.cpp,%,$(SRCS))
PRG_SUFFIX  =.test
OBJ_SUFFIX  =.o
BINS       := $(patsubst %,%$(PRG_SUFFIX),$(PRGS))
OBJS       := $(patsubst %,%$(OBJ_SUFFIX),$(PRGS))
# TEST_OVERHEAD will use MPI_PROC_NULL (no communication)
CXXFLAGS = -O3 -Wall -std=c++14 -pthread -I../include -D_GNU_SOURCE -DTEST_OVERHEAD
LDFLAGS  =
MPICXX 	 =  mpic++
RUNCMD 	 =  mpiexec
NPROCS	 = 2
CXX      = $(MPICXX)

.PHONY: build check clean

build : $(BINS)

OBJ = $(patsubst %$(PRG_SUFFIX),%.o,$@)
BIN = $@

%$(PRG_SUFFIX) : $(OBJS)
	echo "::group::$(BIN)"
	($(MPICXX) $(CXXFLAGS) $(OBJ) -o $(BIN) $(LDFLAGS)||(echo "::endgroup::"; exit 2));
	($(RUNCMD) -np $(NPROCS) ./$(BIN)||(echo "::endgroup::";exit 2));
	echo "::endgroup::"

check: $(BINS)
	make clean

clean:
	$(RM) *$(PRG_SUFFIX) *$(OBJ_SUFFIX)
