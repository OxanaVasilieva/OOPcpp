#include "stdafx.h"
#include <iostream>
#include <string>
#include "Container.h"
#include "Base.h"
#include "Shapes.h"
#include "ShapeFactory.h"

using namespace std;

int Shape::shapeCounter = 0;
int _tmain(int argc, _TCHAR* argv[])
{
	Container<Shape*> container = Container<Shape*>();
	ShapeFactory shapeFactory = ShapeFactory();
	for (int i = 0; i < 20; i++) {
		container.addLast(shapeFactory.createShape());
	}

	std::cout << "Number of all shapes: " << Shape::GetCount() << std::endl;

	std::cout << "Number of shapes in the container: " << container.getSize() << std::endl << std::endl;

	for (container.reset(); Shape* i = container.getCurrent(); container.next()) {
		std::cout << i << std::endl;
	}

	container.clear();

	std::cout << "Number of all shapes: " << Shape::GetCount() << std::endl;

	std::cout << "Number of shapes in the container: " << container.getSize() << std::endl << std::endl;

	return 0;
}

