output: main.o System.o  Display.o Process.o
	g++ main.o System.o Display.o Process.o -o FRS.exe
	./FRS.exe

main.o: main.cc
	g++ -c main.cc

System.o: ./src/System.cc
	g++ -c ./src/System.cc

Display.o: ./src/Display.cc
	g++ -c ./src/Display.cc

Process.o: ./src/Process.cc
	g++ -c ./src/Process.cc

# Flight.o: ./src/Flight.cc
# 	g++ -c ./src/Flight.cc
#
# Passenger.o: ./src/Passenger.cc
# 	g++ -c ./src/Passenger.cc

clean : 
	rm -rf FRS.exe ./*.o


