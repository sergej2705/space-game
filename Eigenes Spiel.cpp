
#include <iostream>
#include "FiringLane.h"
#include <thread>


using namespace std;

int main()
{
   /* cout << "" << endl;
    cout << "" << endl;
    cout << "----------" << endl;
    cout << "|L=       \\ " << endl;
    cout << "|        =G     ---   ---   ---   ---        X " << endl;
    cout << "|   P     / " << endl;
    cout << "|         D" << endl;
    cout << "|         \\ " << endl;
    cout << "|        =G  ---   ---   ---   --#" << endl;
    cout << "|         / " << endl;
    cout << "----------" << endl;
    cout << "" << endl;
    cout << "" << endl;*/


    // X = Asteroieden (Fliegen in tiks auf das Raumschiff zu)
    // G = Geschütz (Eigener Akku 3) (Pro Akku von Player 3 Salven)
    // L= = Ladesäule (Braucht für 1 Ladebalken 2 Tiks)
    // P = Player (Muss hin und her laufen um Batterien auszutauschen)(Hat einen Akku bei sich für die Gschütze)
    // D = Reperaturstation (Hier kann der Player das Raumschif um 1 Leben regenerieren wenn er 5 ticks wartet)
    // Das Raumschif hatt 3 Leben
    //-----------------------------------------------------------------------------------------------------------------


    FiringLane lane = FiringLane();
    int x = 0;

    while (x<10) {

        lane.nextTick();

        lane.print();



        x++;
        std::this_thread::sleep_for(std::chrono::milliseconds(750));
        system("cls");

    }
    










}

