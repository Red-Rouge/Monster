#include "Monster.h"


Monster::Monster()
{
    name = new string("Monster");
    HP = 0;
    MP = 0;
    ATK = 0;
    DEF = 0;
    LV = 0;
}
Monster::Monster(string n)
{
    name = new string("Monster");
    // 从键盘获取其余的数值
    cout << "-------------" << n << "-------------" << endl;
    cout << "请输入" << n << "的HP:";
    cin >> HP;
    cout << "请输入" << n << "的MP:";
    cin >> MP;
    cout << "请输入" << n << "的ATK:";
    cin >> ATK;
    cout << "请输入" << n << "的DEF:";
    cin >> DEF;
    cout << "请输入" << n << "的LV:";
    cin >> LV;
}

Monster::Monster(string n, int hp, int mp, int atk, int def, int lv)
{
    name = new string(n);
    HP = hp;
    MP = mp;
    ATK = atk;
    DEF = def;
    LV = lv;
}


Monster::~Monster()
{
    // cout << get_name() << "已清除" << endl;
    delete name;
}


void Monster::set_name(string n)
{
    delete name;
    name = new string(n);
}

void Monster::set_hp(int hp)
{
    HP = hp;
}
void Monster::set_mp(int mp)
{
    MP = mp;
}
void Monster::set_atk(int atk)
{
    ATK = atk;
}
void Monster::set_def(int def)
{
    DEF = def;
}
void Monster::set_lv(int lv)
{
    LV = lv;
}

string Monster::get_name()
{
    return *name;
}


ostream &operator<<(ostream &out, Monster &monster)
{
    out << "name:" << monster.get_name() << endl;
    out << "ATK:" << monster.ATK << endl;
    out << "DEF:" << monster.DEF << endl;
    out << "LV:" << monster.LV << endl;
    out << "HP:" << monster.HP << endl;
    out << "MP:" << monster.MP << endl;
    return out;
}