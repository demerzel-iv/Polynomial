CompOpt = g++ -O2 -std=c++11
objects = Imaginary.o Int.o Double.o Image.o element.o poly.o polymath.o polyvar.o

codes = Imaginary.cpp Int.cpp Double.cpp Image.cpp element.cpp poly.cpp polymath.cpp polyvar.cpp

main : $(objects) main.cpp 
	$(CompOpt) $(objects) main.cpp -o main 

lib: $(codes)
	g++ -shared -fPIC $(codes) -o libpoly.so 
staticlib: $(objects)
	ar -crv libpoly.a $(objects)

Int.o: Int.cpp Int.h temps.h
	$(CompOpt) $< -o $@ -c
Double.o: Double.cpp Double.h temps.h
	$(CompOpt) $< -o $@ -c
Image.o: Image.cpp Image.h temps.h Imaginary.h
	$(CompOpt) $< -o $@ -c
element.o: element.cpp element.h Int.h Double.h Image.h Imaginary.h
	$(CompOpt) $< -o $@ -c
Imaginary.o: Imaginary.cpp Imaginary.h
	$(CompOpt) $< -o $@ -c
polymath.o: polymath.cpp polymath.h poly.h
	$(CompOpt) $< -o $@ -c
poly.o: poly.cpp  poly.h element.h
	$(CompOpt) $< -o $@ -c
polyvar.o: polyvar.cpp polyvar.h poly.h
	$(CompOpt) $< -o $@ -c

clean: 
	rm $(objects)