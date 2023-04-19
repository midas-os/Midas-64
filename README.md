# MidAS 64
An Operating System for the Nintendo 64

## What is MidAS 64?
MidAS 64 is an operating system for the Nintendo 64. It is written in C++ with the libdragon library.<br>
It is currently in development and is not yet ready for use.

## How to build
### Prerequisites
- [libdragon](https://libdragon.dev)
- [libdragon-cli](https://github.com/rasky/libdragon-cli)

### Cloning
When cloning with git, make sure to use the `--recursive` flag to clone the submodules.
How to clone with git:
```bash
git clone --recursive https://github.com/midas-os/Midas-64.git
```

### Building
To build MidAS 64, run the following command in the root directory of the project (only possible if you have [libdragon-cli](https://github.com/rasky/libdragon-cli) installed and added to your path):
```bash
libdragon make
```

## How to run
To run MidAS 64, you need a Nintendo 64 emulator. We recommend [simple64](https://simple64.github.io/)
