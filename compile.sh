clang++ -c src/funcion.cpp -Iinclude
clang++ -c mainTime.cpp -Iinclude
clang++ -c main.cpp -Iinclude
clang++ -o ejecutable main.o funcion.o
clang++ -o ejecutableTime mainTime.o funcion.o
rm *.o
