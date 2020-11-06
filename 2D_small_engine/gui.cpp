#include <box2d/box2d.h>
#include <TGUI/TGUI.hpp>
#include <iostream>
#include <boost/filesystem.hpp>
#include "gui.h"


Button_fullscreen_mode::Button_fullscreen_mode(tgui::GuiSFML& GUI) {
    button_fullscreen_mode = tgui::Button::create();
    button_fullscreen_mode->setVisible(false);
    button_fullscreen_mode->setTextSize(20);
    button_fullscreen_mode->setPosition(pos_x_button_fullscreen, pos_y_button_fullscreen);
    button_fullscreen_mode->setText(L"Экранный режим");
    button_fullscreen_mode->setSize(width_button_fullscreen, height_button_fullscreen);
    GUI.add(button_fullscreen_mode);
}

void Button_fullscreen_mode::set_offset(std::string screen_size) {
    if (screen_size == "800x600") {
        button_fullscreen_mode->setSize(width_button_fullscreen,height_button_fullscreen);
        button_fullscreen_mode->setPosition(pos_x_button_fullscreen, pos_y_button_fullscreen);
        button_fullscreen_mode->setTextSize(20);
    }
    else if (screen_size == "1024x768") {
        button_fullscreen_mode->setSize(width_button_fullscreen * 1.28, height_button_fullscreen * 1.28);
        button_fullscreen_mode->setPosition(pos_x_button_fullscreen * 1.28, pos_y_button_fullscreen * 1.28);
        button_fullscreen_mode->setTextSize(20 * 1.28);
    }
    else if (screen_size == "1280x1024") {
        button_fullscreen_mode->setSize(width_button_fullscreen * 1.6, height_button_fullscreen * 1.7024);
        button_fullscreen_mode->setPosition(pos_x_button_fullscreen * 1.6, pos_y_button_fullscreen * 1.7024);
        button_fullscreen_mode->setTextSize(20 * 1.65);
    }
    else  if (screen_size == "1600x1200") {
        button_fullscreen_mode->setSize(width_button_fullscreen * 2, height_button_fullscreen * 1.9918);
        button_fullscreen_mode->setPosition(pos_x_button_fullscreen * 2, pos_y_button_fullscreen * 1.9918);
        button_fullscreen_mode->setTextSize(20 * 2);
    }
    else if (screen_size == "1920x1080") {
        button_fullscreen_mode->setSize(width_button_fullscreen * 2.4, height_button_fullscreen * 1.79262);
        button_fullscreen_mode->setPosition(pos_x_button_fullscreen * 2.4, pos_y_button_fullscreen * 1.79262);
        button_fullscreen_mode->setTextSize(20 * 2.1);
    }
    // 1.28, 1.6 , 2, 2.4 - the scale factor is obtained by dividing one resolution by another:
    // 1024/800 = 1.28   
    // 786/600 = 1.28 
}

Button_download_fone::Button_download_fone(tgui::GuiSFML& GUI) {
    button_download_fone = tgui::Button::create();
    button_download_fone->setVisible(false);
    button_download_fone->setTextSize(20);
    button_download_fone->setPosition(pos_x_button_download_fone, pos_y_button_download_fone);
    button_download_fone->setText(L"Установить фон");
    button_download_fone->setSize(width_button_download_fone, height_button_download_fone);
    GUI.add(button_download_fone);
}

void Button_download_fone::set_offset(std::string screen_size) {
    if (screen_size == "800x600") {
        button_download_fone->setSize(width_button_download_fone, height_button_download_fone);
        button_download_fone->setPosition(pos_x_button_download_fone, pos_y_button_download_fone);
        button_download_fone->setTextSize(20);
    }
    else if (screen_size == "1024x768") {
        button_download_fone->setSize(width_button_download_fone * 1.28, height_button_download_fone * 1.28);
        button_download_fone->setPosition(pos_x_button_download_fone * 1.28, pos_y_button_download_fone * 1.28);
        button_download_fone->setTextSize(20 * 1.28);
    }
    else if (screen_size == "1280x1024") {
        button_download_fone->setSize(width_button_download_fone * 1.6, height_button_download_fone * 1.7024);
        button_download_fone->setPosition(pos_x_button_download_fone * 1.6, pos_y_button_download_fone * 1.7024);
        button_download_fone->setTextSize(20 * 1.65);
    }
    else  if (screen_size == "1600x1200") {
        button_download_fone->setSize(width_button_download_fone * 2, height_button_download_fone * 1.9918);
        button_download_fone->setPosition(pos_x_button_download_fone * 2, pos_y_button_download_fone * 1.9918);
        button_download_fone->setTextSize(20 * 2);
    }
    else if (screen_size == "1920x1080") {
        button_download_fone->setSize(width_button_download_fone * 2.4, height_button_download_fone * 1.79262);
        button_download_fone->setPosition(pos_x_button_download_fone * 2.4, pos_y_button_download_fone * 1.7962);
        button_download_fone->setTextSize(20 * 2.1);
    }
}

