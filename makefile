CompOpt = g++ -O2 -std=c++11
objects = Imaginary.o Int.o Double.o Image.o element.o poly.o polymath.o 

main : $(objects) main.cpp 
	$(CompOpt) $(objects) main.cpp -o main 

elementHeadiles =  element.h Int.h Double.h Image.h Imaginary.h

Int.o: Int.h temps.h
Double.o: Double.h temps.h
Image.o: Image.h temps.h Imaginary.h
element.o: element.h Int.h Double.h Image.h Imaginary.h
Imaginary.o: Imaginary.h
polymath.o: polymath.h 
poly.o:  poly.h element.h

clean:
	rm $(objects)