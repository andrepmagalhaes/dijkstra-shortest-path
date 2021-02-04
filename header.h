typedef struct Adj_Matrix
{

    int vertex_num;
    int **matrix;
    int *distance;

} Adj_Matrix;

Adj_Matrix *adj_matrix = NULL;

//distance = 0 ; parent = 1;
int **results = NULL;