#include <box2d/box2d.h>
#include <TGUI/TGUI.hpp>
#include "gui.h"

SmallEngineGUI::SmallEngineGUI(tgui::GuiSFML& GUI) {

    if (!t_fone_menu.loadFromFile("menu.png")) { std::cout << "t_fone_menu error loading texture\n"; };
     s_fone_menu.setTexture(t_fone_menu);
     s_fone_menu.setPosition(10,10);
    combo_box = tgui::ComboBox::create();
    combo_box->setVisible(false);
    combo_box->setSize(160, 31);
    combo_box->setPosition(145,145);
    combo_box->addItem("800x600");
    combo_box->addItem("1024x768");
    combo_box->addItem("1280x1024");
    combo_box->addItem("1600x1200");
    combo_box->addItem("1920x1080");
    combo_box->setSelectedItem("800x600");
    GUI.add(combo_box);
}

void SmallEngineGUI::displaying_widgets() {
    combo_box->setVisible(menu_view);
}