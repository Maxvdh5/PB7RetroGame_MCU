#ifndef LEVELDATA_H
#define LEVELDATA_H

#include "config.h"
#include "block.h"
#include <cstdint>

#define LEVEL_COUNT	2

const BLOCKDATA   blockLocations[LEVEL_COUNT][MAX_STATIC_BLOCKS+MAX_DYNAMIC_BLOCKS] = {
// mainemenulevel.bmp
{
{ -1, -1,1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},
{220,200,4},{240,200,4},{260,200,4},{280,200,4},{300,200,4},{320,200,4},{340,200,4},{360,200,4},
{380,200,4},{220,220,4},{240,220,4},{260,220,4},{280,220,4},{300,220,4},{320,220,4},{340,220,4},
{360,220,4},{380,220,4},{220,240,4},{240,240,4},{260,240,4},{280,240,4},{300,240,4},{320,240,4},
{340,240,4},{360,240,4},{380,240,4},{220,260,4},{240,260,4},{260,260,4},{280,260,4},{300,260,4},
{320,260,4},{340,260,4},{360,260,4},{380,260,4},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},
{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},
{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},
{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},
{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},
{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},
{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},
{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},
{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},
{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},
{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},
},
// Level1AFBIT.bmp
{
{ 20,320,1},{ 40,180,2},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},
{  0,  0,3},{  0, 20,3},{  0, 40,3},{  0, 60,3},{140, 60,0},{180, 60,0},{ 20, 80,0},{ 40, 80,0},
{ 60, 80,0},{ 80, 80,0},{100, 80,0},{120, 80,0},{140, 80,0},{180, 80,0},{200, 80,0},{320, 80,0},
{360, 80,0},{420, 80,0},{440, 80,0},{460, 80,0},{520, 80,0},{540, 80,0},{560, 80,0},{220,100,0},
{300,100,0},{240,120,0},{280,120,0},{620,120,0},{460,140,0},{520,140,0},{540,140,0},{560,140,0},
{580,140,0},{600,140,0},{440,160,0},{  0,180,0},{420,180,0},{560,180,0},{ 20,200,0},{ 40,200,0},
{ 60,200,0},{ 80,200,0},{100,200,0},{120,200,0},{140,200,0},{160,200,0},{180,200,0},{360,200,0},
{380,200,0},{400,200,0},{560,200,0},{180,220,0},{560,220,0},{580,220,0},{180,240,0},{460,240,0},
{520,240,0},{180,260,0},{520,260,0},{560,260,0},{580,260,0},{600,260,0},{620,260,0},{200,280,0},
{520,280,0},{220,300,0},{240,300,0},{260,300,0},{280,300,0},{300,300,0},{320,300,0},{340,300,0},
{360,300,0},{380,300,0},{400,300,0},{420,300,0},{520,300,0},{540,300,0},{  0,340,0},{ 20,340,0},
{ 40,340,0},{ 60,340,0},{ 80,340,0},{100,340,0},{120,340,0},{120,360,0},{340,360,0},{380,360,0},
{580,360,0},{600,360,0},{620,360,0},{120,380,0},{320,380,0},{540,380,0},{120,400,0},{120,420,0},
{280,420,0},{500,420,0},{120,440,0},{140,440,0},{220,440,0},{280,440,0},{400,440,0},{460,440,0},
{120,460,0},{140,460,0},{160,460,0},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},
{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},{ -1,-1,-1},
}
};

#endif // LEVELDATA_H
