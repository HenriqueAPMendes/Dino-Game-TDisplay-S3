#pragma once
#include <map>
#include <string>
#include <SDL2/SDL.h>
#include "AssetsManager.h"

using namespace std;

#define SCREEN_WIDTH 320 
#define SCREEN_HEIGHT 170


class GraphicsManager
{
public:
    ~GraphicsManager();

    static GraphicsManager* getInstance();
	static void deleteInstance();

    void render(int x, int y, string assetName, int srcX = 0, int srcY = 0);
    void present(); // PC only
    void clear();
    void addTexture(string path, string assetName);

private:
    GraphicsManager();
    static GraphicsManager* manager;
    AssetsManager* assets;

    //TFT_eSPI tft; // ESP32 version
    SDL_Renderer* renderer; // PC version
    SDL_Window* window; // PC version
    map<string, SDL_Texture*> textures; // PC only
};