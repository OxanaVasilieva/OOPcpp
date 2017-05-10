class Printable {
public:
	virtual std::string printInfo() = 0;
};

class Named : public Printable {
protected:
	std::string name;
public:
	Named(std::string name) {
		this->name = name;
	}

	std::string getName() {
		return this->name;
	}
};