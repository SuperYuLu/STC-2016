# Options
CC = g++
DEBUG = -g
#LFLAGS = -Wall
CFLAGS = -c -O3

# Files
EXE = run
SRCS = main.cc initTrap.cc isOn.cc calCurrent.cc calField.cc genFieldMatrix.cc\
cleanField.cc calTotalField.cc findFieldMin_V2.cc cleanTrapsField.cc csvWriteAll.cc csvWriteMin.cc
OBJS = $(patsubst %.cc,%.o,$(SRCS))
HEADS = main.h traps.h const.h

# Rules
$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $^ -o $@
initTrap.o: initTrap.cc #const.h traps.h
	$(CC) $(CFLAGS) $<
isOn.o: isOn.cc traps.h
	$(CC) $(CFLAGS) $<
calCurrent.o: calCurrent.cc const.h traps.h
	$(CC) $(CFLAGS) $<
calField.o: calField.cc const.h traps.h
	$(CC) $(CFLAGS) $<
genFieldMatrix.o: genFieldMatrix.cc calCurrent.cc calField.cc traps.h const.h
	$(CC) $(CFLAGS) $<
cleanField.o: cleanField.cc traps.h const.h
	$(CC) $(CFLAGS) $<
calTotalField.o: calTotalField.cc const.h traps.h
	$(CC) $(CFLAGS) $<
findFieldMin_V2.o: findFieldMin_V2.cc
	$(CC) $(CFLAGS) $<
cleanTrapsField.o: cleanTrapsField.cc traps.h const.h
	$(CC) $(CFLAGS) $<
csvWriteAll.o: csvWriteAll.cc
	$(CC) $(CFLAGS) $<
csvWriteMin.o: csvWriteMin.cc
	$(CC) $(CFLAGS) $<
main.o: main.cc main.h const.h traps.h 
	$(CC) $(CFLAGS) $<

# Phony targets
plotall:
	python3 plotAll.py
plotmin:
	python3 plotMin.py
clean:
	rm *.o run
clear:
	rm  ../dat/*
tar:
	tar cfv 
