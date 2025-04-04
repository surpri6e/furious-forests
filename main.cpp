#include "main.hpp"

#include "Core/General.hpp"
#include "Core/Settings.hpp"

#include "Menu/Menu.hpp"
#include "Parcers/TexturesSizesParcer.hpp"
#include "Paths.hpp"

int main() {
    Settings settings;
    
    sf::RenderWindow window(
        sf::VideoMode({ (unsigned int)settings.getWidthWindow(), (unsigned int)settings.getHeightWindow() }),
        "Furious forests",
        settings.getIsWindowFullscreen() ? sf::State::Fullscreen : sf::State::Windowed
    );

    auto parcedTexturesSizes = parceTexturesSizes();

    std::cout << parcedTexturesSizes[paths::textures::menu::PLAY_BUTTON].first << parcedTexturesSizes[paths::textures::menu::PLAY_BUTTON].second << std::endl;

    General G(window, settings);

    auto m = std::make_unique<Menu>(Menu(G));
    
    //auto menu = std::make_unique<Menu>(Menu(G));
    decltype(auto) clock = G.getClock();
    float time = clock.getElapsedTime().asSeconds();

    while (window.isOpen()) {

        time = clock.getElapsedTime().asSeconds();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    //window.close();
                    // m.reset();
                }
            }

            if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouseButtonPressed->button == sf::Mouse::Button::Left)
                {
                    m.reset();
                    //std::cout << "the right button was pressed" << std::endl;
                    //std::cout << "mouse x: " << mouseButtonPressed->position.x << std::endl;
                    //std::cout << "mouse y: " << mouseButtonPressed->position.y << std::endl;
                }
            }
        }

        std::cout << time << std::endl;

        window.clear(sf::Color::Blue);

        //menu.get()->showMenu(window);
        if (!(m.get() == nullptr)) {
            m.get()->showMenu(window);
        }

        /*if (time > 5) {
            m.reset();
        }*/


        // Это гарантирует, что не нужнро в функция отрисовки писать .display()
        window.display();

        // clear the window with black color
        // ОЧИЩАТЬ КОНСОЛЬ ПРИ КАЖДОМ РЕНДЕРИНГЕ 
        //window.clear(sf::Color::Blue);

        //if (time > 10) {
         //   clock.restart();
         //   posLeft += 1;
         //   sh.setPosition(sf::Vector2f(posLeft, 0));
        //}

        //window.draw(sh);

        // draw everything here...
        // window.draw(...);

        // end the current frame
        
    }
}
