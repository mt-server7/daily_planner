all: class_menu

class_menu: main.o class_arr.o class_data_base.o class_menu.o
	g++ main.o class_arr.o class_data_base.o class_menu.o -o class_menu

main.o: main.cpp
	g++ -c main.cpp

class_arr.o: class_arr.cpp
	g++ -c class_arr.cpp

class_data_base.o: class_data_base.cpp
	g++ -c class_data_base.cpp
	
class_menu.o: class_menu.cpp
	g++ -c class_menu.cpp

clean:
	rm -rf *.o class_menu
