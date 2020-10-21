#pragma once
#include "scene.h"

class SmallEngineGUI {
    sf::Texture t_fone_menu;
    sf::Sprite s_fone_menu;
public:
  SmallEngineGUI(tgui::GuiSFML&);
  tgui::Theme theme{ "themes/Black.txt" };
  tgui::ComboBox::Ptr combo_box;
  tgui::Label::Ptr label_settings;
  tgui::EditBox::Ptr edit_box_file_path;
  tgui::ComboBox::Ptr combo_box_type_body;
  tgui::ComboBox::Ptr combo_box_figure;
  tgui::Button::Ptr button_download;
  tgui::EditBox::Ptr edit_box_file_path_fone;
  tgui::Button::Ptr button_download_fone;
  sf::Sprite& get_sprite_fone() { return s_fone_menu; }
  void displaying_widgets();
  bool menu_view = false;
  //combo_box
  tgui::Layout width_combo_box = 310;
  tgui::Layout height_combo_box = 31;
  tgui::Layout pos_x_combo_box = 65;
  tgui::Layout pos_y_combo_box = 165;
  //label_settings
  tgui::Layout width_label_settings = 310;
  tgui::Layout height_label_settings = 150;
  tgui::Layout pos_x_label_settings = 125;
  tgui::Layout pos_y_label_settings = 80;
  //edit_box filepath texture
  tgui::Layout width_edit_box_file_path = 310;
  tgui::Layout height_edit_box_file_path = 31;
  tgui::Layout pos_x_edit_box_file_path = 65;
  tgui::Layout pos_y_edit_box_file_path = 285;
  //combo_box typebody
  tgui::Layout width_combo_box_typebody = 310;
  tgui::Layout height_combo_box_typebody = 31;
  tgui::Layout pos_x_combo_box_typebody = 65;
  tgui::Layout pos_y_combo_box_typebody = 205;
  //button_download texture
  tgui::Layout width_button_download = 190;
  tgui::Layout height_button_download = 31;
  tgui::Layout pos_x_button_download = 125;
  tgui::Layout pos_y_button_download = 370;
  //combo_box figure
  tgui::Layout width_combo_box_figure = 310;
  tgui::Layout height_combo_box_figure = 31;
  tgui::Layout pos_x_combo_box_figure = 65;
  tgui::Layout pos_y_combo_box_figure = 245;
  //edit_box filepath fone
  tgui::Layout width_edit_box_file_path_fone = 310;
  tgui::Layout height_edit_box_file_path_fone = 31;
  tgui::Layout pos_x_edit_box_file_path_fone = 65;
  tgui::Layout pos_y_edit_box_file_path_fone = 325;
  //button download fone
  tgui::Layout width_button_download_fone = 190;
  tgui::Layout height_button_download_fone = 31;
  tgui::Layout pos_x_button_download_fone = 125;
  tgui::Layout pos_y_button_download_fone = 410;
};

