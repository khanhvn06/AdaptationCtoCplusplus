all:
	g++ -std=c++17 Main.cpp -o Main
	g++ -std=c++17 ModelIP.cpp -o ModelIP
	g++ -std=c++17 cplex.cpp -o cplex
	

test:
	chmod +x Main
	

clean:
	$(RM) Main 
