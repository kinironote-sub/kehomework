kehomework: src/main.cpp src/characterrecognizer/featurecalculator.cpp
	g++ -std=c++14 -O2 -Wall src/main.cpp src/characterrecognizer/featurecalculator.cpp -o bin/kehomework
clean:
	rm -f *.o bin/kehomework
