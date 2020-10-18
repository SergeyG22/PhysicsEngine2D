#include <box2d/box2d.h>
#include <TGUI/TGUI.hpp>
#include "gui.h"

SmallEngineGUI::SmallEngineGUI(tgui::GuiSFML& GUI) {
    combo_box = tgui::ComboBox::create();
    combo_box->setSize(120, 21);
    combo_box->setPosition(60, 40);
    combo_box->addItem("800x600");
    combo_box->addItem("1024x768");
    combo_box->addItem("1280x1024");
    combo_box->addItem("1600x1200");
    combo_box->addItem("1920x1080");
    combo_box->setSelectedItem("800x600");
    GUI.add(combo_box);
}
