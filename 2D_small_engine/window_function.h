#pragma once


const float SCALE = 30.f;
const float DEG = 57.29577f;
b2Vec2 gravity(0.f, 9.8f);
b2World world(gravity);
uint32 FLAGS = 0;


void enumeration_flags(uint32& flags) {
    flags += b2Draw::e_shapeBit;
    flags += b2Draw::e_jointBit;
    flags += b2Draw::e_aabbBit;
    flags += b2Draw::e_pairBit;
    flags += b2Draw::e_centerOfMassBit;
}

void get_supported_fullscreen_modes() {
    std::vector<sf::VideoMode>screen_resolution = sf::VideoMode::getFullscreenModes();
    for (const auto& i: screen_resolution) {
        std::cout << i.width<<":"<<i.height<<'\n' ;
    }
}

float system_timer(sf::Clock& clock) {                       //used for binding to time (not to the processor)
    float t = clock.getElapsedTime().asMicroseconds();
    t = t / 8000;
    return t;
}

sf::Vector2f get_size_sprite_with_scale(std::list<gobj::ObjectFactory*>::iterator::value_type it) {
    sf::Vector2f vec;
    vec.x = it->get_texture().getSize().x * it->get_sprite().getScale().x;
    vec.y = it->get_texture().getSize().y * it->get_sprite().getScale().y;
    return vec;
}

std::string get_typename(std::list<gobj::ObjectFactory*>::iterator::value_type it) {
    std::string str(typeid(*it).name());
    return str;
}


void create_body(std::list<gobj::ObjectFactory*>::iterator::value_type it, b2Vec2 pos) {
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

b2Vec2 get_position(std::list<gobj::ObjectFactory*>::iterator::value_type it) {

    if (get_typename(it) == "class gobj::Rectangle") {
        return dynamic_cast<gobj::Rectangle*>(it)->body_rect->GetPosition();
    }
    else if (get_typename(it) == "class gobj::Circle") {
        return dynamic_cast<gobj::Circle*>(it)->body_circle->GetPosition();
    }
}