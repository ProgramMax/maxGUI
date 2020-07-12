PROGRAM_NAME = max
CXX_SRCS = \
	../../Code/max/Hardware/CPU/CPUIDPolicies/X86GCCAssemblyCPUIDPolicy.cpp \
	../../Code/max/Hardware/CPU/IsCPUIDAvailablePolicies/X86GCCAssemblyIsCPUIDAvailablePolicy.cpp \
	../../Code/max/Hardware/CPU/Associativity.cpp \
	../../Code/max/Hardware/CPU/CacheInfo.cpp \
	../../Code/max/Hardware/CPU/CacheLevel.cpp \
	../../Code/max/Hardware/CPU/CPUID.cpp \
	../../Code/max/Hardware/CPU/CPUIDSubleafArgumentsAndResult.cpp \
	../../Code/max/Hardware/CPU/Prefetch.cpp \
	../../Code/max/Hardware/CPU/TLB.cpp \
	../../Code/max/Hardware/CPU/TraceCache.cpp \
	../../Code/max/Logging/DoNothingLogger.cpp \
	../../Code/max/Testing/CoutResultPolicy.cpp
CXX_OBJS = $(CXX_SRCS:.cpp=.o)

INCLUDE_PATHS = \
	../../Code
INCLUDE_PATHS_FLAGS = $(foreach d, $(INCLUDE_PATHS), -I$d)

LIBRARY_PATHS = \
	.
LIBRARY_PATHS_FLAGS = $(foreach d, $(LIBRARY_PATHS), -L$d)

AUTOMATED_TEST_CXX_SRCS = \
	../../Code/max/Algorithms/IsBetweenTest.cpp \
	../../Code/max/Algorithms/CountZeroesTest.cpp \
	../../Code/max/Algorithms/SwapEndianTest.cpp \
	../../Code/max/Containers/RangeTest.cpp \
	../../Code/max/Containers/VectorTest.cpp \
	../../Code/max/Testing/AutomatedTestsEntryPoint.cpp
AUTOMATED_TEST_CXX_OBJS = $(AUTOMATED_TEST_CXX_SRCS:.cpp=.o)

MANUAL_TEST_CXX_SRCS = \
	../../Code/max/Compiling/AliasingOptimizationsTest.cpp \
	../../Code/max/Compiling/ConfigurationTest.cpp \
	../../Code/max/Testing/ManualTestsEntryPoint.cpp
MANUAL_TEST_CXX_OBJS = $(MANUAL_TEST_CXX_SRCS:.cpp=.o)

CPPFLAGS += $(INCLUDE_PATHS_FLAGS) -std=c++14 -Werror -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -m32
LINKER_FLAGS += $(LIBRARY_PATHS_FLAGS)




all: lib$(PROGRAM_NAME).a maxAutomatedTests maxManualTests

lib$(PROGRAM_NAME).a: $(PCH_OBJS) $(CXX_OBJS)
	ar rcs lib$(PROGRAM_NAME).a $(CXX_OBJS)

maxAutomatedTests: $(AUTOMATED_TEST_CXX_OBJS)
	g++ -m32 -g $(AUTOMATED_TEST_CXX_OBJS) $(LINKER_FLAGS) -l$(PROGRAM_NAME) -o maxAutomatedTests

maxManualTests: $(MANUAL_TEST_CXX_OBJS)
	g++ -m32 -g $(MANUAL_TEST_CXX_OBJS) $(LINKER_FLAGS) -l$(PROGRAM_NAME) -o maxManualTests
.cpp.o:
	g++ -g $(CPPFLAGS) -c $< -o $@

clean:
	@- $(RM) lib$(PROGRAM_NAME).a
	@- $(RM) $(CXX_OBJS)
	@- $(RM) maxAutomatedTests
	@- $(RM) $(AUTOMATED_TEST_CXX_OBJS)
	@- $(RM) maxManualTests
	@- $(RM) $(MANUAL_TEST_CXX_OBJS)

distclean: clean
