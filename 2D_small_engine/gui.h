#pragma once
#include "scene.h"


struct Button_create_script {
    tgui::Button::Ptr button_create_script;
    tgui::Layout width_create_script = 260;
    tgui::Layout height_create_script = 31;
    tgui::Layout pos_x_create_script = 455;
    tgui::Layout pos_y_create_script = 85;
    void set_offset(std::string);
    Button_create_script(tgui::GuiSFML&);
};

struct Button_loading_of_script {
    tgui::Button::Ptr button_loading_script;
    tgui::Layout width_loading_script = 260;
    tgui::Layout height_loading_script = 31;
    tgui::Layout pos_x_loading_script = 455;
    tgui::Layout pos_y_loading_script = 125;
    void set_offset(std::string);
    Button_loading_of_script(tgui::GuiSFML&);
};


struct Button_screen_mode {
    tgui::Button::Ptr button_screen_mode;
    tgui::Layout width_button_screen = 260;
    tgui::Layout height_button_screen = 31;
    tgui::Layout pos_x_button_screen = 455;
    tgui::Layout pos_y_button_screen = 325;
    bool enable_fullscreen = true;
    void set_offset(std::string);
    Button_screen_mode(tgui::GuiSFML&);
};

struct Button_download_fone {   
    tgui::Button::Ptr button_download_fone;
    tgui::Layout width_button_download_fone = 260;
    tgui::Layout height_button_download_fone = 31;
    tgui::Layout pos_x_button_download_fone = 455;
    tgui::Layout pos_y_button_download_fone = 245;
    void set_offset(std::string);
    Button_download_fone(tgui::GuiSFML&);
};

struct Button_switching_fullscreen {
    tgui::Button::Ptr button_switching_fullscreen;
    tgui::Layout width_button_switching_fullscreen = 260;
    tgui::Layout height_button_switching_fullscreen = 31;
    tgui::Layout pos_x_button_switching_fullscreen = 455;
    tgui::Layout pos_y_button_switching_fullscreen = 285;
    void set_offset(std::string);
    Button_switching_fullscreen(tgui::GuiSFML&);
};

struct Button_download_texture {
    tgui::Button::Ptr button_download_texture;
    tgui::Layout width_button_download = 260;
    tgui::Layout height_button_download = 31;
    tgui::Layout pos_x_button_download = 455;
    tgui::Layout pos_y_button_download = 205;
    void set_offset(std::string);
    Button_download_texture(tgui::GuiSFML&);
};

struct Button_settings_decoration {
    tgui::Button::Ptr button_settings_decoration;
    tgui::Layout width_settings_decoration = 260;
    tgui::Layout height_settings_decoration = 31;
    tgui::Layout pos_x_settings_decoration = 455;
    tgui::Layout pos_y_settings_decoration = 165;
    void set_offset(std::string);
    Button_settings_decoration(tgui::GuiSFML&);
};

struct Combo_box_invisible_object {
    tgui::ComboBox::Ptr combo_box_invisible_object;
    tgui::Layout width_combo_box_invisible_object = 310;
    tgui::Layout height_combo_box_invisible_object = 31;
    tgui::Layout pos_x_combo_box_invisible_object = 65;
    tgui::Layout pos_y_combo_box_invisible_object = 125;
    tgui::Theme theme{ "themes/Black.txt" };
    void set_offset(std::string);
    Combo_box_invisible_object(tgui::GuiSFML&);
};

struct Combo_box_filepath_fone {
    tgui::ComboBox::Ptr combo_box_file_path_fone;
    tgui::Layout width_combo_box_file_path_fone = 310;
    tgui::Layout height_combo_box_file_path_fone = 31;
    tgui::Layout pos_x_combo_box_file_path_fone = 65;
    tgui::Layout pos_y_combo_box_file_path_fone = 285;
    tgui::Theme theme{ "themes/Black.txt" };
    void set_options_fone();
    void set_offset(std::string);
    Combo_box_filepath_fone(tgui::GuiSFML&);
    bool show_first_element = true;
};

struct Combo_box_figure {
    tgui::ComboBox::Ptr combo_box_figure;
    tgui::Layout width_combo_box_figure = 310;
    tgui::Layout height_combo_box_figure = 31;
    tgui::Layout pos_x_combo_box_figure = 65;
    tgui::Layout pos_y_combo_box_figure = 205;
    tgui::Theme theme{ "themes/Black.txt" };
    void set_offset(std::string);
    Combo_box_figure(tgui::GuiSFML&);
};

