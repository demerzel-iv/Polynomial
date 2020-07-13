codes="Imaginary.cpp Int.cpp Double.cpp Image.cpp element.cpp poly.cpp polymath.cpp polyvar.cpp"
heads="Imaginary.h Int.h Double.h Image.h element.h poly.h polymath.h polyvar.h"
hpath=`pwd`

g++ -shared -fPIC $codes -o libpoly.so

cd /usr/lib
if ! [ -d poly ] ; then mkdir poly ;fi
cd /usr/include
if ! [ -d poly ] ; then mkdir poly ;fi

cd $hpath
cp ./libpoly.so  /usr/lib/poly
cp $heads /usr/include/poly

cd /etc
echo "# for poly"
echo "CPLUS_INCLUDE_PATH=\$CPLUS_INCLUDE_PATH:/usr/include/poly" >> profile
echo "export CPLUS_INCLUDE_PATH" >> profile
echo "LD_LIBRARY_PATH=\$LD_LIBRARY_PATH:/usr/lib/poly" >> profile
echo "export LD_LIBRARY_PATH" >> profile
echo "LIBRARY_PATH=\$LIBRARY_PATH:/usr/lib/poly" >> profile
echo "export LIBRARY_PATH" >> profile
echo "" >> profile