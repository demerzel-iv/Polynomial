CompOpt = g++ -O2 -std=c++11
objects = Int.h Double.h Image.h temps.h element.h 
felement = Int.o Double.o Image.o element.o

mobject = $(felement) main.cpp polynomial.o
main : $(mobject)
	$(CompOpt) $(mobject) -o main 

eobject = $(felement) testelement.cpp
te: $(eobject)
	$(CompOpt) $(eobject) -o te

polynomial.o: $(objects) polynomial.h polynomial.cpp
	$(CompOpt) polynomial.cpp -c -o polynomial.o

element.o: $(objects) element.cpp
	$(CompOpt) element.cpp -c -o element.o

Int.o: Int.cpp Int.h temps.h
	$(CompOpt) Int.cpp -c -o Int.o

Double.o: Double.cpp Double.h temps.h
	$(CompOpt) Double.cpp -c -o Double.o

Image.o: Image.cpp Image.h temps.h;
	$(CompOpt) Image.cpp -c -o Image.o
