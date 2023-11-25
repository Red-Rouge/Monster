#ifndef __MONSTER_H
#define __MONSTER_H

#include <iostream>
#include <string>
#include <cstring>
#include <new>
using namespace std;
class Monster
{
    public:
    string *name;
    int ATK;
    int DEF;
    int HP;
    int MP;
    int LV;
    //默认初始化
    Monster();
    //从键盘获取
    Monster(string name);
    //直接设置
    Monster(string name, int hp, int mp, int atk, int def, int lv);
    ~Monster();
    void set_name(string name);
    void set_hp(int hp);
    void set_mp(int mp);
    void set_atk(int atk);
    void set_def(int def);
    void set_lv(int lv);
    string get_name();
};

ostream &operator<<(ostream &out, Monster &monster);

#endif


