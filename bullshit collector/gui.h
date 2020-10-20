#pragma once
#include "scene.h"

class SmallEngineGUI {
    sf::Texture t_fone_menu;
    sf::Sprite s_fone_menu;
public:
  SmallEngineGUI(tgui::GuiSFML&);
  tgui::ComboBox::Ptr combo_box;
  tgui::CheckBox::Ptr check_box_autoscaling;
  tgui::Label::Ptr label_settings;
  tgui::EditBox::Ptr edit_box_file_path;
  sf::Sprite& get_sprite_fone() { return s_fone_menu; }
  void displaying_widgets();
  bool menu_view = false;
  //########## combo_box
  tgui::Layout width_combo_box = 160;
  tgui::Layout height_combo_box = 31;
  tgui::Layout pos_x_combo_box = 65;
  tgui::Layout pos_y_combo_box = 165;
  //######### label_settings
  tgui::Layout width_label_settings = 160;
  tgui::Layout height_label_settings = 150;
  tgui::Layout pos_x_label_settings = 145;
  tgui::Layout pos_y_label_settings = 60;
  //######### checkbox_autoscaling
  tgui::Layout width_check_box_autoscaling = 31;
  tgui::Layout height_check_box_autoscaling = 31;
  tgui::Layout pos_x_check_box_autoscaling = 65;
  tgui::Layout pos_y_check_box_autoscaling = 115;
  //######### edit_box filepath
  tgui::Layout width_edit_box_file_path = 260;
  tgui::Layout height_edit_box_file_path = 31;
  tgui::Layout pos_x_edit_box_file_path = 65;
  tgui::Layout pos_y_edit_box_file_path = 215;

};

