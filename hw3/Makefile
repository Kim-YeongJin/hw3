CC=g++
CFLAGS= -Wall 
OBJS = makerec.o
INCDIR=./include
LIBDIR=./lib
DIRS = buf fixed student coursereg var recfile

.PHONY: all clean

all: makerec
%.o: %.cpp
	$(CC) -c -I$(INCDIR) $(CFLAGS) -o $@ $<

makerec: $(OBJS)
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d; \
	done
	$(CC) -o makerec $(OBJS) -L$(LIBDIR) -lmyrecfile -lmybuffer -lmyfixed -lmystudent -lmycoursereg -lmyvar
	export LD_LIBRARY_PATH=$(LIBDIR)

clean:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d clean; \
	done
	-rm -rf makerec $(OBJS) 
