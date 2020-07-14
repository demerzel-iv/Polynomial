heads="Imaginary.h Int.h Double.h Image.h element.h poly.h polymath.h polyvar.h polynomial.h"
hpath=`pwd`

make lib
make staticlib

cd /usr/lib
if ! [ -d poly ] ; then mkdir poly ;fi
cd /usr/include
if ! [ -d poly ] ; then mkdir poly ;fi

cd $hpath
cp ./libpoly.so ./libpoly.a /usr/lib/poly
cp $heads /usr/include/poly

cd /etc

if [[ `cat profile` == *"/usr/include/poly"* ]] ; then flag0=1 ; else flag0=0 ; fi
if [[ `cat profile` == *"/usr/lib/poly"* ]]     ; then flag1=1 ; else flag1=0 ; fi
if [[ `cat profile` == *"/usr/lib/poly"* ]]     ; then flag2=1 ; else flag2=0 ; fi
 
if [ $flag0 == 0 ] || [ $flag1 == 0 ] || [ $flag2 == 0 ]; then 
    echo "# for poly" >> profile
fi 
if [ $flag0 == 0 ] ;then 
    echo "CPLUS_INCLUDE_PATH=\$CPLUS_INCLUDE_PATH:/usr/include/poly" >> profile
    echo "export CPLUS_INCLUDE_PATH" >> profile
fi
if [ $flag1 == 0 ] ;then 
    echo "LD_LIBRARY_PATH=\$LD_LIBRARY_PATH:/usr/lib/poly" >> profile
    echo "export LD_LIBRARY_PATH" >> profile
fi
if [ $flag2 == 0 ] ;then 
    echo "LIBRARY_PATH=\$LIBRARY_PATH:/usr/lib/poly" >> profile
    echo "export LIBRARY_PATH" >> profile
fi
if [ $flag0 == 0 ] || [ $flag1 == 0 ] || [ $flag2 == 0 ]; then 
    echo "" >> profile
fi 
