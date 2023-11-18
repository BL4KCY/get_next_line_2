cc *utils.c *line.c .main.c -D BUFFER_SIZE=1
./a.out
sleep 1
rm -f a.out
./run.sh