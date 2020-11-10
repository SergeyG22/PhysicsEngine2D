#pragma once
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Widgets/Button.hpp>
#include "gui.h"
#include "scene.h"
//#include "window_view.h"
#include "b2GLDraw.h"

const float SCALE = 30.f;
const float DEG = 57.29577f;

struct ObjectsEntities {                                          //class for storing objects in the world
    b2Vec2 gravity{ 0.f, 9.8f };
    b2World world{ gravity };
    uint32 FLAGS = 0;
    sf::RenderWindow window{ sf::VideoMode{800,600}, "2D engine", sf::Style::Close | sf::Style::Titlebar };
//    Window_view window_view;
    sf::Clock system_rendering_clock;
    PhysicsPlayer physics_player{ world };
    tgui::GuiSFML GUI{ window };
    Decorative_elements decorative_elements;
    Button_switching_fullscreen button_switching_fullscreen{ GUI };
    Button_screen_mode button_screen_mode{ GUI };
    Button_download_fone button_download_fone{ GUI };
    Combo_box_filepath_fone combo_box_file_path_fone{ GUI };
    Combo_box_invisible_object combo_box_invisible_object{ GUI };
    Combo_box_figure combo_box_figure{ GUI };
    Button_download_texture button_download_texture{ GUI };
    Combo_box_typebody combo_box_type_body{ GUI };
    Combo_box_file_path_texture combo_box_file_path_texture{ GUI };
    Label_settings label_settings{ GUI };
    Combo_box combo_box{ GUI };
    GameBackground game_background;
    GraphicsPlayer graphics_player;
    TransferObjects transfer_objects;
    ObjectsWorld objects_world;
    b2GLDraw debug_draw_instance;
    float time = 0.0;
    ObjectsEntities();
    void create_body(std::list<gobj::ObjectFactory*>::iterator::value_type it, b2Vec2 pos);
};

void enumeration_flags(uint32& flags) {
    flags += b2Draw::e_shapeBit;
    flags += b2Draw::e_jointBit;
    flags += b2Draw::e_aabbBit;
    flags += b2Draw::e_pairBit;
    flags += b2Draw::e_centerOfMassBit;
}

std::string get_typename(std::list<gobj::ObjectFactory*>::iterator::value_type it) {
    std::string str(typeid(*it).name());
    return str;
}

sf::Vector2f get_size_sprite_with_scale(std::list<gobj::ObjectFactory*>::iterator::value_type it) {
    sf::Vector2f vec;
    vec.x = it->get_texture().getSize().x * it->get_sprite().getScale().x;
    vec.y = it->get_texture().getSize().y * it->get_sprite().getScale().y;
    return vec;

}

ObjectsEntities::ObjectsEntities() {
    world.SetDebugDraw(&debug_draw_instance);
    objects_world.to_generate_objects_in_the_world(world);
    enumeration_flags(FLAGS);
    debug_draw_instance.SetFlags(FLAGS);
}

void ObjectsEntities::create_body(std::list<gobj::ObjectFactory*>::iterator::value_type it, b2Vec2 pos) {

    if (get_typename(it) == "class gobj::Rectangle") {
        dynamic_cast<gobj::Rectangle*>(it)->bshape_rect.SetAsBox(get_size_sprite_with_scale(it).x / 2 / SCALE, get_size_sprite_with_scale(it).y / 2 / SCALE);
        dynamic_cast<gobj::Rectangle*>(it)->bdef_rect.position.Set(pos.x, pos.y);
        dynamic_cast<gobj::Rectangle*>(it)->body_rect = world.CreateBody(&dynamic_cast<gobj::Rectangle*>(it)->bdef_rect);
        dynamic_cast<gobj::Rectangle*>(it)->body_rect->CreateFixture(&dynamic_cast<gobj::Rectangle*>(it)->bshape_rect, 5.0);
    }
    else if (get_typename(it) == "class gobj::Circle") {
        dynamic_cast<gobj::Circle*>(it)->bshape_circle.m_radius = get_size_sprite_with_scale(it).x / 2 / SCALE;
        dynamic_cast<gobj::Circle*>(it)->bdef_circle.position.Set(pos.x, pos.y);
        dynamic_cast<gobj::Circle*>(it)->body_circle = world.CreateBody(&dynamic_cast<gobj::Circle*>(it)->bdef_circle);
        dynamic_cast<gobj::Circle*>(it)->body_circle->CreateFixture(&dynamic_cast<gobj::Circle*>(it)->bshape_circle, 5.0);
    }
}
