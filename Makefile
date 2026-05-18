# GENERAL VARIABLES
CC = gcc
CFLAGS = -Wall -g -Iinclude -Itests/testing_include

# Executable name
TARGET = manutenzione

# Explicit list of ALL required object files (.o)
OBJ = obj/main.o \
      obj/Btree.o \
      obj/PQueue.o \
      obj/intervention.o \
      obj/list.o \
      obj/opIntervention.o \
      obj/opRequest.o \
      obj/opTechnician.o \
      obj/request.o \
      obj/technician.o \
      obj/utils.o \
      obj/pqueueTesting.o \
      obj/testingBtree.o \
      obj/testingIntervention.o \
      obj/testingList.o \
      obj/testingOpIntervention.o \
      obj/testingOpRequest.o \
      obj/testingOpTechnician.o \
      obj/testingRequest.o \
      obj/testingTechnician.o \
      obj/testingUtils.o

# MAIN RULES

all: obj_dir $(TARGET)

# # Creates the obj directory while isolating errors
obj_dir:
	@if not exist obj mkdir obj 2>nul || mkdir -p obj

# Linking
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Creating (.o) files for the SOURCE CODE

obj/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o

obj/Btree.o: src/Btree.c
	$(CC) $(CFLAGS) -c src/Btree.c -o obj/Btree.o

obj/PQueue.o: src/PQueue.c
	$(CC) $(CFLAGS) -c src/PQueue.c -o obj/PQueue.o

obj/intervention.o: src/intervention.c
	$(CC) $(CFLAGS) -c src/intervention.c -o obj/intervention.o

obj/list.o: src/list.c
	$(CC) $(CFLAGS) -c src/list.c -o obj/list.o

obj/opIntervention.o: src/opIntervention.c
	$(CC) $(CFLAGS) -c src/opIntervention.c -o obj/opIntervention.o

obj/opRequest.o: src/opRequest.c
	$(CC) $(CFLAGS) -c src/opRequest.c -o obj/opRequest.o

obj/opTechnician.o: src/opTechnician.c
	$(CC) $(CFLAGS) -c src/opTechnician.c -o obj/opTechnician.o

obj/request.o: src/request.c
	$(CC) $(CFLAGS) -c src/request.c -o obj/request.o

obj/technician.o: src/technician.c
	$(CC) $(CFLAGS) -c src/technician.c -o obj/technician.o

obj/utils.o: src/utils.c
	$(CC) $(CFLAGS) -c src/utils.c -o obj/utils.o

# Creating (.o) files for the TESTING CODE

obj/pqueueTesting.o: tests/testing_src/pqueueTesting.c
	$(CC) $(CFLAGS) -c tests/testing_src/pqueueTesting.c -o obj/pqueueTesting.o

obj/testingBtree.o: tests/testing_src/testingBtree.c
	$(CC) $(CFLAGS) -c tests/testing_src/testingBtree.c -o obj/testingBtree.o

obj/testingIntervention.o: tests/testing_src/testingIntervention.c
	$(CC) $(CFLAGS) -c tests/testing_src/testingIntervention.c -o obj/testingIntervention.o

obj/testingList.o: tests/testing_src/testingList.c
	$(CC) $(CFLAGS) -c tests/testing_src/testingList.c -o obj/testingList.o

obj/testingOpIntervention.o: tests/testing_src/testingOpIntervention.c
	$(CC) $(CFLAGS) -c tests/testing_src/testingOpIntervention.c -o obj/testingOpIntervention.o

obj/testingOpRequest.o: tests/testing_src/testingOpRequest.c
	$(CC) $(CFLAGS) -c tests/testing_src/testingOpRequest.c -o obj/testingOpRequest.o

obj/testingOpTechnician.o: tests/testing_src/testingOpTechnician.c
	$(CC) $(CFLAGS) -c tests/testing_src/testingOpTechnician.c -o obj/testingOpTechnician.o

obj/testingRequest.o: tests/testing_src/testingRequest.c
	$(CC) $(CFLAGS) -c tests/testing_src/testingRequest.c -o obj/testingRequest.o

obj/testingTechnician.o: tests/testing_src/testingTechnician.c
	$(CC) $(CFLAGS) -c tests/testing_src/testingTechnician.c -o obj/testingTechnician.o

obj/testingUtils.o: tests/testing_src/testingUtils.c
	$(CC) $(CFLAGS) -c tests/testing_src/testingUtils.c -o obj/testingUtils.o

# CLEANUP
clean:
	@if exist obj rmdir /s /q obj 2>nul || rm -rf obj
	@if exist $(TARGET) del /f /q $(TARGET) 2>nul || rm -f $(TARGET)
	@if exist $(TARGET).exe del /f /q $(TARGET).exe 2>nul || rm -f $(TARGET).exe

.PHONY: all clean obj_dir