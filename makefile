# Makefile para compilar y ejecutar main.c

# Nombre del ejecutable
TARGET = main

# Compilador
CC = gcc


# Regla para compilar el ejecutable
main: main.o
	$(CC) main.o -o main

main.o: main.c
	$(CC) -c main.c

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET)

# Regla para ejecutar el programa
run: $(TARGET)
	./$(TARGET)