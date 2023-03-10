CXX=g++
CXXFLAGS=-g -O3 -std=c++17 -Wall
BINS=01_references.bin 02_structs_with_methods.bin 03a_constructors.bin 03_constructors.bin 04_inheritance.bin 05_subclasses_protected_private.bin 06_templates.bin 07_late_binding.bin heap_and_stack.bin

.phony:	clean all

all:	$(BINS)

%.bin: 	%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *~ *.o $(BINS)
