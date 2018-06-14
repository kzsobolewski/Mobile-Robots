#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++14

TRGDIR=/tmp/robot_scena

__start__: ./robot_scena
	./robot_scena

./robot_scena: obj obj/main.o obj/ObiektGraficzny.o\
           		 obj/lacze_do_gnuplota.o obj/API.o obj/Robot.o obj/Sciezka.o\
					 	 	 obj/Scena.o obj/Przeszkoda.o  obj/Fabryka.o
	g++ -Wall -pedantic -std=c++14 -o ./robot_scena obj/main.o\
                        obj/lacze_do_gnuplota.o obj/ObiektGraficzny.o\
												obj/API.o obj/Robot.o obj/Sciezka.o obj/Scena.o\
												obj/Przeszkoda.o obj/Fabryka.o


obj:
	mkdir -p obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/Scena.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/API.o: src/API.cpp inc/lacze_do_gnuplota.hh inc/Wektor2D.hh  inc/SWektor.hh
	g++ -c ${CXXFLAGS} -o obj/API.o src/API.cpp

obj/ObiektGraficzny.o: src/ObiektGraficzny.cpp inc/ObiektGraficzny.hh\
                       inc/Wektor2D.hh  inc/SWektor.hh
	g++ -c ${CXXFLAGS} -o obj/ObiektGraficzny.o src/ObiektGraficzny.cpp

obj/Robot.o: src/Robot.cpp inc/Robot.hh\
	                     inc/Wektor2D.hh  inc/SWektor.hh inc/ObiektGraficzny.hh
	g++ -c ${CXXFLAGS} -o obj/Robot.o src/Robot.cpp

obj/Sciezka.o: src/Sciezka.cpp inc/Sciezka.hh\
	                     inc/Wektor2D.hh  inc/SWektor.hh inc/ObiektGraficzny.hh
	g++ -c ${CXXFLAGS} -o obj/Sciezka.o src/Sciezka.cpp

obj/Przeszkoda.o: src/Przeszkoda.cpp inc/Przeszkoda.hh\
	                     inc/Wektor2D.hh  inc/SWektor.hh inc/ObiektGraficzny.hh
	g++ -c ${CXXFLAGS} -o obj/Przeszkoda.o src/Przeszkoda.cpp

obj/Scena.o: src/Scena.cpp inc/Scena.hh \
	                     inc/Wektor2D.hh  inc/SWektor.hh inc/ObiektGraficzny.hh
	g++ -c ${CXXFLAGS} -o obj/Scena.o src/Scena.cpp

obj/Fabryka.o: src/Fabryka.cpp inc/Fabryka.hh
	g++ -c ${CXXFLAGS} -o obj/Fabryka.o src/Fabryka.cpp




clear:
	rm -f obj/*.o ./robot_scena
