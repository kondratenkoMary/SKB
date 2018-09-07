#include <iostream>
#include <SFML/Graphics.hpp>
#include "core/core.h"
#include "core/Component/ComponentModel.h"
#include "core/Component/ComponentView.h"
#include "core/Component/ComponentController.h"
ComponentController::ComponentController(Component* component)
{
    __component = component;
}
ComponentController::~ComponentController()
{

}
Component* ComponentController:: Owner() // возвращает модель
{
    return __component;
}
void ComponentController:: SetOwner(Component* component) // установить модель
{
    __component = component;
}

bool ComponentController::Handle(sf::Event event)
{
    bool flag;
    for (int i=0; i<Owner()->Model()->children.size(); i++)
    {
        flag=Owner()->Model()->children[i]->Controller()->Handle(event);
        if (flag)
        {
            break;
        }
    }
    if (flag)
        return true;
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if ( (event.mouseButton.x >=Owner()->Model()->LocalCoord().x) &&
                    (event.mouseButton.y>=Owner()->Model()->LocalCoord().y) &&
                    ( event.mouseButton.x<= Owner()->Model()->LocalCoord().x+Owner()->Model()->Size().x )&&
                    (event.mouseButton.y<= Owner()->Model()->LocalCoord().y+Owner()->Model()->Size().y) )//в прм
            {
                Owner()->Model()->SetFlag(FLAG_FOCUS);
            }
            else
            {
                Owner()->Model()->ResetFlag(FLAG_FOCUS);
            }
        }
    }
 return false;
}
