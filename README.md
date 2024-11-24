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

4. Mata los procesos enviando la señal `SIGTERM` al proceso principal. Esto desencadenará una cascada de señales `SIGTERM` que resultará en la finalización de todos los procesos hijos. Para hacerlo, sigue estos pasos:

    - Encuentra el PID del proceso principal. Puedes usar el comando `ps` o `pstree` para encontrarlo. Por ejemplo:
    
        ```sh
        ps -ef | grep main
        ```

    - Envía la señal `SIGTERM` al proceso principal usando el comando `kill`:

        ```sh
        kill -SIGTERM <PID_DEL_PROCESO_PRINCIPAL>
        ```

    Reemplaza `<PID_DEL_PROCESO_PRINCIPAL>` con el PID del proceso principal que encontraste en el paso anterior.

## Descripción del Código

El archivo [main.c](http://_vscodecontentref_/1) contiene el código fuente del programa. La función [main](http://_vscodecontentref_/2) se encarga de configurar el manejador de señales, crear la jerarquía de procesos y esperar a que se reciba una señal `SIGTERM`. Cuando se recibe la señal `SIGTERM`, el manejador de señales envía la señal `SIGTERM` a todos los procesos hijos, lo que resulta en la finalización de todos los procesos en cascada.

El archivo [Makefile](http://_vscodecontentref_/3) incluye las reglas para compilar y ejecutar el programa, así como para limpiar los archivos generados durante la compilación.

## Funciones Principales

- `configurar_manejador()`: Configura el manejador de señales para la señal `SIGTERM`.
- `manejador(int sig)`: Manejador de señales que envía la señal `SIGTERM` a todos los procesos hijos y espera a que terminen.
- `escribir_pid(pid_t pid, int index)`: Escribe el PID del proceso en un archivo en la posición especificada.
- `leer_pid(int index)`: Lee el PID del archivo en la posición especificada.
- `crea_jerarquia()`: Crea la jerarquía de procesos.

## Archivos

- [main.c](http://_vscodecontentref_/4): Contiene el código fuente del programa.
- [Makefile](http://_vscodecontentref_/5): Contiene las reglas para compilar y ejecutar el programa.
- `pids.txt`: Archivo utilizado para almacenar los PIDs de los procesos.

## Limpieza

El archivo de PIDs (`pids.txt`) se elimina automáticamente al finalizar el programa para limpiar los recursos utilizados.

## Visualización del Árbol de Procesos

Dado que el binario `Arbol_dominiO` no es compatible con Unix, utilizamos `pstree` para visualizar el árbol de procesos generado por el programa. Al ejecutar el programa, se mostrará el árbol de procesos en la terminal.

## Archivos del Proyecto

- `main.c`: Código fuente del programa en C.
- `Makefile`: Archivo para compilar y ejecutar el programa.
- `readme.md`: Este archivo de documentación.

¡Disfruta explorando la creación de árboles de procesos en Unix!
