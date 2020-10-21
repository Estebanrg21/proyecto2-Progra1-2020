#include <utility>
#include <typeinfo>
#include <iostream>
#include <sstream>
#ifndef LISTAENLAZADA_H
	#undef LISTAENLAZADA_H
	#define LISTAENLAZADA_H
#endif
using namespace std;

template<class T = int>
class Node {
private:
	T dato;
	Node *next;
	
public:
	
	Node();
	void setDato(T);
	T getDato();
	
	Node &operator =(T dato);
	
	~Node();
	void setNext(Node *);
	Node *getNext();
	T & operator->() const;
};

template<class T> class Lista;
template<class T> ostream& operator<< (ostream& os, const Lista<T>& l);


template<class T = int>
class Lista {
private:
	Node<T> * cabeza;
	Node<T>* aux;
	int len;
	
public:
	const int &length=len;
	
	Lista();
	~Lista();
	void append(T);
	void addToStart(T);
	string toString() const;
	bool erase(T);
	Node<T>* find(T);  
	void right(T dataToFind,T dataToAdd);
	void left(T dataToFind,T dataToAdd);
	int getIndexOf(T data);
	
	Node<T>*getCabeza();
	
	Node<T> &operator [](int);
	
	friend std::ostream& operator<<<>(std::ostream& os, const Lista<T>& l);
};


/************************ START NODE IMPLEMENTATION *****************************/
template<class T>
Node<T>::Node(){
	dato = T();
	next = nullptr;
	
} // constructor
template<class T>
Node<T>::~Node(){
	// destructor
	//cout<<"\ndeleted:\n"<<dato<<endl;
}
template<class T>
	Node<T> &Node<T>::operator =(T dato){
	this->dato=dato;
	return *this;
}

	
template<class T>
	void Node<T>::setDato(T dato){
	this->dato = dato;
} // set dato
	template<class T>
	T Node<T>::getDato(){
	return dato;
} // getDato
	template<class T>
	void Node<T>::setNext(Node<T> *next){
	this->next = next;
}
template<class T>
	Node<T> *Node<T>::getNext(){
	return next;
}
/************************ END NODE IMPLEMENTATION *****************************/
/******************************************************************************/
/******************************************************************************/	
/************************ START LIST IMPLEMENTATION ***************************/
template<class T>
Lista<T>::Lista(){
	cabeza = nullptr;
	aux=nullptr;
	len=0;
} // constructor

template<class T>
Lista<T>::~Lista(){
	Node<T> *p;
	if(cabeza){
		while(cabeza != nullptr){
			p = cabeza;
			cabeza = cabeza->getNext();	        	
			p->setNext(nullptr);
			delete p; 
		}	
	}
} // destructor
	
/*
	add node to start and increment by 1 the nodes 
	that already exis
*/
	
template<class T>
	void Lista<T>::addToStart(T data) {
	aux=nullptr;
	aux = new Node<T>();
	aux->setDato(data);
	aux->setNext(cabeza);
	cabeza = aux;	
	if(cabeza)len++;
}// addToStart

/*
	print list
*/
template<class T>
	string Lista<T>::toString() const{
	stringstream ss;
	Node<T>*p;
	p = cabeza;	
	if(p == nullptr){
		ss << "[]" << endl;
	}else{
		ss << "\n[" ;
		do {
			ss << p->getDato();
			p = p->getNext();
			ss << ((p)?", ":"");
		} while (p!= nullptr);		
		ss << "]\n" << endl;
		
	}	
	delete p;
	return ss.str();
}  // list



/*
	add node to the end of the list
*/
template<class T>
	void Lista<T>::append(T data){
	aux=nullptr;
	Node<T>*nuevo = new Node<T>;
	nuevo->setDato(data);
	nuevo->setNext(nullptr);
	
	if(!cabeza){
		nuevo->setDato(data);		
		nuevo->setNext(cabeza);
		cabeza = nuevo;
		len++;
	}else{
		aux = cabeza;
		while(aux->getNext() != nullptr){
			aux = aux->getNext();
		}
		aux->setNext(nuevo);
	}
	if(aux)len++;
	
}  // append


/*
	erase element
*/
template<class T>
	bool Lista<T>::erase(T data){
	aux=nullptr;
	aux = cabeza;   
	bool erased = false;
	if(aux){   
		if(aux->getDato() == data){        
			cabeza = aux->getNext();
			delete aux;
			erased = true;
		}else{
			Node<T> *anterior;
			while ((aux != nullptr) && (aux->getDato()!= data)){
				anterior = aux;
				aux = aux->getNext();
			}
			if(aux){ 
				anterior->setNext(aux->getNext());
				delete aux;
				erased = true;
			}		
		}
	}
	if(erased)len--;
	
	return erased;
}// erase a element

/*
	find element by data
*/
template<class T>
	Node<T>* Lista<T>::find(T data){
	aux=nullptr;
	Node<T>* toReturn=nullptr;
	aux= cabeza; 
	if(aux){
		while(aux != nullptr){
			if (aux->getDato()== data){
				toReturn=aux;
				aux=nullptr;
			}else{
				aux = aux->getNext();
			}	
		};		
	}
	aux=nullptr;
	
	
	return toReturn;
}// find by data


/*
	ADD NODE TO THE RIGHT SIDE OF ANOTHER
*/
template<class T>
	void Lista<T>::right(T dataToFind,T dataToAdd){
	aux=nullptr;
	aux = cabeza; 
	Node<T>* p = new Node<T>;
	
	p->setDato(dataToAdd);
	while(aux != nullptr){
		if (aux->getDato()== dataToFind){
			p->setNext(aux->getNext());
			aux->setNext(p);
			break;
		}
		aux = aux->getNext();
	}		
	if(aux)this->len++;
	
}// right

/*
ADD NODE TO THE LEFT SIDE OF ANOTHER
*/
template<class T>
	void Lista<T>::left(T dataToFind,T dataToAdd){
	aux=nullptr;
	aux = cabeza; 
	Node<T>* p = new Node<T>;
	
	p->setDato(dataToAdd);
	Node<T>* prev=nullptr;
	while(aux != nullptr){
		if (aux->getDato()== dataToFind){
			p->setNext(aux);
			if(prev){prev->setNext(p);}else{
				cabeza=p;	
			}
			break;
		}
		prev=aux;
		aux = aux->getNext();
	}	
	if(aux)len++;
	
}// left

/*
	Get index of data
*/
template<class T>
	int Lista<T>::getIndexOf(T data){
	aux=nullptr;
	int counter = 0;	
	aux = cabeza;
	
	if(aux == nullptr){
		counter = -1;
	}else{
		while(aux != nullptr){
			if(aux->getDato()==data)break;
			aux = aux->getNext();
			counter++;
		};		
	}
	if(!aux)counter=-1;
	return counter;
}

template<class T>
Node<T>*Lista<T>::getCabeza(){
	return this->cabeza;
}

/*
	Overload the [] operator
*/
template<class T>
Node<T> & Lista<T>::operator [](int index){
	aux=nullptr;
	int counter = 0;	
	aux = cabeza;
	if(index<0||index>=len)throw runtime_error("index out of range");
	if(aux == nullptr){
		counter = -1;
	}else{
		while(aux != nullptr){
			if(counter==index)break;
			aux = aux->getNext();
			counter++;
		};		
	}
	return (*aux);
}

/*
	Overload the << operator
*/
template<class T>
std::ostream&operator<<(std::ostream& os, const Lista<T>&l){
	os << l.toString();
	return os;
}
/************************ END LIST IMPLEMENTATION ***************************/
