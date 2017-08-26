
export CXX = g++
export CXXFLAGS ?= -c -Wall -Wextra -pedantic -std=c++17

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
$(TARGET)_SUBPROJECTS = $(patsubst %,$(TARGET)_%,$(_SUBPROJECTS))

$(TARGET): $$($(TARGET)_SUBPROJECTS)

endef

$(foreach TARGET,$(TARGETS),$(eval $(RULE)))

define RULE2

$(TARGET)_$(SUBPROJ): | $(TARGET)/$(ODIR)
	$(MAKE) $(TARGET) -C $(SUBPROJ)
	cp "$(SUBPROJ)/$(TARGET)/$(ODIR)/"* "$(TARGET)"

$(TARGET)/$(ODIR):
	mkdir -p "$$@"

endef

$(foreach TARGET,$(TARGETS), $(eval $(foreach SUBPROJ,$(_SUBPROJECTS),$(eval $(RULE2)))))

clean: $(CLEAN)
	rm Release/*
	rm Debug/*
