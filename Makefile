# -----------------------------------------
# PROJECT: table
# AUTHOR : Tommy Wu (7852291)
# -----------------------------------------

# Adopted from the makefile given in class

#---------------------------------------------------------------------
# C++ COMPILER, COMPILER FLAGS, AND TARGET PROGRAM NAME
#---------------------------------------------------------------------
TARGET   =./bin/table
DIR_SRC  =./src/
DIR_OBJS =./.objects
CC       =clang
CCFLAGS  =-Wall -DNDEBUG -g


#---------------------------------------------------------------------
# FILES
#---------------------------------------------------------------------
# We list all files here to make our life easier in specifying dependencies
# \ means the line is not ended. Normally HEADER=header1.h header2.h
# But we want to separate lines so they look nicer.
HEADERS=./header/table.h

SOURCES=./src/main.c  ./src/table.c

OBJECTS=$(DIR_OBJS)/table.o \
		$(DIR_OBJS)/main.o


#---------------------------------------------------------------------
# COMPILING RULES
#---------------------------------------------------------------------
# First rule is default, that is, if you don't specify specific rule, makefile will use the first rule.
default: $(TARGET)

# Link compiled objects and create an executable binary.
# It requires to have directory for objects and to compile objects
$(TARGET): check_headers make_directory $(OBJECTS)
	$(CC)  $(OBJECTS) -o $@

check_headers: $(HEADERS)

make_directory:
	mkdir -p $(DIR_OBJS)/

# Compile C files
$(DIR_OBJS)/%.o: $(DIR_SRC)%.c
	$(CC) $(CCFLAGS) -c $? -o $@

# Clean removes every object and binary
clean:
	rm -rf $(TARGET) $(OBJECTS) $(DIR_OBJS)/


#---------------------------------------------------------------------
# END OF MAKEFILE
#---------------------------------------------------------------------
