#pragma once
#include "scene.h"

struct Button_screen_mode {
    tgui::Button::Ptr button_screen_mode;
    tgui::Layout width_button_screen = 260;
    tgui::Layout height_button_screen = 31;
    tgui::Layout pos_x_button_screen = 95;
    tgui::Layout pos_y_button_screen = 450;
    bool enable_fullscreen = true;
    void set_offset(std::string);
    Button_screen_mode(tgui::GuiSFML&);
};

struct Button_download_fone {   
    tgui::Button::Ptr button_download_fone;
    tgui::Layout width_button_download_fone = 190;
    tgui::Layout height_button_download_fone = 31;
    tgui::Layout pos_x_button_download_fone = 125;
    tgui::Layout pos_y_button_download_fone = 410;
    void set_offset(std::string);
    Button_download_fone(tgui::GuiSFML&);
};

struct Button_switching_fullscreen {
    tgui::Button::Ptr button_switching_fullscreen;
    tgui::Layout width_button_switching_fullscreen = 260;
    tgui::Layout height_button_switching_fullscreen = 35;
    tgui::Layout pos_x_button_switching_fullscreen = 95;
    tgui::Layout pos_y_button_switching_fullscreen = 490;
    void set_offset(std::string);
    Button_switching_fullscreen(tgui::GuiSFML&);
};

struct Button_download_texture {
    tgui::Button::Ptr button_download_texture;
    tgui::Layout width_button_download = 190;
    tgui::Layout height_button_download = 31;
    tgui::Layout pos_x_button_download = 125;
    tgui::Layout pos_y_button_download = 370;
    void set_offset(std::string);
    Button_download_texture(tgui::GuiSFML&);
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

struct Slider_weight_setting {
    tgui::Slider::Ptr slider_weight_setting;
    tgui::Layout width_slider_weight_setting = 210;
    tgui::Layout height_slider_weight_setting = 15;
    tgui::Layout pos_x_slider_weight_setting = 75;
    tgui::Layout pos_y_slider_weight_setting = 335;
    tgui::Theme theme{ "themes/Black.txt" };
    void set_offset(std::string);
    Slider_weight_setting(tgui::GuiSFML&);
};

struct Label_weight {
    tgui::Label::Ptr label_weight;
    tgui::Layout width_label_weight = 310;
    tgui::Layout height_label_weight = 150;
    tgui::Layout pos_x_label_weight = 295;
    tgui::Layout pos_y_label_weight = 320;
    Label_weight(tgui::GuiSFML&);
    void set_offset(std::string);
};

class DisplayingSelectedItem { 
public:  
    DisplayingSelectedItem();
    sf::RectangleShape RectangleShape;
    void update_position(sf::RenderWindow&,sf::RectangleShape&, std::list<gobj::ObjectFactory*>::iterator::value_type it);
};

class Decorative_elements
{
   sf::Texture t_fone_menu;
   sf::Sprite s_fone_menu; 
public:
  DisplayingSelectedItem DisplayingItemRectangleShape;
  Decorative_elements();
  sf::Sprite& get_sprite_fone() { return s_fone_menu; }
  bool menu_view = false;
  bool red_points_view = false;
};




