t.x : main.o t.o Makefile
	g++ -std=gnu++11 -pthread -o t.x main.o t.o -L../proto -L/usr/local/lib -L/usb/SVN/5G-ATW/software/arp/bin -lprotobuf -lproto -lsocket -lz

main.o : main.cpp Makefile
	g++ -std=gnu++11 -I../proto -I/usb/SVN/5G-ATW/software/arp/libs/src/socket -c main.cpp 

t.o : t.cpp Makefile
	g++ -std=gnu++11 -I../proto -c t.cpp 

clean :
	rm -f t.x t.o main.o
