cc *bonus.c .main.c -D BUFFER_SIZE=10
./a.out
#valgrind ./a.out | grep All
sleep 1
rm -f a.out
./run.sh