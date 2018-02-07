.POSIX:
I_DIR = ./inc
CPP = g++
CPPFLAGS = -g -Wall -I$(I_DIR)
LDLIBS = -lncurses --enable-widec

all: main
main: main.o prompt.o frame.o colors.o data_pre.o
	$(CPP) $(LDFLAGS) -o ./bin/ncplot main.o prompt.o frame.o colors.o data_pre.o $(LDLIBS)

main.o: main.cc 
prompt.o: prompt.cc $(I_DIR)/prompt.h
frame.o: frame.cc $(I_DIR)/frame.h $(I_DIR)/colors.h
colors.o: colors.cc $(I_DIR)/colors.h
data_pre.o: data_pre.cc $(I_DIR)/data_pre.h
clean:
	rm -f ./bin/ncplot prompt.o main.o frame.o colors.o data_pre.o
