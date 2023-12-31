#pragma once
#include "imgui.h"
#include <string>
#include "imgui_impl_win32.h"
#include "imgui_impl_dx10.h"
#include <d3d10_1.h>
#include <d3d10.h>
#include <tchar.h>
#include "Byte.h"
#include "Event.h"


class UI
{
private:
	ID3D10Device* m_g_pd3dDevice = nullptr;;
	IDXGISwapChain* m_g_pSwapChain = nullptr;
	UINT                     m_g_ResizeWidth = 0, m_g_ResizeHeight = 0;
	ID3D10RenderTargetView* m_g_mainRenderTargetView = nullptr;
	HWND m_hwnd;
	WNDCLASSEXW m_wc;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	bool m_openInstructionWindow = false;
	bool m_openHelpWindow = false;
	bool m_pcToDecimal = false;

	bool CreateDeviceD3D();
	void CleanupDeviceD3D();
	void CreateRenderTarget();
	void CleanupRenderTarget();

	Event m_event = Event::NONE;

public:
	bool Run(const Byte mainMemory[], const Byte CPURegister[], std::string IR, int programCounter, char screen);
	char instructions[1000];
	char startAddress[3];
	int inputTaken = 0;

	void DrawMemory(const Byte mainMemory[], int programCounter);
	void ShowMessage(std::string header, std::string message);
	void DrawHelpMenu();
	void DrawRegisters(const Byte CPURegister[]);
	void DrawNewProgramWindow();
	void DrawOptions();
	void DrawPcIR(std::string IR, int programCounter);
	void DrawScreenWindow(char screen);
	void SetEvent(Event event);



	UI(ID3D10Device* g_pd3dDevice, IDXGISwapChain* g_pSwapChain, UINT g_ResizeWidth, UINT g_ResizeHeight,
		ID3D10RenderTargetView* g_mainRenderTargetView, HWND& hWnd, WNDCLASSEXW& wc);
	~UI();

};

