#include "Cactus.h"
#include "GraphicsManager.h"
#include <iostream>
using namespace std;


Cactus::Cactus(int model)
{
    this->model = model;
    switch (model)
    {
    case CACTUS_MODEL_1:
        collider = new Collider(320, 106, 11, 24);
        break;
    case CACTUS_MODEL_2:
        collider = new Collider(320, 90, 18, 36);
        break;
    case CACTUS_MODEL_3:
        collider = new Collider(320, 90, 50, 36);
        break;
    case CACTUS_MODEL_4:
        collider = new Collider(320, 90, 35, 36);
        break;
    default:
        break;
    }
    initialPosition = 320;
}

Cactus::~Cactus()
{
    delete collider;
}

void Cactus::update(double dx) 
{
    collider->x = initialPosition + dx;
    render();
}



void Cactus::render()
{
    switch (model)
    {
    case CACTUS_MODEL_1:
        GraphicsManager::getInstance()->render(collider->x, collider->y, CACTUS1);
        break;
    case CACTUS_MODEL_2:
        GraphicsManager::getInstance()->render(collider->x, collider->y, CACTUS2);
        break;
    case CACTUS_MODEL_3:
        GraphicsManager::getInstance()->render(collider->x, collider->y, CACTUS3);
        break;
    case CACTUS_MODEL_4:
        GraphicsManager::getInstance()->render(collider->x, collider->y, CACTUS4);
        break;
    default:
        break;
    }
}

void Cactus::renew()
{
   
    delete collider;
    int x = rand() % 4;
    if (x == 0)
        model = CACTUS_MODEL_1;
    if (x == 1)
        model = CACTUS_MODEL_2;
    if (x == 2)
        model = CACTUS_MODEL_3;
    if (x == 3)
        model = CACTUS_MODEL_4;
    switch (model)
    {
    case CACTUS_MODEL_1:
        collider = new Collider(320, 106, 11, 24);
        break;
    case CACTUS_MODEL_2:
        collider = new Collider(320, 90, 18, 36);
        break;
    case CACTUS_MODEL_3:
        collider = new Collider(320, 90, 50, 36);
        break;
    case CACTUS_MODEL_4:
        collider = new Collider(320, 90, 35, 36);
        break;
    default:
        break;
    }
    initialPosition += rand()%100 + SCREEN_WIDTH;
}
