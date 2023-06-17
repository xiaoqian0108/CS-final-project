#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "map.h"
#pragma once

typedef struct _sList
{
    int32_t             size;
    struct _sListNode   *pHead;
    struct _sListNode   *pTail;
} sList;

typedef struct _sListNode
{
    int32_t             data;
    struct _sListNode   *pNext;
} sListNode;

int32_t initList( sList *pList );
int32_t addNode( sList *pList, int32_t val );
//int32_t LongestRoadLength(int32_t player, int32_t currentVertex, int32_t prevVertex, int32_t vertex_neighbor[][3], int32_t line_neighbor[][2], Vertex *ArrayVertex, Line *ArrayLine, int32_t visited_line[]);
int32_t LongestRoad(int32_t player, int32_t line, Vertex *ArrayVertex, Line *ArrayLine);