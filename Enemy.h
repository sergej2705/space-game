#pragma once

using namespace std;

class Enemy {
public:
	Enemy(int startPosition);
	~Enemy();
	
	int getPosition();
	int move();
	void hit();


private:
	int m_position;


};

