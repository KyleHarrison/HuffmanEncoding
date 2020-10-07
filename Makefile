CPP=g++
INCLUDES_SEARCH_PATH=./huffman_lib/
LIBRARY_LOAD_PATH=./huffman_lib/
LIBRARY_DEPENDENCIES=-lhuffman_lib
CPPFLAGS=-std=c++11 -I $(INCLUDES_SEARCH_PATH) -L $(LIBRARY_LOAD_PATH) $(LIBRARY_DEPENDENCIES)
EXE_NAME=huffencode
#define a generic rule: to go from .cpp to .o files make should invoke the c++ compiler
#the syntax tells make to invoke the compiler without linking (-c), outputting a .o file reading a .cpp file, additionally specifying flags
%.o: %.cpp
	$(CPP) -c -o $@ $< $(CPPFLAGS)
#the next rule will tell make link together our shared library object (.so file / in windows this will be a DLL file) from the compiled objects
$(EXE_NAME): huffencode.o 
	$(CPP) -o $(EXE_NAME) huffencode.o $(CPPFLAGS)  

#Never submit binaries to your git repo or vula, so create a rule for cleaning up the binary objects just leaving your source code behind
clean:
	@rm *.o huffencode
#special rule to run your code... your tutor will probably love you for this!
run:
	export LD_LIBRARY_PATH=$(LIBRARY_LOAD_PATH) && ./huffencode
