// CURSO DE ENGENHARIA DE COMPUTAÇÂO
// DISCIPLINA DE LABORATÓRIO DE PROGRAMAÇÃO II
// Prova 4
// Data de Entrega 03/12/20 até as 23:55 (via Moodle)
// Implemente em C o algoritmo de Dijkstra para a busca do caminho mínimo de origem única
// em grafos ponderados. O programa deverá imprimir na tela os caminhos mínimos do nodo
// de origem para os demais nodos.
// Deverá ser implementado um menu contendo a inserção de arestas, a impressão do grafo, a
// geração do caminho mínimo e a impressão do caminho mínimo.
// Sobre o formato da entrega:
// Os trabalhos são individuais e os arquivos .c e .h devem ser enviados via Moodle até as
// 23:55 do dia da entrega.

// #define INF INT_MAX
#define INF INT_MAX

void print_adj_matrix()
{

    if(adj_matrix->vertex_num == 0)
    {
        printf("A matriz de adjacencia esta vazia!");
    }
    else
    {
        printf("   ");
        for(int i = 0 ; i < adj_matrix->vertex_num ; i++)
        {
            printf(" %i ", i);
        }
        printf("\n\n");
        for(int i = 0 ; i < adj_matrix->vertex_num ; i++)
        {
            printf("%i  ", i);
            for(int j = 0 ; j < adj_matrix->vertex_num ; j++)
            {
                
                printf(" %i ", adj_matrix->matrix[i][j]);
            }
        printf("\n");
        }
    }
}

void menu()
{
    system("cls");

    print_adj_matrix();
    printf("\n");
    printf("==================================\n");
    printf("1 - Inserir Aresta\n");
    printf("2 - Modificar Peso\n");
    printf("3 - Gerar Caminho Minimo\n");
    printf("4 - Imprimir Caminho Minimo\n");
    printf("5 - Sair\n");
    printf("==================================\n");
}


//[linha][coluna]
void handle_dynamic_matrix()
{
    if(adj_matrix->vertex_num == 0)
    {
        adj_matrix->vertex_num++;
        adj_matrix->matrix = (int**) malloc(sizeof(int*)*adj_matrix->vertex_num);
        adj_matrix->matrix[0] = (int*)malloc(sizeof(int));

    }
    else
    {
        adj_matrix = (Adj_Matrix*) realloc(adj_matrix, sizeof(adj_matrix) + sizeof(adj_matrix->vertex_num * sizeof(int*)));
        adj_matrix->vertex_num++;
        adj_matrix->matrix = (int**) realloc(adj_matrix->matrix, adj_matrix->vertex_num * sizeof(int*));
        printf("vertex_num: %i\n", adj_matrix->vertex_num);
        for(int i = 0 ; i < adj_matrix->vertex_num -1 ; i++)
        {
            adj_matrix->matrix[i] = (int*) realloc(adj_matrix->matrix[i], adj_matrix->vertex_num * sizeof(int));
            // printf("\n asdfasdf: %i \n", i);
        }
        
        adj_matrix->matrix[adj_matrix->vertex_num - 1] = (int*)malloc(adj_matrix->vertex_num * sizeof(int));

        // adj_matrix->matrix[adj_matrix->vertex_num - 1] = (int*) malloc(sizeof(int) * adj_matrix->vertex_num);
    }
    
}

void new_node()
{
    handle_dynamic_matrix();
    if(adj_matrix->vertex_num == 1)
    {
        adj_matrix->matrix[0][0] = 0;
    }
    else
    {
        for(int i = 0 ; i < adj_matrix->vertex_num ; i++)
        {   
            adj_matrix->matrix[adj_matrix->vertex_num -1 ][i] = 0;
            adj_matrix->matrix[i][adj_matrix->vertex_num -1 ] = 0;
            
        }
    }
    
}

void set_weight()
{
    int line, column, weight;

    do
    {
        system("cls");
        print_adj_matrix();
        printf("\n");
        printf("Entre a linha, coluna e peso da posicao que se deseja alterar (L C P) (-1 -1 -1 para sair): \n");
        scanf("%i %i %i", &line, &column, &weight);
        
        if(line == -1 && column == -1 && weight == -1)
        {
            break;
        }
        else if((line == column))
        {
            printf("\nA distancia de um nodo para si mesmo deve ser sempre 0!\n");
            system("pause");
        }
        else
        {
            
            adj_matrix->matrix[line][column] = weight;
        
        }
    }while(line != -1 && column != -1 && weight != -1);
    
    
}

