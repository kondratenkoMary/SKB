#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "core/Component/Component.h"
using namespace std;
class ComponentModel
{
private:
    sf::Vector2f localCoord;
    sf::Vector2f size;
    string Name;
    double Angle;
    sf::Uint16 Flag;
    sf::RenderStates __renderstates;
    Component* __component;
public:
    ComponentModel (string name, Component* component);
    void setlocalCoord (int X_coord, int Y_coord);
    void setSize (int A_size, int B_size);
    sf::Vector2f Coord();
    sf::Vector2f Size();
    void setName (string name2);
    string name();
    void setAngle(double angle2);
    double angle();
    void setFlag(sf::Uint16 flag2);
    sf::Uint16 flag();
    void setRenderStates(sf::RenderStates renderstates);
    sf::RenderStates renderstates();
    Component* Owner(); // возвращает модель
    void SetOwner(Component* component); // установить модель

};
