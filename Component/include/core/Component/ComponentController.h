#pragma once
#include "core/core.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "core/Component/ComponentModel.h"
#include "core/Component/ComponentView.h"
#include "core/Component/Component.h"
class ComponentController
{
public:
    ComponentController(Component* component);
    ~ComponentController();
     Component* Owner(); // возвращает модель
     void SetOwner(Component* component); // установить модель
    bool Handle(sf::Event event); // обработчик событий
private:

    Component* __component;
};
