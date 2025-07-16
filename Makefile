CC := clang
CXX := clang++
CFLAGS := -Iinclude
LDFLAGS := -lsfml-system -lsfml-window -lsfml-graphics

# SOURCES := $(wildcard src/*.cpp)
SOURCES := src/main.cpp
OBJECTS := $(patsubst src/%.cpp,build/%.o,$(SOURCES))

all: build/pong

build/%.o: src/%.cpp
	@mkdir -p build
	$(CXX) $(CFLAGS) -c -o $(@) $(<)

build/pong: $(OBJECTS)
	$(CXX) -o $(@) $(^) $(LDFLAGS)

clean:
	rm -fr build

.PHONY: all clean
