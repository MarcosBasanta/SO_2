# Proyecto de Gestión de Procesos

Este proyecto contiene dos programas en C (`opcion1.c` y `opcion2.c`) que gestionan la creación y eliminación de procesos en un árbol de procesos. Ambos programas utilizan señales para coordinar la finalización de los procesos, pero difieren en el orden en que los procesos se eliminan.

## Requisitos

- Sistema operativo Unix.
- Compilador `gcc`.
- Herramienta `pstree` para visualizar el árbol de procesos.

## Instalación de `pstree`

Para instalar `pstree`, puedes usar el siguiente comando en sistemas basados en Debian/Ubuntu:

```sh
sudo apt-get install psmisc
```

En sistemas basados en Red Hat/Fedora, usa:

```sh
sudo yum install psmisc
```

## Ejecución de los Programas

### Opción 1: `opcion1.c`

En `opcion1.c`, los procesos se eliminan del final al inicio. El primer proceso es el que espera a que todos los demás procesos terminen.

1. Compila el programa:
    ```sh
    gcc -o opcion1 opcion1.c
    ```

2. Ejecuta el programa:
    ```sh
    ./opcion1
    ```

3. Mata los procesos enviando la señal `SIGTERM` al proceso principal. Esto desencadenará una cascada de señales `SIGTERM` que resultará en la finalización de todos los procesos hijos. Para hacerlo, sigue estos pasos:

    - Encuentra el PID del proceso principal. Puedes usar el comando `ps` o `pstree` para encontrarlo. Por ejemplo:
    
        ```sh
        ps -ef | grep opcion1
        ```

    - Envía la señal `SIGTERM` al proceso principal usando el comando `kill`:

        ```sh
        kill -SIGTERM <PID_DEL_PROCESO_PRINCIPAL>
        ```

    Reemplaza `<PID_DEL_PROCESO_PRINCIPAL>` con el PID del proceso principal que encontraste en el paso anterior.

### Opción 2: [opcion2.c](http://_vscodecontentref_/3)

En [opcion2.c](http://_vscodecontentref_/4), los procesos se eliminan del inicio al final en escalera. El último proceso del árbol es el que espera a que todos los demás procesos terminen.

1. Compila el programa:
    ```sh
    gcc -o opcion2 opcion2.c
    ```

2. Ejecuta el programa:
    ```sh
    ./opcion2
    ```

3. Mata los procesos enviando la señal `SIGTERM` al proceso principal. Esto desencadenará una cascada de señales `SIGTERM` que resultará en la finalización de todos los procesos hijos. Para hacerlo, sigue estos pasos:

    - Encuentra el PID del proceso principal. Puedes usar el comando `ps` o `pstree` para encontrarlo. Por ejemplo:
    
        ```sh
        ps -ef | grep opcion2
        ```

    - Envía la señal `SIGTERM` al proceso principal usando el comando `kill`:

        ```sh
        kill -SIGTERM <PID_DEL_PROCESO_PRINCIPAL>
        ```

    Reemplaza `<PID_DEL_PROCESO_PRINCIPAL>` con el PID del proceso principal que encontraste en el paso anterior.

## Descripción del Código

### [opcion1.c](http://_vscodecontentref_/5)

El archivo [opcion1.c](http://_vscodecontentref_/6) contiene el código fuente del programa que elimina los procesos del final al inicio. El primer proceso es el que espera a que todos los demás procesos terminen.

### [opcion2.c](http://_vscodecontentref_/7)

El archivo [opcion2.c](http://_vscodecontentref_/8) contiene el código fuente del programa que elimina los procesos del inicio al final en escalera. El último proceso del árbol es el que espera a que todos los demás procesos terminen.

## Funciones Principales

- `configurar_manejador()`: Configura el manejador de señales para la señal `SIGTERM`.
- `manejador(int sig)`: Manejador de señales que envía la señal `SIGTERM` a todos los procesos hijos y espera a que terminen.
- `escribir_pid(pid_t pid, int index)`: Escribe el PID del proceso en un archivo en la posición especificada.
- `leer_pid(int index)`: Lee el PID del archivo en la posición especificada.
- `crea_jerarquia()`: Crea la jerarquía de procesos.

## Archivos

- [opcion1.c](http://_vscodecontentref_/9): Contiene el código fuente del programa que elimina los procesos del final al inicio.
- [opcion2.c](http://_vscodecontentref_/10): Contiene el código fuente del programa que elimina los procesos del inicio al final en escalera.
- [Makefile](http://_vscodecontentref_/11): Contiene las reglas para compilar y ejecutar los programas.
- `pids.txt`: Archivo utilizado para almacenar los PIDs de los procesos.

## Limpieza

El archivo de PIDs (`pids.txt`) se elimina automáticamente al finalizar el programa para limpiar los recursos utilizados.

## Visualización del Árbol de Procesos

Dado que el binario `Arbol_dominiO` no es compatible con Unix, utilizamos `pstree` para visualizar el árbol de procesos generado por el programa. Al ejecutar el programa, se mostrará el árbol de procesos en la terminal.

```sh
ps -f | grep "dom$" | grep -v grep | sort | Arbol_dominO
```

## Archivos del Proyecto

- `opcion1.c`: Código fuente del programa en C.
- `opcion2.c`: Código fuente del programa en C.
- `Makefile`: Archivo para compilar y ejecutar el programa.
- `readme.md`: Este archivo de documentación.

¡Disfruta explorando la creación de árboles de procesos en Unix!
