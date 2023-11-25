#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <unistd.h>
#include "Monster.h"
using namespace std;



int main()
{
    vector<Monster *> monsters;
    vector<Monster *>::iterator iter;
    monsters.reserve(100);
    // 存入monsters信息,3只怪兽
    monsters.insert(monsters.begin(), new Monster("Saber", 12, 12, 12, 12, 1));
    monsters.insert(monsters.begin(), new Monster("Lancer", 12, 12, 12, 12, 3));
    monsters.insert(monsters.begin(), new Monster("Archer", 12, 12, 12, 12, 10));
    monsters.insert(monsters.begin(), new Monster("Rider", 12, 12, 12, 12, 2));
    monsters.insert(monsters.begin(), new Monster("Caster", 12, 12, 12, 12, 7));
    monsters.insert(monsters.begin(), new Monster("Assassin", 12, 12, 12, 12, 9));
    monsters.insert(monsters.begin(), new Monster("Berserker", 12, 12, 12, 12, 0));

    // 使用find_if寻找monsters里名字是saber的怪兽
    iter = find_if(monsters.begin(), monsters.end(), [](Monster *monster)
        {
            return monster->get_name() == "Sber";
        });
    // 删除掉
    // monsters.erase(iter);
    // delete *iter;

    if (iter != monsters.end())
    {
        cout << *(*iter) << endl;
        (*iter)->set_atk(100);
        (*iter)->set_def(100);
        (*iter)->set_hp(100);
        (*iter)->set_mp(100);
        (*iter)->set_lv(100);
    }
    else
        cout << "未找到" << endl;
    // 排序
    sort(monsters.begin(), monsters.end(), [](Monster *monster1, Monster *monster2)
        {
            return monster1->LV < monster2->LV;
        });
    for (iter = monsters.begin();iter != monsters.end();iter++)
    {
        cout << *(*iter) << endl;
    }
    // srand((unsigned)time(NULL));
    // clock_t time;
    // for (int i = 0;i < 10;i++)
    // {
    //     time = clock();
    //     if (i != 0)
    //         cout << "\033[7A" << "\033[K";
    //     iter = monsters.begin() + rand() % monsters.size();
    //     cout << *(*iter) << endl;
    //     while ((clock() - time) < 500 * 1000);
    // }
    // 内存全部释放
    for (vector<Monster *>::iterator iter = monsters.begin(); iter != monsters.end(); iter++)
    {
        delete *iter;
    }
    return 0;
}