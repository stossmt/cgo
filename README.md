# Build Instructions

## Prerequisites

- Vcpkg is required to build cgo. 

    - `git clone https://github.com/microsoft/vcpkg.git`
    - `cd vcpkg && ./bootstrap-vcpkg.sh`
    - Run `pwd` and save the printed filepath as environment variable `export VCPKG_ROOT="{path}"`

## Running

Run `make setup` once.

Run `make build` or `make run` whenever you want to build or run. You don't need to re-run setup everytime, only the first time.

## Running Tests

Run `make setup` once.

Run `make test` to run all tests. You don't need to re-run setup everytime, only the first time.

You can also run a single test. For instance `make test_single TEST_NAME=AdditionTest`