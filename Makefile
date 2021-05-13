Practic_2:  Practic_2.o Trains.o  RManager.o ChekData.o libCheckSize.a libCheckCountElements.so
			gcc -oPractic_2 Practic_2.o Trains.o RManager.o ChekData.o -L. -lCheckSize -lCheckCountElements -Wl,-rpath,.
ChekData.o: ChekData.c
			gcc -c ChekData.c
RManager.o: RManager.c
			gcc -c RManager.c
Trains.o: 	Trains.c
			gcc -c Trains.c
Practic_2.o: Practic_2.c Trains.h RManager.h ChekData.h CheckSize.h CheckCountElements.h
			gcc -c Practic_2.c	
# 
CheckSize.o: CheckSize.c 
			gcc -c CheckSize.c
libCheckSize.a: CheckSize.o 
			ar cr libCheckSize.a CheckSize.o
CheckCountElements.o: CheckCountElements.c
			gcc -c CheckCountElements.c
# 
libCheckCountElements.so: CheckCountElements.o
			gcc -fPIC -shared -olibCheckCountElements.so CheckCountElements.o
# 
UnitTests.o: UnitTests.c Trains.h RManager.h ChekData.h CheckSize.h CheckCountElements.h
			gcc -c UnitTests.c

UnitTests: UnitTests.o  Trains.o RManager.o ChekData.o libCheckSize.a libCheckCountElements.so
			gcc -oUnitTests UnitTests.o Trains.o RManager.o ChekData.o -L. -lCheckSize Unity/src/unity.c

# 
SecondTest.o: SecondTest.c Trains.h RManager.h ChekData.h CheckSize.h CheckCountElements.h
			gcc -c SecondTest.c

SecondTest: SecondTest.o  Trains.o RManager.o ChekData.o libCheckCountElements.so
			gcc -oSecondTest SecondTest.o Trains.o RManager.o ChekData.o Unity/src/unity.c -L. -lCheckCountElements -Wl,-rpath,. 

# 
runtests:	UnitTests SecondTest
			./UnitTests
			./SecondTest
# 
clean:		
			rm --force Practic_2 Trains RManager ChekData SecondTest UnitTests *.so *.a *.o
