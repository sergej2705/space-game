#pragma once

using namespace std;

class Artillery {
public:
	Artillery();
		~Artillery();
	void shoot();
	void hit();



private:
	int m_energylevel;

};
