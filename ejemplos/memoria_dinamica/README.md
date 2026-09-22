# Memoria dinámica en C

Ejemplos independientes sobre reserva, uso, redimensionamiento y liberación de
memoria dinámica. Cada archivo tiene su propio `main` y puede compilarse por
separado con C99.

## Categorías

| Directorio | Tema |
| --- | --- |
| `fundamentos/` | `malloc`, `calloc`, `free`, `sizeof` y validación de reservas. |
| `arreglos/` | Arreglos dinámicos de una y dos dimensiones, crecimiento y reducción. |
| `cadenas/` | Cadenas cuyo almacenamiento se reserva, copia y concatena dinámicamente. |
| `estructuras/` | `struct`, nodos enlazados y matrices almacenadas en memoria dinámica. |
| `robustos/` | Patrones de ownership, overflow de tamaños y cleanup centralizado. |
| `contraejemplos/` | Fugas, uso después de liberar, doble liberación y `realloc` inseguro. |

## Recorrido sugerido

1. `fundamentos/01_malloc_un_elemento.c`
2. `fundamentos/02_arreglo_malloc.c`
3. `fundamentos/03_calloc_inicializa_cero.c`
4. `fundamentos/04_free_y_puntero_nulo.c`
5. `arreglos/01_vector_redimensionable.c`
6. `arreglos/02_realloc_seguro.c`
7. `arreglos/03_matriz_contigua.c`
8. `cadenas/01_copiar_cadena.c`
9. `cadenas/02_concat_str.c`
10. `estructuras/01_struct_dinamico.c`
11. `estructuras/02_lista_enlazada.c`
12. `robustos/01_verificar_overflow.c`
13. `robustos/02_cleanup_contra_error.c`

Los archivos de `contraejemplos/` están destinados a inspección y diagnóstico.
Algunos compilan, pero no deben ejecutarse porque contienen comportamiento
indefinido o fugas intencionales.

## Compilación

```sh
gcc -std=c99 -Wall -Wextra -pedantic fundamentos/01_malloc_un_elemento.c -o /tmp/memoria
```

Para analizar fugas y accesos inválidos, usar una herramienta como Valgrind:

```sh
valgrind --leak-check=full /tmp/memoria
```
