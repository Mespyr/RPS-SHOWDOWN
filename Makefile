SRC_DIRS=src src/engine
SRC_FILES=$(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.cpp))
HEADERS=$(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.hpp))

format: $(SRC_FILES) $(HEADERS)
	clang-format -i $(SRC_FILES) $(HEADERS) -style=file

build: $(SRC_FILES) $(HEADERS)
	cmake --build build/

run: $(SRC_FILES) $(HEADERS)
	./build/RPS_SHOWDOWN
