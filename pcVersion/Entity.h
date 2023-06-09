#pragma once

#include "Collider.h"

class Entity{
public:
    Entity();
    ~Entity();

    virtual void render() = 0;
    virtual void renew() {}
    virtual Collider getCollider() { return *collider; }
    virtual void renew(int info, int px) {}
protected:
    Collider* collider;    
};