Combo_box_filepath_fone::Combo_box_filepath_fone(tgui::GuiSFML& GUI) {
    combo_box_file_path_fone = tgui::ComboBox::create();
    combo_box_file_path_fone->setRenderer(theme.getRenderer("ComboBox"));
    combo_box_file_path_fone->setSize(width_combo_box_file_path_fone, height_combo_box_file_path_fone);
    set_options_fone();
    combo_box_file_path_fone->setTextSize(20);
    combo_box_file_path_fone->setVisible(false);
    combo_box_file_path_fone->setPosition(pos_x_combo_box_file_path_fone, pos_y_combo_box_file_path_fone);
    GUI.add(combo_box_file_path_fone);
}

Combo_box_invisible_object::Combo_box_invisible_object(tgui::GuiSFML& GUI) {
    combo_box_invisible_object = tgui::ComboBox::create();
    combo_box_invisible_object->setRenderer(theme.getRenderer("ComboBox"));
    combo_box_invisible_object->setSize(width_combo_box_invisible_object, height_combo_box_invisible_object);
    combo_box_invisible_object->addItem(L"Объект без текстуры","1");
    combo_box_invisible_object->addItem(L"Объект с текстурой", "2");
    combo_box_invisible_object->setSelectedItem(L"Объект с текстурой");
    combo_box_invisible_object->setTextSize(20);
    combo_box_invisible_object->setVisible(false);
    combo_box_invisible_object->setPosition(pos_x_combo_box_invisible_object, pos_y_combo_box_invisible_object);
    GUI.add(combo_box_invisible_object);
}

void Combo_box_invisible_object::set_offset(std::string screen_size) {
    if (screen_size == "800x600") {
        combo_box_invisible_object->setSize(width_combo_box_invisible_object, height_combo_box_invisible_object);
        combo_box_invisible_object->setPosition(pos_x_combo_box_invisible_object, pos_y_combo_box_invisible_object);
        combo_box_invisible_object->setTextSize(20);
    }
    else if (screen_size == "1024x768") {
        combo_box_invisible_object->setSize(width_combo_box_invisible_object * 1.28, height_combo_box_invisible_object * 1.28);
        combo_box_invisible_object->setPosition(pos_x_combo_box_invisible_object * 1.28, pos_y_combo_box_invisible_object * 1.28);
        combo_box_invisible_object->setTextSize(20 * 1.28);
    }
    else if (screen_size == "1280x1024") {
        combo_box_invisible_object->setSize(width_combo_box_invisible_object * 1.6, height_combo_box_invisible_object * 1.7024);
        combo_box_invisible_object->setPosition(pos_x_combo_box_invisible_object * 1.6, pos_y_combo_box_invisible_object * 1.7024);
        combo_box_invisible_object->setTextSize(20 * 1.65);
    }
    else  if (screen_size == "1600x1200") {
        combo_box_invisible_object->setSize(width_combo_box_invisible_object * 2, height_combo_box_invisible_object * 1.9918);
        combo_box_invisible_object->setPosition(pos_x_combo_box_invisible_object * 2, pos_y_combo_box_invisible_object * 1.9918);
        combo_box_invisible_object->setTextSize(20 * 2);
    }
    else if (screen_size == "1920x1080") {
        combo_box_invisible_object->setSize(width_combo_box_invisible_object * 2.4, height_combo_box_invisible_object * 1.79262);
        combo_box_invisible_object->setPosition(pos_x_combo_box_invisible_object * 2.4, pos_y_combo_box_invisible_object * 1.79262);
        combo_box_invisible_object->setTextSize(20 * 2.1);
    }
}

