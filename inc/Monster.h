#ifndef __MONSTER_H
#define __MONSTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// monster结构体
typedef struct
{
    char *name; //name
    int  ATK; //ATK
    int DEF; //DEF
    int HP; //HP
    int MP; //MP
    int LV; //LV
} __attribute__((packed))  Monster;

// monster默认初始化
int monster_init(Monster *monster);
// monster键盘输入初始化
int monster_scanf(Monster *monster);
// monster设置初始化
int monster_set(Monster *monster, const char *name, const int HP, const int MP, const int ATK, const int DEF, const int LV);
// 新monster默认初始化，返回一个新monster的地址
Monster *monster_new_init();
// 新monster键盘输出初始化，数值从键盘输入，返回一个新monster的地址
Monster *monster_new_scanf();
// 新monster键盘输出初始化，name为怪兽的名字，其它数值自己设置，返回一个新monster的地址
Monster *monster_new_set(const char *name, const int HP, const int MP, const int ATK, const int DEF, const int LV);
// monster释放
int monster_free(Monster *monster);
// monster输出，输出6行数据
int monster_print(const  Monster *monster);
// monster设置名字
void monster_set_name(Monster *monster, const char *name);
// monster设置HP
void monster_set_HP(Monster *monster, const int HP);
// monster设置MP
void monster_set_MP(Monster *monster, const int MP);
// monster设置ATK
void monster_set_ATK(Monster *monster, const int ATK);
// monster设置DEF
void monster_set_DEF(Monster *monster, const int DEF);
// monster设置LV
void monster_set_LV(Monster *monster, const int LV);
// 交换两个monster
int monster_swap(Monster *monster1, Monster *monster2);


#endif


