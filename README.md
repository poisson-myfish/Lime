# Lime
A small operating system with a custom kernel for x86.

I just started this project, so don't expect anything.
The build system also has rough edges, but it will improve with time.

# Building
I build it with clang, so there is no need for a cross-compiler. We do, however, compile the linker.
To build, just clone the repo and run `./build-toolchain.sh`, then run `make`.
To run it in QEMU, just run `make run-qemu`.