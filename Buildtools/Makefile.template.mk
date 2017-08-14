
IDIR = Src
TEMPDIR = Temp
ODIR = Build

CXX ?= g++
CXXFLAGS ?= -c -Wall -Wextra -pedantic -std=c++14

_OBJS = $(shell (find Src -type f -name *.cpp -printf "%f " | sed 's/.cpp/.o/g'))

#/--------------------\
#| 				      |
#|  TARGETS SETTINGS  |
#| 				      |
#\--------------------/

TARGETS = Debug Release
Debug_FLAGS = -Og -g3
Release_FLAGS = -O3 -g0 -DNDEBUG

#/-------------------\
#|	 			     |
#|  MAKEFILE RULES   |
#|				     |
#\-------------------/

all: $(TARGETS)

define RULE
$(TARGET)_OBJS = $(patsubst %,$(TARGET)/$(TEMPDIR)/%,$(_OBJS))
$(TARGET): $(TARGET)/$(ODIR)/$(OUTPUT)

$(TARGET)/$(ODIR)/$(OUTPUT): $$($(TARGET)_OBJS)
	ar crf $$@ $$^

$(TARGET)/$(TEMPDIR)/%.o: $(IDIR)/%.cpp
	$(CXX) -o $$@ $$< $(CXXFLAGS) $($(TARGET)_FLAGS)

clean$(TARGET):
	rm -f $(shell (find $(TARGET) -type f))
endef

$(foreach TARGET,$(TARGETS),$(eval $(RULE)))

clean:
	rm -f $(shell (find $(TARGETS) -type f))
