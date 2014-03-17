#include <iostream>

using namespace std;

class Dragon {
private:
    int strength;
    int attackPoints;
public:
};

class RDragon {
private:
    static int ID;
    static int count;
    Dragon rDragon;
public:
    RDragon(int strth, int atkp): strength(strth), attackPoints(atkp)
        { ID++; count++; }
    RDragon(int strth): strength(strth) { ID++; count++ }
    ~RDragon()
        {
            count--;
        }

}
