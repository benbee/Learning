#include <iostream>
#include <cstring>

using namespace std;

char *fighterName[] = ["dargon", "ninja", "iceman", "lion", "wolf"];

class ArmyBase {
private:
    static times;
    int originHealth;
    int current_id;
    Fighter army[100];
    string name;
    int productOrder[5];        // base on fighterName

public:
    ArmyBase(int f1hp, int f2hp, int f3hp, int f4hp, int f5hp,
             const char* baseName);
};

ArmyBase::ArmyBase(int f1hp, int f2hp, int f3hp, int f4hp, int f5hp,
             const char* baseName)
{
    if (baseName[0] == 'r') {
        productOrder[0] = 3;
        productOrder[]
    }
}

class Fighter {
private:
    int healthPoints;
    int attackPoints;
    char fighterName[10];
public:
    Fighter(int hp, int ap, char *name): healthPoints(ap), attackPoints(ap)
        {
            strcpy(fighterName, name);
        }
};

int main(int argc, char *argv[])
{

    return 0;
}
