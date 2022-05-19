#include <windows.h>
#include <iosteam>
#include "memory.h"
#include "overlay.h"
#include "glob.h"
#include "game.h"
#include "def.h"

HWND hGameWnd;
HWND hOverlayWnd;
RECT wndRect;


void Update() {
	while (true) {
	if (GetAsyncKeyState(VK_INSERT) & 1)
		showmenu = !showmenu;
	}
}


static void render(FOverlay* overlay) {
	while (rendering) {
		overlay->begin_scene();
		overlay->clear_scene();
		frame++;
		ESPLoop();
		RenderMenu();
		overlay->end_scene();
	}
}

static void _init(FOverlay* overlay) {
	if (!overlay->window_init()) {
		printf("[!] Error init overlay window\n");
		Sleep(5000);
		return;
	}
	else {
		printf("[+] init overlay window\n");
	}

	if (!overlay->init_d2d())
		return;

	std::thread r(render, overlay);
	std::thread up(Update);
	r.join();
	up.detach();
	dscdsc.detach();

	overlay->d2d_shutdown();

	return;
}

int main() {
	SetConsoleTitle("Spectra R6");

	Memory::getPid("RainbowSix.exe");
	Base = (uintptr_t)Memory::FindModuleBase("RainbowSix.exe");

	FUCKBE();

	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	HDC monitor = GetDC(hDesktop);
	int current = GetDeviceCaps(monitor, VERTRES);
	int total = GetDeviceCaps(monitor, DESKTOPVERTRES);
	ScreenCenterX = GetSystemMetrics(SM_CXSCREEN) / 2;
	ScreenCenterY = GetSystemMetrics(SM_CYSCREEN) / 2;
	g_overlay = { 0 };
	_init(g_overlay);
}