make:
	@echo "Compiling libraries"
	@clang++ -c src/*.cpp -Iinclude
	@echo "Compiling main"
	@clang++ -c main.cpp -Iinclude
	@echo "Compiling executable"
	@clang++ -o exec *.o

clean:
	@echo "Cleaning"
	@rm *.o
	@rm exec
