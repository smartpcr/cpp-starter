.DEFAULT_GOAL:=help
BUILDDIR = build
TARGET = restapi

## --------------------------------------
## Help
## --------------------------------------
##@ help:
help: ## Display this help.
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make \033[36m<target>\033[0m\n"} /^[0-9a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-25s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)


## --------------------------------------
## Build
## --------------------------------------
##@ build:

.PHONY: info
info: ## Display environment variables
	@echo "OS: ${OS}"
	@echo "BUILDDIR: ${BUILDDIR}"
	@echo "TARGET: ${TARGET}"
	@echo "VCPKG_ROOT: ${VCPKG_ROOT}"

.PHONY: build
build-debug: clean ## Build the project in debug mode
ifeq (${OS},Linux)
	@echo "Building for Linux"
	mkdir -p $(BUILDDIR)
	cmake --preset=linux
	cd $(BUILDDIR) && cmake .. -G "Ninja" -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Debug
	cd $(BUILDDIR) && cmake --build .
else ifeq (${OS},Windows_NT)
	@echo "Building for Windows"
	mkdir $(BUILDDIR)
	cmake --preset=windows
	cd $(BUILDDIR) && cmake .. -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=Debug
	cd $(BUILDDIR) && cmake --build .
else
	$(error Unknown OS: ${OS})
endif

.PHONY: run
debug: build-debug ## Run the project
ifeq (${OS},Linux)
	./$(BUILDDIR)/Debug/$(TARGET)
else ifeq (${OS},Windows_NT)
	$(BUILDDIR)/Debug/$(TARGET).exe
else
	$(error Unknown OS: ${OS})
endif

.PHONY: clean
clean: ## Clean the build directory
ifeq ($(wildcard $(BUILDDIR)/.*),)
	@echo "Build directory already removed"
else
	rm -rf $(BUILDDIR)
endif