void Combo_box_filepath_fone::set_offset(std::string screen_size) {
    if (screen_size == "800x600") {
        combo_box_file_path_fone->setSize(width_combo_box_file_path_fone, height_combo_box_file_path_fone);
        combo_box_file_path_fone->setTextSize(20);
        combo_box_file_path_fone->setPosition(pos_x_combo_box_file_path_fone, pos_y_combo_box_file_path_fone);
    }
    else if (screen_size == "1024x768") {
        combo_box_file_path_fone->setSize(width_combo_box_file_path_fone * 1.28, height_combo_box_file_path_fone * 1.28);
        combo_box_file_path_fone->setTextSize(20 * 1.28);
        combo_box_file_path_fone->setPosition(pos_x_combo_box_file_path_fone * 1.28, pos_y_combo_box_file_path_fone * 1.28);
    }
    else if (screen_size == "1280x1024") {
        combo_box_file_path_fone->setSize(width_combo_box_file_path_fone * 1.6,height_combo_box_file_path_fone * 1.7024);
        combo_box_file_path_fone->setTextSize(20 * 1.65);
        combo_box_file_path_fone->setPosition(pos_x_combo_box_file_path_fone * 1.6, pos_y_combo_box_file_path_fone * 1.7024);
    }
    else  if (screen_size == "1600x1200") {
        combo_box_file_path_fone->setSize(width_combo_box_file_path_fone * 2, height_combo_box_file_path_fone * 1.9918);
        combo_box_file_path_fone->setTextSize(20 * 2);
        combo_box_file_path_fone->setPosition(pos_x_combo_box_file_path_fone * 2, pos_y_combo_box_file_path_fone * 1.9918);
    }
    else if (screen_size == "1920x1080") {
        combo_box_file_path_fone->setSize(width_combo_box_file_path_fone * 2.4, height_combo_box_file_path_fone * 1.79262);
        combo_box_file_path_fone->setTextSize(20 * 2.1);
        combo_box_file_path_fone->setPosition(pos_x_combo_box_file_path_fone * 2.4, pos_y_combo_box_file_path_fone * 1.79262);
    }
}

void Combo_box_filepath_fone::set_options_fone() {
    boost::filesystem::path path_to_folder("background");
    bool show_first_element = true;
    for (auto i = boost::filesystem::directory_iterator(path_to_folder); i != boost::filesystem::directory_iterator(); i++) {
        std::string item = i->path().filename().string();
        combo_box_file_path_fone->addItem(item);
        if (show_first_element) {
            combo_box_file_path_fone->setSelectedItem(item);
            show_first_element = false;
        }
    }
}

Combo_box_figure::Combo_box_figure(tgui::GuiSFML& GUI) {
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
}

void Combo_box_figure::set_offset(std::string screen_size) {
    if (screen_size == "800x600") {
        combo_box_figure->setSize(width_combo_box_figure, height_combo_box_figure);
        combo_box_figure->setPosition(pos_x_combo_box_figure, pos_y_combo_box_figure);
        combo_box_figure->setTextSize(20);
    }
    else if (screen_size == "1024x768") {
        combo_box_figure->setSize(width_combo_box_figure * 1.28, height_combo_box_figure * 1.28);
        combo_box_figure->setPosition(pos_x_combo_box_figure * 1.28, pos_y_combo_box_figure * 1.28);
        combo_box_figure->setTextSize(20 * 1.28);
    }
    else if (screen_size == "1280x1024") {
        combo_box_figure->setSize(width_combo_box_figure * 1.6, height_combo_box_figure * 1.7024);
        combo_box_figure->setPosition(pos_x_combo_box_figure * 1.6, pos_y_combo_box_figure * 1.7024);
        combo_box_figure->setTextSize(20 * 1.65);
    }
    else  if (screen_size == "1600x1200") {
        combo_box_figure->setSize(width_combo_box_figure * 2, height_combo_box_figure * 1.9918);
        combo_box_figure->setPosition(pos_x_combo_box_figure * 2, pos_y_combo_box_figure * 1.9918);
        combo_box_figure->setTextSize(20 * 2);
    }
    else if (screen_size == "1920x1080") {
        combo_box_figure->setSize(width_combo_box_figure * 2.4, height_combo_box_figure * 1.79262);
        combo_box_figure->setPosition(pos_x_combo_box_figure * 2.4, pos_y_combo_box_figure * 1.79262);
        combo_box_figure->setTextSize(20 * 2.1);
    }
}

