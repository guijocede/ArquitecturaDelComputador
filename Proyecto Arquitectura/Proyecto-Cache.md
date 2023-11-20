## Funcionamiento Del programa de Fallos y Asociatividad en la cache

Guillermo Cedeño 30.523.039
Héctor Abreu 30.000.231

---

**Al inicio de nuestro programa se inicializan las variables, las cuales se dividen en:**

- Índices para recorrer ciclos y formateo de memoria.
- Variables auxiliares.
- Variables estructurales, necesarias para el funcionamiento del programa.
- Variables para almacenar datos, como puede ser aquella que simula el almacenamiento en memoria o aquella que posee la secuencia a leer.
---
Para este programa se utilizará un archivo cuyo formato será una secuencia de números separados por un salto de línea y teniendo al final de la secuencia un "-1", siendo este o el inicio de una nueva secuencia o el elemento que precede el final del archivo. Ejemplo:

```C++
0	// Inicio de la primera secuencia
8
0
6
8
-1
0	// Inicio de la segunda secuencia
0
0
0
0
-1
	//Final del archivo (archivo.eof())
```
Ahora sabiendo el formato del archivo se realiza la declaración y apertura estándar de este.
```C++
fstream archivo;
	
	archivo.open("secuencia.txt",ios::in);
    
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
```
Se inicia un ciclo que recorrerá el archivo hasta que no hayan más secuencias, es decir, fin de archivo.

```C++
while(!archivo.eof()){
	...
	}
```

Dentro del ciclo se realizarán las siguiente operaciones:

- Lectura de la secuencia actual.
- Formateo de la memoria previo a la evaluación de cada tipo de cache.

- **Evaluación de la cache de Correspondencia directa:** de forma simple utilizando la formula correspondiente ( Posición = elemento % 4) se comprueba el elemento en la posición en nuestra simulación de memoria, de coincidir los elementos se arroja un acierto, y en caso contrario se arroja un fallo y se reemplaza el elemento antiguo con el actual.

- **Evaluación de la cache Asociativa por conjuntos:** se plantea dividir la memoria en 2 partes, que a su vez tendrán 2 partes cada una. Utilizando auxiliares que determinan la sub posición que fue utilizada hace menos tiempo y a través de la formula que determina a cual de las partes se va a dirigir el elemento ( Posición = elemento % 2) se comparan los valores en las dos sub posiciones con el elemento actual, de encontrarse, se arroja un acierto y la posición con el elemento se vuelve nuestra última posición utilizada. En caso de que no se encuentre el elemento se escribe en la posición utilizada hace más tiempo y se arroja un fallo.

- **Evaluación de la cache Completamente asociativa:** para este caso se utilizan 4 variables que funcionarán como auxiliares que contengan el orden preciso en el que se ha utilizado la memoria, siendo 1 la posición utilizada más recientemente y 4 la posición utilizada menos recientemente. Se compara el elemento actual con los elementos de cada posición, en caso de haber coincidencia se muestra un acierto y se realiza la siguiente comprobación, si la posición fue la menos recientemente utilizada se convierte en la más reciente(auxiliar <-- 1) y el índice de antigüedad de las demás posiciones aumenta en 1, en caso de que haya sido la más recientemente utilizada no se realiza nada especial, y si no se cumple con ninguno de los dos casos la posición se convierte en la más recientemente utilizada y aumenta el índice de antigüedad de las demás posiciones ignorando la más antigua. En caso de que no se encuentre el elemento se muestra un fallo, se escribe el elemento en la posición menos recientemente utilizada y se aumenta el índice de antigüedad de las demás posiciones en 1.

- Cada tipo de cache se verá acompañada de la secuencia que se está evaluando actualmente para diferenciar fácilmente de que secuencia se trata.

Finalmente este ciclo se repetirá hasta llegar al final del archivo(archivo.eof()), es decir, cuando no se encuentren más secuencias, una vez llegado a ese punto se cerrará el archivo y finalizará el programa de forma normal con los datos mostrados siendo mostrados en pantalla.
