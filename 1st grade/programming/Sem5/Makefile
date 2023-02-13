TARGET = problem_lr
CC = gcc
CFLAGS = -g -Wall -Wpedantic -Wextra -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

PREF_SRC = .
PREF_OBJ = .

SRC = $(TARGET).c
OBJ = $(TARGET).o

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o : $(PREF_SRC)%.c
	$(CC) -c $< -o $@

clean : 
	rm $(TARGET) *.o 