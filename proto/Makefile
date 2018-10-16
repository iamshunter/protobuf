libproto.a : ris.pb.o t2.pb.o Makefile
	ar r libproto.a ris.pb.o t2.pb.o
	ranlib libproto.a
	ar t libproto.a

ris.pb.o : ris.proto
	protoc -I=. --cpp_out=. ./ris.proto
	protoc -I=. --go_out=. ./ris.proto
	g++ -std=gnu++11 -I. -c ris.pb.cc
	mv ./ris.pb.go src/ris

t2.pb.o : t2.proto
	protoc -I=. --cpp_out=. ./t2.proto
	protoc -I=. --go_out=. ./t2.proto
	g++ -std=gnu++11 -I. -c t2.pb.cc
	mv ./t2.pb.go src/t2

clean :
	rm -f ris.pb.h t2.pb.h ris.pb.o t2.pb.o ris.pb.cc t2.pb.cc libproto.a src/ris/ris.pb.go src/t2/t2.pb.go 
