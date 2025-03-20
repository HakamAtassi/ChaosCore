


all:
	verilator --binary vsrc/SDL2.v csrc/SDL2.cc -LDFLAGS -lSDL2 -j 12
