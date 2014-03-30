#include <iostream>

using namespace std;

class RDragon {
private:
    static int ID;
    static int count;
    Dragon rDragon;
public:
    RDragon(int strth, int atkp): strength(strth), attackPoints(atkp)
        { ID++; count++; }
    RDragon(int strth): strength(strth) { ID++; count++; }
    ~RDragon() { count--; }
};

class BDragon {
private:
    static int ID;
    static int count;
    Dragon rDragon;
public:
    BDragon(int strth, int atkp): strength(strth), attackPoints(atkp)
        { ID++; count++; }
    BDragon(int strth): strength(strth) { ID++; count++; }
    ~BDragon() { count--; }
};
