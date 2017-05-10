
class Shape : public Printable {
private:
	static int shapeCounter;
public:
	Shape::Shape() {
		Shape::shapeCounter++;
	}

	virtual Shape::~Shape() {
		Shape::shapeCounter--;
	}

	static int GetCount() {
		return Shape::shapeCounter;
	};
};

std::ostream & operator<< (std::ostream & ioStream, Shape* s){
	return (ioStream << s->printInfo());
}

class Point: public Shape, public Named {
protected:
	double x;
	double y;
public:
	Point() : Named("Point") {

	}
	Point::Point(double x, double y, std::string name = "Point") : Shape(), Named(name) {
		this->x = x;
		this->y = y;
	}

	double getX() {
		return x;
	}

	double getY() {
		return y;
	}

	virtual std::string printInfo() {
		return "Name: " + this->getName() + "\n" +
			"Coordinates: (" + std::to_string((long double)x) + ", " + std::to_string((long double)y) + ") \n";
	}

	//копирующий конструктор
	Point(const Point &p ) : Named("Point") {
		x = p.x;
		y = p.y;
	}

	//оператор присваивания
	Point& Point::operator=(const Point& p) {
		if (this == &p) return *this;
		this->x = p.x;
		this->y = p.y;
		return *this;
	}

};

const double PI = 3.1415926535897932384626;

class Circle : public Point {
private:
	double radius;
public:
	Circle::Circle(double x, double y, double r, std::string name = "Circle"): Point(x, y, name) {
		this->radius = r;
	}

	long double getPerimeter() {
		return 2 * PI * radius;
	}

	long double getArea() {
		return PI * radius * radius;
	}

	virtual std::string printInfo() {
		return "Name: " + this->getName() + "\n"
			"Center: (" + std::to_string((long double)x) + ", " + std::to_string((long double)y) + ") \n" +
			"Radius: " + std::to_string((long double)radius) + "\n" +
			"Perimeter: " + std::to_string(getPerimeter()) + "\n" +
			"Area: " + std::to_string(getArea()) + "\n";
	}
}; 

class Rect : public Point {
private:
	double x2;
	double y2;
public:
	Rect::Rect(double x1, double y1, double x2, double y2, std::string name = "Rectangle") : Point(x1, x2, name) {
		  this->x2 = x2;
		  this->y2 = y2;
	}

	long double getPerimeter() {
		return 2 * abs(x2 - x + y2 - y);
	}

	long double getArea() {
		return abs(x2 - x) * abs(y2 - y);
	}

	virtual std::string printInfo() {
		return "Name: " + this->getName() + "\n" + 
			"First point: (" + std::to_string((long double)x) + ", " + std::to_string((long double)y) + ") \n" +
			"Second point: (" + std::to_string((long double)x2) + ", " + std::to_string((long double)y2) + ") \n" +
			"Perimeter: " + std::to_string(getPerimeter()) + "\n" +
			"Area: " + std::to_string(getArea()) + "\n";
	}
};

class Square : public Rect {
public:
	Square(double x, double y, double length, std::string name = "Square") : Rect(x, y, x + length, y + length, name) {
	}
};

class Polyline : public Shape, public Named {
protected:
	Container< Point > points;
public:
	Polyline::Polyline(std::string name = "Polyline") : Shape(), Named(name) {
		this->points = Container< Point >(); 
	};

	~Polyline() {
		points.clear();
	};

	void addPoint(Point const & point) {
		this->points.addLast(point);
	};

	long double getLength() {
		long double pr = 0;
		Point * prev;

		for (points.reset(), prev = points.getCurrent(), points.next(); Point * p = points.getCurrent(); points.next()) {
			pr += sqrt(pow(p->getX() - prev->getX(), 2) + pow(p->getY() - prev->getY(), 2));
			prev = p;
		}

		return pr;
	}

	std::string getCoordinates() {
		std::string s = "Coordinates of points: \n";
		for (points.reset(); Point * p = points.getCurrent(); points.next()) {
			s += "(" + std::to_string((long double)p->getX()) + ", " + std::to_string((long double)p->getY()) + ") \n";
		}
		return s;
	}

	std::string printInfo() {
		return "Name: " + this->getName() + "\n" + 
			"Number of points: " + std::to_string((long double)points.getSize()) + "\n" +
			getCoordinates() +
			"Length: " + std::to_string(getLength()) + "\n";
	}
}; 

class Polygon : public Polyline {
public:
	Polygon(std::string name = "Polygon") : Polyline(/*points, n,*/ name) {

	}

	long double getLength() {
		long double pr = 0;
		Point * prev;
		Point p1, p2;

		try{	
			p1 = points.getFirst();
			p2 = points.getLast();		
		} catch(int i) {
			std::cout << "Error " << i << ": Taking an item from an empty container!" << std::endl;
			return 0;
		};
		
		
		pr += sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));

		for (points.reset(), prev = points.getCurrent(), points.next(); Point * p = points.getCurrent(); points.next()) {
			pr += sqrt(pow(p->getX() - prev->getX(), 2) + pow(p->getY() - prev->getY(), 2));
			prev = p;
		}

		return pr;
	}

	std::string printInfo() {
		return "Name: " + this->getName() + "\n" + 
			"Number of points: " + std::to_string((long double)points.getSize()) + "\n" +
			getCoordinates() +
			"Perimeter: " + std::to_string(getLength()) + "\n";
	}
}; 

