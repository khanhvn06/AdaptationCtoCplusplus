all:
	g++ -std=c++17 Main.cpp cplex.cpp ModelIP.cpp
	g++ -std=c++17 main.exe Main.cpp cplex.cpp ModelIP.cpp
	

test:
	chmod +x Main
	

clean:
	$(RM) Main 
