heads="Imaginary.h Int.h Double.h Image.h element.h poly.h polymath.h polyvar.h"
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

if [[ $CPLUS_INCLUDE_PATH == *"/usr/include/poly"* ]] && [[ $LD_LIBRARY_PATH == *"/usr/lib/poly"* ]] && [[ $LIBRARY_PATH == *"/usr/lib/poly"* ]] ; 
then 
    flag=1
else 
    flag=0
fi
if [ $flag == 1 ] ; then 
    echo "# for poly" >> profile
fi 
if [[ $CPLUS_INCLUDE_PATH == *"/usr/include/poly"* ]] ;then 
    echo "CPLUS_INCLUDE_PATH=\$CPLUS_INCLUDE_PATH:/usr/include/poly" >> profile
    echo "export CPLUS_INCLUDE_PATH" >> profile
fi
if [[ $LD_LIBRARY_PATH == *"/usr/lib/poly"* ]] ;then 
    echo "LD_LIBRARY_PATH=\$LD_LIBRARY_PATH:/usr/lib/poly" >> profile
    echo "export LD_LIBRARY_PATH" >> profile
fi
if [[ $LIBRARY_PATH == *"/usr/lib/poly"* ]] ;then 
    echo "LIBRARY_PATH=\$LIBRARY_PATH:/usr/lib/poly" >> profile
    echo "export LIBRARY_PATH" >> profile
fi
if [ $flag == 1 ] ; then 
    echo "" >> profile
fi 