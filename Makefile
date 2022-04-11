all:
	g++ -std=c++17 Main.cpp -o Main cplex.cpp ModelIP.cpp
	
	

test:
	chmod +x Main
	

clean:
	$(RM) Main 
