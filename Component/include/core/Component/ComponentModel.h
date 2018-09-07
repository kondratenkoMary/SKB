#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "core/Component/Component.h"
using namespace std;

const int FLAG_FOCUS=1;
const int FLAG_VISIBLE=2;
class ComponentModel
{
    friend ComponentController;
private:
    sf::Vector2f localCoord;
    sf::Vector2f size;
    string Name;
    double Angle;
    sf::Uint16 Flag;
    sf::RenderStates __renderstates;
    Component* __component;
    pComponent __parent;//
    vector<pComponent>children;
public:
    ComponentModel (string name, Component* component);
    void setlocalCoord (int X_coord, int Y_coord);
    void setSize (int A_size, int B_size);
    sf::Vector2f LocalCoord();
    sf::Vector2f Size();
    void setName (string name2);
    string name();
    void setAngle(double angle2);
    double angle();
    void setFlag(sf::Uint16 flag2);
    sf::Uint16 GetFlag(sf::Uint16 flag);
    sf::Uint16 flag();
    void setRenderStates(sf::RenderStates renderstates);
    sf::RenderStates renderstates();
    Component* Owner(); // возвращает модель
    void SetOwner(Component* component); // установить модель
    void setChildren (int index, pComponent child);
    pComponent Children (int index, pComponent child);
    void Add(pComponent child);
    unsigned int Count(int count);
    pComponent Find(string name);
    bool Find (pComponent component);
    void Exclude(pComponent component);
    void Delete(pComponent component);
    void Delete(string  name);
    void SetFlag(const sf::Uint16 flag);
    void ResetFlag (const sf::Uint16 flag);
    sf::Vector2f AbsoluteCoord();
    Component*Parent();
    void SetParent(Component* parent);
};
