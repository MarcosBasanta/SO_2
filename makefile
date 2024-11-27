# Makefile para compilar y ejecutar main.c

# Nombre del ejecutable
TARGET = opcion1

# Compilador
CC = gcc


# Regla para compilar el ejecutable
opcion1: opcion1.o
	$(CC) opcion1.o -o dom

opcion1.o: opcion1.c
	$(CC) -c opcion1.c

opcion2: opcion2.o
	$(CC) opcion2.o -o dom

opcion2.o: opcion2.c
	$(CC) -c opcion2.c

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET)

# Regla para ejecutar el programa
run: $(TARGET)
	./$(TARGET)