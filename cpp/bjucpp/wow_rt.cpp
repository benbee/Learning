#include <cstring>
#include <iostream>
#include <string>
#include<iomanip>

using namespace std;

// class Fighter {
// private:
//     int healthPoints;
//     int attackPoints;
//     string fighterName;
// public:
//     Fighter(int hp, int ap, string name): healthPoints(ap), attackPoints(ap)
//         {
//             fighterName = name;
//         }
// };


class ArmyBase {
private:
    static string fighterName[5];
    //static string fighterHealthPoints[5];
    int originHealth;
    int current_id;
    int times;
    string fighters[100];
    string name;
    int productOrder[5];        // base on fighterName
    int fighterHp[5];

public:
    ArmyBase(int f1hp, int f2hp, int f3hp, int f4hp, int f5hp,
             int o_hp, const string baseName);
    void produceArmyBoth(ArmyBase , ArmyBase);
    int  countFighter(string fname);
    int produceOne(void);
    void addFighter(string fname);
    void print_name(void) { cout << name << endl; };
    void print_fighters(void);
};

string ArmyBase::fighterName[5] = {"dargon", "ninja", "iceman", "lion", "wolf"};
//int ArmyBase::times = 0;

void ArmyBase::print_fighters(void)
{
    for (int i = 0; i < 100; i++) {
        cout << fighters[i] << endl;
    }
}

ArmyBase::ArmyBase(int f1hp, int f2hp, int f3hp, int f4hp, int f5hp,
                   int o_hp, const string baseName)
{
    times = 0;
    current_id = 0;
    // for (int i = 0; i < 100; i++) {
    //     fighters[i] = "";
    // }

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
    // need reorder
    fighterHp[0] = f1hp;
    fighterHp[1] = f2hp;
    fighterHp[2] = f3hp;
    fighterHp[3] = f4hp;
    fighterHp[4] = f5hp;

    name = baseName;
}

int ArmyBase::countFighter(string name)
{
    int count = 0;

    for (int i; i < 100; i++) {
        if (fighters[i] == name) {
            count++;
        }
    }

    return count;
}

int ArmyBase::produceOne()
{
    // need a if to jugg if wen can contunie to produce
    current_id++;
    int ord_num = current_id % 5 - 1;
    fighters[current_id - 1] = fighterName[productOrder[ord_num]];
    originHealth -= fighterHp[productOrder[]];

    // print out product one state
    cout << setw(3) << setfill('0') << times << " "<< name << " " <<
        fighters[current_id - 1] <<
        fighters[current_id] << " " << current_id << " born with "
        "strength " << fighterHp[productOrder[ord_num]] <<
        "," << countFighter(fighters[productOrder[0]]) <<
        " " << fighters[current_id - 1] <<
        " in " << name << " headquarter"
         << endl;

    times++;

    return 0;
}

void ArmyBase::addFighter(string fname)
{
    fighters[current_id++] = fname;

    std::cout << "Fighter:" << fname
              << "added" << std::endl;
}

void ArmyBase::produceArmyBoth(ArmyBase red, ArmyBase blue)
{
    return;
}


int main(int argc, char *argv[])
{
    ArmyBase red_base(3, 4, 5, 6, 7, 50, "red");
    red_base.produceOne();
    red_base.produceOne();
    red_base.produceOne();
    red_base.produceOne();

    ArmyBase blue_base(3, 4, 5, 6, 7, 50, "blue");
    blue_base.produceOne();
    blue_base.produceOne();
    blue_base.produceOne();
    blue_base.produceOne();
    //blue_base.addFighter("bnb");
    // blue_base.print_name();
    // blue_base.print_fighters();

    return 0;
}
