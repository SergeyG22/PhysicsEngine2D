#pragma once
#include "scene.h"

struct button_fullscreen_mode {
    tgui::Layout width_button_fullscreen = 260;
    tgui::Layout height_button_fullscreen = 31;
    tgui::Layout pos_x_button_fullscreen = 95;
    tgui::Layout pos_y_button_fullscreen = 450;
};

struct button_download_fone {
    tgui::Layout width_button_download_fone = 190;
    tgui::Layout height_button_download_fone = 31;
    tgui::Layout pos_x_button_download_fone = 125;
    tgui::Layout pos_y_button_download_fone = 410;
};

struct combo_box_filepath_fone {
    tgui::Layout width_combo_box_file_path_fone = 310;
    tgui::Layout height_combo_box_file_path_fone = 31;
    tgui::Layout pos_x_combo_box_file_path_fone = 65;
    tgui::Layout pos_y_combo_box_file_path_fone = 325;
};

struct combo_box_figure {
    tgui::Layout width_combo_box_figure = 310;
    tgui::Layout height_combo_box_figure = 31;
    tgui::Layout pos_x_combo_box_figure = 65;
    tgui::Layout pos_y_combo_box_figure = 245;
};

struct button_download_texture {
    tgui::Layout width_button_download = 190;
    tgui::Layout height_button_download = 31;
    tgui::Layout pos_x_button_download = 125;
    tgui::Layout pos_y_button_download = 370;
};

struct combo_box_typebody {
    tgui::Layout width_combo_box_typebody = 310;
    tgui::Layout height_combo_box_typebody = 31;
    tgui::Layout pos_x_combo_box_typebody = 65;
    tgui::Layout pos_y_combo_box_typebody = 205;
};

struct combo_box_file_path_texture {
    tgui::Layout width_combo_box_file_path_texture = 310;
    tgui::Layout height_combo_box_file_path_texture = 31;
    tgui::Layout pos_x_combo_box_file_path_texture = 65;
    tgui::Layout pos_y_combo_box_file_path_texture = 285;
};

struct label_settings {
    tgui::Layout width_label_settings = 310;
    tgui::Layout height_label_settings = 150;
    tgui::Layout pos_x_label_settings = 125;
    tgui::Layout pos_y_label_settings = 80;
};

struct combo_box {
    tgui::Layout width_combo_box = 310;
    tgui::Layout height_combo_box = 31;
    tgui::Layout pos_x_combo_box = 65;
    tgui::Layout pos_y_combo_box = 165;
};

class SmallEngineGUI : public combo_box, public label_settings,public combo_box_file_path_texture,
                       public combo_box_typebody, public button_download_texture, public combo_box_figure,
                       public combo_box_filepath_fone, public button_download_fone,public button_fullscreen_mode
{
    sf::Texture t_fone_menu;
    sf::Sprite s_fone_menu;
public:
  SmallEngineGUI(tgui::GuiSFML&);
  tgui::Theme theme{ "themes/Black.txt" }; 
  tgui::Label::Ptr label_settings;
  tgui::ComboBox::Ptr combo_box_file_path_texture;
  tgui::ComboBox::Ptr combo_box_type_body;
  tgui::ComboBox::Ptr combo_box_figure;
  tgui::ComboBox::Ptr combo_box_file_path_fone;
  tgui::ComboBox::Ptr combo_box;
  tgui::Button::Ptr button_download;  
  tgui::Button::Ptr button_download_fone;
  tgui::Button::Ptr button_fullscreen_mode;
  sf::Sprite& get_sprite_fone() { return s_fone_menu; }
  void displaying_widgets();
  void SET_OPTIONS_combo_box_fone();
  void SET_OPTIONS_combo_box_texture();
  bool menu_view = false;
  bool enable_fullscreen = true;
};

