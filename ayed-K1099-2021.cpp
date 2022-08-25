// ayed-K1099-2021.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//dogor

#include <iostream>
using namespace std;

//Cargar nodos en una pila
//1. definir el nodo
struct Nodo {
	int info;
	Nodo *sgte;
	}; // crear el nodo con los dos campos
	
	
	int main(){
		//crear la estructura
		Nodo *Pila = NULL; //declarar el puntero que apuntara al inicio de la estructura. 
						   //Se debe inicializar con NULL


     
		


	return 0;
}
	//Agregar un nodo al final de una lista enlazada
	void agregarNodo(Nodo *&p, int x)
	{
		Nodo *nuevo = new Nodo();
		nuevo->info = x;
		nuevo->sgte = NULL;
		if (p == NULL) {
			p = nuevo;
			}
		else{
			Nodo * aux = p;
			while (aux->sgte != NULL) {
			aux = aux->sgte;
		  }
		  aux->sgte = nuevo;
		}
	}
	//Mostrar el contenido de una lista enlazada
	void mostrar(Nodo *p)
	{
		Nodo *aux = p;
		while (aux != NULL) {
			cout << aux->info << endl;
			aux = aux->sgte;
		}
	}

	void liberar(Nodo *&p)
	{
		Nodo *aux;
		while (p != NULL) {
			aux = p;
			p = p->sgte;
			delete aux;
		}
	}

	//Determinar si una lista enlazada contiene o no un valor especificado
	//La función buscar permite determinar si alguno de los nodos de la lista p 
	//contiene el valor v. Retorna un puntero al nodo que contiene dicho valor 
	//o NULL si ninguno de los nodos lo contiene.

	Nodo *buscar(Nodo* p, int v)
	{
		Nodo *aux = p;
		while (aux != NULL && aux->info != v) {
			  aux = aux->sgte;
			}
		return aux;
	}

	//Eliminar de la lista al nodo que contiene un determinado valor
	//La función eliminar permite eliminar de la lista p al nodo que contiene el valor v.
	void eliminar(Nodo*& p, int v)
	{
		Nodo* aux = p;
		Nodo* ant = NULL;
		while (aux != NULL && aux->info != v) {
			ant = aux;
			aux = aux->sgte;
		}
		if (ant != NULL) {
			ant->sgte = aux->sgte;
		}
		else{
			p = aux->sgte;
		}
		delete aux;
	}

	//Eliminar el primer nodo de una lista
	//La función eliminarPrimerNodo elimina el primer nodo de la lista 
	//y retorna el valor que este contenía.
	int eliminarPrimerNodo(Nodo *& p)
	{
		int ret = p->info;
		Nodo *aux = p;
		p = p->sgte;
		delete aux;
		return ret;
	}

	//Insertar un nodo manteniendo el orden de la lista
	//La función insertarOrdenado permite insertar el valor v respetando el criterio
	//de ordenamiento de la lista p; se presume que la lista está ordenada o vacía.
	//Retorna la dirección de memoria del nodo insertado.
	Nodo * insertarOrdenado(Nodo *&p, int v)
	{
		Nodo *nuevo = new Nodo();
		nuevo->info = v;
		nuevo->sgte = NULL;
		Nodo *ant = NULL;
		Nodo *aux = p;
		while (aux != NULL && aux->info <= v) {
			ant = aux;
			aux = aux->sgte;
		}
		if (ant == NULL) {
			p = nuevo;
		}
		else{
		  ant->sgte = nuevo;
		}
		nuevo->sgte = aux;
		return nuevo;
	}
	//Ordenar una lista enlazada
	//La función ordenar ordena la lista direccionada por p.La estrategia consiste 
	// en eliminar uno a uno los nodos de la lista e insertarlos en orden en una 
	//lista nueva; finalmente hacer que p apunte a la nueva lista.
	void ordenar(Nodo *& p){
		Nodo * q = NULL;
		while (p != NULL) {
			int v = eliminarPrimerNodo(p);
			insertarOrdenado(q, v);
			}
		p = q;
		}

	//Insertar en una lista enlazada un valor sin repetición
	//La función buscaEInsertaOrdenado busca el valor v en la lista p.
	//Si no lo encuentra entonces lo inserta respetando el criterio de ordenamiento.
	//Retorna un puntero al nodo encontrado o insertado y asigna el valor true o false 
	//al parámetro enc según corresponda.

	Nodo* buscaEInsertaOrdenado(Nodo*& p, int v, bool& enc)
	{
		Nodo *x = buscar(p, v);
		enc = x != NULL;
		if (!enc) {
			x = insertarOrdenado(p, v);
		}
		return x;
	}
