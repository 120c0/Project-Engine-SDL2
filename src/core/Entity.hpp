#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <map>
#include <algorithm>

#include "Component.hpp"

using namespace std;

class Entity
{
  public:
    Entity();
  
    // setting and setter
    virtual void add(Component *) noexcept;
    virtual void remove(const string) noexcept;
    virtual void update() noexcept;

    template<typename Type>
    Type* get(const string __name) noexcept {
      if(this->has(__name))
        return dynamic_cast<Type*>(this->components[__name]);
      std::cerr << "Error[get<>()]: '" << __name << "' not found." << std::endl;
      return nullptr;
    }
    // getting and getter
    virtual bool has(const string) const;

    virtual ~Entity();
  private:
    map<const string, Component*> components;
};

#endif