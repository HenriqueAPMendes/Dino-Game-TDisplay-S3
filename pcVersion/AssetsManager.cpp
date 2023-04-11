#include "headers/AssetsManager.h"

AssetsManager *AssetsManager::manager = NULL;

AssetsManager::AssetsManager()
{
    Asset *tmpAsset;
    tmpAsset = new Asset("assets/trex.bmp", 54, 54);
    assets.insert(std::make_pair("dino", tmpAsset));
    tmpAsset = new Asset("assets/crouch.bmp", 54, 27);
    assets.insert(std::make_pair("crouch", tmpAsset));
    tmpAsset = new Asset("assets/bird.bmp", 42, 32);
    assets.insert(std::make_pair("bird", tmpAsset));

    tmpAsset = new Asset("assets/menu.bmp", 320, 170);
    assets.insert(std::make_pair("menu", tmpAsset));
    tmpAsset = new Asset("assets/background.bmp", 320, 170);
    assets.insert(std::make_pair("background", tmpAsset));
}

AssetsManager::~AssetsManager()
{
    map<string, Asset *>::iterator i;
    for (i = assets.begin(); i != assets.end(); i++)
    {
        delete i->second;
    }
}

AssetsManager *AssetsManager::getInstance()
{
    if (!manager)
        manager = new AssetsManager();

    return manager;
}

void AssetsManager::deleteInstance()
{
    if (manager)
        delete manager;
}

/*short *AssetsManager::getAsset(string assetName)
{
    return assets[assetName];
}*/
// ESP32 version

Asset *AssetsManager::getAsset(string assetName)
{
    return assets[assetName];
} // PC Version