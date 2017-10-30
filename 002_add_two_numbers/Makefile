CFLAGS += -g -Wall-Werror -O2  
CPPFLAGS += -I./inc -std=c++11
LDFLAGS +=-lpthread -g

# SRC_OBJ =$(patsubst %.c, %.o, $(wildcard *.c))  
SRC_FILES = $(wildcard *.cpp)
SRC_OBJ = $(SRC_FILES:.cpp=.o)
SRC_BIN = 002_add_two_numbers

$(SRC_BIN): $(SRC_OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

#$(SRC_OBJ): 001_two_sum.hpp

.PHONY: clean run

run: $(SRC_BIN)
	-./$^

clean:
	-rm -Rf $(SRC_BIN) $(SRC_OBJ)