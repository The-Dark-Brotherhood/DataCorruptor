#
# FILE : makefile
# PROJECT :  A-03: Hoochamacallit DataCreator
# PROGRAMMER : Michael Gordon & Gabriel Gurgel
# FIRST VERSION : 2020-03-12
# DESCRIPTION : This makefile is from the MyApp Example provided in the SET Program
#
# FINAL BINARY Target
../dataReader/bin/DataCorruptor :	./obj/DataCorruptor.o	./obj/DataCorruptorLogging.o
	cc ./obj/DataCorruptor.o	./obj/DataCorruptorLogging.o -o	../dataReader/bin/DataCorruptor
#
# =======================================================
#                     Dependencies
# =======================================================
./obj/DataCorruptor.o :	./src/DataCorruptor.c ./inc/DataCorruptor.h
	cc -c ./src/DataCorruptor.c -o ./obj/DataCorruptor.o

./obj/DataCorruptorLogging.o : ./src/DataCorruptorLogging.c ./inc/DataCorruptor.h
	cc -c ./src/DataCorruptorLogging.c -o ./obj/DataCorruptorLogging.o

#
# =======================================================
# Other targets
# =======================================================
all : ../dataReader/bin/DataCorruptor

clean:
	rm -f ./bin/*
	rm -f ./obj/*.o
	rm -f ./inc/*.h~
	rm -f ./src/*.c~