Button_download_texture::Button_download_texture(tgui::GuiSFML& GUI) {
    button_download_texture = tgui::Button::create();
    button_download_texture->setVisible(false);
    button_download_texture->setTextSize(20);
    button_download_texture->setPosition(pos_x_button_download, pos_y_button_download);
    button_download_texture->setText(L"Создать тело");
    button_download_texture->setSize(width_button_download, height_button_download);
    GUI.add(button_download_texture);
}

void Button_download_texture::set_offset(std::string screen_size) {
    if (screen_size == "800x600") {
        button_download_texture->setSize(width_button_download, height_button_download);
        button_download_texture->setPosition(pos_x_button_download, pos_y_button_download);
        button_download_texture->setTextSize(20);
    }
    else if (screen_size == "1024x768") {
        button_download_texture->setSize(width_button_download * 1.28, height_button_download * 1.28);
        button_download_texture->setPosition(pos_x_button_download * 1.28, pos_y_button_download * 1.28);
        button_download_texture->setTextSize(20 * 1.28);
    }
    else if (screen_size == "1280x1024") {
        button_download_texture->setSize(width_button_download * 1.6, height_button_download * 1.7024);
        button_download_texture->setPosition(pos_x_button_download * 1.6, pos_y_button_download * 1.7024);
        button_download_texture->setTextSize(20 * 1.65);
    }
    else  if (screen_size == "1600x1200") {
        button_download_texture->setSize(width_button_download * 2, height_button_download * 1.9918);
        button_download_texture->setPosition(pos_x_button_download * 2,pos_y_button_download * 1.9918);
        button_download_texture->setTextSize(20 * 2);
    }
    else if (screen_size == "1920x1080") {
        button_download_texture->setSize(width_button_download * 2.4, height_button_download * 1.79262);
        button_download_texture->setPosition(pos_x_button_download * 2.4,pos_y_button_download * 1.79262);
        button_download_texture->setTextSize(20 * 2.1);
    }
}

Combo_box_typebody::Combo_box_typebody(tgui::GuiSFML& GUI) {
    combo_box_type_body = tgui::ComboBox::create();
    combo_box_type_body->setRenderer(theme.getRenderer("ComboBox"));
    combo_box_type_body->setVisible(false);
    combo_box_type_body->setTextSize(20);
    combo_box_type_body->setSize(width_combo_box_typebody, height_combo_box_typebody);
    combo_box_type_body->setPosition(pos_x_combo_box_typebody, pos_y_combo_box_typebody);
    combo_box_type_body->addItem(L"Статическое","1");
    combo_box_type_body->addItem(L"Динамическое","2");
    combo_box_type_body->setSelectedItem(L"Статическое");
    GUI.add(combo_box_type_body);
}

void Combo_box_typebody::set_offset(std::string screen_size) {
    if (screen_size == "800x600") {
        combo_box_type_body->setSize(width_combo_box_typebody, height_combo_box_typebody);
        combo_box_type_body->setPosition(pos_x_combo_box_typebody, pos_y_combo_box_typebody);
        combo_box_type_body->setTextSize(20);
    }
    else if (screen_size == "1024x768") {
        combo_box_type_body->setSize(width_combo_box_typebody * 1.28, height_combo_box_typebody * 1.28);
        combo_box_type_body->setPosition(pos_x_combo_box_typebody * 1.28, pos_y_combo_box_typebody * 1.28);
        combo_box_type_body->setTextSize(20 * 1.28);
    }
    else if (screen_size == "1280x1024") {
        combo_box_type_body->setSize(width_combo_box_typebody * 1.6, height_combo_box_typebody * 1.7024);
        combo_box_type_body->setPosition(pos_x_combo_box_typebody * 1.6, pos_y_combo_box_typebody * 1.7024);
        combo_box_type_body->setTextSize(20 * 1.65);
    }
    else  if (screen_size == "1600x1200") {
        combo_box_type_body->setSize(width_combo_box_typebody * 2, height_combo_box_typebody * 1.9918);
        combo_box_type_body->setPosition(pos_x_combo_box_typebody * 2, pos_y_combo_box_typebody * 1.9918);
        combo_box_type_body->setTextSize(20 * 2);
    }
    else if (screen_size == "1920x1080") {
        combo_box_type_body->setSize(width_combo_box_typebody * 2.4, height_combo_box_typebody * 1.79262);
        combo_box_type_body->setPosition(pos_x_combo_box_typebody * 2.4, pos_y_combo_box_typebody * 1.79262);
        combo_box_type_body->setTextSize(20 * 2.1);
    }
}

