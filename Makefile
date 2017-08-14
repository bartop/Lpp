
all: Debug Release

Debug:
	$(MAKE) Debug -C Implementation
	cp Implementation/Debug/* Api/DebugLibs/

Release:
	$(MAKE) Release -C Implementation
	cp Implementation/Release/* Api/DebugLibs/

clean:
	rm -f Api/DebugLibs/*
	rm -f Api/ReleaseLibs/*

