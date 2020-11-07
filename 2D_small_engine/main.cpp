#include <iostream>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Widgets/Button.hpp>
#include <boost/filesystem.hpp>
#include "gui.h"
#include "scene.h"
#include "b2GLDraw.h"


std::vector<sf::Vector2u>scr_size{ {800,600},{1020,768},{1280,1020},{1600,1200},{1920,1080} };
 b2Vec2 gravity(0.f, 9.8f);
 b2World world (gravity);
 uint32 FLAGS = 0;
 bool debugging_view = false;
 const float SCALE = 30.f;
 const float DEG = 57.29577f;

std::string get_typename(std::list<gobj::ObjectFactory*>::iterator::value_type it);

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
    sf::RenderWindow window{ sf::VideoMode{800,600}, "2D engine", sf::Style::Close | sf::Style::Titlebar };
    sf::Clock system_rendering_clock;
    PhysicsPlayer physics_player{ world };
    tgui::GuiSFML GUI{ window };
    Decorative_elements decorative_elements;
    Button_fullscreen_mode button_fullscreen_mode{ GUI };
    Button_download_fone button_download_fone{ GUI};
    Combo_box_filepath_fone combo_box_file_path_fone{ GUI };
    Combo_box_invisible_object combo_box_invisible_object{ GUI};
    Combo_box_figure combo_box_figure { GUI };
    Button_download_texture button_download_texture { GUI };
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
};

ObjectsEntities::ObjectsEntities() {
    world.SetDebugDraw(&debug_draw_instance);
    objects_world.to_generate_objects_in_the_world(world);
    enumeration_flags(FLAGS);
    debug_draw_instance.SetFlags(FLAGS);
}

void set_window_center_of_screen(ObjectsEntities& entity) {
    auto desktop = sf::VideoMode::getDesktopMode();
    sf::Vector2i pos;
    pos.x = desktop.width / 2 - entity.window.getSize().x / 2;
    pos.y = desktop.height / 2 - entity.window.getSize().y / 2;
    entity.window.setPosition(pos);
}

void call_offset(ObjectsEntities& entity,std::string size) {
    entity.button_fullscreen_mode.set_offset(size);
    entity.button_download_fone.set_offset(size);
    entity.combo_box_file_path_fone.set_offset(size);
    entity.combo_box_invisible_object.set_offset(size);
    entity.combo_box_figure.set_offset(size);
    entity.button_download_texture.set_offset(size);
    entity.combo_box_type_body.set_offset(size);
    entity.combo_box_file_path_texture.set_offset(size);
    entity.label_settings.set_offset(size);
    entity.combo_box.set_offset(size);
}

void set_screen_resolution(ObjectsEntities& entity) {
    tgui::String screen_size = entity.combo_box.combo_box->getSelectedItem();
    std::string size = screen_size.toAnsiString();
        if (screen_size=="800x600") {
                entity.window.setSize(scr_size[0]);
                set_window_center_of_screen(entity); 
                call_offset(entity,size);
        }
        
        else if (screen_size=="1024x768") {
                entity.window.setSize(scr_size[1]);
                set_window_center_of_screen(entity);                
                call_offset(entity,size);
        }
       
        else if (screen_size=="1280x1024") {
                entity.window.setSize(scr_size[2]);
                set_window_center_of_screen(entity);
                call_offset(entity,size);
        }
        else  if (screen_size=="1600x1200") {
                entity.window.setSize(scr_size[3]);
                set_window_center_of_screen(entity);
                call_offset(entity,size);              
        }
        else if (screen_size=="1920x1080") {
                entity.window.setSize(scr_size[4]);
                set_window_center_of_screen(entity);
                call_offset(entity,size);
        }   
}

void set_fullscreen_viewport(ObjectsEntities& entity) {

    if (entity.button_fullscreen_mode.enable_fullscreen) {
        entity.window.create(sf::VideoMode(1900, 1080), "2D engine", sf::Style::Fullscreen);
        sf::View view_port;
        view_port.setViewport(sf::FloatRect(0.f, 0.f, 1.25f, 1.65f));
        entity.window.setView(view_port);
        set_screen_resolution(entity);
        entity.button_fullscreen_mode.button_fullscreen_mode->setText(L"Оконный режим");
        entity.button_fullscreen_mode.enable_fullscreen = false;
    }
    else {
        entity.window.create(sf::VideoMode(800, 600), "2D engine", sf::Style::Close | sf::Style::Titlebar);
        set_screen_resolution(entity);
        entity.button_fullscreen_mode.button_fullscreen_mode->setText(L"Экранный режим");
        entity.button_fullscreen_mode.enable_fullscreen = true;
    }

 // get_supported_fullscreen_modes();  //disabled (used only for displaying information)
}

