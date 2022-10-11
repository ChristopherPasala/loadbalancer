all: main


main: request.o Webserver.h LoadBalancer.h 
	g++ request.o main.cpp -o main

request.o: Request.h
	g++ -c Request.cpp

clean:
	rm -f *.o main