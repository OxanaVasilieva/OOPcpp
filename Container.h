template <class U> class Item {
public:
	Item(U v, Item<U> *p, Item<U> *n) {
		value = v;
		prev = p;
		next = n;
	};

	U & getValue() {
		return value;
	} 

	Item<U>* getPrev() {
		return prev;
	}

	Item<U>* getNext() {
		return next;
	}

	void setPrev(Item<U>* p) {
		prev = p;
	}

	void setNext(Item<U>* n) {
		next = n;
	}

private:
	U value;
	Item<U> *prev;
	Item<U> *next;
};

template <class T> class Container {
private:
	Item<T> *first;
	Item<T> *last;
	Item<T> *current;
	int size;

public:
	Container() {
		first = NULL;
		last = NULL;
		current = NULL;
		size = 0;
	};

	//добавить новый элемент в начало
	void addFirst(const T & element) {
		Item<T> *temp = new Item<T> (element, NULL, first);
		if (first != NULL) first->setPrev(temp);
		first = temp;
		if (size == 0) last = temp;
		size++;
	};

	//добавить новый элемент в конец
	void addLast(const T & element) {
		Item<T> *temp = new Item<T> (element, last, NULL);
		if (last != NULL) last->setNext(temp);
		last = temp;
		if (size == 0) first = temp;
		size++;
	};

	//удалить первый элемент
	void removeFirst() {
		if (size == 0) return;
		Item<T> *second = first->getNext();
		if (second != NULL) second->setPrev(NULL);
		delete first;
		first = second;
		size--;
	};

	//удалить последний элемент
	void removeLast() {
		if (size == 0) return;
		Item<T> *penult = last->getPrev();
		if (penult != NULL) penult->setNext(NULL);
		delete last;
		last = penult;
		size--;
	};

	//получить значение первого элемента
	T getFirst() {
		if (first == NULL) throw 11;
		return first->getValue();
	};

	//получить значение последнего элемента
	T getLast() {
		if (first == NULL) throw 11;
		return last->getValue();
	};

	//сместить поинтер на первый элемент
	void reset() {
		current = first;
	}

	//получить указатель на текущий элемент
	T* getCurrent() {
		if (current == NULL) return NULL;
		return &(current->getValue());
	}

	//сместить поинтер на следующий элемент
	void next() {
		current = current->getNext();
	}

	//узнать кол-во элементов
	int getSize() {
		return size;
	};

	//проверить на пустоту
	bool isEmpty() {
		if (size > 0) return false;
		return true;
	};

	//очистить
	void clear() {
		if (size == 0) return;
		for(Item<T>* i = first->getNext(); i != NULL; i = i->getNext()) {
			delete i->getPrev();
			size--;
		}
		if (last != NULL) {
			delete last;
			size--;
		}
		first = NULL;
		last = NULL ;
	};
};


//специализация шаблона (для указателей)
template <class T> class Container<T*> {
private:
	Item<T*> *first;
	Item<T*> *last;
	Item<T*> *current;
	int size;

public:
	Container() {
		first = NULL;
		last = NULL;
		current = NULL;
		size = 0;
	};

	//добавить новый элемент в начало
	void addFirst( T*  element) {
		Item<T*> *temp = new Item<T*> (element, NULL, first);
		if (first != NULL) first->setPrev(temp);
		first = temp;
		if (size == 0) last = temp;
		size++;
	};

	//добавить новый элемент в конец
	void addLast( T*  element) {
		Item<T*> *temp = new Item<T*> (element, last, NULL);
		if (last != NULL) last->setNext(temp);
		last = temp;
		if (size == 0) first = temp;
		size++;
	};

	//удалить первый элемент
	void removeFirst() {
		if (size == 0) return;
		Item<T*> *second = first->getNext();
		if (second != NULL) second->setPrev(NULL);
		delete first;
		first = second;
		size--;
	};

	//удалить последний элемент
	void removeLast() {
		if (size == 0) return;
		Item<T*> *penult = last->getPrev();
		if (penult != NULL) penult->setNext(NULL);
		delete last;
		last = penult;
		size--;
	};

	//получить значение первого элемента
	T* getFirst() {
		return first->getValue();
	};

	//получить значение последнего элемента
	T* getLast() {
		return last->getValue();
	};

	//переместить поинтер на первый элемент
	void reset() {
		current = first;
	}

	//получить указатель на текущий объект
	T* getCurrent() {
		if (current == NULL) return NULL;
		return current->getValue();
	}

	//сместить поинтер на следующий элемент
	void next() {
		current = current->getNext();
	}

	//узнать кол-во элементов
	int getSize() {
		return size;
	};

	//проверить на пустоту
	bool isEmpty() {
		if (size > 0) return false;
		return true;
	};

	//очистить
	void clear() {
		if (size == 0) return;
		for(Item<T*>* i = first->getNext(); i != NULL; i = i->getNext()) {
			delete i->getPrev()->getValue();
			delete i->getPrev();
			size--;
		}
		if (last != NULL) {
			delete last->getValue();
			delete last;
			size--;
		}
		first = NULL;
		last = NULL ;
	};
};