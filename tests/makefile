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
	$(MPICXX) $(CXXFLAGS) $(OBJ) -o $(BIN) $(LDFLAGS);
	$(RUNCMD) -np $(NPROCS) ./$(BIN)

check: $(BINS)

clean:
	$(RM) $(BINS) $(OBJS)
