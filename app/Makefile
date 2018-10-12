t.x : main.o t.o Makefile
	g++ -std=gnu++11 -pthread -o t.x main.o t.o -L../proto -L/usr/local/lib -lprotobuf -lproto 

main.o : main.cpp Makefile
	g++ -std=gnu++11 -I../proto -c main.cpp 

t.o : t.cpp Makefile
	g++ -std=gnu++11 -I../proto -c t.cpp 

clean :
	rm -f t.x t.o main.o
