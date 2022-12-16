#pragma once

using namespace std;

class Bullet {
public:
	Bullet();
	~Bullet();

	void move();
	int getPosition();
	int getDamage();
	
	

private:
	int m_position;
	int m_damage;



};