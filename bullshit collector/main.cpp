#include <iostream>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Widgets/Button.hpp>
#include "gui.h"
#include "scene.h"
#include "b2GLDraw.h"

std::vector<sf::Vector2u>scr_size{ {800,600},{1020,768},{1280,1020},{1600,1200},{1920,1080} };
 b2Vec2 gravity(0.f, 9.8f);
 b2World world (gravity);
 uint32 FLAGS = 0;
 bool debugging_view = true;


float system_timer(sf::Clock&clock){                       //used for binding to time (not to the processor)
    float t = clock.getElapsedTime().asMicroseconds();
    t = t/8000;
    return t;
}

void enumeration_flags(uint32& flags) {
    flags += b2Draw::e_shapeBit;
    flags += b2Draw::e_jointBit;
    flags += b2Draw::e_aabbBit;
    flags += b2Draw::e_pairBit;
    flags += b2Draw::e_centerOfMassBit;
}

struct ObjectsEntities {                                          //class for storing objects in the world
    sf::RenderWindow window{ sf::VideoMode{800,600}, "2D engine" };
    sf::Clock system_rendering_clock;
    PhysicsPlayer physics_player{ world };
    tgui::GuiSFML GUI{ window };
    SmallEngineGUI small_engine_gui{GUI};
    GameBackground game_background;
    GraphicsPlayer graphics_player;
    TransferObjects transfer_objects;
    ObjectsWorld objects_world;
    b2GLDraw debug_draw_instance;
    float time = 0.0;
    ObjectsEntities();
};

ObjectsEntities::ObjectsEntities() {
    world.SetDebugDraw(&debug_draw_instance);
    objects_world.to_generate_objects_in_the_world(world);
    enumeration_flags(FLAGS);
    debug_draw_instance.SetFlags(FLAGS);
}

void set_screen_resolution(ObjectsEntities& entity) {
    tgui::String screen_size = entity.small_engine_gui.combo_box->getSelectedItem();
    if (screen_size == "800x600")       { entity.window.setSize(scr_size[0]); }
    else if (screen_size == "1024x768") { entity.window.setSize(scr_size[1]); }
    else if (screen_size == "1280x1024"){ entity.window.setSize(scr_size[2]); }
    else if (screen_size == "1600x1200"){ entity.window.setSize(scr_size[3]); }
    else if (screen_size == "1920x1080"){ entity.window.setSize(scr_size[4]); }
}

int main()
{    
    ObjectsEntities entity;
    entity.small_engine_gui.combo_box->onItemSelect(set_screen_resolution,std::ref(entity));

    while (entity.window.isOpen()) {
        entity.time = system_timer(entity.system_rendering_clock);
        sf::Event event;
        while (entity.window.pollEvent(event)) {

            entity.GUI.handleEvent(event);            // event for TGUI

            entity.physics_player.keyboard_interaction(entity.graphics_player);
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Left) {
                    for (auto const& it : entity.objects_world.list_object) {
                        if (static_cast<Rectangle_*>(it)->get_sprite().getGlobalBounds().contains(entity.transfer_objects.get_mouse_coordinte(entity.window).x, entity.transfer_objects.get_mouse_coordinte(entity.window).y)) {
                            entity.transfer_objects.deltaX = entity.transfer_objects.get_mouse_coordinte(entity.window).x - static_cast<Rectangle_*>(it)->get_sprite().getPosition().x;
                            entity.transfer_objects.deltaY = entity.transfer_objects.get_mouse_coordinte(entity.window).y - static_cast<Rectangle_*>(it)->get_sprite().getPosition().y;
                            entity.transfer_objects.can_be_moved = true;
                        }
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.key.code == sf::Mouse::Left)
                    entity.transfer_objects.can_be_moved = false;
            }
        
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Tab) {
                    if (debugging_view) {
                        debugging_view = false;
                    }
                    else {
                        debugging_view = true;
                    }
                }
            }

            if (event.type == sf::Event::Closed)
                entity.window.close();
        }
        
        if (entity.transfer_objects.can_be_moved) {
            for (auto const& it : entity.objects_world.list_object) {
                if (static_cast<Rectangle_*>(it)->get_sprite().getGlobalBounds().contains(entity.transfer_objects.get_mouse_coordinte(entity.window).x, entity.transfer_objects.get_mouse_coordinte(entity.window).y)) {
                    static_cast<Rectangle_*>(it)->get_sprite().setPosition(entity.transfer_objects.get_mouse_coordinte(entity.window).x - entity.transfer_objects.deltaX, entity.transfer_objects.get_mouse_coordinte(entity.window).y - entity.transfer_objects.deltaY);
                    float delta_x = (entity.transfer_objects.get_mouse_coordinte(entity.window).x - entity.transfer_objects.deltaX)/30.f; // дельтаX
                    float delta_y = (entity.transfer_objects.get_mouse_coordinte(entity.window).y - entity.transfer_objects.deltaY)/30.f; // дельтаY                                
                    b2Vec2 vector;
                    vector.x = delta_x - static_cast<Rectangle_*>(it)->x_initial_coordinates_of_the_sprite(); //  получить дельтуX и дельтуY. Вычесть из нее координаты верхнего левого угла спрайта.
                    vector.y = delta_y - static_cast<Rectangle_*>(it)->y_initial_coordinates_of_the_sprite(); //  координаты верхнего угла(x,y) инициализируются один раз (во время компиляции)
                    static_cast<Rectangle_*>(it)->body_rect->SetTransform(vector,0);
                }
            }

        }
        
        world.Step(1/120.f,8,3);
        entity.window.clear();
        entity.window.draw(entity.game_background);
        entity.GUI.draw();
        entity.physics_player.jump(world);
        entity.physics_player.update(entity.window, entity.graphics_player.get_sprite());
        entity.window.draw(static_cast<Rectangle_*>(entity.objects_world.get_object_world(3))->get_sprite());
        entity.window.draw(static_cast<Rectangle_*>(entity.objects_world.get_object_world(4))->get_sprite());
        entity.window.draw(static_cast<Rectangle_*>(entity.objects_world.get_object_world(5))->get_sprite());
        if (debugging_view) {
            world.DebugDraw();
        }
        entity.window.display();
    }
    return 0;
}



                    















