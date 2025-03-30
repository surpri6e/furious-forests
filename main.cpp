#include "main.hpp"

#include "Core/Paths.hpp"
#include "Managers/TexturesManager.hpp"

using namespace std;

int main()
{
	//cout << "Hello CMake." << endl;
	//return 0;
    // create the window
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");

    sf::Clock clock;

    std::uint32_t time = clock.getElapsedTime().asMilliseconds();

    sf::RectangleShape sh;

    //TexturesManager m;

    //std::cout << paths::PATH_TO_TEXTURE;
    

    int posLeft = 0;
    sh.setSize(sf::Vector2f(30, 30));
    sh.setPosition(sf::Vector2f(posLeft, 0));
    sh.setFillColor(sf::Color::Blue);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        time = clock.getElapsedTime().asMilliseconds();
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();

        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        if (time > 10) {
            clock.restart();
            posLeft += 1;
            sh.setPosition(sf::Vector2f(posLeft, 0));
        }

        window.draw(sh);

        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }
}
