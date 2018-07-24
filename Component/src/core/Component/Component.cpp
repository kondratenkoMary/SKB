#include <iostream>
#include <SFML/Graphics.hpp>
#include "core/Component/ComponentModel.h"
#include "core/Component/ComponentView.h"
#include "core/Component/ComponentController.h"
#include "core/Component/Component.h"
using namespace std;
Component:: Component(string name)
{
    __model = new ComponentModel(name, this);
    __view = new ComponentView(this);
    __controller=new ComponentController(this);
}
Component:: ~Component()
{

}
ComponentModel* Component::Model()
{
    return __model;
}
void Component:: SetModel(ComponentModel* model)
{
    __model = model;
}
ComponentView* Component::View()
{
    return __view;
}
void Component:: SetView(ComponentView* view)
{
    __view=view;
}
ComponentController* Component::Controller()
{
    return __controller;
}
void Component:: SetController(ComponentController* controller)
{
    __controller=controller;
}

