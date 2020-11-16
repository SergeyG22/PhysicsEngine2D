#include <iostream>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Widgets/Button.hpp>
#include <boost/filesystem.hpp>
#include <algorithm>
#include "gui.h"
#include "scene.h"
#include "b2GLDraw.h"
#include "window_function.h"

std::vector<sf::Vector2u>scr_size{ {800,600},{1020,768},{1280,1020},{1600,1200},{1920,1080} };
bool debugging_view = false;

extern void enumeration_flags(uint32& flags);
extern void get_supported_fullscreen_modes();
extern float system_timer(sf::Clock& clock);
extern sf::Vector2f get_size_sprite_with_scale(std::list<gobj::ObjectFactory*>::iterator::value_type it);
extern std::string get_typename(std::list<gobj::ObjectFactory*>::iterator::value_type it);
extern b2Vec2 get_position(std::list<gobj::ObjectFactory*>::iterator::value_type it);
extern const float SCALE;
extern const float DEG;
extern b2Vec2 gravity;
extern b2World world;
extern uint32 FLAGS;


struct ObjectsEntities {                                          //class for storing objects in the world
    sf::RenderWindow window{ sf::VideoMode{1920,1080}, "2D engine", sf::Style::Close | sf::Style::Fullscreen };    
    sf::Clock system_rendering_clock;
    PhysicsPlayer physics_player{ world };
    tgui::GuiSFML GUI{ window };
    Images_elements images_elements;
    Decor_elements decor_elements;
    Button_switching_fullscreen button_switching_fullscreen{ GUI };
    Button_screen_mode button_screen_mode{ GUI };
    Button_download_fone button_download_fone{ GUI };
    Button_download_texture button_download_texture{ GUI };
    Button_settings_decoration button_settings_decoration{ GUI };
    Combo_box_filepath_fone combo_box_file_path_fone{ GUI };
    Combo_box_invisible_object combo_box_invisible_object{ GUI };
    Combo_box_figure combo_box_figure{ GUI };
    Combo_box combo_box{ GUI };
    Combo_box_typebody combo_box_type_body{ GUI };
    Combo_box_file_path_texture combo_box_file_path_texture{ GUI };
    Combo_box_decor combo_box_decor{ GUI };
    Slider_weight_setting slider_weight_setting {GUI};
    Label_weight label_weight{ GUI };
    GameBackground game_background;
    GraphicsPlayer graphics_player;
    TransferObjects transfer_objects;
    ObjectsWorld objects_world;
    DecorativeObjectsWorld decorative_objects_world;
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

void TGUI_set_view(ObjectsEntities&);
void TGUI_set_viewport(ObjectsEntities&);


void call_offset(ObjectsEntities& entity, std::string size) {
    entity.button_switching_fullscreen.set_offset(size);
    entity.button_screen_mode.set_offset(size);
    entity.button_download_fone.set_offset(size);
    entity.button_download_texture.set_offset(size);
    entity.combo_box_file_path_fone.set_offset(size);
    entity.combo_box_invisible_object.set_offset(size);
    entity.combo_box_figure.set_offset(size);   
    entity.combo_box_type_body.set_offset(size);
    entity.combo_box_file_path_texture.set_offset(size);
    entity.combo_box.set_offset(size);
    entity.label_weight.set_offset(size);   
    entity.slider_weight_setting.set_offset(size);
    entity.button_settings_decoration.set_offset(size);
    entity.combo_box_decor.set_offset(size);
}

void enable_fullscreen_mode(ObjectsEntities& entity) {
    entity.window.setSize(scr_size[0]);
    set_window_center_of_screen(entity);
    call_offset(entity, "800x600");
    entity.window.create(sf::VideoMode(1920, 1080), "2D engine", sf::Style::Fullscreen);
    TGUI_set_view(entity);
    entity.combo_box.combo_box->setEnabled(false);
    entity.game_background.set_scale_background();
}

void set_size_centreand_extension(int i, ObjectsEntities& entity,std::string& size) {
    entity.window.setSize(scr_size[i]);
    set_window_center_of_screen(entity);
    call_offset(entity, size);
}

void set_screen_resolution(ObjectsEntities& entity) {
    std::string size = entity.combo_box.combo_box->getSelectedItem().toAnsiString();
    int ID = entity.combo_box.combo_box->getSelectedItemIndex();
    switch (ID) {
    case 0: { set_size_centreand_extension(0, entity, size); break; }
    case 1: { set_size_centreand_extension(1, entity, size); break; }
    case 2: { set_size_centreand_extension(2, entity, size); break; }
    case 3: { set_size_centreand_extension(3, entity, size); break; }
    case 4: { set_size_centreand_extension(4, entity, size); break; }
    }

}

void set_fullscreen_viewport(ObjectsEntities& entity) {

    if (entity.button_screen_mode.enable_fullscreen) {
        entity.window.create(sf::VideoMode(1920, 1080), "2D engine", sf::Style::Fullscreen);
        sf::View view_port;
        view_port.setViewport(sf::FloatRect(0.f, 0.f, 1.25f, 1.65f));
        entity.window.setView(view_port);
        set_screen_resolution(entity);
        entity.button_screen_mode.button_screen_mode->setText(L"Оконный режим");
        entity.button_screen_mode.enable_fullscreen = false;
        entity.combo_box.combo_box->setEnabled(true);
        TGUI_set_viewport(entity);
        entity.game_background.get_sprite().setScale(1, 1);
    }
    else {
        entity.window.create(sf::VideoMode(800, 600), "2D engine", sf::Style::Close | sf::Style::Titlebar);
        set_screen_resolution(entity);
        entity.button_screen_mode.button_screen_mode->setText(L"Экранный режим");
        entity.button_screen_mode.enable_fullscreen = true;
        TGUI_set_view(entity);
        entity.combo_box.combo_box->setEnabled(true);
        float x = entity.window.getSize().x;
        float y = entity.window.getSize().y;
        if(x == 800 && y == 600){ entity.game_background.get_sprite().setScale(1,1); }
        else if(x == 1024 && y == 768){ entity.game_background.get_sprite().setScale(1.28, 1.28); }
        else if (x == 1280 && y == 1024) { entity.game_background.get_sprite().setScale(1.6, 1.7); }
        else if (x == 1600 && y == 1200) { entity.game_background.get_sprite().setScale(2,2); }
        else if (x == 1920 && y == 1080) { entity.game_background.get_sprite().setScale(2.4,1.8); }

                
    }

   ///  get_supported_fullscreen_modes();  //disabled (used only for displaying information)
}

void set_new_fone(ObjectsEntities& entity) {   
     entity.game_background.upload_background("background/" + entity.combo_box_file_path_fone.combo_box_file_path_fone->getSelectedItem().toAnsiString());
}

void show_widgets(ObjectsEntities& entity, bool state) {
    entity.images_elements.menu_view = state;
    entity.button_download_texture.button_download_texture->setVisible(state);
    entity.button_download_fone.button_download_fone->setVisible(state);
    entity.button_screen_mode.button_screen_mode->setVisible(state);
    entity.button_switching_fullscreen.button_switching_fullscreen->setVisible(state);
    entity.button_settings_decoration.button_settings_decoration->setVisible(state);
    entity.combo_box.combo_box->setVisible(state);
    entity.combo_box_figure.combo_box_figure->setVisible(state);
    entity.combo_box_file_path_fone.combo_box_file_path_fone->setVisible(state);
    entity.combo_box_invisible_object.combo_box_invisible_object->setVisible(state);
    entity.combo_box_file_path_texture.combo_box_file_path_texture->setVisible(state);
    entity.combo_box_type_body.combo_box_type_body->setVisible(state);
    entity.combo_box_decor.combo_box_decor->setVisible(state);
    entity.slider_weight_setting.slider_weight_setting->setVisible(state);
    entity.label_weight.label_weight->setVisible(state);

}

void create_body_with_higher_density(std::list<gobj::ObjectFactory*>::iterator::value_type it, b2Vec2 pos, ObjectsEntities& obj) {
    if (get_typename(it) == "class gobj::Rectangle") {
            dynamic_cast<gobj::Rectangle*>(it)->bshape_rect.SetAsBox(get_size_sprite_with_scale(it).x / 2 / SCALE, get_size_sprite_with_scale(it).y / 2 / SCALE);
            dynamic_cast<gobj::Rectangle*>(it)->bdef_rect.position.Set(pos.x, pos.y);
            dynamic_cast<gobj::Rectangle*>(it)->body_rect = world.CreateBody(&dynamic_cast<gobj::Rectangle*>(it)->bdef_rect);
            it->get_body_pointer()->CreateFixture(&dynamic_cast<gobj::Rectangle*>(it)->bshape_rect, dynamic_cast<gobj::Rectangle*>(it)->density += 1);
            obj.slider_weight_setting.slider_weight_setting->setValue(dynamic_cast<gobj::Rectangle*>(it)->density);
            obj.label_weight.label_weight->setText(tgui::String(dynamic_cast<gobj::Rectangle*>(it)->density));
        }
    
    else if (get_typename(it) == "class gobj::Circle") {
        dynamic_cast<gobj::Circle*>(it)->bshape_circle.m_radius = get_size_sprite_with_scale(it).x / 2 / SCALE;
        dynamic_cast<gobj::Circle*>(it)->bdef_circle.position.Set(pos.x, pos.y);
        dynamic_cast<gobj::Circle*>(it)->body_circle = world.CreateBody(&dynamic_cast<gobj::Circle*>(it)->bdef_circle);
        it->get_body_pointer()->CreateFixture(&dynamic_cast<gobj::Circle*>(it)->bshape_circle, dynamic_cast<gobj::Circle*>(it)->density += 1);
        obj.slider_weight_setting.slider_weight_setting->setValue(dynamic_cast<gobj::Circle*>(it)->density);
        obj.label_weight.label_weight->setText(tgui::String(dynamic_cast<gobj::Circle*>(it)->density));
    }
}

void create_body_with_less_density(std::list<gobj::ObjectFactory*>::iterator::value_type it, b2Vec2 pos, ObjectsEntities& obj) {
        if (get_typename(it) == "class gobj::Rectangle") {
            dynamic_cast<gobj::Rectangle*>(it)->bshape_rect.SetAsBox(get_size_sprite_with_scale(it).x / 2 / SCALE, get_size_sprite_with_scale(it).y / 2 / SCALE);
            dynamic_cast<gobj::Rectangle*>(it)->bdef_rect.position.Set(pos.x, pos.y);
            dynamic_cast<gobj::Rectangle*>(it)->body_rect = world.CreateBody(&dynamic_cast<gobj::Rectangle*>(it)->bdef_rect);
            it->get_body_pointer()->CreateFixture(&dynamic_cast<gobj::Rectangle*>(it)->bshape_rect, dynamic_cast<gobj::Rectangle*>(it)->density -= 1);
            obj.slider_weight_setting.slider_weight_setting->setValue(dynamic_cast<gobj::Rectangle*>(it)->density);
            obj.label_weight.label_weight->setText(tgui::String(dynamic_cast<gobj::Rectangle*>(it)->density));
        }
    else if (get_typename(it) == "class gobj::Circle") {        
        dynamic_cast<gobj::Circle*>(it)->bshape_circle.m_radius = get_size_sprite_with_scale(it).x / 2 / SCALE;
        dynamic_cast<gobj::Circle*>(it)->bdef_circle.position.Set(pos.x, pos.y);
        dynamic_cast<gobj::Circle*>(it)->body_circle = world.CreateBody(&dynamic_cast<gobj::Circle*>(it)->bdef_circle);
        it->get_body_pointer()->CreateFixture(&dynamic_cast<gobj::Circle*>(it)->bshape_circle, dynamic_cast<gobj::Circle*>(it)->density -= 1);
        obj.slider_weight_setting.slider_weight_setting->setValue(dynamic_cast<gobj::Circle*>(it)->density);
        obj.label_weight.label_weight->setText(tgui::String(dynamic_cast<gobj::Circle*>(it)->density));
    }
}



void add_decorative_object_to_world(ObjectsEntities& entity) {
    entity.decorative_objects_world.list_decor_elements.push_back(new Decor_elements(entity.combo_box_decor.combo_box_decor->getSelectedItem().toAnsiString()));
}


void add_object_to_world(ObjectsEntities& entity) {

    sf::Texture texture; //temporary texture for getting width and height
    int id_type_body = entity.combo_box_type_body.combo_box_type_body->getSelectedItemId().toInt();
    int id_visible_object = entity.combo_box_invisible_object.combo_box_invisible_object->getSelectedItemId().toInt();

    switch (entity.combo_box_figure.combo_box_figure->getSelectedItemIndex())
    {
    case 0:
    {       
        std::string path = "circle/" + entity.combo_box_file_path_texture.combo_box_file_path_texture->getSelectedItem().toAnsiString();                                        
        if (!texture.loadFromFile(path)) { std::cout << "The texture path is not correct\n"; }
        switch (id_type_body)
        {
        case 1: {
            entity.objects_world.list_object.push_back(new gobj::Circle(world, texture.getSize().x, texture.getSize().y, path, b2_staticBody, id_visible_object));
            break;
        }
        case 2: {
            entity.objects_world.list_object.push_back(new gobj::Circle(world, texture.getSize().x, texture.getSize().y, path, b2_dynamicBody, id_visible_object));
            break;
        }
        }
        break;
    }
    case 1:
    {
        std::string path = "rectangle/" + entity.combo_box_file_path_texture.combo_box_file_path_texture->getSelectedItem().toAnsiString();
        if (!texture.loadFromFile(path)) {  std::cout << "The texture path is not correct\n"; }
        switch (id_type_body)
        {
        case 1: {
            entity.objects_world.list_object.push_back(new gobj::Rectangle(world, texture.getSize().x, texture.getSize().y, 750, 200, path, b2_staticBody, id_visible_object));
            break;
        }
        case 2: {
            entity.objects_world.list_object.push_back(new gobj::Rectangle(world, texture.getSize().x, texture.getSize().y, 750, 200, path, b2_dynamicBody, id_visible_object));
            break;
        }
        }
    }
    }



}



void select_item(ObjectsEntities& entity) {
    switch (entity.combo_box_figure.combo_box_figure->getSelectedItemIndex()) {
    case 0: {
        entity.combo_box_file_path_texture.set_options_texture("circle");
        entity.combo_box_file_path_texture.combo_box_file_path_texture->setSelectedItemByIndex(0);
        break;
    }
    case 1: {
        entity.combo_box_file_path_texture.set_options_texture("rectangle");
        entity.combo_box_file_path_texture.combo_box_file_path_texture->setSelectedItemByIndex(0);
        break;
    }
    }

}

void updating_list_with_mouse(ObjectsEntities& entity) {
    switch (entity.combo_box_figure.combo_box_figure->getSelectedItemIndex()) {
    case 0: {
        entity.combo_box_file_path_texture.set_options_texture("circle");
        entity.combo_box_file_path_texture.combo_box_file_path_texture->setSelectedItem(entity.combo_box_file_path_texture.combo_box_file_path_texture->getSelectedItem());
        break;
    }
    case 1: {
        entity.combo_box_file_path_texture.set_options_texture("rectangle");
        entity.combo_box_file_path_texture.combo_box_file_path_texture->setSelectedItem(entity.combo_box_file_path_texture.combo_box_file_path_texture->getSelectedItem());
        break;
    }
    }
}

void updating_list_combo_box_fone(ObjectsEntities& entity) {
    entity.combo_box_file_path_fone.combo_box_file_path_fone->setSelectedItem(entity.combo_box_file_path_fone.combo_box_file_path_fone->getSelectedItem());
}

void updaiting_list_combo_box_decor(ObjectsEntities& entity) {
    entity.combo_box_decor.combo_box_decor->setSelectedItem(entity.combo_box_decor.combo_box_decor->getSelectedItem());
}


void TGUI_set_view(ObjectsEntities& entity) {
    tgui::FloatRect rect;
    tgui::Vector2f view_port_size;
    view_port_size.x = 1920;
    view_port_size.y = 1080;
    rect.setSize(view_port_size);
    entity.GUI.setAbsoluteView(rect);
}

void TGUI_set_viewport(ObjectsEntities& entity) {
    tgui::FloatRect rect;
    tgui::Vector2f view_port_size;
    view_port_size.x = 1920;
    view_port_size.y = 1080;
    rect.setSize(view_port_size);
    entity.GUI.setAbsoluteViewport(rect);
}


void change_weight(ObjectsEntities& entity) {    

    for (const auto& it : entity.objects_world.list_object) {       
        if (it->get_state()) {            
            if (get_typename(it) == "class gobj::Rectangle") {     
                it->get_body_pointer()->GetFixtureList()->SetDensity(entity.slider_weight_setting.slider_weight_setting->getValue());
                it->get_body_pointer()->ResetMassData();
                it->get_body_pointer()->SetAwake(true);
                tgui::String mass(entity.slider_weight_setting.slider_weight_setting->getValue());
                entity.label_weight.label_weight->setText(mass);
            }           
            else if(get_typename(it) == "class gobj::Circle"){
                it->get_body_pointer()->GetFixtureList()->SetDensity(entity.slider_weight_setting.slider_weight_setting->getValue());
                it->get_body_pointer()->ResetMassData();
                it->get_body_pointer()->SetAwake(true);
                tgui::String mass(entity.slider_weight_setting.slider_weight_setting->getValue());
                entity.label_weight.label_weight->setText(mass);
            }
            
        }
        
    }

}

void events_called_by_widgets(ObjectsEntities& entity) {
    entity.button_screen_mode.button_screen_mode->onClick(set_fullscreen_viewport, std::ref(entity));
    entity.button_download_texture.button_download_texture->onClick(add_object_to_world, std::ref(entity));
    entity.button_switching_fullscreen.button_switching_fullscreen->onClick(enable_fullscreen_mode, std::ref(entity));
    entity.button_settings_decoration.button_settings_decoration->onClick(add_decorative_object_to_world,std::ref(entity));
   // entity.button_download_fone.button_download_fone->onClick(set_new_fone, std::ref(entity));
    entity.combo_box_file_path_fone.combo_box_file_path_fone->onItemSelect(set_new_fone, std::ref(entity));   
    entity.combo_box.combo_box->onItemSelect(set_screen_resolution, std::ref(entity));
    entity.combo_box_figure.combo_box_figure->onItemSelect(select_item, std::ref(entity));
    entity.combo_box_file_path_texture.combo_box_file_path_texture->onMouseEnter(updating_list_with_mouse, std::ref(entity));
    entity.combo_box_decor.combo_box_decor->onMouseEnter(updaiting_list_combo_box_decor,std::ref(entity));
    entity.combo_box_file_path_fone.combo_box_file_path_fone->onMouseEnter(updating_list_combo_box_fone, std::ref(entity));
    entity.slider_weight_setting.slider_weight_setting->onValueChange(change_weight,std::ref(entity));
}

void reset_state_all_objects(ObjectsEntities& entity) {
  for (const auto &it:  entity.objects_world.list_object) { 
      it->reset_state();
    }
}

void init_rectangle(std::list<gobj::ObjectFactory*>::iterator::value_type it,ObjectsEntities& entity)
{
    it->get_body_pointer()->SetGravityScale(0.0);
    reset_state_all_objects(entity);
    it->set_state_select_object(true);
    float density = it->get_body_pointer()->GetFixtureList()->GetDensity();
    entity.slider_weight_setting.slider_weight_setting->setValue(density);
    entity.label_weight.label_weight->setText(tgui::String(density));
}

void init_circle(std::list<gobj::ObjectFactory*>::iterator::value_type it, ObjectsEntities& entity) {
    it->get_body_pointer()->SetGravityScale(0.0);
    reset_state_all_objects(entity);
    it->set_state_select_object(true);
    float density = it->get_body_pointer()->GetFixtureList()->GetDensity();
    entity.slider_weight_setting.slider_weight_setting->setValue(density);
    entity.label_weight.label_weight->setText(tgui::String(density));
}


// ПОПРАВИТЬ КОЛЛИЗИЮ МЕЖДУ ОБЬЕКТАМИ ДЕКОРА
// СДЕЛАТЬ МАСШТАБИРОВАНИЕ И УДАЛЕНИЕ ДЕКОРА


int main()
{
    setlocale(LC_ALL, "russian");
    ObjectsEntities entity;
    events_called_by_widgets(entity);
    entity.game_background.upload_background("background/"+entity.combo_box_file_path_fone.combo_box_file_path_fone->getSelectedItem().toAnsiString());
    entity.game_background.set_scale_background();

    while (entity.window.isOpen()) {
        entity.time = system_timer(entity.system_rendering_clock);
        sf::Event event;
        while (entity.window.pollEvent(event)) {
            entity.GUI.handleEvent(event);            // event for TGUI
            entity.physics_player.keyboard_interaction(entity.graphics_player);


            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Left) {
                    for (auto const& it : entity.decorative_objects_world.list_decor_elements) {
                        sf::Vector2f mouse_coord;
                        mouse_coord.x = entity.transfer_objects.get_mouse_coordinte(entity.window).x;
                        mouse_coord.y = entity.transfer_objects.get_mouse_coordinte(entity.window).y;
                        if (it->get_sprite_decor().getGlobalBounds().contains(mouse_coord.x, mouse_coord.y)) {
                            it->check = true;
                            entity.transfer_objects.deltaX = mouse_coord.x - it->get_sprite_decor().getPosition().x;
                            entity.transfer_objects.deltaY = mouse_coord.y - it->get_sprite_decor().getPosition().y;
                            entity.transfer_objects.can_be_moved_decor_world = true;
                        }
                        else {
                            it->check = false;
                        }

                    }
                }
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.key.code == sf::Mouse::Left) {
                    entity.transfer_objects.can_be_moved_decor_world = false;
                }
            }


            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Left) {
                    for (auto const& it : entity.objects_world.list_object) {
                        sf::Vector2f mouse_coord;
                        mouse_coord.x = entity.transfer_objects.get_mouse_coordinte(entity.window).x;
                        mouse_coord.y = entity.transfer_objects.get_mouse_coordinte(entity.window).y;
                        if (it->get_sprite().getGlobalBounds().contains(mouse_coord.x, mouse_coord.y)) {
                            entity.transfer_objects.deltaX = mouse_coord.x - it->get_sprite().getPosition().x;
                            entity.transfer_objects.deltaY = mouse_coord.y - it->get_sprite().getPosition().y;
                            entity.transfer_objects.can_be_moved_objects_world = true;

                            if (get_typename(it) == "class gobj::Rectangle") {
                                init_rectangle(it, entity);
                            }
                            else if (get_typename(it) == "class gobj::Circle") {
                                init_circle(it, entity);
                            }
                        }
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.key.code == sf::Mouse::Left) {
                    entity.transfer_objects.can_be_moved_objects_world = false;

                    for (auto const& it : entity.objects_world.list_object) {
                        if (get_typename(it) == "class gobj::Rectangle") {
                            it->get_body_pointer()->SetGravityScale(1.0);
                        }
                        else if (get_typename(it) == "class gobj::Circle") {
                            it->get_body_pointer()->SetGravityScale(1.0);
                        }
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

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Right) {
                    for (auto const& it : entity.decorative_objects_world.list_decor_elements) {
                        if (it->get_sprite_decor().getGlobalBounds().contains(entity.transfer_objects.get_mouse_coordinte(entity.window).x, entity.transfer_objects.get_mouse_coordinte(entity.window).y)) {
                            if (it->get_sprite_decor().getColor() == sf::Color::Red) {
                                it->get_sprite_decor().setColor(sf::Color::White);
                            }
                            else {
                                it->get_sprite_decor().setColor(sf::Color::Red);
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
                                    dynamic_cast<gobj::Rectangle*>(it)->density = it->get_body_pointer()->GetFixtureList()->GetDensity();
                                    world.DestroyBody(it->get_body_pointer());
                                }
                                else if (get_typename(it) == "class gobj::Circle") {
                                    dynamic_cast<gobj::Circle*>(it)->density = it->get_body_pointer()->GetFixtureList()->GetDensity();
                                    world.DestroyBody(it->get_body_pointer());
                                }

                                create_body_with_higher_density(it, pos, entity);
                            }
                            else if (event.mouseWheelScroll.delta < 0) {
                                sf::Vector2f scale = it->get_sprite().getScale();
                                scale.x -= 0.1;
                                scale.y -= 0.1;
                                it->get_sprite().setScale(scale);
                                b2Vec2 pos = get_position(it);
                                if (get_typename(it) == "class gobj::Rectangle") {
                                    dynamic_cast<gobj::Rectangle*>(it)->density = it->get_body_pointer()->GetFixtureList()->GetDensity();
                                    world.DestroyBody(it->get_body_pointer());
                                }
                                else if (get_typename(it) == "class gobj::Circle") {
                                    dynamic_cast<gobj::Circle*>(it)->density = it->get_body_pointer()->GetFixtureList()->GetDensity();
                                    world.DestroyBody(it->get_body_pointer());

                                }
                                create_body_with_less_density(it, pos, entity);


                            }
                        }

                    }
                }

            }

            if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                    for (auto const& it : entity.decorative_objects_world.list_decor_elements) {
                        if (it->get_sprite_decor().getGlobalBounds().contains(entity.transfer_objects.get_mouse_coordinte(entity.window).x, entity.transfer_objects.get_mouse_coordinte(entity.window).y)) {
                            if (event.mouseWheelScroll.delta > 0) {
                                sf::Vector2f scale = it->get_sprite_decor().getScale();
                                scale.x += 0.1;
                                scale.y += 0.1;
                                it->get_sprite_decor().setScale(scale);
                            }
                            else if (event.mouseWheelScroll.delta < 0) {
                                sf::Vector2f scale = it->get_sprite_decor().getScale();
                                scale.x -= 0.1;
                                scale.y -= 0.1;
                                it->get_sprite_decor().setScale(scale);
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
                        if (it->get_sprite().getGlobalBounds().contains(mouse_coord.x, mouse_coord.y)) {
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
                                    world.DestroyBody(dynamic_cast<gobj::Rectangle*>(entity.objects_world.get_object_world(i))->get_body_pointer());
                                    if (entity.objects_world.get_object_world(i)->get_state()) {
                                        entity.label_weight.label_weight->setText("0");
                                    }
                                    auto it = entity.objects_world.list_object.begin();
                                    std::advance(it, i);
                                    entity.objects_world.list_object.erase(it);
                                }
                                else if (get_typename(entity.objects_world.get_object_world(i)) == "class gobj::Circle") {
                                    world.DestroyBody(dynamic_cast<gobj::Circle*>(entity.objects_world.get_object_world(i))->get_body_pointer());
                                    if (entity.objects_world.get_object_world(i)->get_state()) {
                                        entity.label_weight.label_weight->setText("0");
                                    }
                                    auto it = entity.objects_world.list_object.begin();
                                    std::advance(it, i);
                                    entity.objects_world.list_object.erase(it);
                                }

                            }

                        }
                }
            }


            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Delete) {
                    for (int i = 0; i < entity.decorative_objects_world.list_decor_elements.size(); ++i)
                        if (entity.decorative_objects_world.get_decor_object_world(i)->get_sprite_decor().getGlobalBounds().contains(entity.transfer_objects.get_mouse_coordinte(entity.window).x, entity.transfer_objects.get_mouse_coordinte(entity.window).y)) {
                            if (entity.decorative_objects_world.get_decor_object_world(i)->get_sprite_decor().getColor() == sf::Color::Red) {
                                auto it = entity.decorative_objects_world.list_decor_elements.begin();
                                std::advance(it, i);
                                entity.decorative_objects_world.list_decor_elements.erase(it);
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
                    if (entity.images_elements.menu_view) {
                        show_widgets(entity, false);
                    }
                    else {
                        show_widgets(entity, true);
                    }
                }

            }

 
            if (event.type == sf::Event::Closed)
                entity.window.close();
        }

        if (entity.transfer_objects.can_be_moved_decor_world) {
            for (auto const& it : entity.decorative_objects_world.list_decor_elements) {
                sf::Vector2f coord;
                coord.x = entity.transfer_objects.get_mouse_coordinte(entity.window).x;
                coord.y = entity.transfer_objects.get_mouse_coordinte(entity.window).y;
                sf::Vector2f del;
                del.x = entity.transfer_objects.deltaX;
                del.y = entity.transfer_objects.deltaY;

                if (it->get_sprite_decor().getGlobalBounds().contains(coord.x, coord.y)) {
                    if (it->check) {
                        it->get_sprite_decor().setPosition(coord.x - del.x, coord.y - del.y);
                    }
                }
            }
        }



        if (entity.transfer_objects.can_be_moved_objects_world) {
            for (auto const& it : entity.objects_world.list_object) {
                sf::Vector2f coord;
                coord.x = entity.transfer_objects.get_mouse_coordinte(entity.window).x;
                coord.y = entity.transfer_objects.get_mouse_coordinte(entity.window).y;
                sf::Vector2f del;
                del.x = entity.transfer_objects.deltaX;
                del.y = entity.transfer_objects.deltaY;

                if (it->get_sprite().getGlobalBounds().contains(coord.x, coord.y)) {
                    it->get_sprite().setPosition(coord.x - del.x, coord.y - del.y);
                    b2Vec2 delta;
                    delta.x = (coord.x - del.x) / SCALE;
                    delta.y = (coord.y - del.y) / SCALE;
                    b2Vec2 vector;
                    vector.x = delta.x - it->upperleft_coord_sprite().x;
                    vector.y = delta.y - it->upperleft_coord_sprite().y;
                    if (get_typename(it) == "class gobj::Rectangle") {
                        it->get_body_pointer()->SetTransform(vector, it->get_angle() / DEG);
                        it->get_body_pointer()->SetAwake(true);
                    }
                    else if (get_typename(it) == "class gobj::Circle") {
                        it->get_body_pointer()->SetTransform(vector, it->get_angle() / DEG);
                        it->get_body_pointer()->SetAwake(true);
                    }

                }

            }

        }

        

        world.Step(1 / 120.f, 8, 3);
        entity.window.clear();
        entity.window.draw(entity.game_background);
        entity.physics_player.jump(world);
        entity.physics_player.update(entity.window, entity.graphics_player.get_sprite());
        entity.window.draw(entity.decor_elements.get_sprite_decor());
        for (auto const& it : entity.objects_world.list_object) {
            it->update_position(entity.window);
        }

        for (auto const& it : entity.decorative_objects_world.list_decor_elements) {
            entity.window.draw(it->get_sprite_decor());
        }

        entity.window.draw(entity.images_elements.DisplayingItemRectangleShape.RectangleShape);
       
        if (entity.images_elements.menu_view) {
            entity.window.draw(entity.images_elements.get_sprite_fone());
        }

        if (debugging_view) {
            world.DebugDraw();
        }

        entity.GUI.draw();      
        entity.window.display();


    }
    return 0;
}
















































                 





























