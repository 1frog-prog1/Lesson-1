#include <iostream>


class FlyBehavior {
public:
	virtual void fly() = NULL;
};

class QuackBehavior {
public:
	virtual void quack() = NULL;
};

class Quack : public QuackBehavior {
	void quack() override {
		std::cout << "Quack-quack!\n";
	}
};

class NoSound : public QuackBehavior {
	void quack() override {
		std::cout << "You are trying to quack...\n"
			<< "But there is no sound.\n";
	}
};

class FlyWithWings : public FlyBehavior {
	void fly() override {
		std::cout << "I am flying!\n";
	}
};

class NoFly : public FlyBehavior {
	void fly() override {
		std::cout << "Can't fly...\n";
	}
};


class IDuck {
protected:
	FlyBehavior* fly_beh;
	QuackBehavior* quack_beh;

public:
	void setQuack(QuackBehavior* quack_beh) {
		this->quack_beh = quack_beh;
	}

	void setFly(FlyBehavior* fly_beh) {
		this->fly_beh = fly_beh;
	}

	void swim() {
		std::cout << "I am swimming!\n";
	}

	void quack() {
		quack_beh->quack();
	}

	void fly() {
		fly_beh->fly();
	}

	virtual void display() = NULL;

	void present() {
		this->display();
		this->swim();
		this->fly();
		this->quack();
		std::cout << std::endl;
	}
};

class MarrladDuck : public IDuck {
public:
	MarrladDuck() {
		fly_beh = new FlyWithWings;
		quack_beh = new Quack;
	}

	void display() override {
		std::cout << "I am Marrlad Duck!\n";
	}
};

class ReadHeadDuck : public IDuck {
public:
	ReadHeadDuck() {
		fly_beh = new FlyWithWings;
		quack_beh = new Quack;
	}

	void display() override {
		std::cout << "I am Read Head Duck!\n";
	}
};

class RubberDuck : public IDuck {
public:
	RubberDuck() {
		fly_beh = new NoFly;
		quack_beh = new Quack;
	}

	void display() override {
		std::cout << "I am a Rubber Duck!\n";
	}
};