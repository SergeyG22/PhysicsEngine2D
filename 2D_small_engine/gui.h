#pragma once
#include "scene.h"

struct Button_fullscreen_mode {
    tgui::Button::Ptr button_fullscreen_mode;
    tgui::Layout width_button_fullscreen = 260;
    tgui::Layout height_button_fullscreen = 31;
    tgui::Layout pos_x_button_fullscreen = 95;
    tgui::Layout pos_y_button_fullscreen = 450;
    bool enable_fullscreen = true;
    void set_offset(std::string);
    Button_fullscreen_mode(tgui::GuiSFML&);
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
    tgui::Layout pos_y_combo_box_file_path_fone = 325;
    tgui::Theme theme{ "themes/Black.txt" };
    void set_options_fone();
    void set_offset(std::string);
    Combo_box_filepath_fone(tgui::GuiSFML&);
};

struct Combo_box_figure {
    tgui::ComboBox::Ptr combo_box_figure;
    tgui::Layout width_combo_box_figure = 310;
    tgui::Layout height_combo_box_figure = 31;
    tgui::Layout pos_x_combo_box_figure = 65;
    tgui::Layout pos_y_combo_box_figure = 245;
    tgui::Theme theme{ "themes/Black.txt" };
    void set_offset(std::string);
    Combo_box_figure(tgui::GuiSFML&);
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

struct Combo_box_typebody {
    tgui::ComboBox::Ptr combo_box_type_body;
    tgui::Layout width_combo_box_typebody = 310;
    tgui::Layout height_combo_box_typebody = 31;
    tgui::Layout pos_x_combo_box_typebody = 65;
    tgui::Layout pos_y_combo_box_typebody = 205;
    tgui::Theme theme{ "themes/Black.txt" };
    void set_offset(std::string);
    Combo_box_typebody(tgui::GuiSFML&);
};

struct Combo_box_file_path_texture {
    tgui::ComboBox::Ptr combo_box_file_path_texture;
    tgui::Layout width_combo_box_file_path_texture = 310;
    tgui::Layout height_combo_box_file_path_texture = 31;
    tgui::Layout pos_x_combo_box_file_path_texture = 65;
    tgui::Layout pos_y_combo_box_file_path_texture = 285;
    tgui::Theme theme{ "themes/Black.txt" };
    void set_options_texture(std::string);
    void set_offset(std::string);
    Combo_box_file_path_texture(tgui::GuiSFML&);
    bool show_first_element = true;
};

struct Label_settings {
    tgui::Label::Ptr label_settings;
    tgui::Layout width_label_settings = 310;
    tgui::Layout height_label_settings = 150;
    tgui::Layout pos_x_label_settings = 125;
    tgui::Layout pos_y_label_settings = 80;
    Label_settings(tgui::GuiSFML&);
    void set_offset(std::string);
};

struct Combo_box {
    tgui::ComboBox::Ptr combo_box;
    tgui::Layout width_combo_box = 310;
    tgui::Layout height_combo_box = 31;
    tgui::Layout pos_x_combo_box = 65;
    tgui::Layout pos_y_combo_box = 165;
    tgui::Theme theme{ "themes/Black.txt" };
    void set_offset(std::string);
    Combo_box(tgui::GuiSFML&);
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




