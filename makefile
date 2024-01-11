CXX = g++

# This is the compiler links
CXXLINKS = -g -Wall -Wextra -Wpedantic

# This is the compiler flag
CXXFLAG = -c

# This are the objects dependencies file
OBJS = program.o person.o book.o librarian.o member.o

# Produce the executable
.PHONY: all
all : execute

execute : main.cpp $(OBJS)
	@echo "---------------------------------------"
	@echo "Creating the executable for the program"
	@echo "---------------------------------------"
	$(CXX) $(CXXLINKS) -o $@ $^

# Produce the test
.PHONY: test
test : testing

testing: test.cpp $(OBJS)
	$(CXX) $(CXXLINKS) -o $@ $^

%.o : %.cpp
	@echo "---------------------------------------"
	@echo "Compiling the file $<"
	@echo "---------------------------------------"
	$(CXX) $(CXXLINKS) $(CXXFLAG) $<

# For clean up
.PHONY : clean 
clean :
	@echo "---------------------------------------"
	@echo "Clean up $<"
	@echo "---------------------------------------"
	$(RM) *.o
	$(RM) execute
	$(RM) testing

# Dependencies chains
program.o 	: program.cpp program.h
person.o    : person.cpp person.h
librarian.o	: librarian.cpp librarian.h
member.o	: member.cpp member.h
book.o	    : book.cpp book.h
