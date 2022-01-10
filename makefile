progam: main.cpp cell.cpp board.cpp modeButton.cpp interface.cpp text.cpp
	g++ -std=c++17 main.cpp cell.cpp board.cpp modeButton.cpp interface.cpp text.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 
run: main
	./main

del: program
	rm main
