PROGRAM_NAME = maxGUI
CXX_SRCS = \
	../../Code/maxGUI/ButtonImplementation.cpp \
	../../Code/maxGUI/Control.cpp \
	../../Code/maxGUI/ControlImplementation.cpp \
	../../Code/maxGUI/ControlWithText.cpp \
	../../Code/maxGUI/ControlWithTextImplementation.cpp \
	../../Code/maxGUI/EntryPoint.cpp \
	../../Code/maxGUI/FormAllocatorConcept.cpp \
	../../Code/maxGUI/FormConcept.cpp \
	../../Code/maxGUI/FormContainer.cpp \
	../../Code/maxGUI/MultilineTextBoxImplementation.cpp
	#../../Code/maxGUI/CheckBoxImplementation.cpp \
	#../../Code/maxGUI/ControlWithList.cpp \
	#../../Code/maxGUI/DropDownBoxImplementation.cpp \
	#../../Code/maxGUI/Frame.cpp \
	#../../Code/maxGUI/Label.cpp \
	#../../Code/maxGUI/ListBoxImplementation.cpp \
	#../../Code/maxGUI/ProgressBar.cpp \
	#../../Code/maxGUI/RadioButtonImplementation.cpp \
	#../../Code/maxGUI/TextBoxImplementation.cpp
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

EXAMPLE1_CXX_SRCS = \
	../../Code/Examples/1-SimpleExample/EntryPoint.cpp
EXAMPLE1_CXX_OBJS = $(EXAMPLE1_CXX_SRCS:.cpp=.o)

CPPFLAGS += $(INCLUDE_PATHS_FLAGS) -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -std=c++20 -fPIC
LINKER_FLAGS += $(LIBRARY_PATHS_FLAGS) -lQt5Widgets -lQt5Gui -lQt5Core




all: lib$(PROGRAM_NAME).a maxGUIAutomatedTests example1

lib$(PROGRAM_NAME).a: $(PCH_OBJS) $(CXX_OBJS)
	ar rcs lib$(PROGRAM_NAME).a $(CXX_OBJS)

maxGUIAutomatedTests: $(AUTOMATED_TEST_CXX_OBJS)
	clang++ -g $(AUTOMATED_TEST_CXX_OBJS) $(LINKER_FLAGS) -l$(PROGRAM_NAME) -o maxGUIAutomatedTests

example1: $(EXAMPLE1_CXX_OBJS)
	clang++ -g $(EXAMPLE1_CXX_OBJS) $(LINKER_FLAGS) -l$(PROGRAM_NAME) -o example1

.cpp.o:
	clang++ -g $(CPPFLAGS) -c $< -o $@

clean:
	@- $(RM) lib$(PROGRAM_NAME).a
	@- $(RM) $(CXX_OBJS)
	@- $(RM) maxAutomatedTests
	@- $(RM) $(AUTOMATED_TEST_CXX_OBJS)
	@- $(RM) example1
	@- $(RM) $(EXAMPLE1_CXX_OBJS)

distclean: clean
