
.PHONY: all Debug Release clean

all: Debug Release

Debug: | Api/DebugLibs
	$(MAKE) Debug -C Implementation
	cp Implementation/Debug/* Api/DebugLibs/

Api/DebugLibs:
	mkdir -p Api/DebugLibs

Release: | Api/ReleaseLibs
	$(MAKE) Release -C Implementation
	cp Implementation/Release/* Api/ReleaseLibs/

Api/ReleaseLibs:
	mkdir -p Api/ReleaseLibs

clean:
	rm -f Api/DebugLibs/*
	rm -f Api/ReleaseLibs/*
