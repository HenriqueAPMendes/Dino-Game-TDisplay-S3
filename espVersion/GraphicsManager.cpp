#include "GraphicsManager.h"
#include "background.h"
GraphicsManager *GraphicsManager::manager = NULL;

TFT_eSPI tft;  // esp32
TFT_eSprite sprite = TFT_eSprite(&tft);
TFT_eSprite background = TFT_eSprite(&tft);

GraphicsManager::GraphicsManager() {
  tft.init();  // esp32 version
  tft.fillScreen(TFT_BLACK);
  sprite.createSprite(SCREEN_HEIGHT, SCREEN_WIDTH);
  background.createSprite(640, 170);
  background.pushImage(0, 0, 170, 640, backgroundBMP);

  assets = AssetsManager::getInstance();
}

GraphicsManager::~GraphicsManager() {
  AssetsManager::deleteInstance();
  sprite.deleteSprite();
  background.deleteSprite();
}

GraphicsManager *GraphicsManager::getInstance() {
  if (!manager)
    manager = new GraphicsManager();

  return manager;
}

void GraphicsManager::deleteInstance() {
  if (manager)
    delete manager;
}

void GraphicsManager::clear() {
  sprite.fillSprite(TFT_BLACK);  // ESP32 version
  render(0, 0, BACKGROUND);
}

void GraphicsManager::present() {
  sprite.pushSprite(0, 0);
}


// ESP32 version
void GraphicsManager::render(int x, int y, int assetName, int srcX, int srcY) {
  Asset *img = assets->getAsset(assetName);
  sprite.pushImage(y, x, img->getH(), img->getW(), img->getBMP());
}

void GraphicsManager::renderBackground(int dx) {
  sprite.pushSprite(0, 0);
}