int min_dist(int vertex_num, int *visited)
{
    int min_dist = INF;
    int min_node = 0;

    // printf("\n");
    // for(int i = 0 ; i < vertex_num ; i++)
    // {
    //     printf(" %i ", visited[i]);
    // }
    // printf("\n\n");
    // system("pause");

    for(int i = 0 ; i < vertex_num ; i++)
    {
        if(visited[i] == 0 && results[0][i] < min_dist)
        {
            min_dist = results[0][i];
            min_node = i;
        }
    }

    return min_node;
}

void dijkstra(int vertx_num, int **matrix, int source)
{
    int dijk_matrix[vertx_num][vertx_num];
    int *visited = (int*) malloc(sizeof(int) * vertx_num);
    int min_distance_node;

    if(results == NULL)
    {
        results = (int**) malloc(sizeof(int*) * 2);
        results[0] = (int*) malloc(sizeof(int) * vertx_num);
        results[1] = (int*) malloc(sizeof(int) * vertx_num);

    }
    else
    {
        free(results[0]);
        free(results[1]);
        free(results);

        results = (int**) malloc(sizeof(int*) * 2);
        results[0] = (int*) malloc(sizeof(int) * vertx_num);
        results[1] = (int*) malloc(sizeof(int) * vertx_num);
    }

    for(int i = 0 ; i < vertx_num ; i++)
    {
        for(int j = 0 ; j < vertx_num ; j++)
        {
            if(i == j)
            {
                dijk_matrix[i][j] = 0;
            }
            else if(matrix[i][j] == 0)
            {
                dijk_matrix[i][j] = INF;
            }
            else
            {
                dijk_matrix[i][j] = matrix[i][j];
            }
        }
    }

    // printf("\n\n");
    // for(int i = 0 ; i < vertx_num ; i ++)
    // {
    //     for(int j = 0 ; j < vertx_num ; j++)
    //     {
    //         printf(" %i ", dijk_matrix[i][j]);
    //     }
    //     printf("\n");
    // }

    // printf("\n\n");
    // system("pause");

    for(int i = 0; i < vertx_num ; i++)
    {
        results[0][i] = INF;
        visited[i] = 0;
        results[1][i] = i;
    }

    results[0][source] = 0;

    for(int i = 0 ; i < vertx_num ; i++)
    {
        min_distance_node = min_dist(vertx_num, visited);
        // printf("min dist node: %i\n", min_distance_node);
        // system("pause");
        visited[min_distance_node] = 1;

        for(int adj = 0 ; adj < vertx_num ; adj++)
        {
            if(dijk_matrix[min_distance_node][adj] != INF && results[0][adj] > (results[0][min_distance_node] + dijk_matrix[min_distance_node][adj]))
            {
                // printf("entrou\n");
                // system("pause");
                results[0][adj] = results[0][min_distance_node] + dijk_matrix[min_distance_node][adj];
                results[1][adj] = min_distance_node;
            }
        }
    }

}

void print_results(int source, int dest)
{
    int parnode = results[1][dest];
    system("cls");
    printf("Nodo Inicio: %i\n", source);
    printf("Nodo Destino: %i\n", dest);
    printf("Custo: %i\n", results[0][dest]);
    printf("Caminho: ");
    printf("%i ", dest);
    while(parnode != source)
    {
        printf("<- %i ", parnode);
        parnode = results[1][parnode];
    }
    printf("<- %i", source);
    
    // printf("Nodo: \t\t\tCusto: \t\t\tCaminho\n\n");

    // printf("%i\t\t\t%i\t\t\t ", dest, results[0][dest]);
    // printf("%i ", dest);
    // while(parnode != source)
    //     {
    //         printf("<- %i ", parnode);
    //         parnode = results[1][parnode];
    //     }
    // printf("\n");

    // for(int i = 0 ; i < adj_matrix->vertex_num ; i++)
    // {
    //     printf("%i\t\t\t%i\t\t\t ",i, results[0][i]);
    //     printf("%i ", i);
    //     parnode = results[1][i];
    //     while(parnode != source)
    //     {
    //         printf("<- %i ", parnode);
    //         parnode = results[1][parnode];
    //     }
    //     printf("\n");
    // }
}
