all: sphere

sphere: main.o sphere.o
	g++ -L/usr/local/lib -o sphere main.o sphere.o -lglut -lCoin -lGL -lXext -lSM -lICE -lX11 -ldl -lpthread

main.o: main.C
	g++ -g -I/usr/local/include/Inventor/annex -lglut -D_REENTRANT -g -O2 -c main.C

sphere.o: sphere.C
	g++ -g -I/usr/local/include/Inventor/annex -lglut -D_REENTRANT -g -O2 -c sphere.C

clean:
	rm -rfv *.o sphere
