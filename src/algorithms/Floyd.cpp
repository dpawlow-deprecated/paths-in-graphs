//
// Created by Guido Maceira on 17/5/18.
//

//La entrada consistir´a de una primera l´ınea con dos enteros n y m, correspondientes a la
//cantidad de ciudades y a la cantidad de rutas, respectivamente. A continuaci´on, habr´a n
//l´ıneas. Cada l´ınea tendra un entero ci
//, representando el costo del litro de combustible en la
//ciudad i. Luego le suceder´an m l´ıneas con tres enteros, ai
//, bi y li
//. ai y bi
//indicar´a las ciudades
//conectadas por la ruta, mientras que li
//indicar´a la cantidad de litros necesarios para recorrerla.
//Asumiremos que todos los valores en la entrada ser´an enteros positivos.
//La salida consistir´a de n ∗ (n − 1)/2 l´ıneas. Cada linea tendra tres enteros ai
//, bi
//, si
//. ai y bi
//debe indicar las ciudades consideradas, cumpliendose que ai < bi
//. si
//indicar´a el costo m´ınimo
//necesario para ir de una ciudad a otra. Las l´ıneas en la salida deberan estar ordenadas seg´un
//el ord´en lexicogr´afico de las ciudades pertinentes.

void floyd(AMatrixGraph matrix, AListGraph list){

    AMatrixGraph matrix;

    createAdjacencyMatrix(matrix,list);

    for(int k = 0; k < n; ){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }
}

