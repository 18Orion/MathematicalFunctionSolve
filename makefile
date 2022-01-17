make:
	@echo "Compilando librerias"
	clang++ -c src/*.cpp -Iinclude
	@echo "Compilando main"
	clang++ -c main.cpp -Iinclude

clean:
	rm *.o
	rm exec