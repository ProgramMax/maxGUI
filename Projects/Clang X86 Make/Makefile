PROGRAM_NAME = maxGUI
CXX_SRCS = \
	../../Code/maxGUI/Button.cpp \
	../../Code/maxGUI/Control.cpp \
	../../Code/maxGUI/ControlWithText.cpp
	#../../Code/maxGUI/CheckBox.cpp \
	#../../Code/maxGUI/ControlWithList.cpp \
	#../../Code/maxGUI/DropDownBox.cpp \
	#../../Code/maxGUI/EntryPoint.cpp \
	#../../Code/maxGUI/Form.cpp \
	#../../Code/maxGUI/Frame.cpp \
	#../../Code/maxGUI/Label.cpp \
	#../../Code/maxGUI/ListBox.cpp \
	#../../Code/maxGUI/MultilineTextBox.cpp \
	#../../Code/maxGUI/ProgressBar.cpp \
	#../../Code/maxGUI/RadioButton.cpp \
	#../../Code/maxGUI/Rectangle.cpp \
	#../../Code/maxGUI/TextBox.cpp
CXX_OBJS = $(CXX_SRCS:.cpp=.o)

INCLUDE_PATHS = \
	../../Code \
	../../Dependencies/max/Code
INCLUDE_PATHS_FLAGS = $(foreach d, $(INCLUDE_PATHS), -I$d)

LIBRARY_PATHS = \
	.
LIBRARY_PATHS_FLAGS = $(foreach d, $(LIBRARY_PATHS), -L$d)

AUTOMATED_TEST_CXX_SRCS = \
	../../Code/maxGUI/TestingEntryPoint.cpp
AUTOMATED_TEST_CXX_OBJS = $(AUTOMATED_TEST_CXX_SRCS:.cpp=.o)

CPPFLAGS += $(INCLUDE_PATHS_FLAGS) -std=c++14 -Werror -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion
LINKER_FLAGS += $(LIBRARY_PATHS_FLAGS)




all: lib$(PROGRAM_NAME).a maxGUIAutomatedTests

lib$(PROGRAM_NAME).a: $(PCH_OBJS) $(CXX_OBJS)
	ar rcs lib$(PROGRAM_NAME).a $(CXX_OBJS)

maxGUIAutomatedTests: $(AUTOMATED_TEST_CXX_OBJS)
	clang++ -g $(AUTOMATED_TEST_CXX_OBJS) $(LINKER_FLAGS) -l$(PROGRAM_NAME) -o maxGUIAutomatedTests

.cpp.o:
	clang++ -g $(CPPFLAGS) -c $< -o $@

clean:
	@- $(RM) lib$(PROGRAM_NAME).a
	@- $(RM) $(CXX_OBJS)
	@- $(RM) maxGUIAutomatedTests
	@- $(RM) $(AUTOMATED_TEST_CXX_OBJS)

distclean: clean
