#include "headers/GraphicsManager.h"
#include "headers/AssetsManager.h"
#include <iostream>
using namespace std;

AssetsManager *assets = AssetsManager::getInstance();

GraphicsManager *GraphicsManager::manager = nullptr;

GraphicsManager::GraphicsManager() {
    SDL_Window *window = SDL_CreateWindow("SLD test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if(!window){
        cout << "Error: Failed to open window\nSDL Error:" << SDL_GetError();
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

GraphicsManager::~GraphicsManager() {

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

GraphicsManager *GraphicsManager::getInstance()
{
    if (!manager)
        manager = new GraphicsManager();

    return manager;
}

void GraphicsManager::deleteInstance()
{
    if (manager)
        delete manager;
}

// PC only
void GraphicsManager::addTexture(string path, string assetName){
    SDL_Surface* tmpSurface = SDL_LoadBMP(path.c_str());
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    if(tex)
        textures.emplace(assetName, tex);
    SDL_FreeSurface(tmpSurface);
}

// PC version
void GraphicsManager::clear()
{
    SDL_RenderClear(renderer);
}

// PC version
void GraphicsManager::render(int x, int y, string assetName)
{
    Asset *img = assets->getAsset(assetName);
    SDL_Texture *tex;

    tex = textures[assetName];
    if (!tex)
    {
        string path = img->getPath();
        addTexture(path, assetName);
        tex = textures[assetName];
    }
    SDL_Rect src = {0, 0, img->getW(), img->getH()};
    SDL_Rect dest = {x, y, img->getW(), img->getH()};
    SDL_RenderCopy(renderer, tex, &src, &dest);
}

/*
// ESP32 version
void GraphicsManager::clear(){
    tft.fillScreen(TFT_BLACK);
} 

// ESP32 version
void GraphicsManager::render(int x, int y, string assetName){
    Asset* img = assets->getAsset(assetName);
    tft.pushImage(x, y, img->getW(), img->getH(), img->getBMP());
}
*/