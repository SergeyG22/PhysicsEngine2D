#include <box2d/box2d.h>
#include <TGUI/TGUI.hpp>
#include "gui.h"

SmallEngineGUI::SmallEngineGUI(tgui::GuiSFML& GUI) {

    if (!t_fone_menu.loadFromFile("menu.png")) { std::cout << "t_fone_menu error loading texture\n"; };
    s_fone_menu.setTexture(t_fone_menu);
    s_fone_menu.setPosition(10,10);
    combo_box = tgui::ComboBox::create();
    combo_box->setRenderer(theme.getRenderer("ComboBox"));
    combo_box->setVisible(false);
    combo_box->setTextSize(20);      
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
    label_settings->setText(L"Настройки");
    label_settings->setTextSize(30);
    GUI.add(label_settings);

    edit_box_file_path = tgui::EditBox::create();
    edit_box_file_path->setRenderer(theme.getRenderer("EditBox"));
    edit_box_file_path->setSize(width_edit_box_file_path,height_edit_box_file_path);
    edit_box_file_path->setText("C:\\Users\\Dolba\\texture.png");
    edit_box_file_path->setTextSize(20);
    edit_box_file_path->setVisible(false);
    edit_box_file_path->setPosition(pos_x_edit_box_file_path,pos_y_edit_box_file_path);
    GUI.add(edit_box_file_path);

    combo_box_type_body = tgui::ComboBox::create();
    combo_box_type_body->setRenderer(theme.getRenderer("ComboBox"));
    combo_box_type_body->setVisible(false);
    combo_box_type_body->setTextSize(20);                   
    combo_box_type_body->setSize(width_combo_box_typebody, height_combo_box_typebody);
    combo_box_type_body->setPosition(pos_x_combo_box_typebody, pos_y_combo_box_typebody);
    combo_box_type_body->addItem(L"Статическое");
    combo_box_type_body->addItem(L"Динамическое");
    combo_box_type_body->setSelectedItem(L"Статическое");
    GUI.add(combo_box_type_body);

    button_download = tgui::Button::create();
    button_download->setVisible(false);
    button_download->setTextSize(20);
    button_download->setPosition(pos_x_button_download,pos_y_button_download);
    button_download->setText(L"Создать тело");
    button_download->setSize(width_button_download, height_button_download);
    GUI.add(button_download);

    combo_box_figure = tgui::ComboBox::create();
    combo_box_figure->setRenderer(theme.getRenderer("ComboBox"));
    combo_box_figure->setVisible(false);
    combo_box_figure->setTextSize(20);
    combo_box_figure->setSize(width_combo_box_figure, height_combo_box_figure);
    combo_box_figure->setPosition(pos_x_combo_box_figure, pos_y_combo_box_figure);
    combo_box_figure->addItem(L"Круг");
    combo_box_figure->addItem(L"Угол");
    combo_box_figure->addItem(L"Полигон");
    combo_box_figure->addItem(L"Цепь");
    combo_box_figure->setSelectedItem(L"Полигон");
    GUI.add(combo_box_figure);

    edit_box_file_path_fone = tgui::EditBox::create();
    edit_box_file_path_fone->setRenderer(theme.getRenderer("EditBox"));
    edit_box_file_path_fone->setSize(width_edit_box_file_path_fone, height_edit_box_file_path_fone);
    edit_box_file_path_fone->setText("C:\\Users\\Dolba\\fone.png");
    edit_box_file_path_fone->setTextSize(20);
    edit_box_file_path_fone->setVisible(false);
    edit_box_file_path_fone->setPosition(pos_x_edit_box_file_path_fone, pos_y_edit_box_file_path_fone);
    GUI.add(edit_box_file_path_fone);

    button_download_fone = tgui::Button::create();
    button_download_fone->setVisible(false);
    button_download_fone->setTextSize(20);
    button_download_fone->setPosition(pos_x_button_download_fone, pos_y_button_download_fone);
    button_download_fone->setText(L"Установить фон");
    button_download_fone->setSize(width_button_download_fone, height_button_download_fone);
    GUI.add(button_download_fone);



}

void SmallEngineGUI::displaying_widgets() {
    combo_box->setVisible(menu_view);
    label_settings->setVisible(menu_view);
    edit_box_file_path->setVisible(menu_view);
    combo_box_type_body->setVisible(menu_view);
    button_download->setVisible(menu_view);
    combo_box_figure->setVisible(menu_view);
    edit_box_file_path_fone->setVisible(menu_view);
    button_download_fone->setVisible(menu_view);
}