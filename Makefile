V=1
SOURCE_DIR=src
BUILD_DIR=build
include $(N64_INST)/include/n64.mk

all: midas.z64
.PHONY: all

OBJS = $(BUILD_DIR)/main.o

midas.z64: N64_ROM_TITLE="MidAS 64"
midas.z64: $(BUILD_DIR)/sprites.dfs

$(BUILD_DIR)/sprites.dfs: $(wildcard filesystem/*)
$(BUILD_DIR)/midas.elf: $(OBJS)

clean:
	rm -f $(BUILD_DIR)/* *.z64
.PHONY: clean

-include $(wildcard $(BUILD_DIR)/*.d)