
IDIR = Src
ODIR = Build
TEMPDIR = Temp

TESTIDIR = TestSrc
TESTODIR = Test

OUTPUT = lib$(PROJECT).a


CXX ?= g++
CXXFLAGS ?= -c -Wall -Wextra -pedantic -std=c++14

_OBJS = $(shell (find Src -type f -name *.cpp -printf "%f " | sed 's/.cpp/.o/g'))
TESTS = $(shell (find TestSrc -type f -name *.cpp -printf "%f " | sed 's/.cpp//g'))

#/--------------------\
#| 				      |
#|  TARGETS SETTINGS  |
#| 				      |
#\--------------------/

TARGETS = Debug Release
Debug_FLAGS = -Og -g3
Release_FLAGS = -O3 -g0 -DNDEBUG
TEST_FLAGS ?= $(Debug_FLAGS) -Wall -Wextra -pedantic -std=c++14

#/-------------------\
#|	 			     |
#|  MAKEFILE RULES   |
#|				     |
#\-------------------/
.PHONY: all $(TARGETS) test clean cleanTests $(TESTS) $(patsubst %,clean%,$(TARGETS))
all: $(TARGETS) test

test: $(TESTS)

$(TESTODIR):
	mkdir -p "$@"

cleanTests:
	rm -f "$(TESTODIR)/*"

define TESTS_RULE

$(TEST): $(TESTODIR)/$(TEST).exe | $(TESTODIR)
	$$<

$(TESTODIR)/$(TEST).exe: $(TESTIDIR)/$$(TEST).cpp Debug/$(ODIR)/$(OUTPUT) | $(TESTODIR)
	$(CXX) -o "$$@" $$< $(TEST_FLAGS) -LDebug/$(ODIR) -l$(PROJECT)

endef


define TARGETS_RULE
$(TARGET)_OBJS = $(patsubst %,$(TARGET)/$(TEMPDIR)/%,$(_OBJS))
$(TARGET): $(TARGET)/$(ODIR)/$(OUTPUT)

$(TARGET)/$(ODIR)/$(OUTPUT): $$($(TARGET)_OBJS) | $(TARGET)/$(ODIR)
	ar crf "$$@" $$^

$(TARGET)/$(TEMPDIR)/%.o: $(IDIR)/%.cpp | $(TARGET)/$(TEMPDIR)
	$(CXX) -o "$$@" "$$<" $(CXXFLAGS) $($(TARGET)_FLAGS)

$(TARGET)/$(TEMPDIR):
	mkdir -p "$$@"

$(TARGET)/$(ODIR):
	mkdir -p "$$@"

clean$(TARGET):
	rm -f $$$$(find $(TARGET) -type f)
endef

$(foreach TARGET,$(TARGETS),$(eval $(TARGETS_RULE)))
$(foreach TEST,$(TESTS),$(eval $(TESTS_RULE)))

clean: cleanTests
	rm -f $$(find $(TARGETS) -type f)
