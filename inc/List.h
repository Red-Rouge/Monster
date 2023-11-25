#ifndef __LIST_H__
#define __LIST_H__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Monster.h"


typedef struct
{
    Monster **monsters;//monster节点指针
    int size;//长度
} __attribute__((packed))   List; //存放了monster的列表

// List默认初始化，length最大存储内存
int list_init(List *list, const int length);
// 新List默认初始化，length最大存储内存，返回一个初始默认化List的地址
List *list_create(const int length);
// List释放
int list_free(List *list);
// 向List的尾部添加数据，monster为monster的地址
int list_add(List *list, Monster *monster);
// 删除list里的数据，name为要删除的monster的名字
int list_del(List *list, const char *name);
// 在List里寻找name的怪兽，没有返回NULL
Monster *list_find(List *list, const char *name);


#endif


