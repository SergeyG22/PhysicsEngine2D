#include <box2d/box2d.h>
#include <TGUI/TGUI.hpp>
#include "gui.h"

SmallEngineGUI::SmallEngineGUI(tgui::GuiSFML& T_GUI) {
	   auto button = tgui::Button::create("button");
       button->setPosition(300,300);
       T_GUI.add(button);
}

