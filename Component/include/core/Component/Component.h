#pragma once
#include <iostream>
#include "core/core.h"
#include <SFML/Graphics.hpp>
#include "core/Component/ComponentModel.h"
#include "core/Component/ComponentView.h"
#include "core/Component/ComponentController.h"
using namespace std;


class Component
{
public:
    Component(string name);
    ~Component();

    ComponentModel* Model(); // возвращает модель
    void SetModel(ComponentModel* model); // установить модель

    ComponentView* View(); // возвращает представление
    void SetView(ComponentView* view); // установить представление

    ComponentController* Controller(); // возвращает контроллер
    void SetController(ComponentController* controller); // установить контроллер
private:
    ComponentModel* __model;
    ComponentController* __controller;
    ComponentView* __view;
};
