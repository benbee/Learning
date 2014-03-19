#include <cstring>
#include <iostream>

using namespace std;


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


class ArmyBase {
private:
    static int times;
    static string fighterName[5];
    //static string fighterHealthPoints[5];
    int originHealth;
    int current_id;
    Fighter fighters[100];
    string name;
    int productOrder[5];        // base on fighterName
    int fighterHp[5];

public:
    ArmyBase(int f1hp, int f2hp, int f3hp, int f4hp, int f5hp,
             int o_hp, const char* baseName);
    void produceArmyBoth(ArmyBase , ArmyBase);
};

string ArmyBase::fighterName[5] = {"dargon", "ninja", "iceman", "lion", "wolf"};
int ArmyBase::times = 0;

ArmyBase::ArmyBase(int f1hp, int f2hp, int f3hp, int f4hp, int f5hp,
                   int o_hp, const char* baseName)
{
    originHealth = o_hp;
    if (baseName[0] == 'r') {
        productOrder[0] = 2;
        productOrder[1] = 3;
        productOrder[2] = 4;
		productOrder[3] = 1;
        productOrder[4] = 0;
    }

    if (baseName[0] == 'b') {
        productOrder[0] = 3;
        productOrder[1] = 0;
        productOrder[2] = 1;
		productOrder[3] = 2;
        productOrder[4] = 4;
    }

    fighterHp[0] = f1hp;
    fighterHp[1] = f2hp;
    fighterHp[2] = f3hp;
    fighterHp[3] = f4hp;
    fighterHp[4] = f5hp;

    strcpy(name, baseName);
    int i;
    for (i = 0; i < 100; i++) {
        fighters[i] = Fighter(0, 0, "untrained");
    }
}

void ArmyBase::produceArmyBoth(ArmyBase red, ArmyBase blue)
{

}


int main(int argc, char *argv[])
{
    return 0;
}
