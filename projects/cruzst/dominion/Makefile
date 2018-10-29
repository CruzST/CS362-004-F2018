CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS) -coverage

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unittest1: unittest1.c dominion.c rngs.c
	gcc -g dominion.c -lm rngs.c unittest1.c -o unittest1

unittest2: unittest2.c dominion.c rngs.c
	gcc -g dominion.c -lm rngs.c unittest2.c -o unittest2

unittest3: unittest3.c dominion.c rngs.c
	gcc -g dominion.c -lm rngs.c unittest3.c -o unittest3

unittest4: unittest4.c dominion.c rngs.c
	gcc -g dominion.c -lm rngs.c unittest4.c -o unittest4

cardtest1: cardtest1.c dominion.c rngs.c
	gcc -g dominion.c -lm rngs.c cardtest1.c -o cardtest1

cardtest2: cardtest1.c dominion.c rngs.c
	gcc -g dominion.c -lm rngs.c cardtest2.c -o cardtest2

cardtest3: cardtest1.c dominion.c rngs.c
	gcc -g dominion.c -lm rngs.c cardtest3.c -o cardtest3

cardtest4: cardtest1.c dominion.c rngs.c
	gcc -g dominion.c -lm rngs.c cardtest4.c -o cardtest4

unittestresults: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	unittest1 &> unittestresults.out
	unittest2 >> unittestresults.out
	unittest3 >> unittestresults.out
	unittest4 >> unittestresults.out
	cardtest1 >> unittestresults.out
	cardtest2 >> unittestresults.out
	cardtest3 >> unittestresults.out
	cardtest4 >> unittestresults.out
	./playdom 2
	gcov dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out




player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player unittestresults

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 unittestresults.out
