SRCS       := $(wildcard *.cpp)
PRGS       := $(patsubst %.cpp,%,$(SRCS))
PRG_SUFFIX  =.test
BINS       := $(patsubst %,%$(PRG_SUFFIX),$(PRGS))
OBJS       := $(patsubst %,%.o,$(PRGS))
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
	printf "::group::$(BIN)\n"
	($(MPICXX) $(CXXFLAGS) $(OBJ) -o $(BIN) $(LDFLAGS)||(printf "\n::end-group::\n"; exit 2));
	($(RUNCMD) -np $(NPROCS) ./$(BIN)||(printf "\n::end-group::\n";exit 2));
	printf "\n::end-group::\n"

check: $(BINS)

clean:
	$(RM) $(BINS) $(OBJS)
