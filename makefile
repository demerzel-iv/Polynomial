CompOpt = g++ -O2 -std=c++11
objects = Int.h Double.h Image.h temps.h element.h polymath.h
felement = Int.o Double.o Image.o element.o Imaginary.o polymath.o

mobject = $(felement) main.cpp poly.o
main : $(mobject)
	$(CompOpt) $(mobject) -o main 

eobject = $(felement) testimage.cpp polynomial.o
teste: $(eobject)
	$(CompOpt) $(eobject) -o teste

poly.o: $(objects) poly.h poly.cpp
	$(CompOpt) poly.cpp -c -o poly.o

element.o: $(objects) element.cpp
	$(CompOpt) element.cpp -c -o element.o

Int.o: Int.cpp Int.h temps.h
	$(CompOpt) Int.cpp -c -o Int.o

Double.o: Double.cpp Double.h temps.h
	$(CompOpt) Double.cpp -c -o Double.o

Image.o: Image.cpp Image.h temps.h Imaginary.h
	$(CompOpt) Image.cpp -c -o Image.o
	
Imaginary.o: Imaginary.cpp Imaginary.h

polymath.o: polymath.h polymath.cpp
	$(CompOpt) polymath.cpp -c -o polymath.o