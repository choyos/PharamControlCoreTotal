/*  Trabajo fin de curso de programación 2010*/
/*Apellidos: Hoyos Martín
Nombre: César
Login: ceshoymar */

/*Declaración de funciones de tratamiento de la información recibida*/

#ifndef HORA_H
#define HORA_H

#include "typedef.h"

//Crea un nuevo tipo laboratorio con la informacion que se necesita
LABORATORY * CreaNodoLab(char * fileName);

//Crea un nodo de tipo medicina, con la información leida de la trama.
MEDICINE * CreaNodoMed ( int stock, float precio_med, float precio_alm, float coste_pedido, float coste_recogida, float coste_sin_stock, float coste_oportunidad, int* repartidos, int maxStock, int minStock, int nTamPedidos, int* vTamPedidos, int horizonte);

//Crea la lista de laboratorios enlazando los nodos
void EnlazaLabs (LABORATORY * laboratorioNuevo, LABORATORY ** laboratorioPrimero);

//Crea la lista de medicinas enlazando los medicamentos.
void EnlazaMedicinas (MEDICINE * medicinaNueva, MEDICINE ** medicinaPrimera);	

//Borra los nodos de los laboratorios, usa la funcion BorraMedicinas
void BorraLabs(LABORATORY ** laboratorioPrimero);

//Borra la lista completa de medicinas liberando la memoria.
void BorraMedicinas (MEDICINE ** medicinaPrimera); 

//Imprime todos los datos de todos los medicamentos leidos
void ImprimeMedicinas (MEDICINE * pAnterior, int horizonte, int numPedidos);

//Realiza el calculo de la matriz de combinaciones de las diferentes medicinas y las añade a la estructura
void MatrizCombMedicinas (MEDICINE ** medicinaPrimera, int numPedidos);

//Realiza el calculo de coste total
float EvaluaMedicinas(MEDICINE ** medicinaPrimera, int horizonte, int numPedidos, int * posibilidad, int ** matPedidosOptimos, int ** matStockOptimo, float * Jmin);

//Función para almacenar las variables optimas ligadas a los medicamentos
void AlmacenaOptimos(MEDICINE ** medicinaPrimera, int horizonte, int ** matPedidosOptimos, int ** matStockOptimo, float * Jmin);

//Funcion que imprime los resultados de ejecución del programa. Hace uso de ImprimeResultadosMeds
void ImprimeResultados(LABORATORY ** laboratorioPrimero, int horizonte);

//Funcion para imprimir de forma presentable los resultados de los medicamentos
void ImprimeResultadosMeds(MEDICINE ** medicinaPrimera, int horizonte, float Jtotal);

//Función que borra un medicamento
void BorraMedicina(MEDICINE * medicina);

#endif