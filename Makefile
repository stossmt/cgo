BUILD_DIR = build
EXECUTABLE = cgo

all: build

setup:
	@mkdir -p $(BUILD_DIR)
	@cmake -B $(BUILD_DIR) -S . -DCMAKE_TOOLCHAIN_FILE=/Users/matthewstoss/programming/vcpkg/scripts/buildsystems/vcpkg.cmake

build:
	@cmake --build $(BUILD_DIR)

run: build
	@$(BUILD_DIR)/$(EXECUTABLE)

clean:
	@rm -rf $(BUILD_DIR)

test: build
	@ctest --test-dir $(BUILD_DIR)

test_single: build
	@if [ -z "$(TEST_NAME)" ]; then \
		echo "Please specify a test name using TEST_NAME=<test_name>"; \
	else \
		ctest --test-dir $(BUILD_DIR) -R $(TEST_NAME); \
	fi

.PHONY: all setup build run clean test