#include <iostream>
#include <string>
#include "Artillery.h"


using namespace std;

Artillery::Artillery(){
	m_energylevel = 3;

}
Artillery::~Artillery() {}


 void Artillery::shoot() {
	 while (m_energylevel > 0) {
		 //...print 1 Bullet glaube ich weis aber nicht wie
		 m_energylevel = m_energylevel - 1;
	 }

 }
 void Artillery::hit() {


 }





