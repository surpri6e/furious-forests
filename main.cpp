#include "main.hpp"

#include "Core/General.hpp"
#include "Core/Settings.hpp"
#include "Menu/Menu.hpp"
#include "Core/InputsObserver.hpp"

int main() {
    // USE DYNAMIC MEMORY
    auto settings = Settings();
    auto inputsObserver = InputsObserver();

    auto window = sf::RenderWindow(
        sf::VideoMode({ (unsigned int)settings.getWidthWindow(), (unsigned int)settings.getHeightWindow() }),
        "Furious forests",
        settings.getIsWindowFullscreen() ? sf::State::Fullscreen : sf::State::Windowed
    );

    auto G = General(window, settings, inputsObserver);

    auto menu = std::make_unique<Menu>(Menu(G));

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>()) {
                inputsObserver.setMousePositionX(mouseMoved->position.x);
                inputsObserver.setMousePositionY(mouseMoved->position.y);
            }

            if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouseButtonPressed->button == sf::Mouse::Button::Left) inputsObserver.setIsLeftMouseButtonPressed(true);
                if (mouseButtonPressed->button == sf::Mouse::Button::Right) inputsObserver.setIsRightMouseButtonPressed(true);
            }

            if (const auto* mouseButtonReleased = event->getIf<sf::Event::MouseButtonReleased>()) {
                if (mouseButtonReleased->button == sf::Mouse::Button::Left) inputsObserver.setIsLeftMouseButtonPressed(false);
                if (mouseButtonReleased->button == sf::Mouse::Button::Right) inputsObserver.setIsRightMouseButtonPressed(false);
            }

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) inputsObserver.setIsEscapePressed(true);
                if (keyPressed->scancode == sf::Keyboard::Scancode::Enter) inputsObserver.setIsEnterPressed(true);

                if (keyPressed->scancode == sf::Keyboard::Scancode::W) inputsObserver.setIsWPressed(true);
                if (keyPressed->scancode == sf::Keyboard::Scancode::A) inputsObserver.setIsAPressed(true);
                if (keyPressed->scancode == sf::Keyboard::Scancode::S) inputsObserver.setIsSPressed(true);
                if (keyPressed->scancode == sf::Keyboard::Scancode::D) inputsObserver.setIsDPressed(true);

                if (keyPressed->scancode == sf::Keyboard::Scancode::E) inputsObserver.setIsEPressed(true);
            }

            if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
                if (keyReleased->scancode == sf::Keyboard::Scancode::Escape) inputsObserver.setIsEscapePressed(false);
                if (keyReleased->scancode == sf::Keyboard::Scancode::Enter) inputsObserver.setIsEnterPressed(false);

                if (keyReleased->scancode == sf::Keyboard::Scancode::W) inputsObserver.setIsWPressed(false);
                if (keyReleased->scancode == sf::Keyboard::Scancode::A) inputsObserver.setIsAPressed(false);
                if (keyReleased->scancode == sf::Keyboard::Scancode::S) inputsObserver.setIsSPressed(false);
                if (keyReleased->scancode == sf::Keyboard::Scancode::D) inputsObserver.setIsDPressed(false);

                if (keyReleased->scancode == sf::Keyboard::Scancode::E) inputsObserver.setIsEPressed(false);
            }
        }

        // CLEAR ON EVERY RENDER!
        window.clear(sf::Color::Black);

        if (menu.get() != nullptr) {
            menu.get()->showMenu(G);
        }

        // .display() ONLY HERE!
        window.display();
    }
}