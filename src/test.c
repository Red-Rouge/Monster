#include <stdio.h>
#include <string.h>
// 定义一个结构体
typedef struct Monster
{
    char name[50];
    int ATK;
    int DEF;
    int HP;
    int MP;
    int LV;
} Monster;

int main()
{
    Monster monsters[5];

    // 初始化monsters数组
    for (int i = 0; i < 5; i++)
    {
        monsters[i].ATK = i * 10;
        monsters[i].DEF = i * 20;
        monsters[i].HP = i * 30;
        monsters[i].MP = i * 40;
        monsters[i].LV = i * 50;
        strcpy(monsters[i].name, "Monster ");
    }

    printf("name\t       ATK\tDEF\tHP\tMP\tLV\t\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s\t%d\t%d\t\n", monsters[i].name, monsters[i].ATK, monsters[i].DEF);
    }

    return 0;
}