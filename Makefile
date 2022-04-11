all:
	g++ -std=c++17 Main.cpp -o Main
	

test:
	chmod +x Main
	

clean:
	$(RM) hello 
