TARGET_EXEC ?= game.html
CXX ?= em++ 

SRC_DIRS ?= "./"
BUILD_DIR ?= ./build

CPPFLAGS := --std=c++1z 

MKDIR_P ?= mkdir -p

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(CPPFLAGS) -s USE_SDL_IMAGE="2" -s SDL2_IMAGE_FORMATS="[“png”]" $(SRCS) -o $(TARGET_EXEC)

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)

run: $(BUILD_DIR)/$(TARGET_EXEC)
	$(BUILD_DIR)/$(TARGET_EXEC)

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)






