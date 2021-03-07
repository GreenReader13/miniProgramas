
all: P7_act1.out

P7_act1.out: Cuenta.o CuentaAhorro.o CuentaCheques.o Test.o
	g++ -Wall -std=c++14 -o Test.out Cuenta.o CuentaAhorro.o CuentaCheques.o Test.o

Test.o: Test.cpp 
	g++ -Wall -std=c++11 -c Test.cpp

Cuenta.o: Cuenta.cpp Cuenta.hpp
	g++ -Wall -std=c++11 -c Cuenta.cpp

CuentaAhorro.o: CuentaAhorro.cpp CuentaAhorro.hpp
	g++ -Wall -std=c++11 -c CuentaAhorro.cpp

CuentaCheques.o: CuentaCheques.cpp CuentaCheques.hpp
	g++ -Wall -std=c++11 -c CuentaCheques.cpp

clean: 
	-rm *.o *.out *.*~
