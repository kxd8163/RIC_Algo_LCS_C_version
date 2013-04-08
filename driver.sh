CC=g++
CFLAGS=-c 
PGFLAGS=-pg
OFLAGS=-o

GPROF=gprof

#echo "Usage: function-name stringlen1 stringlen2"
echo "enter function to use [naive|dp|memo]: [RETURN] "
read func_name
echo "enter string length1: [RETURN]"
read stringlen1
echo "enter string length2: [RETURN]"
read stringlen2


$CC $CFLAGS run.cpp naive.cpp dp.cpp linspace.cpp $PGFLAGS
$CC $OFLAGS run run.o naive.o dp.o linspace.o $PGFLAGS

./run $func_name $stringlen1 $stringlen2
echo "running gprof..."

#if [ -f gprof.out ]
#then
#    rm gprof.out
#fi

$GPROF -e naive -f run > gprof.out 
