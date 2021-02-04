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

#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "functions.c"

int main()
{

    adj_matrix = (Adj_Matrix*) malloc(sizeof(Adj_Matrix));
    adj_matrix->vertex_num = 0;
    adj_matrix->distance = NULL;

    int option = 0;
    int src, dest;

    // for(int i = 0 ; i < 20 ; i++)
    // {
    //     new_node();
    //     print_adj_matrix();
    //     printf("\n=======================================\n");
        
        
    // }

    



    do
    {
        
        menu();
        scanf("%i", &option);

        switch (option)
        {
        case 1:
            {
                new_node();
            }
            break;
        
        case 2:
            {
                set_weight();
            }
            break;
        
        case 3:
            {  
                system("cls");
                printf("Digite o nodo de inicio: ");
                scanf("%i", &src);
                dijkstra(adj_matrix->vertex_num, adj_matrix->matrix, src);
            }
            break;

        case 4:
            {
                system("cls");
                printf("Digite o nodo de destino: ");
                scanf("%i", &dest);
                system("cls");
                print_results(src, dest);
                printf("\n\n");
                system("pause");
            }
            break;

        case 5:
            {

            }
            break;

        default:
            break;
        }

    } while (option != 5);
    

    return 0;
}
