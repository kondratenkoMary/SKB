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
    Component object2("KEK");
    object.Model()->Add(&object2);
  //  Component object3("lol");

    object.Model()->setlocalCoord(50,50);
   object2.Model()->setlocalCoord(90,90);
   // object3.Model()->setlocalCoord(300,300);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            object.Controller()->Handle(event);
          object2.Controller()->Handle(event);
           // object3.Controller()->Handle(event);
        }

        window.clear(); //очистка экран
        object.Model()->setSize(500,500);
		object.View()->Render(window);
		object2.Model()->setSize(400,400);
		object2.View()->Render(window);
		//object3.Model()->setSize(100,100);
		//object3.View()->Render(window);
        window.display(); // вывод изображения
    }

    return 0;
}
