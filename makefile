# Makefile para compilar y ejecutar main.c

# Nombre del ejecutable
TARGET = main

# Compilador
CC = gcc

# Regla por defecto
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): main.c
	$(CC) -o $(TARGET) main.c

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET)

# Regla para ejecutar el programa
run: $(TARGET)
	./$(TARGET)