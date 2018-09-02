#include<iostream>
#include "core/Component/ComponentModel.h"
#include <SFML/Graphics.hpp>
using namespace std;

ComponentModel::ComponentModel (string name,Component* component)
{
    setlocalCoord( 0,0);
    setSize( 200,100);
    setName(name);
    setAngle(0.0);
    setFlag(0);
    __component = component;
}
Component* ComponentModel:: Owner() // возвращает модель
{
    return __component;
}
void ComponentModel:: SetOwner(Component* component) // установить модель
{
    __component = component;
}
void ComponentModel::setlocalCoord (int X_coord, int Y_coord)
{
    localCoord.x=X_coord;
    localCoord.y=Y_coord;
}
void ComponentModel::setSize (int A_size, int B_size)
{
    size.x=A_size;
    size.y=B_size;
}
sf::Vector2f ComponentModel::LocalCoord()
{
    return localCoord;
}
sf::Vector2f ComponentModel::Size()
{
    return size;
}
void ComponentModel::setName(string name2)
{
    Name=name2;
}
string ComponentModel::name()
{
    return Name;
}
void ComponentModel::setAngle(double angle2)
{
    Angle=angle2;
}
double ComponentModel::angle()
{
    return Angle;
}
void ComponentModel::setFlag(sf::Uint16 flag)
{
    Flag=flag;
}
sf::Uint16 ComponentModel:: GetFlag(sf::Uint16 flag)
{
    return Flag&&flag;//все  нули
}
sf::Uint16 ComponentModel::flag()
{
    return Flag;
}
void ComponentModel::setRenderStates(sf::RenderStates renderstates)
{
    __renderstates = renderstates;
}

sf::RenderStates ComponentModel::renderstates()
{
    return __renderstates;
}

void ComponentModel:: setChildren (int index, pComponent child)
{
    children[index]=child;
}

pComponent ComponentModel::Children (int index, pComponent child)
{
    return children[index];
}
void ComponentModel::Add(pComponent child)    // Добавить потомка
{
    children.push_back(child);
}
unsigned int ComponentModel::Count(int count)// количиество потомков
{
    count=children.size();
}
pComponent ComponentModel::Find(string name) // ищет компонент по имени
{
    for( int i=0; i<children.size(); i++)
    {
        if (children[i]->Model()->name()==name)
        {
            return children[i];
        }
    }
}

bool ComponentModel::Find (pComponent component)
{
    for (int i=0; i<children.size(); i++)
    {
        if (children[i]==component)
        {
            return true;
        }
        else
            return false;
    }
}
void ComponentModel::Exclude(pComponent component)
{
    for (int i=0; i<children.size(); i++)
    {
        if (children[i]==component)
        {
            children.erase(children.begin()+i);
        }
    }
}
void ComponentModel:: Delete(pComponent component)
{
    for (int i=0; i<children.size(); i++)
    {
        if (children[i]==component)
        {
            delete children[i];
            Exclude (children[i]);
        }
    }
}
void ComponentModel::Delete(string  name)
{
    for( int i=0; i<children.size(); i++)
    {
        if (children[i]->Model()->name()==name)
        {
            delete children[i];
            Exclude (children[i]);
        }
    }
}
void ComponentModel::SetFlag(const sf::Uint16 flag)
{
  Flag = Flag | flag;
}

void ComponentModel::ResetFlag(const sf::Uint16 flag)
{
    sf::Uint16 not_flag;
	not_flag = ! flag;
	Flag &= not_flag;
}
