#pragma once
#include "scene.h"

class SmallEngineGUI {
    sf::Texture t_fone_menu;
    sf::Sprite s_fone_menu;
public:
  SmallEngineGUI(tgui::GuiSFML&);
  tgui::ComboBox::Ptr combo_box;
  sf::Sprite& get_sprite_fone() { return s_fone_menu; }
  void displaying_widgets();
  bool menu_view = false;
};