void set_new_fone(ObjectsEntities& entity) {
    entity.game_background.upload_background("background/"+entity.combo_box_file_path_fone.combo_box_file_path_fone->getSelectedItem().toAnsiString());
}

void get_supported_fullscreen_modes() {
    std::vector<sf::VideoMode> screenResolution = sf::VideoMode::getFullscreenModes();
    for (std::size_t i = 0; i < screenResolution.size(); ++i) {
        std::cout << screenResolution[i].width << ":" << screenResolution[i].height << std::endl;
    }
}

void show_widgets(ObjectsEntities& entity, bool state) {
    entity.decorative_elements.menu_view = state;
    entity.button_download_texture.button_download_texture->setVisible(state);
    entity.button_download_fone.button_download_fone->setVisible(state);
    entity.button_fullscreen_mode.button_fullscreen_mode->setVisible(state);
    entity.combo_box.combo_box->setVisible(state);
    entity.combo_box_figure.combo_box_figure->setVisible(state);
    entity.combo_box_file_path_fone.combo_box_file_path_fone->setVisible(state);
    entity.combo_box_invisible_object.combo_box_invisible_object->setVisible(state);
    entity.combo_box_file_path_texture.combo_box_file_path_texture->setVisible(state);
    entity.combo_box_type_body.combo_box_type_body->setVisible(state);
}

void add_object_to_world(ObjectsEntities& entity) {

        int id_type_body = entity.combo_box_type_body.combo_box_type_body->getSelectedItemId().toInt();
        int id_visible_object = entity.combo_box_invisible_object.combo_box_invisible_object->getSelectedItemId().toInt();

        std::string path = "resources/" + entity.combo_box_file_path_texture.combo_box_file_path_texture->getSelectedItem().toAnsiString();
        sf::Texture texture;                                   //temporary texture for getting width and height
        if (!texture.loadFromFile(path)) {
            std::cout << "The texture path is not correct\n";
        }
        sf::Vector2u object_size = texture.getSize();
        
        switch (id_type_body) 
        {
        case 1: {
            entity.objects_world.list_object.push_back(new gobj::Rectangle(world, object_size.x, object_size.y, 350, 200, path, b2_staticBody, id_visible_object));
            break;
           }
        case 2: {
            entity.objects_world.list_object.push_back(new gobj::Rectangle(world, object_size.x, object_size.y, 350, 200, path, b2_dynamicBody, id_visible_object));
            break;
           }
        }

}

sf::Vector2f get_size_sprite_with_scale(std::list<gobj::ObjectFactory*>::iterator::value_type it){
    sf::Vector2f vec;
    vec.x = it->get_texture().getSize().x * it->get_sprite().getScale().x;
    vec.y = it->get_texture().getSize().y * it->get_sprite().getScale().y;
    return vec;  
}

