#include <cstring>
#include <iostream>
#include <string>
#include <iomanip>
// stop point fixed
// need to consider the continue process
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
    int count_proc;             // n timee the produceOne process
    int times;
    string fighters[100];
    string name;
    int productOrder[5];        // base on fighterName
    int fighterHp[5];
    int end;
    int ord_num;
public:
    ArmyBase(int f1hp, int f2hp, int f3hp, int f4hp, int f5hp,
             int o_hp, const string baseName);
    //void produceArmyBoth(ArmyBase , ArmyBase);
    int  countFighter(string fname);
    int produceOne(void);
    void addFighter(string fname);
    void print_name(void) { cout << name << endl; };
    void print_fighters(void);
    void stop_msg(int times_);
    int getEnd(void);
    int getNextOrdNum(int current_ord_num);
};

string ArmyBase::fighterName[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};
//int ArmyBase::times = 0;

int ArmyBase::getEnd(void)
{
    return end;
}

int ArmyBase::getNextOrdNum(int current_ord_num)
{
    int i;
    current_ord_num = current_ord_num % 5;

    for (i = current_ord_num + 1; i < 5; i++) {
        if (originHealth >= fighterHp[i]) {
            return i;
        }
    }

    for (i = 0; i < current_ord_num + 1; i++) {
        if (originHealth >= fighterHp[i]) {
            return i;
        }
    }
    return -1;
}

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
    count_proc = 0;
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
    end = 0;
    ord_num = 0;
}

int ArmyBase::countFighter(string name)
{
    int count = 0;

    for (int i = 0; i < 100; i++) {
        if (fighters[i] == name) {
            count++;
        }
    }

    return count;
}

int ArmyBase::produceOne()
{
    if (end > 0) {
        return 0;
    } else {
        // need a if to jugg if wen can contunie to produce
        count_proc++;
        if (ord_num >= 0){
            originHealth -= fighterHp[productOrder[ord_num]];
            if (originHealth < 0) {
                originHealth += fighterHp[productOrder[ord_num]];
                //count_proc--;
                ord_num = getNextOrdNum(ord_num);
                //produceOne();
            } else {
            fighters[count_proc - 1] = fighterName[productOrder[ord_num]];
            // print out product one state
            cout << setw(3) << setfill('0') << times << " "<< name << " " <<
                fighters[count_proc - 1] <<
                " " << count_proc << " born with "
                "strength " << fighterHp[productOrder[ord_num]] <<
                "," << countFighter(fighterName[productOrder[ord_num]]) <<
                " " << fighters[count_proc - 1] <<
                " in " << name << " headquarter"
                 << endl;
            ord_num = getNextOrdNum(ord_num);
            }
        } else {
            end++;
        }
        if (end == 1) {
            stop_msg(times - 1);
            return -1;
        }
        times++;
    }

    return 0;
}

void ArmyBase::addFighter(string fname)
{
    fighters[count_proc++] = fname;

    std::cout << "Fighter:" << fname
              << "added" << std::endl;
}

void produceArmyBoth(ArmyBase red, ArmyBase blue)
{
    do
    {
        red.produceOne();
        blue.produceOne();
    } while (red.getEnd() <= 0 || blue.getEnd() <= 0);

}

void ArmyBase::stop_msg(int times_)
{
    cout << setw(3) << setfill('0') << times_ + 1 << " " << name <<
        " headquarter stops making warriors" << endl;
}

int main(int argc, char *argv[])
{
    int case_n = 0;
    int fhp[5];
    cin >> case_n;

    for (int i = 1; i <= case_n; i++) {

        int ori_hp;
        cin >> ori_hp;

        for (int j = 0; j < 5; j++) {
            cin >> fhp[j];
        }
        cout << "Case:" << i << endl;
        ArmyBase red_base(fhp[0], fhp[1], fhp[2], fhp[3], fhp[4],
                          ori_hp, "red");

        ArmyBase blue_base(fhp[0], fhp[1], fhp[2], fhp[3], fhp[4],
                           ori_hp, "blue");
        produceArmyBoth(red_base, blue_base);
    }

    // red_base.produceOne();

    return 0;
}
