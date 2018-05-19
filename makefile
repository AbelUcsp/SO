BIN       = bin
SRC 	  = src
OBJ 	  = obj
CXX 	  = gcc

SOURCES = $(wildcard $(SRC)/*.c)
OBJS = $(addprefix $(OBJ)/*, $(notdir $(SOURCES:.c)))
target1 = pw
target2 = pr


all: $(BIN)/$(target1) $(BIN)/$(target2) 

$(BIN)/$(target1): $(OBJS) 
	@$(CXX) src/pw.c -o $@ -lrt -lpthread
$(BIN)/$(target2): $(OBJS)
	@$(CXX) src/pr.c -o $@ -lrt -lpthread







clean:
	-rm *.o $(OBJS) 
