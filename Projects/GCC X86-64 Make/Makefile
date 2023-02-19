PROGRAM_NAME = maxGUI
CXX_SRCS = \
	../../Code/maxGUI/Button.cpp \
	../../Code/maxGUI/Control.cpp \
	../../Code/maxGUI/ControlWithText.cpp \
	../../Code/maxGUI/EntryPoint.cpp \
	../../Code/maxGUI/FormAllocatorConcept.cpp \
	../../Code/maxGUI/FormConcept.cpp \
	../../Code/maxGUI/FormContainer.cpp \
	../../Code/maxGUI/MultilineTextBox.cpp
	#../../Code/maxGUI/CheckBox.cpp \
	#../../Code/maxGUI/ControlWithList.cpp \
	#../../Code/maxGUI/DropDownBox.cpp \
	#../../Code/maxGUI/Frame.cpp \
	#../../Code/maxGUI/Label.cpp \
	#../../Code/maxGUI/ListBox.cpp \
	#../../Code/maxGUI/ProgressBar.cpp \
	#../../Code/maxGUI/RadioButton.cpp \
	#../../Code/maxGUI/TextBox.cpp
CXX_OBJS = $(CXX_SRCS:.cpp=.o)

INCLUDE_PATHS = \
	../../Code \
	../../Dependencies/max/Code \
	/usr/include/qt/QtWidgets \
	/usr/include/qt \
	/usr/include/qt/QtCore \
	/usr/include/qt/QtGui \
	/usr/include/x86_64-linux-gnu/qt5/QtWidgets \
	/usr/include/x86_64-linux-gnu/qt5 \
	/usr/include/x86_64-linux-gnu/QtCore \
	/usr/include/x86_64-linux-gnu/QtGui

INCLUDE_PATHS_FLAGS = $(foreach d, $(INCLUDE_PATHS), -I$d)

LIBRARY_PATHS = \
	.
LIBRARY_PATHS_FLAGS = $(foreach d, $(LIBRARY_PATHS), -L$d)

AUTOMATED_TEST_CXX_SRCS = \
	../../Code/maxGUI/TestingEntryPoint.cpp
AUTOMATED_TEST_CXX_OBJS = $(AUTOMATED_TEST_CXX_SRCS:.cpp=.o)

# TODO: Ubuntu 20.04 (one of our test machines) has a version of GCC which recognizes c++2a, not c++20
CPPFLAGS += $(INCLUDE_PATHS_FLAGS) -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -std=c++2a -fPIC
LINKER_FLAGS += $(LIBRARY_PATHS_FLAGS) -lQt5Widgets -lQt5Gui -lQt5Core




all: lib$(PROGRAM_NAME).a maxGUIAutomatedTests

lib$(PROGRAM_NAME).a: $(PCH_OBJS) $(CXX_OBJS)
	ar rcs lib$(PROGRAM_NAME).a $(CXX_OBJS)

maxGUIAutomatedTests: $(AUTOMATED_TEST_CXX_OBJS)
	g++ -g $(AUTOMATED_TEST_CXX_OBJS) $(LINKER_FLAGS) -l$(PROGRAM_NAME) -o maxGUIAutomatedTests

example1: $(EXAMPLE1_CXX_OBJS)
	clang++ -g $(EXAMPLE1_CXX_OBJS) $(LINKER_FLAGS) -l$(PROGRAM_NAME) -o example1

.cpp.o:
	g++ -g $(CPPFLAGS) -c $< -o $@

clean:
	@- $(RM) lib$(PROGRAM_NAME).a
	@- $(RM) $(CXX_OBJS)
	@- $(RM) maxAutomatedTests
	@- $(RM) $(AUTOMATED_TEST_CXX_OBJS)
	@- $(RM) example1
	@- $(RM) $(EXAMPLE1_CXX_OBJS)

distclean: clean
