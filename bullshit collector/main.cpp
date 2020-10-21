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
 bool debugging_view = false;


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
  //  sf::RenderWindow window{ sf::VideoMode{800,600}, "2D engine", sf::Style::Fullscreen };
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
        if (screen_size == "800x600") {
            entity.window.setSize(scr_size[0]);
                entity.small_engine_gui.combo_box->setSize(entity.small_engine_gui.width_combo_box, entity.small_engine_gui.height_combo_box);
                entity.small_engine_gui.combo_box->setPosition(entity.small_engine_gui.pos_x_combo_box, entity.small_engine_gui.pos_y_combo_box);
                entity.small_engine_gui.combo_box->setTextSize(20);
                entity.small_engine_gui.label_settings->setTextSize(30);
                entity.small_engine_gui.label_settings->setPosition(entity.small_engine_gui.pos_x_label_settings,entity.small_engine_gui.pos_y_label_settings);               
                entity.small_engine_gui.edit_box_file_path->setSize(entity.small_engine_gui.width_edit_box_file_path,entity.small_engine_gui.height_edit_box_file_path);
                entity.small_engine_gui.edit_box_file_path->setTextSize(20);
                entity.small_engine_gui.edit_box_file_path->setPosition(entity.small_engine_gui.pos_x_edit_box_file_path,entity.small_engine_gui.pos_y_edit_box_file_path);
                entity.small_engine_gui.combo_box_type_body->setSize(entity.small_engine_gui.width_combo_box_typebody,entity.small_engine_gui.height_combo_box_typebody);
                entity.small_engine_gui.combo_box_type_body->setPosition(entity.small_engine_gui.pos_x_combo_box_typebody,entity.small_engine_gui.pos_y_combo_box_typebody);
                entity.small_engine_gui.combo_box_type_body->setTextSize(20);
                entity.small_engine_gui.button_download->setSize(entity.small_engine_gui.width_button_download, entity.small_engine_gui.height_button_download);
                entity.small_engine_gui.button_download->setPosition(entity.small_engine_gui.pos_x_button_download,entity.small_engine_gui.pos_y_button_download);
                entity.small_engine_gui.button_download->setTextSize(20);
                entity.small_engine_gui.combo_box_figure->setSize(entity.small_engine_gui.width_combo_box_figure,entity.small_engine_gui.height_combo_box_figure);
                entity.small_engine_gui.combo_box_figure->setPosition(entity.small_engine_gui.pos_x_combo_box_figure,entity.small_engine_gui.pos_y_combo_box_figure);
                entity.small_engine_gui.combo_box_figure->setTextSize(20);
                entity.small_engine_gui.edit_box_file_path_fone->setSize(entity.small_engine_gui.width_edit_box_file_path_fone, entity.small_engine_gui.height_edit_box_file_path_fone);
                entity.small_engine_gui.edit_box_file_path_fone->setTextSize(20);
                entity.small_engine_gui.edit_box_file_path_fone->setPosition(entity.small_engine_gui.pos_x_edit_box_file_path_fone, entity.small_engine_gui.pos_y_edit_box_file_path_fone);
                entity.small_engine_gui.button_download_fone->setSize(entity.small_engine_gui.width_button_download_fone, entity.small_engine_gui.height_button_download_fone);
                entity.small_engine_gui.button_download_fone->setPosition(entity.small_engine_gui.pos_x_button_download_fone, entity.small_engine_gui.pos_y_button_download_fone);
                entity.small_engine_gui.button_download_fone->setTextSize(20);
                entity.small_engine_gui.button_fullscreen_mode->setSize(entity.small_engine_gui.width_button_fullscreen, entity.small_engine_gui.height_button_fullscreen);
                entity.small_engine_gui.button_fullscreen_mode->setPosition(entity.small_engine_gui.pos_x_button_fullscreen, entity.small_engine_gui.pos_y_button_fullscreen);
                entity.small_engine_gui.button_fullscreen_mode->setTextSize(20);
            
        }
        else if (screen_size == "1024x768") {
            entity.window.setSize(scr_size[1]);
                entity.small_engine_gui.combo_box->setSize(entity.small_engine_gui.width_combo_box * 1.28, entity.small_engine_gui.height_combo_box * 1.28);
                entity.small_engine_gui.combo_box->setPosition(entity.small_engine_gui.pos_x_combo_box * 1.28, entity.small_engine_gui.pos_y_combo_box * 1.28);
                entity.small_engine_gui.combo_box->setTextSize(20 * 1.28);
                entity.small_engine_gui.label_settings->setTextSize(30 * 1.28);
                entity.small_engine_gui.label_settings->setPosition(entity.small_engine_gui.pos_x_label_settings * 1.28, entity.small_engine_gui.pos_y_label_settings * 1.28);               
                entity.small_engine_gui.edit_box_file_path->setSize(entity.small_engine_gui.width_edit_box_file_path * 1.28, entity.small_engine_gui.height_edit_box_file_path * 1.28);
                entity.small_engine_gui.edit_box_file_path->setTextSize(20 * 1.28);
                entity.small_engine_gui.edit_box_file_path->setPosition(entity.small_engine_gui.pos_x_edit_box_file_path * 1.28, entity.small_engine_gui.pos_y_edit_box_file_path * 1.28);
                entity.small_engine_gui.combo_box_type_body->setSize(entity.small_engine_gui.width_combo_box_typebody * 1.28, entity.small_engine_gui.height_combo_box_typebody * 1.28);
                entity.small_engine_gui.combo_box_type_body->setPosition(entity.small_engine_gui.pos_x_combo_box_typebody * 1.28, entity.small_engine_gui.pos_y_combo_box_typebody * 1.28);
                entity.small_engine_gui.combo_box_type_body->setTextSize(20 * 1.28);
                entity.small_engine_gui.button_download->setSize(entity.small_engine_gui.width_button_download * 1.28, entity.small_engine_gui.height_button_download * 1.28);
                entity.small_engine_gui.button_download->setPosition(entity.small_engine_gui.pos_x_button_download * 1.28, entity.small_engine_gui.pos_y_button_download * 1.28);
                entity.small_engine_gui.button_download->setTextSize(20 * 1.28);
                entity.small_engine_gui.combo_box_figure->setSize(entity.small_engine_gui.width_combo_box_figure * 1.28, entity.small_engine_gui.height_combo_box_figure * 1.28);
                entity.small_engine_gui.combo_box_figure->setPosition(entity.small_engine_gui.pos_x_combo_box_figure * 1.28, entity.small_engine_gui.pos_y_combo_box_figure * 1.28);
                entity.small_engine_gui.combo_box_figure->setTextSize(20 * 1.28);
                entity.small_engine_gui.edit_box_file_path_fone->setSize(entity.small_engine_gui.width_edit_box_file_path_fone * 1.28, entity.small_engine_gui.height_edit_box_file_path_fone * 1.28);
                entity.small_engine_gui.edit_box_file_path_fone->setTextSize(20 * 1.28);
                entity.small_engine_gui.edit_box_file_path_fone->setPosition(entity.small_engine_gui.pos_x_edit_box_file_path_fone * 1.28, entity.small_engine_gui.pos_y_edit_box_file_path_fone * 1.28);
                entity.small_engine_gui.button_download_fone->setSize(entity.small_engine_gui.width_button_download_fone * 1.28, entity.small_engine_gui.height_button_download_fone * 1.28);
                entity.small_engine_gui.button_download_fone->setPosition(entity.small_engine_gui.pos_x_button_download_fone * 1.28, entity.small_engine_gui.pos_y_button_download_fone * 1.28);
                entity.small_engine_gui.button_download_fone->setTextSize(20 * 1.28);
                entity.small_engine_gui.button_fullscreen_mode->setSize(entity.small_engine_gui.width_button_fullscreen * 1.28, entity.small_engine_gui.height_button_fullscreen * 1.28);
                entity.small_engine_gui.button_fullscreen_mode->setPosition(entity.small_engine_gui.pos_x_button_fullscreen * 1.28, entity.small_engine_gui.pos_y_button_fullscreen * 1.28);
                entity.small_engine_gui.button_fullscreen_mode->setTextSize(20 * 1.28);
        }
        else if (screen_size == "1280x1024") {
            entity.window.setSize(scr_size[2]);
                entity.small_engine_gui.combo_box->setSize(entity.small_engine_gui.width_combo_box * 1.6, entity.small_engine_gui.height_combo_box * 1.7024);
                entity.small_engine_gui.combo_box->setPosition(entity.small_engine_gui.pos_x_combo_box * 1.6, entity.small_engine_gui.pos_y_combo_box * 1.7024);
                entity.small_engine_gui.combo_box->setTextSize(20 * 1.65);
                entity.small_engine_gui.label_settings->setTextSize(30 * 1.65);
                entity.small_engine_gui.label_settings->setPosition(entity.small_engine_gui.pos_x_label_settings * 1.6, entity.small_engine_gui.pos_y_label_settings * 1.7024);             
                entity.small_engine_gui.edit_box_file_path->setSize(entity.small_engine_gui.width_edit_box_file_path *1.6, entity.small_engine_gui.height_edit_box_file_path * 1.7024);
                entity.small_engine_gui.edit_box_file_path->setTextSize(20 * 1.65);
                entity.small_engine_gui.edit_box_file_path->setPosition(entity.small_engine_gui.pos_x_edit_box_file_path *1.6, entity.small_engine_gui.pos_y_edit_box_file_path * 1.7024);
                entity.small_engine_gui.combo_box_type_body->setSize(entity.small_engine_gui.width_combo_box_typebody * 1.6, entity.small_engine_gui.height_combo_box_typebody * 1.7024);
                entity.small_engine_gui.combo_box_type_body->setPosition(entity.small_engine_gui.pos_x_combo_box_typebody * 1.6, entity.small_engine_gui.pos_y_combo_box_typebody * 1.7024);
                entity.small_engine_gui.combo_box_type_body->setTextSize(20 * 1.65);
                entity.small_engine_gui.button_download->setSize(entity.small_engine_gui.width_button_download * 1.6,entity.small_engine_gui.height_button_download * 1.7024);
                entity.small_engine_gui.button_download->setPosition(entity.small_engine_gui.pos_x_button_download * 1.6, entity.small_engine_gui.pos_y_button_download * 1.7024);
                entity.small_engine_gui.button_download->setTextSize(20 * 1.65);
                entity.small_engine_gui.combo_box_figure->setSize(entity.small_engine_gui.width_combo_box_figure * 1.6, entity.small_engine_gui.height_combo_box_figure * 1.7024);
                entity.small_engine_gui.combo_box_figure->setPosition(entity.small_engine_gui.pos_x_combo_box_figure * 1.6, entity.small_engine_gui.pos_y_combo_box_figure * 1.7024);
                entity.small_engine_gui.combo_box_figure->setTextSize(20 * 1.65);
                entity.small_engine_gui.edit_box_file_path_fone->setSize(entity.small_engine_gui.width_edit_box_file_path_fone * 1.6, entity.small_engine_gui.height_edit_box_file_path_fone * 1.7024);
                entity.small_engine_gui.edit_box_file_path_fone->setTextSize(20 * 1.65);
                entity.small_engine_gui.edit_box_file_path_fone->setPosition(entity.small_engine_gui.pos_x_edit_box_file_path_fone * 1.6, entity.small_engine_gui.pos_y_edit_box_file_path_fone * 1.7024);
                entity.small_engine_gui.button_download_fone->setSize(entity.small_engine_gui.width_button_download_fone * 1.6, entity.small_engine_gui.height_button_download_fone * 1.7024);
                entity.small_engine_gui.button_download_fone->setPosition(entity.small_engine_gui.pos_x_button_download_fone * 1.6, entity.small_engine_gui.pos_y_button_download_fone * 1.7024);
                entity.small_engine_gui.button_download_fone->setTextSize(20 * 1.65);
                entity.small_engine_gui.button_fullscreen_mode->setSize(entity.small_engine_gui.width_button_fullscreen * 1.6, entity.small_engine_gui.height_button_fullscreen * 1.7024);
                entity.small_engine_gui.button_fullscreen_mode->setPosition(entity.small_engine_gui.pos_x_button_fullscreen * 1.6, entity.small_engine_gui.pos_y_button_fullscreen * 1.7024);
                entity.small_engine_gui.button_fullscreen_mode->setTextSize(20 * 1.65);
        }
        else if (screen_size == "1600x1200") {            
                entity.window.setSize(scr_size[3]);
                entity.small_engine_gui.combo_box->setSize(entity.small_engine_gui.width_combo_box * 2, entity.small_engine_gui.height_combo_box * 1.9918);
                entity.small_engine_gui.combo_box->setPosition(entity.small_engine_gui.pos_x_combo_box * 2, entity.small_engine_gui.pos_y_combo_box * 1.9918);
                entity.small_engine_gui.combo_box->setTextSize(20 * 2);
                entity.small_engine_gui.label_settings->setTextSize(30 * 2);
                entity.small_engine_gui.label_settings->setPosition(entity.small_engine_gui.pos_x_label_settings * 2, entity.small_engine_gui.pos_y_label_settings * 1.9918);               
                entity.small_engine_gui.edit_box_file_path->setSize(entity.small_engine_gui.width_edit_box_file_path * 2, entity.small_engine_gui.height_edit_box_file_path * 1.9918);
                entity.small_engine_gui.edit_box_file_path->setTextSize(20 * 2);
                entity.small_engine_gui.edit_box_file_path->setPosition(entity.small_engine_gui.pos_x_edit_box_file_path * 2, entity.small_engine_gui.pos_y_edit_box_file_path * 1.9918);
                entity.small_engine_gui.combo_box_type_body->setSize(entity.small_engine_gui.width_combo_box_typebody * 2, entity.small_engine_gui.height_combo_box_typebody * 1.9918);
                entity.small_engine_gui.combo_box_type_body->setPosition(entity.small_engine_gui.pos_x_combo_box_typebody * 2, entity.small_engine_gui.pos_y_combo_box_typebody * 1.9918);
                entity.small_engine_gui.combo_box_type_body->setTextSize(20 * 2);
                entity.small_engine_gui.button_download->setSize(entity.small_engine_gui.width_button_download * 2, entity.small_engine_gui.height_button_download * 1.9918);
                entity.small_engine_gui.button_download->setPosition(entity.small_engine_gui.pos_x_button_download * 2, entity.small_engine_gui.pos_y_button_download * 1.9918);
                entity.small_engine_gui.button_download->setTextSize(20 * 2);
                entity.small_engine_gui.combo_box_figure->setSize(entity.small_engine_gui.width_combo_box_figure * 2, entity.small_engine_gui.height_combo_box_figure * 1.9918);
                entity.small_engine_gui.combo_box_figure->setPosition(entity.small_engine_gui.pos_x_combo_box_figure * 2, entity.small_engine_gui.pos_y_combo_box_figure * 1.9918);
                entity.small_engine_gui.combo_box_figure->setTextSize(20 * 2);
                entity.small_engine_gui.edit_box_file_path_fone->setSize(entity.small_engine_gui.width_edit_box_file_path_fone * 2, entity.small_engine_gui.height_edit_box_file_path_fone * 1.9918);
                entity.small_engine_gui.edit_box_file_path_fone->setTextSize(20 * 2);
                entity.small_engine_gui.edit_box_file_path_fone->setPosition(entity.small_engine_gui.pos_x_edit_box_file_path_fone * 2, entity.small_engine_gui.pos_y_edit_box_file_path_fone * 1.9918);
                entity.small_engine_gui.button_download_fone->setSize(entity.small_engine_gui.width_button_download_fone * 2, entity.small_engine_gui.height_button_download_fone * 1.9918);
                entity.small_engine_gui.button_download_fone->setPosition(entity.small_engine_gui.pos_x_button_download_fone * 2, entity.small_engine_gui.pos_y_button_download_fone * 1.9918);
                entity.small_engine_gui.button_download_fone->setTextSize(20 * 2);
                entity.small_engine_gui.button_fullscreen_mode->setSize(entity.small_engine_gui.width_button_fullscreen * 2, entity.small_engine_gui.height_button_fullscreen * 1.9918);
                entity.small_engine_gui.button_fullscreen_mode->setPosition(entity.small_engine_gui.pos_x_button_fullscreen * 2, entity.small_engine_gui.pos_y_button_fullscreen * 1.9918);
                entity.small_engine_gui.button_fullscreen_mode->setTextSize(20 * 2);

        }
        else if (screen_size == "1920x1080") {
            entity.window.setSize(scr_size[4]);
                entity.small_engine_gui.combo_box->setSize(entity.small_engine_gui.width_combo_box * 2.4, entity.small_engine_gui.height_combo_box * 1.79262);
                entity.small_engine_gui.combo_box->setPosition(entity.small_engine_gui.pos_x_combo_box * 2.4, entity.small_engine_gui.pos_y_combo_box * 1.79262);
                entity.small_engine_gui.combo_box->setTextSize(20 * 2.1);
                entity.small_engine_gui.label_settings->setTextSize(30 * 2.1);
                entity.small_engine_gui.label_settings->setPosition(entity.small_engine_gui.pos_x_label_settings * 2.4, entity.small_engine_gui.pos_y_label_settings * 1.79262);               
                entity.small_engine_gui.edit_box_file_path->setSize(entity.small_engine_gui.width_edit_box_file_path * 2.4, entity.small_engine_gui.height_edit_box_file_path * 1.79262);
                entity.small_engine_gui.edit_box_file_path->setTextSize(20 * 2.1);
                entity.small_engine_gui.edit_box_file_path->setPosition(entity.small_engine_gui.pos_x_edit_box_file_path * 2.4, entity.small_engine_gui.pos_y_edit_box_file_path * 1.79262);
                entity.small_engine_gui.combo_box_type_body->setSize(entity.small_engine_gui.width_combo_box_typebody * 2.4, entity.small_engine_gui.height_combo_box_typebody * 1.79262);
                entity.small_engine_gui.combo_box_type_body->setPosition(entity.small_engine_gui.pos_x_combo_box_typebody * 2.4, entity.small_engine_gui.pos_y_combo_box_typebody * 1.79262);
                entity.small_engine_gui.combo_box_type_body->setTextSize(20 * 2.1);
                entity.small_engine_gui.button_download->setSize(entity.small_engine_gui.width_button_download * 2.4, entity.small_engine_gui.height_button_download * 1.79262);
                entity.small_engine_gui.button_download->setPosition(entity.small_engine_gui.pos_x_button_download * 2.4, entity.small_engine_gui.pos_y_button_download * 1.79262);
                entity.small_engine_gui.button_download->setTextSize(20 * 2.1);
                entity.small_engine_gui.combo_box_figure->setSize(entity.small_engine_gui.width_combo_box_figure * 2.4, entity.small_engine_gui.height_combo_box_figure * 1.79262);
                entity.small_engine_gui.combo_box_figure->setPosition(entity.small_engine_gui.pos_x_combo_box_figure * 2.4, entity.small_engine_gui.pos_y_combo_box_figure * 1.79262);
                entity.small_engine_gui.combo_box_figure->setTextSize(20 * 2.1);
                entity.small_engine_gui.edit_box_file_path_fone->setSize(entity.small_engine_gui.width_edit_box_file_path_fone * 2.4, entity.small_engine_gui.height_edit_box_file_path_fone * 1.79262);
                entity.small_engine_gui.edit_box_file_path_fone->setTextSize(20 * 2.1);
                entity.small_engine_gui.edit_box_file_path_fone->setPosition(entity.small_engine_gui.pos_x_edit_box_file_path_fone * 2.4, entity.small_engine_gui.pos_y_edit_box_file_path_fone * 1.79262);
                entity.small_engine_gui.button_download_fone->setSize(entity.small_engine_gui.width_button_download_fone * 2.4, entity.small_engine_gui.height_button_download_fone * 1.79262);
                entity.small_engine_gui.button_download_fone->setPosition(entity.small_engine_gui.pos_x_button_download_fone * 2.4, entity.small_engine_gui.pos_y_button_download_fone * 1.7962);
                entity.small_engine_gui.button_download_fone->setTextSize(20 * 2.1);
                entity.small_engine_gui.button_fullscreen_mode->setSize(entity.small_engine_gui.width_button_fullscreen * 2.4, entity.small_engine_gui.height_button_fullscreen * 1.79262);
                entity.small_engine_gui.button_fullscreen_mode->setPosition(entity.small_engine_gui.pos_x_button_fullscreen * 2.4, entity.small_engine_gui.pos_y_button_fullscreen * 1.79262);
                entity.small_engine_gui.button_fullscreen_mode->setTextSize(20 * 2.1);
        }

    // 1.28, 1.6 , 2, 2.4 - the scale factor is obtained by dividing one resolution by another:
    // 1024/800 = 1.28   
    // 786/600 = 1.28    
}

