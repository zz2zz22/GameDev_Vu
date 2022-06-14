#pragma once
#define DIRECTINPUT_VERSION 0x0800
//Get lib from Dung sample Util header
#include <Windows.h>
#include <signal.h>
#include <string>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include <vector>

#include <codecvt>

#include <d3d10.h>
#include <D3DX10.h>
#include <dinput.h>

namespace GameUtils {
	const unsigned int SCREEN_WIDTH = 320;
	const unsigned int SCREEN_HEIGHT = 240; //Init screen size (change)
	//Used in all entity classes
	const unsigned int MAX_FILE_LINE = 5000;

	//Mainly used in the Game and Sprite class
	extern ID3D10Device* directDevice;
	extern ID3DX10Sprite* spriteHandler;
	//For debugging
	extern ID3DX10Font* font;
	extern void GetFontRect(LPCSTR, RECT*);
	extern void WriteTextToScreen(LPCSTR, RECT*, UINT, D3DXCOLOR); //Use to write text dx10

	extern std::vector<std::string> SplitStr(std::string, std::string = "\t");
	extern std::vector<unsigned int> SplitDigit(unsigned int);

	extern LPCWSTR ToLPCWSTR(std::string);
	extern std::string ToStr(std::wstring&);
}

typedef struct RectFloat { //init a frame rectangle bound size
	float left, top, right, bottom;

	RectFloat() : left(0), top(0), right(0), bottom(0) {}
	RectFloat(float l, float t, float r, float b) : left(l), top(t), right(r), bottom(b) {}
} RECTF;

struct Texture {
	unsigned int width = 0;
	unsigned int height = 0;

	ID3D10Texture2D* texture = nullptr;
	ID3D10ShaderResourceView* resourceView = nullptr;

	//Texture, shader resource view
	Texture(ID3D10Texture2D* tex, ID3D10ShaderResourceView* srView) {
		texture = tex;
		resourceView = srView;

		D3D10_TEXTURE2D_DESC desc;
		texture->GetDesc(&desc);
		width = desc.Width;
		height = desc.Height;
	}

	//Use this to release resources
	//Otherwise, release them individually
	void Release() {
		texture->Release();
		resourceView->Release();
	}
};