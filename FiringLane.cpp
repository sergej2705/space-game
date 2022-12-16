#include <array>

#include "FiringLane.h"


using namespace std;



FiringLane::FiringLane()
{
	m_length = 20;
	 m_artillery = Artillery();
	 m_bullets = {};
	 m_enemies = {Enemy(m_length)};
}

FiringLane::~FiringLane()
{

}


void FiringLane::nextTick()
{

}

string FiringLane::print()
{
	char* lane = new char[m_length];



	return string();
}
