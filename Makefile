CC := clang
CXX := clang++
CFLAGS := -Ilib/raylib/src -Iinclude

SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(patsubst src/%.cpp,build/%.o,$(SOURCES))

all: raylib build/pong

raylib:
	git submodule init
	git submodule update
	make -C lib/raylib/src PLATFORM=PLATFORM_DESKTOP RAYLIB_LIBTYPE=SHARED

build/%.o: src/%.cpp
	@mkdir -p build
	$(CXX) $(CFLAGS) -c -o $(@) $(<)

build/pong: $(OBJECTS)
	$(CXX) -o $(@) $(^)

clean:
	rm -fr build

.PHONY: all clean
