
all: Debug Release

Debug:
	$(MAKE) Debug -C Implementation
	mkdir -p Api/DebugLibs
	cp Implementation/Debug/* Api/DebugLibs/

Release:
	$(MAKE) Release -C Implementation
	mkdir -p Api/ReleaseLibs
	cp Implementation/Release/* Api/ReleaseLibs/

clean:
	rm -f Api/DebugLibs/*
	rm -f Api/ReleaseLibs/*

