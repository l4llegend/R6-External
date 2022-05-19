#pragma once 
#include "overlay.h"
#include "def.h"
#include "memory.h"

namespace Settings{
int width;
int height;
float fovx;
float fovy;
}

bool BoxESP = false;

bool showmenu = true;
bool rendering = true;
int frame = 0;
FOverlay* g_overlay;


float ScreenCenterX;
float ScreenCenterY;
uint64_t team_id
uint64_t gameManager;
uint64_t profileManager;
uint64_t entityList;
uint32_t entityCount;
uintptr_t camera;
uint64_t localPlayer;
uint64_t localPawn;
uint64_t localTeam;
uint64_t replicationinfo;
auto world_to_screen;


vec3 localPos;

uint64_t Base = 0;
uintptr_t getPid = 0;