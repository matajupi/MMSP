CC := gcc
OBJS := mmslib.o
CFLAGS := -W -Wall

TEST_CFLAGS := $(CFLAGS)
TEST_LIBDIR := -L/usr/TEST_LIBDIR
TEST_LIB := -lcunit

all: main test

main: $(OBJS)

test: test.c mmslib.c
	$(CC) $^ $(TEST_CFLAGS) $(TEST_LIBDIR) $(TEST_LIB) -o $@

$(OBJS): mms.h

.PHONY: clean
clean:
	-rm *.o
	-rm main test

.DEFAULT_GOAL=all