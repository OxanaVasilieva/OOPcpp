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

	//�������� ����� ������� � ������
	void addFirst(const T & element) {
		Item<T> *temp = new Item<T> (element, NULL, first);
		if (first != NULL) first->setPrev(temp);
		first = temp;
		if (size == 0) last = temp;
		size++;
	};

	//�������� ����� ������� � �����
	void addLast(const T & element) {
		Item<T> *temp = new Item<T> (element, last, NULL);
		if (last != NULL) last->setNext(temp);
		last = temp;
		if (size == 0) first = temp;
		size++;
	};

	//������� ������ �������
	void removeFirst() {
		if (size == 0) return;
		Item<T> *second = first->getNext();
		if (second != NULL) second->setPrev(NULL);
		delete first;
		first = second;
		size--;
	};

	//������� ��������� �������
	void removeLast() {
		if (size == 0) return;
		Item<T> *penult = last->getPrev();
		if (penult != NULL) penult->setNext(NULL);
		delete last;
		last = penult;
		size--;
	};

	//�������� �������� ������� ��������
	T getFirst() {
		if (first == NULL) throw 11;
		return first->getValue();
	};

	//�������� �������� ���������� ��������
	T getLast() {
		if (first == NULL) throw 11;
		return last->getValue();
	};

	//�������� ������� �� ������ �������
	void reset() {
		current = first;
	}

	//�������� ��������� �� ������� �������
	T* getCurrent() {
		if (current == NULL) return NULL;
		return &(current->getValue());
	}

	//�������� ������� �� ��������� �������
	void next() {
		current = current->getNext();
	}

	//������ ���-�� ���������
	int getSize() {
		return size;
	};

	//��������� �� �������
	bool isEmpty() {
		if (size > 0) return false;
		return true;
	};

	//��������
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


//������������� ������� (��� ����������)
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

	//�������� ����� ������� � ������
	void addFirst( T*  element) {
		Item<T*> *temp = new Item<T*> (element, NULL, first);
		if (first != NULL) first->setPrev(temp);
		first = temp;
		if (size == 0) last = temp;
		size++;
	};

	//�������� ����� ������� � �����
	void addLast( T*  element) {
		Item<T*> *temp = new Item<T*> (element, last, NULL);
		if (last != NULL) last->setNext(temp);
		last = temp;
		if (size == 0) first = temp;
		size++;
	};

	//������� ������ �������
	void removeFirst() {
		if (size == 0) return;
		Item<T*> *second = first->getNext();
		if (second != NULL) second->setPrev(NULL);
		delete first;
		first = second;
		size--;
	};

	//������� ��������� �������
	void removeLast() {
		if (size == 0) return;
		Item<T*> *penult = last->getPrev();
		if (penult != NULL) penult->setNext(NULL);
		delete last;
		last = penult;
		size--;
	};

	//�������� �������� ������� ��������
	T* getFirst() {
		return first->getValue();
	};

	//�������� �������� ���������� ��������
	T* getLast() {
		return last->getValue();
	};

	//����������� ������� �� ������ �������
	void reset() {
		current = first;
	}

	//�������� ��������� �� ������� ������
	T* getCurrent() {
		if (current == NULL) return NULL;
		return current->getValue();
	}

	//�������� ������� �� ��������� �������
	void next() {
		current = current->getNext();
	}

	//������ ���-�� ���������
	int getSize() {
		return size;
	};

	//��������� �� �������
	bool isEmpty() {
		if (size > 0) return false;
		return true;
	};

	//��������
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