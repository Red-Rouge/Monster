#include "List.h"

int list_init(List *list, const int length)
{
    // 判断内存空间是否被开辟
    list->size = 0;
    list->monsters = (Monster **)malloc(sizeof(Monster *) * length);
    // list->monsters = NULL;
    return 0;
}
List *list_create(const int length)
{
    List *list = (List *)malloc(sizeof(List));
    list_init(list, length);
    return list;
}

int list_free(List *list)
{
    for (int i = 0;i < list->size;i++)
    {
        //释放掉monster，包括name
        monster_free(list->monsters[i]);
        list->monsters[i] = NULL;
    }
    free(list->monsters);
    free(list);
    return 0;
}

int list_add(List *list, Monster *monster)
{
    list->monsters[list->size] = monster;
    list->size++;
    return 0;
}

Monster *list_find(List *list, const char *name)
{
    // 遍历list，寻找为name的monster
    for (int i = 0;i < list->size;i++)
    {
        if (strcmp(list->monsters[i]->name, name) == 0)
        {
            return list->monsters[i];
        }
    }
    printf("未找到\n");
    return NULL;
}

int list_del(List *list, const char *name)
{
    for (int i = 0;i < list->size;i++)
    {

        if (strcmp(list->monsters[i]->name, name) == 0)
        {
            // 将这节点的monster的数据转移到后边
            for (int j = i;j < list->size - 1;j++)
            {
                // 交换
                monster_swap(list->monsters[j], list->monsters[j + 1]);
            }
            monster_free(list->monsters[list->size - 1]);
            list->monsters[list->size - 1] = NULL;
            list->size--;
            return 0;
        }
    }
    printf("未找到\n");
    return -1;
}






