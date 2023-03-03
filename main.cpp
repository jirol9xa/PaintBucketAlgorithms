#include "ActionManager.hpp"
#include "Background.hpp"
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
    sf::RenderWindow window(sf::VideoMode(width, height), window_name);
    Render           render(&window);

    Background    back_gr(width, height, {75, 150, 225});
    ActionManager mng(&back_gr);
    Canvas        canvas({0, 0}, {255, 255, 255}, width * 0.9, height * 0.9);
    Button        start_button({width - 50, height - 50}, {0, 0, 200});
    FillTool      fill({225, 150, 75});

    // Colors buttons
    Button orchid({width - 50, 100}, {0xDA, 0x70, 0xD6});
    Button zinnvaldite({width - 50, 150}, {0xEB, 0xC2, 0xAF});

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
            render.draw(mng.getBackground()->pixels_);
            window.display();
            window.clear();
        });
    fill.setReqMouseClickFunc(
        [&]() -> Vec2
        {
            for (;;)
            {
                sf::Event event;
                while (window.pollEvent(event))
                    if (event.type == sf::Event::Closed)
                        window.close();

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) ||
                    sf::Mouse::isButtonPressed(sf::Mouse::Right))
                {
                    Vec2 pos = {sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y};
                    return pos;
                }
            }
        });

    start_button.connect([&]() -> bool { return fill.toggle(); });
    orchid.connect(
        [&]() -> bool
        {
            fill.setColor(orchid.getColor());
            return true;
        });
    zinnvaldite.connect(
        [&]() -> bool
        {
            fill.setColor(zinnvaldite.getColor());
            return true;
        });

    mng.registerWidget(&start_button);
    mng.registerWidget(&orchid);
    mng.registerWidget(&zinnvaldite);
    mng.registerWidget(&canvas);
    mng.registerView(&render);
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
        render.draw(mng.getBackground()->pixels_);

        window.display();
        window.clear();
    }

    return 0;
}
