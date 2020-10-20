#include <box2d/box2d.h>
#include <TGUI/TGUI.hpp>
#include "gui.h"

SmallEngineGUI::SmallEngineGUI(tgui::GuiSFML& GUI) {

    if (!t_fone_menu.loadFromFile("menu.png")) { std::cout << "t_fone_menu error loading texture\n"; };
    s_fone_menu.setTexture(t_fone_menu);
    s_fone_menu.setPosition(10,10);
    combo_box = tgui::ComboBox::create();
    combo_box->setVisible(false);
    combo_box->setTextSize(20);       // ÄÎÏÈËÈÒÜ ÐÀÇÌÅÐ!!!!!!!!!!!!!!!!!!!!!!!!
    combo_box->setSize(width_combo_box, height_combo_box);
    combo_box->setPosition(pos_x_combo_box,pos_y_combo_box);
    combo_box->addItem("800x600");
    combo_box->addItem("1024x768");
    combo_box->addItem("1280x1024");
    combo_box->addItem("1600x1200");
    combo_box->addItem("1920x1080");
    combo_box->setSelectedItem("800x600");
    GUI.add(combo_box);

    label_settings = tgui::Label::create();
    label_settings->setVisible(false);
    label_settings->setPosition(pos_x_label_settings,pos_y_label_settings);
    label_settings->setText(L"Íàñòðîéêè");
    label_settings->setTextSize(20);
    GUI.add(label_settings);

    check_box_autoscaling = tgui::CheckBox::create();
    check_box_autoscaling->setChecked(true);
    check_box_autoscaling->setVisible(false);
    check_box_autoscaling->setPosition(pos_x_check_box_autoscaling, pos_y_check_box_autoscaling);
    check_box_autoscaling->setText(L"Ìàñøòàáèðîâàíèå");
    check_box_autoscaling->setSize(width_check_box_autoscaling, height_check_box_autoscaling);
    check_box_autoscaling->setTextSize(20);
    GUI.add(check_box_autoscaling);

    edit_box_file_path = tgui::EditBox::create();
    edit_box_file_path->setSize(width_edit_box_file_path,height_edit_box_file_path);
    edit_box_file_path->setText("C:\\Users\\Dolba");
    edit_box_file_path->setTextSize(20);
    edit_box_file_path->setVisible(false);
    edit_box_file_path->setPosition(pos_x_edit_box_file_path,pos_y_edit_box_file_path);
    GUI.add(edit_box_file_path);
}

void SmallEngineGUI::displaying_widgets() {
    combo_box->setVisible(menu_view);
    label_settings->setVisible(menu_view);
    check_box_autoscaling->setVisible(menu_view);
    edit_box_file_path->setVisible(menu_view);
}