void create_body(std::list<gobj::ObjectFactory*>::iterator::value_type it,b2Vec2 pos) {

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

void update_combo_box_items(ObjectsEntities& entity) {
    entity.combo_box_file_path_texture.set_options_texture();
}

void events_called_by_widgets(ObjectsEntities& entity) {
    entity.combo_box.combo_box->onItemSelect(set_screen_resolution, std::ref(entity));
    entity.button_fullscreen_mode.button_fullscreen_mode->onClick(set_fullscreen_viewport, std::ref(entity));
    entity.button_download_fone.button_download_fone->onClick(set_new_fone, std::ref(entity));
    entity.button_download_texture.button_download_texture->onClick(add_object_to_world, std::ref(entity));
    entity.combo_box_file_path_texture.combo_box_file_path_texture->onMouseEnter(update_combo_box_items, std::ref(entity));
}

std::string get_typename(std::list<gobj::ObjectFactory*>::iterator::value_type it) {
    std::string str(typeid(*it).name());
    return str;
}



int main()
{        
    setlocale(LC_ALL, "russian");
    ObjectsEntities entity;
    events_called_by_widgets(entity);


    while (entity.window.isOpen()) {
        entity.time = system_timer(entity.system_rendering_clock);
        sf::Event event;
        while (entity.window.pollEvent(event)) {
            entity.GUI.handleEvent(event);            // event for TGUI
            entity.physics_player.keyboard_interaction(entity.graphics_player);
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.key.code == sf::Mouse::Left) {
                        for (auto const& it : entity.objects_world.list_object) {
                            sf::Vector2f mouse_coord;
                            mouse_coord.x = entity.transfer_objects.get_mouse_coordinte(entity.window).x;
                            mouse_coord.y = entity.transfer_objects.get_mouse_coordinte(entity.window).y;
                            if (it->get_sprite().getGlobalBounds().contains(mouse_coord.x, mouse_coord.y)) {
                                entity.transfer_objects.deltaX = mouse_coord.x - it->get_sprite().getPosition().x;
                                entity.transfer_objects.deltaY = mouse_coord.y - it->get_sprite().getPosition().y;
                                entity.transfer_objects.can_be_moved = true;
                                
                                if (get_typename(it) == "class gobj::Rectangle") {
                                     dynamic_cast<gobj::Rectangle*>(it)->body_rect->SetGravityScale(0.0);
                                 }
                                else if (get_typename(it) == "class gobj::Circle") {
                                    dynamic_cast<gobj::Circle*>(it)->body_circle->SetGravityScale(0.0);
                                }


                             //   dynamic_cast<gobj::Rectangle*>(it)->body_rect->SetGravityScale(0.0);
                            //    dynamic_cast<gobj::Circle*>(it)->body_circle->SetGravityScale(0.0);
                            }
                        }
                    }
                }
                             
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.key.code == sf::Mouse::Left) {
                    entity.transfer_objects.can_be_moved = false;
                    
                    for (auto const& it : entity.objects_world.list_object) {

                        if (get_typename(it) == "class gobj::Rectangle") {
                            dynamic_cast<gobj::Rectangle*>(it)->body_rect->SetGravityScale(1.0);
                        }
                        else if (get_typename(it) == "class gobj::Circle") {
                            dynamic_cast<gobj::Circle*>(it)->body_circle->SetGravityScale(1.0);
                        }


                       //    dynamic_cast<gobj::Circle*>(it)->body_circle->SetGravityScale(1.0);
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Right) {
                    for (auto const& it : entity.objects_world.list_object) {
                        if (it->get_sprite().getGlobalBounds().contains(entity.transfer_objects.get_mouse_coordinte(entity.window).x, entity.transfer_objects.get_mouse_coordinte(entity.window).y)) {
                            if (it->get_sprite().getColor() == sf::Color::Red) {
                                it->get_sprite().setColor(sf::Color::White);
                            }
                            else {
                                it->get_sprite().setColor(sf::Color::Red);
                            }

                        }
                    }

                }
            }


            if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                      for (auto const& it : entity.objects_world.list_object) {
                        if (it->get_sprite().getGlobalBounds().contains(entity.transfer_objects.get_mouse_coordinte(entity.window).x, entity.transfer_objects.get_mouse_coordinte(entity.window).y)) {
                               if (event.mouseWheelScroll.delta > 0) {
                                  sf::Vector2f scale = it->get_sprite().getScale();
                                  scale.x += 0.1;
                                  scale.y += 0.1;
                                  it->get_sprite().setScale(scale);                                                               
                                  b2Vec2 pos = get_position(it);
                                  if (get_typename(it) == "class gobj::Rectangle") {
                                      world.DestroyBody(dynamic_cast<gobj::Rectangle*>(it)->body_rect);
                                  }
                                  else if (get_typename(it) == "class gobj::Circle") {
                                      world.DestroyBody(dynamic_cast<gobj::Circle*>(it)->body_circle);
                                  }

                               //   world.DestroyBody(dynamic_cast<gobj::Rectangle*>(it)->body_rect);
                                  create_body(it,pos);    
                               }
                               else if (event.mouseWheelScroll.delta < 0) {
                                   sf::Vector2f scale = it->get_sprite().getScale();
                                   scale.x -= 0.1;
                                   scale.y -= 0.1;
                                   it->get_sprite().setScale(scale);
                                   b2Vec2 pos = get_position(it);
                                   if (get_typename(it) == "class gobj::Rectangle") {
                                       world.DestroyBody(dynamic_cast<gobj::Rectangle*>(it)->body_rect);
                                   }
                                   else if (get_typename(it) == "class gobj::Circle") {
                                       world.DestroyBody(dynamic_cast<gobj::Circle*>(it)->body_circle);
                                   }
                                
                               //    world.DestroyBody(dynamic_cast<gobj::Rectangle*>(it)->body_rect);
                                   create_body(it,pos);
                               }
                        }

                      }
                  }

              }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Middle) {
                    for (const auto& it : entity.objects_world.list_object) {
                        sf::Vector2f mouse_coord;
                        mouse_coord.x = entity.transfer_objects.get_mouse_coordinte(entity.window).x;
                        mouse_coord.y = entity.transfer_objects.get_mouse_coordinte(entity.window).y;
                        if (it->get_sprite().getGlobalBounds().contains(mouse_coord.x,mouse_coord.y)) {                          
                            it->update_position(entity.window, it->set_angle(6));
                        }

                    }

                }
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Delete) {
                    for (int i = 0; i < entity.objects_world.list_object.size(); ++i)
                        if (entity.objects_world.get_object_world(i)->get_sprite().getGlobalBounds().contains(entity.transfer_objects.get_mouse_coordinte(entity.window).x, entity.transfer_objects.get_mouse_coordinte(entity.window).y)) {
                            if (entity.objects_world.get_object_world(i)->get_sprite().getColor() == sf::Color::Red) {
                                if (get_typename(entity.objects_world.get_object_world(i)) == "class gobj::Rectangle") {
                                    world.DestroyBody(dynamic_cast<gobj::Rectangle*>(entity.objects_world.get_object_world(i))->body_rect); // dynamic maybe remove
                                    auto it = entity.objects_world.list_object.begin();
                                    std::advance(it, i);
                                    entity.objects_world.list_object.erase(it);
                                }
                                else if (get_typename(entity.objects_world.get_object_world(i)) == "class gobj::Circle") {
                                    world.DestroyBody(dynamic_cast<gobj::Circle*>(entity.objects_world.get_object_world(i))->body_circle); // dynamic maybe remove
                                    auto it = entity.objects_world.list_object.begin();
                                    std::advance(it, i);
                                    entity.objects_world.list_object.erase(it);
                                }

                            }

                        }
                }
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
  
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Tilde) {
                    if (entity.decorative_elements.menu_view) {
                        show_widgets(entity,false);
                    }
                    else {
                        show_widgets(entity, true);
                    }
                }

            }
                     
            if (event.type == sf::Event::Closed)
                entity.window.close();
        }

        if (entity.transfer_objects.can_be_moved) {           
            for (auto const& it : entity.objects_world.list_object) {
                 sf::Vector2f coord;
                 coord.x = entity.transfer_objects.get_mouse_coordinte(entity.window).x;
                 coord.y = entity.transfer_objects.get_mouse_coordinte(entity.window).y;
                 sf::Vector2f del;
                 del.x = entity.transfer_objects.deltaX;
                 del.y = entity.transfer_objects.deltaY;

                if (it->get_sprite().getGlobalBounds().contains(coord.x,coord.y)) {
                    it->get_sprite().setPosition(coord.x - del.x, coord.y - del.y);
                    b2Vec2 delta;
                    delta.x = (coord.x - del.x) / SCALE; 
                    delta.y = (coord.y - del.y) / SCALE; 
                    b2Vec2 vector;
                    vector.x = delta.x - it->upperleft_coord_sprite().x;
                    vector.y = delta.y - it->upperleft_coord_sprite().y;
                    if (get_typename(it) == "class gobj::Rectangle") {
                        dynamic_cast<gobj::Rectangle*>(it)->body_rect->SetTransform(vector, it->get_angle() / DEG);
                        dynamic_cast<gobj::Rectangle*>(it)->body_rect->SetAwake(true);
                    }
                    else if (get_typename(it) == "class gobj::Circle") {
                        dynamic_cast<gobj::Circle*>(it)->body_circle->SetTransform(vector, it->get_angle() / DEG);
                        dynamic_cast<gobj::Circle*>(it)->body_circle->SetAwake(true);
                    }

                }

            }

        }


    world.Step(1/120.f, 8, 3);
    entity.window.clear();    
    entity.window.draw(entity.game_background);   
    entity.physics_player.jump(world);
    entity.physics_player.update(entity.window, entity.graphics_player.get_sprite());
    
        for (auto const& it : entity.objects_world.list_object) {
            it->update_position(entity.window);        
        }

    if (debugging_view) {
        world.DebugDraw();
    }
    entity.window.draw(entity.decorative_elements.DisplayingItemRectangleShape.RectangleShape);

    if (entity.decorative_elements.menu_view) {
        entity.window.draw(entity.decorative_elements.get_sprite_fone());
    }

   


    entity.GUI.draw();    
    entity.window.display();
  }
    return 0;
}












































                 





























