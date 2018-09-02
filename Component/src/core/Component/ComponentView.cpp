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
    ComponentModel* model = Owner()->Model();
    coord = Owner()->Model()->LocalCoord();
   // coord = model->Coord();
 //  coord=__model->Coord();
     size=model->Size();
    //size=__model->Size();

    sf::RectangleShape rectangle(size);
    if ( Owner()->Model()->GetFlag(FLAG_FOCUS)>0)
    {
        rectangle.setFillColor(sf::Color::Green);///
    }else rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(coord);
    target.draw(rectangle);
}