Combo_box_file_path_texture::Combo_box_file_path_texture(tgui::GuiSFML& GUI) {
    combo_box_file_path_texture = tgui::ComboBox::create();
    combo_box_file_path_texture->setRenderer(theme.getRenderer("ComboBox"));
    combo_box_file_path_texture->setSize(width_combo_box_file_path_texture, height_combo_box_file_path_texture);
    set_options_texture();
    combo_box_file_path_texture->setTextSize(20);
    combo_box_file_path_texture->setVisible(false);
    combo_box_file_path_texture->setPosition(pos_x_combo_box_file_path_texture, pos_y_combo_box_file_path_texture);
    GUI.add(combo_box_file_path_texture);
}

void Combo_box_file_path_texture::set_options_texture() {
    tgui::String str = combo_box_file_path_texture->getSelectedItem();
    combo_box_file_path_texture->removeAllItems();
    boost::filesystem::path path_to_folder("resources");   
    for (auto i = boost::filesystem::directory_iterator(path_to_folder); i != boost::filesystem::directory_iterator(); i++) {
        std::string item = i->path().filename().string();
        combo_box_file_path_texture->addItem(item);
    }
    if (show_first_element) {
        combo_box_file_path_texture->setSelectedItemByIndex(0);
        show_first_element = false;
    }
    else { combo_box_file_path_texture->setSelectedItem(str);
    }
}

void Combo_box_file_path_texture::set_offset(std::string screen_size) {
    if (screen_size == "800x600") {
        combo_box_file_path_texture->setSize(width_combo_box_file_path_texture, height_combo_box_file_path_texture);
        combo_box_file_path_texture->setTextSize(20);
        combo_box_file_path_texture->setPosition(pos_x_combo_box_file_path_texture, pos_y_combo_box_file_path_texture);
    }
    else if (screen_size == "1024x768") {
        combo_box_file_path_texture->setSize(width_combo_box_file_path_texture * 1.28, height_combo_box_file_path_texture * 1.28);
        combo_box_file_path_texture->setTextSize(20 * 1.28);
        combo_box_file_path_texture->setPosition(pos_x_combo_box_file_path_texture * 1.28, pos_y_combo_box_file_path_texture * 1.28);
    }
    else if (screen_size == "1280x1024") {
        combo_box_file_path_texture->setSize(width_combo_box_file_path_texture * 1.6, height_combo_box_file_path_texture * 1.7024);
        combo_box_file_path_texture->setTextSize(20 * 1.65);
        combo_box_file_path_texture->setPosition(pos_x_combo_box_file_path_texture * 1.6, pos_y_combo_box_file_path_texture * 1.7024);
    }
    else  if (screen_size == "1600x1200") {
        combo_box_file_path_texture->setSize(width_combo_box_file_path_texture * 2, height_combo_box_file_path_texture * 1.9918);
        combo_box_file_path_texture->setTextSize(20 * 2);
        combo_box_file_path_texture->setPosition(pos_x_combo_box_file_path_texture * 2, pos_y_combo_box_file_path_texture * 1.9918);
    }
    else if (screen_size == "1920x1080") {
        combo_box_file_path_texture->setSize(width_combo_box_file_path_texture * 2.4, height_combo_box_file_path_texture * 1.79262);
        combo_box_file_path_texture->setTextSize(20 * 2.1);
        combo_box_file_path_texture->setPosition(pos_x_combo_box_file_path_texture * 2.4, pos_y_combo_box_file_path_texture * 1.79262);
    }
}

Label_settings::Label_settings(tgui::GuiSFML& GUI) {
    label_settings = tgui::Label::create();
    label_settings->setVisible(false);
    label_settings->setPosition(pos_x_label_settings, pos_y_label_settings);
    label_settings->setText(L"Настройки");
    label_settings->setTextSize(30);
    GUI.add(label_settings);
}

