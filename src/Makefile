# Options
CC = g++
DEBUG = -g
LFLAGS = 
CFLAGS = -c -O3

# Files
EXE = run
SRCS = main.cc initTrap.cc isOn.cc calCurrent.cc calField.cc genFieldMatrix.cc\
calTotalField.cc findFieldMin.cc
OBJS = $(patsubst %.cc,%.o,$(SRCs))
HEADS = main.h traps.h const.h

# Rules
all: $(SRCS) $(EXE)
main.h: traps.h
$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(SRCS) -o $@
initTrap.o: initTrap.cc const.h traps.h
	$(CC) $(CFLAGS) $<
isOn.o: isOn.cc traps.h
	$(CC) $(CFLAGS) $<
calCurrent.o: calCurrent.cc const.h traps.h
	$(CC) $(CFLAGS) $<
calField.o: calField.cc const.h traps.h
	$(CC) $(CFLAGS) $<
genFieldMatrix.o: genFieldMatrix.cc calCurrent.cc calField.cc traps.h const.h
	$(CC) $(CFLAGS) $<
calTotalField.o: calTotalField.cc const.h traps.h
	$(CC) $(CFLAGS) $<
findFieldMin.o: findFieldMin.cc
	$(CC) $(CFLAGS) $<
main.o: main.cc main.h
	$(CC) $(CFLAGS) $<

# Phony targets
clean:
	\rm *.o *~
tar:
	tar cfv 

