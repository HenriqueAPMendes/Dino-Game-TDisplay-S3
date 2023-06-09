#include "Cactus.h"
#include "GraphicsManager.h"

// Constructor
Cactus::Cactus(int model) {
  this->model = model;
  switch (model) {
    case CACTUS_MODEL_1:
      collider = new Collider(320, 106, 11, 24);
      break;
    case CACTUS_MODEL_2:
      collider = new Collider(320, 94, 18, 36);
      break;
    case CACTUS_MODEL_3:
      collider = new Collider(320, 94, 50, 36);
      break;
    case CACTUS_MODEL_4:
      collider = new Collider(320, 94, 35, 36);
      break;
    default:
      break;
  }
}

// Destructor
Cactus::~Cactus() {
  delete collider;
}

// Update position based on traveled distance received
void Cactus::update(double dx) {
  collider->x += dx;
}

// Render calling graphics manager
void Cactus::render() {
  switch (model) {
    case CACTUS_MODEL_1:
      GraphicsManager::getInstance()->render(collider->x, collider->y, ASSET_CACTUS1);
      break;
    case CACTUS_MODEL_2:
      GraphicsManager::getInstance()->render(collider->x, collider->y, ASSET_CACTUS2);
      break;
    case CACTUS_MODEL_3:
      GraphicsManager::getInstance()->render(collider->x, collider->y, ASSET_CACTUS3);
      break;
    case CACTUS_MODEL_4:
      GraphicsManager::getInstance()->render(collider->x, collider->y, ASSET_CACTUS4);
      break;
    default:
      break;
  }
}

// Renew based on new height and position
void Cactus::renew(int info, int px) {

  delete collider;

  if (info == 0)
    model = CACTUS_MODEL_1;
  else if (info == 1)
    model = CACTUS_MODEL_2;
  else if (info == 2)
    model = CACTUS_MODEL_3;
  else if (info == 3)
    model = CACTUS_MODEL_4;

  switch (model) {
    case CACTUS_MODEL_1:
      collider = new Collider(px, 106, 11, 24);
      break;
    case CACTUS_MODEL_2:
      collider = new Collider(px, 94, 18, 36);
      break;
    case CACTUS_MODEL_3:
      collider = new Collider(px, 94, 50, 36);
      break;
    case CACTUS_MODEL_4:
      collider = new Collider(px, 94, 35, 36);
      break;
    default:
      break;
  }
}
