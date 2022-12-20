#pragma once

class Test
{
private:
	float position = 0;

public:
	Test();
	~Test();

	void move();
	void spawn();
	

	float getPosition()
	{
		return position;
	}
};


//-------------------------------------------------
//cpp

int l = 0;

Test::Test()
{
	std::cout << "Constructor Test\n";
	
}

Test::~Test()
{
	std::cout << "Destructor Test\n";
}

void Test::move()
{
	position++;
}

void Test::spawn()
{
	cout << "spawn";

	Test* l = new Test;
	l++;

}