# Numa Library

## Description

Numa Library is a lightweight C library that provides function to generate hexadecimal & ASCII dumps of binary data.

## Key Features

- Customizable output format
- Support for different grouping sizes (1, 2, 4, or 8 bytes)
- ASCII representation alongside hex output
- Configurable number of bytes per row

## Installation

### Prerequisities

- CMake (version 3.10 or higher)
- A C compiler (supporting C99 standard)


### Building the Library

1. For the default static library build
```shell
cmake -B build
cmake --build build
```
2. To build a shared library:
```shell
cmake -B build -DBUILD_SHARED_LIBS=ON
cmake --build build
```

### Installing the Library

To install the library to the default location (/usr/local):
```shell
sudo cmake --install build
```

To specify a custom installation directory:
```shell
cmake -B build -DINSTALL_DIR=/usr
cmake --build build
cmake --install build
```