// ДОДЕЛАТЬ ФУЛЛСКРИН РЕЖИМ - УСТАНОВИТЬ ПОРТ ПРОСМОТРА ДЛЯ КАЖДОГО РАЗРЕШЕНИЯ (см.Ютуб)


int main()
{
    ObjectsEntities entity;
    entity.small_engine_gui.combo_box->onItemSelect(set_screen_resolution, std::ref(entity));

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

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Tilde) {
                    if (entity.small_engine_gui.menu_view) {
                        entity.small_engine_gui.menu_view = false;
                        entity.small_engine_gui.displaying_widgets();
                    }
                    else {
                        entity.small_engine_gui.menu_view = true;
                        entity.small_engine_gui.displaying_widgets();
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
                    float delta_x = (entity.transfer_objects.get_mouse_coordinte(entity.window).x - entity.transfer_objects.deltaX) / 30.f; // äåëüòàX
                    float delta_y = (entity.transfer_objects.get_mouse_coordinte(entity.window).y - entity.transfer_objects.deltaY) / 30.f; // äåëüòàY                                
                    b2Vec2 vector;
                    vector.x = delta_x - static_cast<Rectangle_*>(it)->x_initial_coordinates_of_the_sprite(); //  ïîëó÷èòü äåëüòóX è äåëüòóY. Âû÷åñòü èç íåå êîîðäèíàòû âåðõíåãî ëåâîãî óãëà ñïðàéòà.
                    vector.y = delta_y - static_cast<Rectangle_*>(it)->y_initial_coordinates_of_the_sprite(); //  êîîðäèíàòû âåðõíåãî óãëà(x,y) èíèöèàëèçèðóþòñÿ îäèí ðàç (âî âðåìÿ êîìïèëÿöèè)
                    static_cast<Rectangle_*>(it)->body_rect->SetTransform(vector, 0);
                }
            }

        }

    world.Step(1 / 120.f, 8, 3);
    entity.window.clear();
    entity.window.draw(entity.game_background);
    entity.physics_player.jump(world);
    entity.physics_player.update(entity.window, entity.graphics_player.get_sprite());
    entity.window.draw(static_cast<Rectangle_*>(entity.objects_world.get_object_world(3))->get_sprite());
    entity.window.draw(static_cast<Rectangle_*>(entity.objects_world.get_object_world(4))->get_sprite());
    entity.window.draw(static_cast<Rectangle_*>(entity.objects_world.get_object_world(5))->get_sprite());
    if (debugging_view) {
        world.DebugDraw();
    }
    if (entity.small_engine_gui.menu_view) {
        entity.window.draw(entity.small_engine_gui.get_sprite_fone());
    }
    entity.GUI.draw();
    
    entity.window.display();
  }
    return 0;
}



                    















