a4q3: main.o image.o basic.o exception.o decorator.o flip.o rotate.o sepia.o
	g++ -Werror=vla main.o basic.o image.o exception.o decorator.o flip.o rotate.o sepia.o -o a4q3

image.o: image.cc image.h ppm.h
	g++ -std=c++14 -c image.cc

exception.o: exception.cc exception.h
	g++ -std=c++14 -c exception.cc

basic.o: basic.cc basic.h image.h exception.h 
	g++ -std=c++14 -c basic.cc

decorator.o: decorator.cc decorator.h image.h
	g++ -std=c++14 -c decorator.cc

flip.o: flip.cc flip.h decorator.h
	g++ -std=c++14 -c flip.cc

rotate.o: rotate.cc rotate.h decorator.h
	g++ -std=c++14 -c rotate.cc

sepia.o: sepia.cc sepia.h decorator.h
	g++ -std=c++14 -c sepia.cc

main.o: main.cc image.h basic.h exception.h decorator.h flip.h rotate.h sepia.h
	g++ -std=c++14 -c main.cc

.PHONY: clean

clean:
	rm *.o a4q3
