#include "main.hpp"

#include "Paths.hpp"
#include "Managers/TexturesManager.hpp"
#include "Menu/Menu.hpp"
#include "Core/General.hpp"

int main() {
    General G("Furious forests");

    // Заново перепроверить всю систему, тем более касаемо парсера настроек

    /*auto g = std::make_unique<General>(General("a"));
    g.*/
    


    //int posLeft = 0;
    //sh.setSize(sf::Vector2f(30, 30));
    //sh.setPosition(sf::Vector2f(posLeft, 0));
    //sh.setFillColor(sf::Color::Blue);

    // run the program as long as the window is open
    //while (window.isOpen())
    //{
        //time = clock.getElapsedTime().asMilliseconds();
        // check all the window's events that were triggered since the last iteration of the loop
        //while (const std::optional event = window.pollEvent())
        //{
            // "close requested" event: we close the window
            //if (event->is<sf::Event::Closed>())
                //window.close();

           // m.showMenu(window);

       // }

        // clear the window with black color
        // ОЧИЩАТЬ КОНСОЛЬ ПРИ КАЖДОМ РЕНДЕРИНГЕ 
        //window.clear(sf::Color::Black);

        //if (time > 10) {
         //   clock.restart();
         //   posLeft += 1;
         //   sh.setPosition(sf::Vector2f(posLeft, 0));
        //}

        //window.draw(sh);

        // draw everything here...
        // window.draw(...);

        // end the current frame
        //window.display();
    //}
}
