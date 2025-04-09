#include "main.hpp"

#include "Core/General.hpp"
#include "Core/Settings.hpp"
#include "Menu/Menu.hpp"


int main() {
    Settings settings;
    sf::RenderWindow window(
        sf::VideoMode({ (unsigned int)settings.getWidthWindow(), (unsigned int)settings.getHeightWindow() }),
        "Furious forests",
        settings.getIsWindowFullscreen() ? sf::State::Fullscreen : sf::State::Windowed
    );
    General G(window, settings);

    window.setVisible(true);

    auto menu = std::make_unique<Menu>(Menu(G));

    decltype(auto) clock = G.getClock();
    std::uint32_t time = clock.getElapsedTime().asMilliseconds();

    // Пока без этой переменной не обойтись
    bool justLeftButtonPressed = false;
    while (window.isOpen()) {

        time = clock.getElapsedTime().asMilliseconds();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            /*if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    
                }
            }*/

            if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
            {
                // Этот обработчик нулевого указателя оптимизировать
                if (!(menu.get() == nullptr)) {
                    menu.get()->changeMouseMiniInformation(mouseMoved->position.x, mouseMoved->position.y, justLeftButtonPressed);
                }
            }

            if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouseButtonPressed->button == sf::Mouse::Button::Left)
                {
                    justLeftButtonPressed = true;
                    // Этот обработчик нулевого указателя оптимизировать
                    if (!(menu.get() == nullptr)) {
                        menu.get()->changeMouseMiniInformation(mouseButtonPressed->position.x, mouseButtonPressed->position.y, justLeftButtonPressed);
                    }
                }
            }

            if (const auto* mouseButtonReleased = event->getIf<sf::Event::MouseButtonReleased>())
            {
                if (mouseButtonReleased->button == sf::Mouse::Button::Left)
                {
                    justLeftButtonPressed = false;
                    // Этот обработчик нулевого указателя оптимизировать
                    if (!(menu.get() == nullptr)) {
                        menu.get()->changeMouseMiniInformation(mouseButtonReleased->position.x, mouseButtonReleased->position.y, justLeftButtonPressed);
                    }
                }
            }
        }
        // ОЧИЩАТЬ КОНСОЛЬ ПРИ КАЖДОМ РЕНДЕРИНГЕ 
        window.clear(sf::Color::Black);


        // Этот обработчик нулевого указателя оптимизировать
        if (!(menu.get() == nullptr)) {
            menu.get()->showMenu(G);
        }


        // Это гарантирует, что не нужно в функция отрисовки писать .display()
        window.display();
    }
}