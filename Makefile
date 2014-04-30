TARGET = matrix
SRCS = main.c matrix.c

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -lm

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

matrix.c : matrix.h

.c.o :
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f *.o $(TARGET)