struct Combo_box_typebody {
    tgui::ComboBox::Ptr combo_box_type_body;
    tgui::Layout width_combo_box_typebody = 310;
    tgui::Layout height_combo_box_typebody = 31;
    tgui::Layout pos_x_combo_box_typebody = 65;
    tgui::Layout pos_y_combo_box_typebody = 165;
    tgui::Theme theme{ "themes/Black.txt" };
    void set_offset(std::string);
    Combo_box_typebody(tgui::GuiSFML&);
};

struct Combo_box_file_path_texture {
    tgui::ComboBox::Ptr combo_box_file_path_texture;
    tgui::Layout width_combo_box_file_path_texture = 310;
    tgui::Layout height_combo_box_file_path_texture = 31;
    tgui::Layout pos_x_combo_box_file_path_texture = 65;
    tgui::Layout pos_y_combo_box_file_path_texture = 245;
    tgui::Theme theme{ "themes/Black.txt" };
    void set_options_texture(std::string);
    void set_offset(std::string);
    Combo_box_file_path_texture(tgui::GuiSFML&);
    bool show_first_element = true;
};

struct Combo_box {
    tgui::ComboBox::Ptr combo_box;
    tgui::Layout width_combo_box = 310;
    tgui::Layout height_combo_box = 31;
    tgui::Layout pos_x_combo_box = 65;
    tgui::Layout pos_y_combo_box = 85;
    tgui::Theme theme{ "themes/Black.txt" };
    void set_offset(std::string);
    Combo_box(tgui::GuiSFML&);
};

struct Combo_box_decor {
    tgui::ComboBox::Ptr combo_box_decor;
    tgui::Layout width_combo_box_decor = 310;
    tgui::Layout height_combo_box_decor = 31;
    tgui::Layout pos_x_combo_box_decor = 65;
    tgui::Layout pos_y_combo_box_decor = 325;
    tgui::Theme theme{ "themes/Black.txt" };
    void set_offset(std::string);
    void set_options_decor();
    Combo_box_decor(tgui::GuiSFML&);
    bool show_first_element = true;
};

struct Combo_box_script {
    tgui::ComboBox::Ptr combo_box_script;
    tgui::Layout width_combo_box_script = 310;
    tgui::Layout height_combo_box_script = 31;
    tgui::Layout pos_x_combo_box_script = 65;
    tgui::Layout pos_y_combo_box_script = 365;
    tgui::Theme theme{ "themes/Black.txt" };
    void set_offset(std::string);
    void set_options_script();
    Combo_box_script(tgui::GuiSFML&);
    bool show_first_element;
};


struct Slider_weight_setting {
    tgui::Slider::Ptr slider_weight_setting;
    tgui::Layout width_slider_weight_setting = 210;
    tgui::Layout height_slider_weight_setting = 15;
    tgui::Layout pos_x_slider_weight_setting = 75;
    tgui::Layout pos_y_slider_weight_setting = 425;
    tgui::Theme theme{ "themes/Black.txt" };
    void set_offset(std::string);
    Slider_weight_setting(tgui::GuiSFML&);
};

struct Label_weight {
    tgui::Label::Ptr label_weight;
    tgui::Layout width_label_weight = 310;
    tgui::Layout height_label_weight = 150;
    tgui::Layout pos_x_label_weight = 295;
    tgui::Layout pos_y_label_weight = 415;
    Label_weight(tgui::GuiSFML&);
    void set_offset(std::string);
};

class DisplayingSelectedItem { 
public:  
    DisplayingSelectedItem();
    sf::RectangleShape RectangleShape;
    void update_position(sf::RenderWindow&,sf::RectangleShape&, std::list<gobj::ObjectFactory*>::iterator::value_type it);
};

class Decor_elements {
    sf::Sprite s_decor;
    float x_pos;
    float y_pos;
public:
    Decor_elements(std::string,float,float);
    Decor_elements() {};
    sf::Sprite& get_sprite_decor() { return s_decor; }
    sf::Texture t_decor;
    bool check = false;
};

struct DecorativeObjectsWorld {
    std::list<Decor_elements*>list_decor_elements;
    Decor_elements* get_decor_object_world(int);
};



class Images_elements
{
   sf::Texture t_fone_menu;
   sf::Texture t_target;
   sf::Sprite s_fone_menu;
   sf::Sprite s_target;
public:
  DisplayingSelectedItem DisplayingItemRectangleShape;
  Images_elements(sf::RenderWindow&);
  sf::Sprite& get_sprite_fone() { return s_fone_menu; }
  sf::Sprite& get_sprite_target() { return s_target;  }
  bool menu_view = false;
};




