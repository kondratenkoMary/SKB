#include<iostream>
#include "core/Component/ComponentModel.h"
#include <SFML/Graphics.hpp>
#include "core/Component/ComponentView.h"
#include "core/Component/ComponentController.h"
#include "core/Component/Component.h"
using namespace std;
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "sfml");
    Component object("SFML");

    object.Model()->setlocalCoord(100,100);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            object.Controller()->Handle(event);
        }

        window.clear(); //очистка экран
		object.View()->Render(window);
        window.display(); // вывод изображения
    }

    return 0;
}
