TARGET_EXEC ?= game
CXX ?= g++

SRC_DIRS ?= ./
BUILD_DIR ?= ./build

SDLFLAGS := $(shell sdl2-config --cflags --libs)

MKDIR_P ?= mkdir -p

SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(SDLFLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)






