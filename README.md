# Práctica 2: Creación de un Árbol de Procesos en C

Este proyecto consiste en un programa en C que crea un árbol de procesos similar al mostrado en la imagen [aquí](http://avellano.fis.usal.es/~ssooi/domino1.gif). El programa utiliza la función `fork()` para crear múltiples procesos hijos y organiza estos procesos en una jerarquía específica.

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

## Compilación y Ejecución

El proyecto incluye un `Makefile` para facilitar la compilación y ejecución del programa. Sigue estos pasos:

1. Abre una terminal y navega al directorio del proyecto.
2. Compila el programa usando el comando:

    ```sh
    make
    ```

3. Ejecuta el programa con el comando:

    ```sh
    make run
    ```

## Descripción del Código

El archivo `main.c` contiene el código fuente del programa. La función principal `crea_jerarquia()` utiliza múltiples llamadas a `fork()` para crear un árbol de procesos. Cada proceso imprime su ID de proceso (PID) y luego espera durante 40 segundos antes de finalizar.

El `Makefile` proporciona reglas para compilar (`make`), limpiar (`make clean`) y ejecutar (`make run`) el programa.

## Visualización del Árbol de Procesos

Dado que el binario `Arbol_dominiO` no es compatible con Unix, utilizamos `pstree` para visualizar el árbol de procesos generado por el programa. Al ejecutar el programa, se mostrará el árbol de procesos en la terminal.

## Archivos del Proyecto

- `main.c`: Código fuente del programa en C.
- `Makefile`: Archivo para compilar y ejecutar el programa.
- `readme.md`: Este archivo de documentación.

¡Disfruta explorando la creación de árboles de procesos en Unix!
