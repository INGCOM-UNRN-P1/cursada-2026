# Punteros

Ejemplos independientes para trabajar punteros en C sin memoria dinámica.
Cada archivo contiene un `main` y puede compilarse por separado.

## Categorías

| Directorio | Tema |
| --- | --- |
| `basicos/` | Declaración, dirección, indirección, `NULL` y puntero a puntero. |
| `arreglos/` | Relación entre arreglos y punteros, aritmética y cadenas. |
| `funciones/` | Parámetros por dirección, resultados múltiples y punteros a funciones. |
| `efectos_secundarios/` | Modificaciones observables sobre variables recibidas mediante punteros. |
| `const/` | Qué puede modificarse según la posición de `const`. |
| `salvajes/` | Punteros sin destino válido: no inicializados, direcciones inventadas o fuera de rango. |
| `colgantes/` | Punteros cuyo objeto dejó de existir, más una alternativa segura con `static`. |

## Recorrido sugerido

1. `basicos/01_direccion_e_indireccion.c`
2. `basicos/02_puntero_nulo_seguro.c`
3. `arreglos/01_arreglo_y_puntero.c`
4. `arreglos/02_aritmetica_dentro_del_arreglo.c`
5. `funciones/01_parametro_por_direccion.c`
6. `efectos_secundarios/01_modificar_argumento.c`
7. `efectos_secundarios/02_aliasing.c`
8. `const/01_combinaciones_const.c`
9. `basicos/03_puntero_a_puntero.c`
10. `funciones/02_resultados_multiples.c`
11. `funciones/03_puntero_a_funcion.c`

Casos de frontera:

- `arreglos/05_uno_pasado_no_se_desreferencia.c` muestra el límite `one-past`.
- `salvajes/03_aritmetica_fuera_de_objeto.c` muestra el error asociado.
- `salvajes/04_modificar_literal.c` contrasta con `arreglos/03_cadena_con_puntero_const.c`.
- `colgantes/04_alternativa_segura_estatica.c` muestra una solución sin memoria dinámica.

Los archivos de `salvajes/` y `colgantes/` son contraejemplos. Compilan
intencionalmente, pero no deben ejecutarse: contienen comportamiento indefinido.
Sirven para leer, diagnosticar y corregir.

## Compilación

```sh
gcc -std=c99 -Wall -Wextra -pedantic basicos/01_direccion_e_indireccion.c -o /tmp/punteros
```

Para detectar varios errores antes de ejecutar:

```sh
gcc -std=c99 -Wall -Wextra -pedantic -fanalyzer archivo.c -o /tmp/punteros
```
