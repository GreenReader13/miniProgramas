
all: P5_act3.out

P5_act3.out: Reloj.o Fecha.o Cheque.o Empleado.o P5_act3.o
	g++ -Wall -std=c++14 -o P5_act3.out Reloj.o Fecha.o Cheque.o Empleado.o P5_act3.o

P5_act3.o: P5_act3.cpp 
	g++ -Wall -std=c++11 -c P5_act3.cpp

Empleado.o: Empleado.cpp Empleado.hpp
	g++ -Wall -std=c++11 -c Empleado.cpp

Cheque.o: Cheque.cpp Cheque.hpp
	g++ -Wall -std=c++11 -c Cheque.cpp

Reloj.o: Reloj.cpp Reloj.hpp
	g++ -Wall -std=c++11 -c Reloj.cpp

Fecha.o: Fecha.cpp Fecha.hpp
	g++ -Wall -std=c++11 -c Fecha.cpp

clean: 
	-rm *.o *.out *.*~
