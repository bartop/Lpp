
export CXX = g++
export CXXFLAGS ?= -c -Wall -Wextra -pedantic -std=c++14

ODIR = Build

_SUBPROJECTS = Boolean Number


#/--------------------\
#| 				      |
#|  TARGETS SETTINGS  |
#| 				      |
#\--------------------/

TARGETS = Debug Release

all: $(TARGETS)

define RULE
$(TARGET)_SUBPROJECTS = $(patsubst %,$(TARGET)/lib%.a,$(_SUBPROJECTS))

$(TARGET): $$($(TARGET)_SUBPROJECTS)

endef

$(foreach TARGET,$(TARGETS),$(eval $(RULE)))

define RULE2
$(TARGET)_$(SUBPROJ) = $(patsubst %,$(TARGET)/lib%.a,$(SUBPROJ))
$(TARGET)_$(SUBPROJ)_REQS = $(patsubst %,$(patsubst %,%/$(TARGET)/$(ODIR)/lib%.a,$(SUBPROJ)),$(SUBPROJ))

$$($(TARGET)_$(SUBPROJ)): $$($(TARGET)_$(SUBPROJ)_REQS)
	$(MAKE) $(TARGET) -C $(SUBPROJ)
	mkdir -p $$(@D)
	cp $$< $$@

endef

$(foreach TARGET,$(TARGETS), $(eval $(foreach SUBPROJ,$(_SUBPROJECTS),$(eval $(RULE2)))))

clean: $(CLEAN)
	rm Release/*
	rm Debug/*