void Label_settings::set_offset(std::string screen_size) {
    if (screen_size == "800x600") {
        label_settings->setTextSize(30);
        label_settings->setPosition(pos_x_label_settings, pos_y_label_settings);
    }
    else if (screen_size == "1024x768") {
        label_settings->setTextSize(30 * 1.28);
        label_settings->setPosition(pos_x_label_settings * 1.28, pos_y_label_settings * 1.28);
    }
    else if (screen_size == "1280x1024") {
        label_settings->setTextSize(30 * 1.65);
        label_settings->setPosition(pos_x_label_settings * 1.6, pos_y_label_settings * 1.7024);
    }
    else  if (screen_size == "1600x1200") {
        label_settings->setTextSize(30 * 2);
        label_settings->setPosition(pos_x_label_settings * 2, pos_y_label_settings * 1.9918);
    }
    else if (screen_size == "1920x1080") {
        label_settings->setTextSize(30 * 2.1);
        label_settings->setPosition(pos_x_label_settings * 2.4, pos_y_label_settings * 1.79262);
    }
}

Combo_box::Combo_box(tgui::GuiSFML& GUI) {
    combo_box = tgui::ComboBox::create();
    combo_box->setRenderer(theme.getRenderer("ComboBox"));
    combo_box->setVisible(false);
    combo_box->setTextSize(20);
    combo_box->setSize(width_combo_box, height_combo_box);
    combo_box->setPosition(pos_x_combo_box, pos_y_combo_box);
    combo_box->addItem("800x600");
    combo_box->addItem("1024x768");
    combo_box->addItem("1280x1024");
    combo_box->addItem("1600x1200");
    combo_box->addItem("1920x1080");
    combo_box->setSelectedItem("800x600");
    GUI.add(combo_box);
}

void Combo_box::set_offset(std::string screen_size) {
    if (screen_size == "800x600") {
        combo_box->setSize(width_combo_box, height_combo_box);
        combo_box->setPosition(pos_x_combo_box,pos_y_combo_box);
        combo_box->setTextSize(20);
    }
    else if (screen_size == "1024x768") {
        combo_box->setSize(width_combo_box * 1.28, height_combo_box * 1.28);
        combo_box->setPosition(pos_x_combo_box * 1.28, pos_y_combo_box * 1.28);
        combo_box->setTextSize(20 * 1.28);
    }
    else if (screen_size == "1280x1024") {
        combo_box->setSize(width_combo_box * 1.6, height_combo_box * 1.7024);
        combo_box->setPosition(pos_x_combo_box * 1.6, pos_y_combo_box * 1.7024);
        combo_box->setTextSize(20 * 1.65);
    }
    else  if (screen_size == "1600x1200") {
        combo_box->setSize(width_combo_box * 2, height_combo_box * 1.9918);
        combo_box->setPosition(pos_x_combo_box * 2, pos_y_combo_box * 1.9918);
        combo_box->setTextSize(20 * 2);
    }
    else if (screen_size == "1920x1080") {
        combo_box->setSize(width_combo_box * 2.4, height_combo_box * 1.79262);
        combo_box->setPosition(pos_x_combo_box * 2.4, pos_y_combo_box * 1.79262);
        combo_box->setTextSize(20 * 2.1);
    }

}

Decorative_elements::Decorative_elements() {
    if (!t_fone_menu.loadFromFile("decorative element/menu.png")) { std::cout << "t_fone_menu error loading texture\n"; };
    s_fone_menu.setTexture(t_fone_menu);
    s_fone_menu.setPosition(10,10); 
}

DisplayingSelectedItem::DisplayingSelectedItem() {
    RectangleShape.setFillColor(sf::Color(100,250,50));
}

void DisplayingSelectedItem::update_position(sf::RenderWindow& window,sf::RectangleShape& shape, std::list<ObjectFactory*>::iterator::value_type it) {
    shape.setPosition(dynamic_cast<gobj::Rectangle_*>(it)->body_rect->GetPosition().x * 30.f, dynamic_cast<gobj::Rectangle_*>(it)->body_rect->GetPosition().y * 30.f);
    shape.setRotation(57.29577f * dynamic_cast<gobj::Rectangle_*>(it)->body_rect->GetAngle());
    window.draw(shape);
}

