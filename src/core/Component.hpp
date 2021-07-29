#ifndef COMPONENENT_H
#define COMPONENENT_H

class Entity;

#include <cstring>
#include <iostream>

using namespace std;

class Component
{
  public:
    bool started;
    
    explicit Component(const string);

    virtual void setEntity(Entity*) noexcept;
    virtual Entity* getEntity() noexcept;
    virtual void update() noexcept;
    virtual void start() noexcept;
    virtual const string &getName() const;

    virtual ~Component();
  private:
    Entity *entity;
    string name;
};

#endif