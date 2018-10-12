libproto.a : t1.pb.o t2.pb.o 
	ar r libproto.a t1.pb.o t2.pb.o
	ranlib libproto.a
	ar t libproto.a

t1.pb.o : t1.proto
	protoc -I=. --cpp_out=. ./t1.proto
	g++ -std=gnu++11 -I. -c t1.pb.cc

t2.pb.o : t2.proto
	protoc -I=. --cpp_out=. ./t2.proto
	g++ -std=gnu++11 -I. -c t2.pb.cc

clean :
	rm -f t1.pb.h t2.pb.h t1.pb.o t2.pb.o t1.pb.cc t2.pb.cc libproto.a
