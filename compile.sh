clang++ -c src/funcion.cpp -Iinclude
clang++ -c mainTime.cpp -Iinclude
clang++ -o ejecutable mainTime.o funcion.o
rm *.o
