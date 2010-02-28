# Wolfetparser
# Author: 	Joakim Bech, d00jb@efd.lth.se
# 
# Makefile to make the test programs myserver and myclient,
# using the classes Connection and Server that are defined
# in /usr/local/cs/lib/sun/connection.h (server.h), and
# the library libclientserver.a in the same directory.
#
# Note that the executables are created in the current directory.
#
TARGETDIR	= ../build/
SOURCEDIR	= ../src/
PREFIX		= $(HOME)/bin
VPATH			= $(SOURCEDIR)

# Define the compiler
CXX			= g++

# Define the linker. This must be done since the implicit rule
# for linking .o-files uses CC as the linker.
CC				= g++

# Define compiler flags
CXXFLAGS	 = -Wall -W -pedantic-errors 
CXXFLAGS	+= -Wmissing-braces -Wparentheses -Wold-style-cast
#CXXFLAGS +=-ggdb
#CXXFLAGS +=-Werror

# Define linker flags
#LDFLAGS		 = -debug.h

# Define source files
SRC	= $(patsubst $(SOURCEDIR)%,%,$(wildcard $(SOURCEDIR)*.cpp))

# Targets
PROGS	= wolfparser
OBJS 	= wolfparser.o wolfetparser.o parser.o debug.o utilities.o \
	parserfactory.o wolfetfactory.o

# Phony targets
.PHONY: all clean distclean

all: $(PROGS)

# Targets rely on implicit rules for compiling and linking.
# Only one .o-file for each executable in this case.

wolfparser: $(OBJS)
	$(CC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $@ $^

# Standard clean and cleaner
clean:
	rm -f *.o

distclean:
	rm -f $(PROGS)
	rm -f *.d*
	rm -f $(OBJS)
	rm -f *.a*

# Generate dependencies in *.d files
%.d: %.cpp
	@set -e; rm -f $@; \
	 $(CXX) -MM $(CPPFLAGS) $< > $@.$$$$; \
	 sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	 rm -f $@.$$$$

# Include dependencies in *.d files
include $(SRC:.cpp=.d)

