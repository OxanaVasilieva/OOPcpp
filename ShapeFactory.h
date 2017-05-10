class ShapeFactory {
private:
	enum shapeTypes {point, circle, rect, square, polyline, polygon};
public:
	Shape* createShape() {
		Shape* shape;
		double x, y, radius, x2, y2, length;
		int n;
		int const max = 100;
		Polyline* pl;
		Polygon* pg;
		int type = rand() % (polygon + 1);
		switch (type) {
		case point:
			x = 2 * rand() % (max + 1) - max;
			y =  2 * rand() % (max + 1) - max;
			shape = new Point(x, y);
			break;
		case circle:
			x = 2 * rand() % (max + 1) - max;
			y =  2 * rand() % (max + 1) - max;
			radius = rand() % max + 1;
			shape = new Circle(x, y, radius);
			break;
		case rect:
			x = 2 * rand() % (max + 1) - max;
			y =  2 * rand() % (max + 1) - max;
			x2 = rand() % max + x + 1;
			y2 =  rand() % max + y + 1;
			shape = new Rect(x, y, x2, y2);
			break;
		case square:
			x = 2 * rand() % (max + 1) - max;
			y =  2 * rand() % (max + 1) - max;
			length = rand() % max + 1;
			shape = new Square(x, y, length);
			break;
		case polyline:
			pl = new Polyline();
			n = rand() % 5 + 1;
			for (int i = 0; i < n; i++) {
				x = 2 * rand() % (max + 1) - max;
				y =  2 * rand() % (max + 1) - max;
				pl->addPoint(Point(x, y));
			}
			shape = pl;
			break;
		case polygon:
			pg = new Polygon();
			n = rand() % 5 + 1;
			for (int i = 0; i < n; i++) {
				x = 2 * rand() % (max + 1) - max;
				y =  2 * rand() % (max + 1) - max;
				pg->addPoint(Point(x, y));
			}
			shape = pg;
			break;
		default:
			break;
		}
		return shape;
	}
};