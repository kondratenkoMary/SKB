#include <iostream>
#include <SFML/Graphics.hpp>
#include "core/Component/ComponentModel.h"
#include "core/Component/ComponentView.h"
ComponentView::ComponentView(Component* component)
{
    __component = component;
}
ComponentView::~ComponentView()
{

}

Component* ComponentView:: Owner() // возвращает модель
{
    return __component;
}
void ComponentView:: SetOwner(Component* component) // установить модель
{
    __component = component;
}
void ComponentView::Render(sf::RenderTarget& target)
{
    sf::Vector2f coord;
    sf::Vector2f size;
    //просто выход пр ипроверке фокуса1
    ComponentModel* model = Owner()->Model();
    coord = Owner()->Model()->LocalCoord();
    // coord = model->Coord();
//  coord=__model->Coord();
    size=model->Size();
    //size=__model->Size();
    sf::RectangleShape rectangle(size);
     if ( Owner()->Model()->GetFlag(FLAG_FOCUS)>0)
    {
        rectangle.setFillColor(sf::Color(0x00000000));// просто прозрачный цвет
        rectangle.setOutlineThickness(1);
        rectangle.setOutlineColor(sf::Color::Green);
    }
    else
        {
        rectangle.setFillColor(sf::Color(0x00000000));
        rectangle.setOutlineThickness(1);
        rectangle.setOutlineColor(sf::Color::White);
        }
    rectangle.setPosition(coord);
    if( Owner()->Model()->GetFlag(FLAG_VISIBLE)==0)
    {
        cout<<"no";
    }else {
    target.draw(rectangle);
    }

}


