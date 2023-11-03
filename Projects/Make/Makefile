LIBRARY = maxGUI

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

CXX_OBJS = $(patsubst ../../Code/%.cpp,Build/Objects/%.o,$(CXX_SRCS))

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
AUTOMATED_TEST_CXX_OBJS = $(patsubst ../../Code/%.cpp,Build/Objects/%.o,$(AUTOMATED_TEST_CXX_SRCS))

EXAMPLE1_CXX_SRCS = \
	../../Code/Examples/1-SimpleExample/EntryPoint.cpp
EXAMPLE1_CXX_OBJS = $(patsubst ../../Code/%.cpp,Build/Objects/%.o,$(EXAMPLE1_CXX_SRCS))

CPPFLAGS += $(INCLUDE_PATHS_FLAGS) -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -std=c++20 -fPIC
LINKER_FLAGS += $(LIBRARY_PATHS_FLAGS) -lQt5Widgets -lQt5Gui -lQt5Core



all: lib$(LIBRARY).a maxGUIAutomatedTests example1

lib$(LIBRARY).a: $(CXX_OBJS)
	ar rcs lib$(LIBRARY).a $(CXX_OBJS)

$(CXX_OBJS): $(CXX_SRCS)
	mkdir -p $(dir $@)
	$(CXX) -g $(CPPFLAGS) -c $(patsubst Build/Objects/%.o,../../Code/%.cpp,$@) -o $@

maxGUIAutomatedTests: lib$(LIBRARY).a $(AUTOMATED_TEST_CXX_OBJS)
	$(CXX) -g $(AUTOMATED_TEST_CXX_OBJS) $(LINKER_FLAGS) -l$(LIBRARY) -o maxGUIAutomatedTests

$(AUTOMATED_TEST_CXX_OBJS): $(AUTOMATED_TEST_CXX_SRCS)
	mkdir -p $(dir $@)
	$(CXX) -g $(CPPFLAGS) -c $(patsubst Build/Objects/%.o,../../Code/%.cpp,$@) -o $@

example1: lib$(LIBRARY).a $(EXAMPLE1_CXX_OBJS)
	$(CXX) -g $(EXAMPLE1_CXX_OBJS) $(LINKER_FLAGS) -l$(LIBRARY) -o example1

$(EXAMPLE1_CXX_OBJS): $(EXAMPLE1_CXX_SRCS)
	mkdir -p $(dir $@)
	$(CXX) -g $(CPPFLAGS) -c $(patsubst Build/Objects/%.o,../../Code/%.cpp,$@) -o $@

.PHONY: clean
distclean: clean
clean:
	for file in lib$(LIBRARY).a $(CXX_OBJS) maxGUIAutomatedTests $(AUTOMATED_TEST_CXX_OBJS) example1 $(EXAMPLE1_CXX_OBJS) ; do \
		rm $${file} ; \
	done
