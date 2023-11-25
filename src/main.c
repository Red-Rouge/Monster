#include <stdio.h>
#include <time.h>
#include <unistd.h>  
#include "Monster.h"
#include "List.h"


int monsters_add(List *monsters);
int monsters_find(List *monsters);
int monsters_del(List *monsters);
int monsters_set(List *monsters);
int monsters_draw(List *monsters);

int main()
{
    List *monsters = list_create(20);
    int status;
    while (1)
    {
        // 输入n的值，并判度是否数去正确
        printf("请选择你要执行的操作：1:添加;2:查询;3:删除;4:修改;5:抽卡;6:退出\n请输入：");
        while (((scanf("%d", &status)) != 1) || status < 1 || status > 9)
        {
            while (getchar() != '\n');
            printf("输入错误，请重新输入\n");
            sleep(1);
            for (int j = 0;j < 3;j++)
            {
                printf("\033[A\033[K");
            }
            printf("请选择你要执行的操作：\n请输入：");
        }
        for (int j = 0;j < 2;j++)
        {
            printf("\033[A\033[K");
        }

        if (status == 1)
        {
            monsters_add(monsters);
        }
        else if (status == 2)
        {
            monsters_find(monsters);
        }
        else if (status == 3)
        {
            monsters_del(monsters);
        }
        else if (status == 4)
        {
            monsters_set(monsters);
        }
        else if (status == 5)
        {
            monsters_draw(monsters);
        }
        else if (status == 6)
        {
            printf("退出程序\n");
            sleep(1);
            break;

        }
    }
    list_free(monsters);
    return 0;
}


int monsters_add(List *monsters)
{
    printf("添加怪物\n");
    sleep(1);
    printf("\033[A\033[K");
    return list_add(monsters, monster_new_scanf());
}

int monsters_find(List *monsters)
{
    // 查找怪兽，并输出
    char *name = (char *)calloc(20, sizeof(char));
    printf("查找怪物\n");
    sleep(1);
    printf("\033[A\033[K");
    printf("请输入要查找的怪物的名字：");
    scanf("%s", name);
    printf("\033[A\033[K");
    if (NULL != list_find(monsters, name))
    {
        monster_print(list_find(monsters, name));
        sleep(3);
        for (int j = 0;j < 6;j++)
        {
            printf("\033[A\033[K");
        }
    }
    else
    {
        sleep(1);
        printf("\033[A\033[K");
    }
    free(name);
    return 0;
}

int monsters_del(List *monsters)
{
    char *name = (char *)calloc(20, sizeof(char));
    printf("删除怪物\n");
    sleep(1);
    printf("\033[A\033[K");
    printf("请输入要删除的怪物的名字：");
    scanf("%s", name);
    printf("\033[A\033[K");
    list_del(monsters, name);
    sleep(1);
    printf("\033[A\033[K");
    free(name);
    return 0;
}

int monsters_set(List *monsters)
{
    char *name = (char *)calloc(20, sizeof(char));
    printf("修改怪物\n");
    sleep(1);
    printf("\033[A\033[K");
    printf("请输入要修改的怪物的名字：");
    scanf("%s", name);
    printf("\033[A\033[K");
    if (NULL != list_find(monsters, name))
    {
        while (1)
        {
            int type = 0;
            printf("请选择你想修改的属性:0:name;1:ATK;2:DEF;3:HP;4:MP;5:LV;6:退出\n请输入：");
            while (((scanf("%d", &type)) != 1) || type < 0 || type > 6)
            {
                while (getchar() != '\n');
                printf("输入错误，退出\n");
                sleep(1);
                for (int j = 0;j < 2;j++)
                {
                    printf("\033[A\033[K");
                }
                return 0;
            }
            for (int j = 0;j < 3;j++)
            {
                printf("\033[A\033[K");
            }
            if (type == 0)
            {
                char *new_name = (char *)calloc(20, sizeof(char));
                printf("请输入新的名字：");
                scanf("%s", new_name);
                printf("\033[A\033[K");
                monster_set_name(list_find(monsters, name), new_name);
                strcpy(name, new_name);
                free(new_name);
            }
            else if (type == 1)
            {
                int new_atk = 0;
                printf("请输入新的攻击力：");
                scanf("%d", &new_atk);
                printf("\033[A\033[K");
                monster_set_ATK(list_find(monsters, name), new_atk);
            }
            else if (type == 2)
            {
                int new_def = 0;
                printf("请输入新的防御力：");
                scanf("%d", &new_def);
                printf("\033[A\033[K");
                monster_set_DEF(list_find(monsters, name), new_def);
            }
            else if (type == 3)
            {
                int new_hp = 0;
                printf("请输入新的血量：");
                scanf("%d", &new_hp);
                printf("\033[A\033[K");
                monster_set_HP(list_find(monsters, name), new_hp);
            }
            else if (type == 4)
            {
                int new_mp = 0;
                printf("请输入新的魔力值：");
                scanf("%d", &new_mp);
                printf("\033[A\033[K");
                monster_set_MP(list_find(monsters, name), new_mp);
            }
            else if (type == 5)
            {
                int new_lv = 0;
                printf("请输入新的等级：");
                scanf("%d", &new_lv);
                printf("\033[A\033[K");
                monster_set_LV(list_find(monsters, name), new_lv);
            }
            else if (type == 6)
            {
                printf("正在退出修改\n");
                sleep(1);
                printf("\033[A\033[K");
                break;
            }
        }

    }
    else
    {
        sleep(1);
        printf("\033[A\033[K");
    }
    free(name);
    return 0;

}

int monsters_draw(List *monsters)
{
    printf("开始抽卡...\n");
    sleep(1);
    printf("\033[A\033[K");
    srand((unsigned)time(NULL));
    for (int i = 0;i < 10 && monsters->size != 0;i++)
    {
        monster_print(monsters->monsters[rand() % monsters->size]);
        usleep(500 * 1000);
        // 每次光标回退一行，并且清除哪一行
        for (int j = 0;j < 6;j++)
        {
            printf("\033[A\033[K");
        }
    }
    return 0;
}










// list_add(monsters, monster_new_set("saber", 10, 20, 30, 40, 50));
// list_add(monsters, monster_new_set("lancer", 60, 60, 80, 90, 100));
// list_add(monsters, monster_new_set("archer", 110, 120, 30, 140, 150));
// list_add(monsters, monster_new_scanf());
// // 删除数据
// // list_del(monsters, "archer");
// // list_del(monsters, "lancer");
// // list_del(monsters, "saber");
// list_del(monsters, "assassin");
// srand((unsigned)time(NULL));
// clock_t start;
// for (int i = 0;i < 10 && monsters->size != 0;i++)
// {
//     monster_print(monsters->monsters[rand() % monsters->size]);
//     start = clock();
//     while ((clock() - start) < 200 * 1000);
//     // 每次光标回退一行，并且清除哪一行
//     for (int j = 0;j < 6;j++)
//     {
//         printf("\033[A\033[K");
//     }
// }

