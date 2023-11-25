#include "Monster.h"
int monster_init(Monster *monster)
{
    monster->name = (char *)calloc(20, sizeof(char));//开辟monster的name的内存
    strcpy(monster->name, "Monster");
    monster->HP = 0;
    monster->MP = 0;
    monster->ATK = 0;
    monster->DEF = 0;
    monster->LV = 0;
    return 0;
}

int monster_scanf(Monster *monster)
{
    monster->name = (char *)calloc(20, sizeof(char));
    printf("输入怪兽的名字：");
    scanf("%s", monster->name);
    printf("\033[A\033[K");
    printf("------%s----------\n", monster->name);
    printf("输入%s的攻击力：", monster->name);
    while ((scanf("%d", &monster->ATK)) != 1)
    {
        while (getchar() != '\n');
        printf("输入错误，请重新输入\n");
        usleep(500 * 1000);
        for (int j = 0;j < 2;j++)
        {
            printf("\033[A\033[K");
        }
        printf("输入%s的攻击力：", monster->name);
    }
    printf("输入%s的防御力：", monster->name);
    while ((scanf("%d", &monster->DEF)) != 1)
    {
        while (getchar() != '\n');
        printf("输入错误，请重新输入\n");
        usleep(500 * 1000);
        for (int j = 0;j < 2;j++)
        {
            printf("\033[A\033[K");
        }
        printf("输入%s的防御力：", monster->name);
    }
    printf("输入%s的生命值：", monster->name);
    while ((scanf("%d", &monster->HP)) != 1)
    {
        while (getchar() != '\n');
        printf("输入错误，请重新输入\n");
        usleep(500 * 1000);
        for (int j = 0;j < 2;j++)
        {
            printf("\033[A\033[K");
        }
        printf("输入%s的生命值：", monster->name);
    }
    printf("输入%s的魔力值：", monster->name);
    while ((scanf("%d", &monster->MP)) != 1)
    {
        while (getchar() != '\n');
        printf("输入错误，请重新输入\n");
        usleep(500 * 1000);
        for (int j = 0;j < 2;j++)
        {
            printf("\033[A\033[K");
        }
        printf("输入%s的魔力值：", monster->name);
    }
    printf("输入%s的等级：", monster->name);
    while ((scanf("%d", &monster->LV)) != 1)
    {
        while (getchar() != '\n');
        printf("输入错误，请重新输入\n");
        usleep(500 * 1000);
        for (int j = 0;j < 2;j++)
        {
            printf("\033[A\033[K");
        }
        printf("输入%s的等级：", monster->name);
    }
    for (int i = 0;i < 6;i++)
        printf("\033[A\033[K");
    return 0;
}
int monster_set(Monster *monster, const char *name, const int HP, const int MP, const int ATK, const int DEF, const int LV)
{
    monster->name = (char *)calloc(20, sizeof(char));
    strcpy(monster->name, name);
    monster->HP = HP;
    monster->MP = MP;
    monster->ATK = ATK;
    monster->DEF = DEF;
    monster->LV = LV;
    return 0;
}

Monster *monster_new_init()
{
    Monster *monster = (Monster *)calloc(1, sizeof(Monster));
    monster_init(monster);
    return monster;
}

Monster *monster_new_scanf()
{
    Monster *monster = (Monster *)calloc(1, sizeof(Monster));
    monster_scanf(monster);
    return monster;
}

Monster *monster_new_set(const char *name, const int HP, const int MP, const int ATK, const int DEF, const int LV)
{
    Monster *monster = (Monster *)calloc(1, sizeof(Monster));
    monster_set(monster, name, HP, MP, ATK, DEF, LV);
    return monster;
}

int monster_free(Monster *monster)
{
    printf("Free %s\n", monster->name);
    free(monster->name);
    free(monster);
    return 0;
}


int monster_print(const Monster *monster)
{
    if (monster == NULL)
        return -1;
    printf("------%s----------\n", monster->name);
    printf("HP: %d\n", monster->HP);
    printf("MP: %d\n", monster->MP);
    printf("ATK: %d\n", monster->ATK);
    printf("DEF: %d\n", monster->DEF);
    printf("LV: %d\n", monster->LV);
    return 0;
}



void monster_set_name(Monster *monster, const char *name)
{
    free(monster->name);
    monster->name = (char *)calloc(20, sizeof(char));
    strcpy(monster->name, name);
}
void monster_set_HP(Monster *monster, const int HP)
{
    monster->HP = HP;
}
void monster_set_MP(Monster *monster, const int MP)
{
    monster->MP = MP;
}
void monster_set_ATK(Monster *monster, const int ATK)
{
    monster->ATK = ATK;
}
void monster_set_DEF(Monster *monster, const int DEF)
{
    monster->DEF = DEF;
}
void monster_set_LV(Monster *monster, const int LV)
{
    monster->LV = LV;
}


int monster_swap(Monster *monster1, Monster *monster2)
{
    Monster *temp = (Monster *)calloc(1, sizeof(Monster));
    monster_set(temp, monster1->name, monster1->HP, monster1->MP, monster1->ATK, monster1->DEF, monster1->LV);
    // 交换
    monster_set_name(monster1, monster2->name);
    monster_set_HP(monster1, monster2->HP);
    monster_set_MP(monster1, monster2->MP);
    monster_set_ATK(monster1, monster2->ATK);
    monster_set_DEF(monster1, monster2->DEF);
    monster_set_LV(monster1, monster2->LV);

    monster_set_name(monster2, temp->name);
    monster_set_HP(monster2, temp->HP);
    monster_set_MP(monster2, temp->MP);
    monster_set_ATK(monster2, temp->ATK);
    monster_set_DEF(monster2, temp->DEF);
    monster_set_LV(monster2, temp->LV);

    free(temp->name);
    free(temp);
    return 0;
}
