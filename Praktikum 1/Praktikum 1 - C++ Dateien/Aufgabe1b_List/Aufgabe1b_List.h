#ifndef _LIST_H
#define _LIST_H
#include "Node.h"
#include <string>
#include <iostream>

template <class T>
class List 
{

	.
	.
	.

	void format(const std::string & start, const std::string & zwischen, const std::string & ende);	// Mit der format-Methode kann die Ausgabe gesteuert werden: operator <<
	List<T> & operator = (const List<T> & _List);						// Zuweisungsoperator definieren
	List<T> & operator = (const List<T> * _List);						// Zuweisungsoperator definieren
	List<T> & operator + (const List<T> & List_Append);					// Listen zusammenführen zu einer Liste
	List<T> & operator + (const List<T> * List_Append);					// Listen zusammenführen zu einer Liste
	template <typename Tf>
	friend std::ostream & operator << (std::ostream & stream, const List<Tf> & Liste);		// Ausgabeoperator überladen
	template <typename Tf>
	friend std::ostream & operator << (std::ostream & stream, const List<Tf> * Liste);		// Ausgabeoperator überladen
};

.
.
.

template <class T>
void List<T>::format(const std::string & start, const std::string & zwischen, const std::string & ende)
{
	_form.start = start;
	_form.zwischen = zwischen;
	_form.ende = ende;
}

template <class T>
List<T> & List<T>::operator = (const List<T> & _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == &_List) return *this;	//  !! keine Aktion notwendig
	Node<T> * tmp_node;
	if (_size)
	{
		Node<T> * tmp_del;
		tmp_node = head->next;
		while (tmp_node != tail)		// Alle eventuell vorhandenen Knoten in this löschen
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node->next;
			delete tmp_del;
		}
		_size = 0;
		head->next = tail;
		tail->prev = head;
	}
	tmp_node = _List.head->next;
	while (tmp_node != _List.tail)
	{
		InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (_List.temp) delete & _List;		// ist die Uebergebene Liste eine temporaere Liste? -> aus Operator +
	return *this;
}

template <class T>
List<T> & List<T>::operator = (const List<T> * _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == _List) return *this;	//  !! keine Aktion notwendig
	Node<T> * tmp_node;
	if (_size)
	{
		Node<T> * tmp_del;
		tmp_node = head->next;
		while (tmp_node != tail)		// Alle eventuell vorhandenen Knoten in this loeschen
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node->next;
			delete tmp_del;
		}
		_size = 0;
		head->next = tail;
		tail->prev = head;
	}
	tmp_node = _List->head->next;
	while (tmp_node != _List->tail)
	{
		InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (_List->temp) delete _List;		// ist die Uebergebene Liste eine temporaere Liste? -> aus Operator +
	return *this;
}

template <class T>
List<T> & List<T>::operator + (const List<T> & List_Append)
{
	Node<T> * tmp_node;
	List<T> * tmp;
	if (temp){								// this ist eine temporaere Liste und kann veraendert werden
		tmp = this;
	}
	else {
		tmp = new List(this);				// this ist keine temporaere Liste -> Kopie erzeugen
		tmp->temp = true;					// Merker setzten, dass es sich um eine temporaere Liste handelt
	}
	if (List_Append._size) {				// anhängen der uebergebenen Liste an tmp
		tmp_node = List_Append.head->next;
		while (tmp_node != List_Append.tail){
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append.temp) delete & List_Append;		// wurde eine temporaere Liste uebergeben, dann wird diese geloescht						
	return *tmp;
}

template <class T>
List<T> & List<T>::operator + (List<T> const * List_Append)
{
	Node<T> * tmp_node;
	List<T> * tmp;
	if (temp){								// this ist eine temporaere Liste und kann veraendert werden
		tmp = this;
	}
	else {
		tmp = new List(this);				// this ist keine temporaere Liste -> Kopie erzeugen
		tmp->temp = true;					// Merker setzten, dass es sich um eine temporaere Liste handelt
	}
	if (List_Append->_size) {				// anhaengen der uebergebenen Liste an tmp
		tmp_node = List_Append->head->next;
		while (tmp_node != List_Append->tail){
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append->temp) delete List_Append;		// wurde eine temporaere Liste uebergeben, dann wird diese geloescht					
	return *tmp;
}


template <class Tf>
std::ostream & operator << (std::ostream  & stream, const List<Tf> & Liste)
{
	stream << Liste._form.start;
	for (Node<Tf> * tmp = Liste.head->next; tmp != Liste.tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste.tail ? Liste._form.ende : Liste._form.zwischen);
	if (Liste.temp) delete & Liste;			// wurde eine temporaere Liste uebergeben, dann wird diese geloescht
	return stream;
}

template <class Tf>
std::ostream & operator << (std::ostream  & stream, const List<Tf> * Liste)
{
	stream << Liste->_form.start;
	for (Node<Tf> * tmp = Liste->head->next; tmp != Liste->tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste->tail ? Liste->_form.ende : Liste->_form.zwischen);
	if (Liste->temp) delete Liste;			// wurde eine temporaere Liste uebergeben, dann wird diese geloescht
	return stream;
}

#endif