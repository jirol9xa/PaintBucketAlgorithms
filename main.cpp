#include "ActionManager.hpp"
#include "Button.hpp"
#include "Canvas.hpp"
#include "FillToop.hpp"
#include "Render.hpp"
#include "VideoSettings.hpp"
#include <SFML/Graphics.hpp>
#include <assert.h>
#include <iostream>

int main()
{
    using namespace Settings;
    sf::RenderWindow window(sf::VideoMode(width, heigth), window_name);
    ActionManager    mng;

    // Use calloc instead of new for getting zero memory
    uint32_t *display = static_cast<uint32_t *>(calloc(width * heigth, sizeof(uint32_t)));
    assert(display);
    Render render(&window);

    Canvas   canvas({0, 0}, {255, 255, 255}, width * 0.9, heigth * 0.9);
    Button   start_button({width - 50, heigth - 50}, {0, 0, 200});
    FillTool fill;

    // Very bad move, but i don't know how to do it better yet
    fill.setReqDrawFunc(
        [&]()
        {
            // That part used for avoiding warning from linux about unused graphic window
            sf::Event event;
            while (window.pollEvent(event))
                if (event.type == sf::Event::Closed)
                    window.close();

            mng.drawWithoutTools();
            render.draw(display);
            window.display();
            window.clear();
        });

    start_button.connect([&]() -> bool { return fill.toggle(); });

    mng.registerWidget(&start_button);
    mng.registerWidget(&canvas);
    mng.registerView(&render);
    mng.registerPixels(display);
    mng.registerTool(&fill);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Vec2 pos = {sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y};
            mng.onClick(pos, true);
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            Vec2 pos = {sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y};
            mng.onClick(pos, false);
        }

        mng.draw();
        render.draw(display);

        window.display();
        window.clear();
    }

    free(display);
    return 0;
}
