TARGET_EXEC ?= game
CXX ?= clang++ 
CWEB ?= em++

SRC_DIRS ?= "./"
BUILD_DIR ?= ./build

SDLFLAGS := $(shell sdl2-config --cflags --libs) -lSDL2_Image -w -Wc++17
CPPFLAGS := --std=c++14
WEBFLAGS := -O3 -s USE_SDL_IMAGE="2" -s SDL2_IMAGE_FORMATS="['png']"

MKDIR_P ?= mkdir -p

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(SDLFLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(SDLFLAGS)  $(CXXFLAGS) -c $< -o $@

web:
	$(CWEB) $(CPPFLAGS) $(WEBFLAGS) $(SRCS) --preload-file ./assets/ship.png --preload-file ./assets/background.png  -o $(BUILD_DIR)/index.html

run: $(BUILD_DIR)/$(TARGET_EXEC)
	$(BUILD_DIR)/$(TARGET_EXEC)

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)






