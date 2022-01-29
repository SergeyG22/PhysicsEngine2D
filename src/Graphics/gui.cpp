#include <../../box_2d-src/include/box2d/box2d.h>
#include <TGUI/TGUI.hpp>
#include <iostream>
#include <../../boost_filesystem-src/include/boost/filesystem.hpp>
#include "../../include/gui.h"


Button_screen_mode::Button_screen_mode(tgui::Gui& GUI) {
    button_screen_mode = tgui::Button::create();
    button_screen_mode->setVisible(false);
    button_screen_mode->setTextSize(20);
    button_screen_mode->setPosition(pos_x_button_screen, pos_y_button_screen);
    button_screen_mode->setText(L"Экранный режим");
    button_screen_mode->setSize(width_button_screen, height_button_screen);
    GUI.add(button_screen_mode);
}

void Button_screen_mode::set_offset(std::string screen_size) {
    if (screen_size == "800x600") {
        button_screen_mode->setSize(width_button_screen,height_button_screen);
        button_screen_mode->setPosition(pos_x_button_screen, pos_y_button_screen);
        button_screen_mode->setTextSize(20);
    }
    else if (screen_size == "1024x768") {
        button_screen_mode->setSize(width_button_screen * 1.28, height_button_screen * 1.28);
        button_screen_mode->setPosition(pos_x_button_screen * 1.28, pos_y_button_screen * 1.28);
        button_screen_mode->setTextSize(20 * 1.28);
    }
    else if (screen_size == "1280x1024") {
        button_screen_mode->setSize(width_button_screen * 1.6, height_button_screen * 1.7024);
        button_screen_mode->setPosition(pos_x_button_screen * 1.6, pos_y_button_screen * 1.7024);
        button_screen_mode->setTextSize(20 * 1.65);
    }
    else  if (screen_size == "1600x1200") {
        button_screen_mode->setSize(width_button_screen * 2, height_button_screen * 1.9918);
        button_screen_mode->setPosition(pos_x_button_screen * 2, pos_y_button_screen * 1.9918);
        button_screen_mode->setTextSize(20 * 2);
    }
    else if (screen_size == "1920x1080") {
        button_screen_mode->setSize(width_button_screen * 2.4, height_button_screen * 1.79262);
        button_screen_mode->setPosition(pos_x_button_screen * 2.4, pos_y_button_screen * 1.79262);
        button_screen_mode->setTextSize(20 * 2.1);
    }


    // 1.28, 1.6 , 2, 2.4 - the scale factor is obtained by dividing one resolution by another:
    // 1024/800 = 1.28   
    // 786/600 = 1.28 
}

Button_switching_fullscreen::Button_switching_fullscreen(tgui::Gui& GUI) {
    button_switching_fullscreen = tgui::Button::create();
    button_switching_fullscreen->setVisible(false);
    button_switching_fullscreen->setTextSize(20);
    button_switching_fullscreen->setPosition(pos_x_button_switching_fullscreen, pos_y_button_switching_fullscreen);
    button_switching_fullscreen->setText(L"Полноэкранный режим");
    button_switching_fullscreen->setSize(width_button_switching_fullscreen, height_button_switching_fullscreen);
    GUI.add(button_switching_fullscreen);
}

void Button_switching_fullscreen::set_offset(std::string screen_size) {
    if (screen_size == "800x600") {
        button_switching_fullscreen->setSize(width_button_switching_fullscreen, height_button_switching_fullscreen);
        button_switching_fullscreen->setPosition(pos_x_button_switching_fullscreen, pos_y_button_switching_fullscreen);
        button_switching_fullscreen->setTextSize(20);
    }
    else if (screen_size == "1024x768") {
        button_switching_fullscreen->setSize(width_button_switching_fullscreen * 1.28, height_button_switching_fullscreen * 1.28);
        button_switching_fullscreen->setPosition(pos_x_button_switching_fullscreen * 1.28, pos_y_button_switching_fullscreen * 1.28);
        button_switching_fullscreen->setTextSize(20 * 1.28);
    }
    else if (screen_size == "1280x1024") {
        button_switching_fullscreen->setSize(width_button_switching_fullscreen * 1.6, height_button_switching_fullscreen * 1.7024);
        button_switching_fullscreen->setPosition(pos_x_button_switching_fullscreen * 1.6, pos_y_button_switching_fullscreen * 1.7024);
        button_switching_fullscreen->setTextSize(20 * 1.65);
    }
    else  if (screen_size == "1600x1200") {
        button_switching_fullscreen->setSize(width_button_switching_fullscreen * 2, height_button_switching_fullscreen * 1.9918);
        button_switching_fullscreen->setPosition(pos_x_button_switching_fullscreen * 2, pos_y_button_switching_fullscreen * 1.9918);
        button_switching_fullscreen->setTextSize(20 * 2);
    }
    else if (screen_size == "1920x1080") {
        button_switching_fullscreen->setSize(width_button_switching_fullscreen * 2.4, height_button_switching_fullscreen * 1.79262);
        button_switching_fullscreen->setPosition(pos_x_button_switching_fullscreen * 2.4, pos_y_button_switching_fullscreen * 1.79262);
        button_switching_fullscreen->setTextSize(20 * 2.1);
    }

}

Button_download_fone::Button_download_fone(tgui::Gui& GUI) {
    button_download_fone = tgui::Button::create();
    button_download_fone->setVisible(false);
    button_download_fone->setTextSize(20);
    button_download_fone->setPosition(pos_x_button_download_fone, pos_y_button_download_fone);
    button_download_fone->setText(L"Установить фон");
    button_download_fone->setSize(width_button_download_fone, height_button_download_fone);
    GUI.add(button_download_fone);
}

Button_download_texture::Button_download_texture(tgui::Gui& GUI) {
    button_download_texture = tgui::Button::create();
    button_download_texture->setVisible(false);
    button_download_texture->setTextSize(20);
    button_download_texture->setPosition(pos_x_button_download, pos_y_button_download);
    button_download_texture->setText(L"Создать тело");
    button_download_texture->setSize(width_button_download, height_button_download);
    GUI.add(button_download_texture);
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
        button_download_texture->setPosition(pos_x_button_download * 2, pos_y_button_download * 1.9918);
        button_download_texture->setTextSize(20 * 2);
    }
    else if (screen_size == "1920x1080") {
        button_download_texture->setSize(width_button_download * 2.4, height_button_download * 1.79262);
        button_download_texture->setPosition(pos_x_button_download * 2.4, pos_y_button_download * 1.79262);
        button_download_texture->setTextSize(20 * 2.1);
    }

}

Button_settings_decoration::Button_settings_decoration(tgui::Gui& GUI) {
    button_settings_decoration = tgui::Button::create();
    button_settings_decoration->setVisible(false);
    button_settings_decoration->setTextSize(20);
    button_settings_decoration->setPosition(pos_x_settings_decoration, pos_y_settings_decoration);
    button_settings_decoration->setText(L"Создать декорацию");
    button_settings_decoration->setSize(width_settings_decoration, height_settings_decoration);
    GUI.add(button_settings_decoration);
}

void Button_settings_decoration::set_offset(std::string screen_size) {
    if (screen_size == "800x600") {
        button_settings_decoration->setSize(width_settings_decoration, height_settings_decoration);
        button_settings_decoration->setPosition(pos_x_settings_decoration, pos_y_settings_decoration);
        button_settings_decoration->setTextSize(20);
    }
    else if (screen_size == "1024x768") {
        button_settings_decoration->setSize(width_settings_decoration * 1.28, height_settings_decoration * 1.28);
        button_settings_decoration->setPosition(pos_x_settings_decoration * 1.28, pos_y_settings_decoration * 1.28);
        button_settings_decoration->setTextSize(20 * 1.28);
    }
    else if (screen_size == "1280x1024") {
        button_settings_decoration->setSize(width_settings_decoration * 1.6, height_settings_decoration * 1.7024);
        button_settings_decoration->setPosition(pos_x_settings_decoration * 1.6, pos_y_settings_decoration * 1.7024);
        button_settings_decoration->setTextSize(20 * 1.65);
    }
    else  if (screen_size == "1600x1200") {
        button_settings_decoration->setSize(width_settings_decoration * 2, height_settings_decoration * 1.9918);
        button_settings_decoration->setPosition(pos_x_settings_decoration * 2, pos_y_settings_decoration * 1.9918);
        button_settings_decoration->setTextSize(20 * 2);
    }
    else if (screen_size == "1920x1080") {
        button_settings_decoration->setSize(width_settings_decoration * 2.4, height_settings_decoration * 1.79262);
        button_settings_decoration->setPosition(pos_x_settings_decoration * 2.4, pos_y_settings_decoration * 1.79262);
        button_settings_decoration->setTextSize(20 * 2.1);
    }
}

Button_create_script::Button_create_script(tgui::Gui& GUI) {
    button_create_script = tgui::Button::create();
    button_create_script->setVisible(false);
    button_create_script->setTextSize(20);
    button_create_script->setPosition(pos_x_create_script, pos_y_create_script);
    button_create_script->setText(L"Создать сценарий");
    button_create_script->setSize(width_create_script, height_create_script);
    GUI.add(button_create_script);
}

void Button_create_script::set_offset(std::string screen_size) {
    if (screen_size == "800x600") {
        button_create_script->setSize(width_create_script, height_create_script);
        button_create_script->setPosition(pos_x_create_script, pos_y_create_script);
        button_create_script->setTextSize(20);
    }
    else if (screen_size == "1024x768") {
        button_create_script->setSize(width_create_script * 1.28, height_create_script * 1.28);
        button_create_script->setPosition(pos_x_create_script * 1.28, pos_y_create_script * 1.28);
        button_create_script->setTextSize(20 * 1.28);
    }
    else if (screen_size == "1280x1024") {
        button_create_script->setSize(width_create_script * 1.6, height_create_script * 1.7024);
        button_create_script->setPosition(pos_x_create_script * 1.6, pos_y_create_script * 1.7024);
        button_create_script->setTextSize(20 * 1.65);
    }
    else  if (screen_size == "1600x1200") {
        button_create_script->setSize(width_create_script * 2, height_create_script * 1.9918);
        button_create_script->setPosition(pos_x_create_script * 2, pos_y_create_script * 1.9918);
        button_create_script->setTextSize(20 * 2);
    }
    else if (screen_size == "1920x1080") {
        button_create_script->setSize(width_create_script * 2.4, height_create_script * 1.79262);
        button_create_script->setPosition(pos_x_create_script * 2.4, pos_y_create_script * 1.79262);
        button_create_script->setTextSize(20 * 2.1);
    }
}

Button_loading_of_script::Button_loading_of_script(tgui::Gui& GUI) {
    button_loading_script = tgui::Button::create();
    button_loading_script->setVisible(false);
    button_loading_script->setTextSize(20);
    button_loading_script->setPosition(pos_x_loading_script, pos_y_loading_script);
    button_loading_script->setText(L"Загрузить сценарий");
    button_loading_script->setSize(width_loading_script, height_loading_script);
    GUI.add(button_loading_script);
}

void Button_loading_of_script::set_offset(std::string screen_size) {
    if (screen_size == "800x600") {
        button_loading_script->setSize(width_loading_script, height_loading_script);
        button_loading_script->setPosition(pos_x_loading_script, pos_y_loading_script);
        button_loading_script->setTextSize(20);
    }
    else if (screen_size == "1024x768") {
        button_loading_script->setSize(width_loading_script * 1.28, height_loading_script * 1.28);
        button_loading_script->setPosition(pos_x_loading_script * 1.28, pos_y_loading_script * 1.28);
        button_loading_script->setTextSize(20 * 1.28);
    }
    else if (screen_size == "1280x1024") {
        button_loading_script->setSize(width_loading_script * 1.6, height_loading_script * 1.7024);
        button_loading_script->setPosition(pos_x_loading_script * 1.6, pos_y_loading_script * 1.7024);
        button_loading_script->setTextSize(20 * 1.65);
    }
    else  if (screen_size == "1600x1200") {
        button_loading_script->setSize(width_loading_script * 2, height_loading_script * 1.9918);
        button_loading_script->setPosition(pos_x_loading_script * 2, pos_y_loading_script * 1.9918);
        button_loading_script->setTextSize(20 * 2);
    }
    else if (screen_size == "1920x1080") {
        button_loading_script->setSize(width_loading_script * 2.4, height_loading_script * 1.79262);
        button_loading_script->setPosition(pos_x_loading_script * 2.4, pos_y_loading_script * 1.79262);
        button_loading_script->setTextSize(20 * 2.1);
    }
}

Combo_box_script::Combo_box_script(tgui::Gui& GUI) {
    combo_box_script = tgui::ComboBox::create();
    combo_box_script->setRenderer(theme.getRenderer("ComboBox"));
    combo_box_script->setSize(width_combo_box_script, height_combo_box_script);
    set_options_script();
    combo_box_script->setTextSize(20);
    combo_box_script->setVisible(false);
    combo_box_script->setPosition(pos_x_combo_box_script, pos_y_combo_box_script);
    GUI.add(combo_box_script);
}

void Combo_box_script::set_offset(std::string screen_size) {
    if (screen_size == "800x600") {
        combo_box_script->setSize(width_combo_box_script, height_combo_box_script);
        combo_box_script->setTextSize(20);
        combo_box_script->setPosition(pos_x_combo_box_script, pos_y_combo_box_script);
    }
    else if (screen_size == "1024x768") {
        combo_box_script->setSize(width_combo_box_script * 1.28, height_combo_box_script * 1.28);
        combo_box_script->setTextSize(20 * 1.28);
        combo_box_script->setPosition(pos_x_combo_box_script * 1.28, pos_y_combo_box_script * 1.28);
    }
    else if (screen_size == "1280x1024") {
        combo_box_script->setSize(width_combo_box_script * 1.6, height_combo_box_script * 1.7024);
        combo_box_script->setTextSize(20 * 1.65);
        combo_box_script->setPosition(pos_x_combo_box_script * 1.6, pos_y_combo_box_script * 1.7024);
    }
    else  if (screen_size == "1600x1200") {
        combo_box_script->setSize(width_combo_box_script * 2, height_combo_box_script * 1.9918);
        combo_box_script->setTextSize(20 * 2);
        combo_box_script->setPosition(pos_x_combo_box_script * 2, pos_y_combo_box_script * 1.9918);
    }
    else if (screen_size == "1920x1080") {
        combo_box_script->setSize(width_combo_box_script * 2.4, height_combo_box_script * 1.79262);
        combo_box_script->setTextSize(20 * 2.1);
        combo_box_script->setPosition(pos_x_combo_box_script * 2.4, pos_y_combo_box_script * 1.79262);
    }
}

void Combo_box_script::set_options_script() {
    sf::String str = combo_box_script->getSelectedItem();
    combo_box_script->removeAllItems();
    boost::filesystem::path path_to_folder("scripts");

    for (auto i = boost::filesystem::directory_iterator(path_to_folder); i != boost::filesystem::directory_iterator(); i++) {
        std::string item = i->path().filename().string();
        combo_box_script->addItem(item);
    }
    if (show_first_element) {
        combo_box_script->setSelectedItemByIndex(0);
        show_first_element = false;
    }
    else {
        combo_box_script->setSelectedItem(str);
    }
}

Combo_box_filepath_fone::Combo_box_filepath_fone(tgui::Gui& GUI) {
    combo_box_file_path_fone = tgui::ComboBox::create();
    combo_box_file_path_fone->setRenderer(theme.getRenderer("ComboBox"));
    combo_box_file_path_fone->setSize(width_combo_box_file_path_fone, height_combo_box_file_path_fone);
    set_options_fone();
    combo_box_file_path_fone->setTextSize(20);
    combo_box_file_path_fone->setVisible(false);
    combo_box_file_path_fone->setPosition(pos_x_combo_box_file_path_fone, pos_y_combo_box_file_path_fone);
    GUI.add(combo_box_file_path_fone);
}

Combo_box_invisible_object::Combo_box_invisible_object(tgui::Gui& GUI) {
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
    sf::String str = combo_box_file_path_fone->getSelectedItem();
    combo_box_file_path_fone->removeAllItems();
    boost::filesystem::path path_to_folder("background");

    for (auto i = boost::filesystem::directory_iterator(path_to_folder); i != boost::filesystem::directory_iterator(); i++) {
        std::string item = i->path().filename().string();
        combo_box_file_path_fone->addItem(item);
    }
        if (show_first_element) {
            combo_box_file_path_fone->setSelectedItemByIndex(0);
            show_first_element = false;
        }
        else {
            combo_box_file_path_fone->setSelectedItem(str);
        }
    
}

Combo_box_figure::Combo_box_figure(tgui::Gui& GUI) {
    combo_box_figure = tgui::ComboBox::create();
    combo_box_figure->setRenderer(theme.getRenderer("ComboBox"));
    combo_box_figure->setVisible(false);
    combo_box_figure->setTextSize(20);
    combo_box_figure->setSize(width_combo_box_figure, height_combo_box_figure);
    combo_box_figure->setPosition(pos_x_combo_box_figure, pos_y_combo_box_figure);
    combo_box_figure->addItem(L"Круг");
    combo_box_figure->addItem(L"Квадрат");
    combo_box_figure->setSelectedItem(L"Квадрат");
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

Combo_box_typebody::Combo_box_typebody(tgui::Gui& GUI) {
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

Combo_box_file_path_texture::Combo_box_file_path_texture(tgui::Gui& GUI) {
    combo_box_file_path_texture = tgui::ComboBox::create();
    combo_box_file_path_texture->setRenderer(theme.getRenderer("ComboBox"));
    combo_box_file_path_texture->setSize(width_combo_box_file_path_texture, height_combo_box_file_path_texture);
    set_options_texture("rectangle");
    combo_box_file_path_texture->setTextSize(20);
    combo_box_file_path_texture->setVisible(false);
    combo_box_file_path_texture->setPosition(pos_x_combo_box_file_path_texture, pos_y_combo_box_file_path_texture);
    GUI.add(combo_box_file_path_texture);
}

void Combo_box_file_path_texture::set_options_texture(std::string folder_figure) {

        sf::String str = combo_box_file_path_texture->getSelectedItem();
        combo_box_file_path_texture->removeAllItems();
        boost::filesystem::path path_to_folder(folder_figure);
        for (auto i = boost::filesystem::directory_iterator(path_to_folder); i != boost::filesystem::directory_iterator(); i++) {
            std::string item = i->path().filename().string();
            combo_box_file_path_texture->addItem(item);
        }
        if (show_first_element) {
            combo_box_file_path_texture->setSelectedItemByIndex(0);
            show_first_element = false;
        }
        else {
            combo_box_file_path_texture->setSelectedItem(str);
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

void Combo_box::set_offset(std::string screen_size) {
    if (screen_size == "800x600") {
        combo_box->setSize(width_combo_box, height_combo_box);
        combo_box->setPosition(pos_x_combo_box, pos_y_combo_box);
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

Combo_box::Combo_box(tgui::Gui& GUI) {
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
    combo_box->setEnabled(false);
    GUI.add(combo_box);
}

Combo_box_decor::Combo_box_decor(tgui::Gui& GUI) {
    combo_box_decor = tgui::ComboBox::create();
    combo_box_decor->setRenderer(theme.getRenderer("ComboBox"));
    set_options_decor();
    combo_box_decor->setVisible(false);
    combo_box_decor->setTextSize(20);
    combo_box_decor->setSize(width_combo_box_decor, height_combo_box_decor);
    combo_box_decor->setPosition(pos_x_combo_box_decor, pos_y_combo_box_decor);
    GUI.add(combo_box_decor);
}

void Combo_box_decor::set_offset(std::string screen_size) {
    if (screen_size == "800x600") {
        combo_box_decor->setSize(width_combo_box_decor, height_combo_box_decor);
        combo_box_decor->setPosition(pos_x_combo_box_decor, pos_y_combo_box_decor);
        combo_box_decor->setTextSize(20);
    }
    else if (screen_size == "1024x768") {
        combo_box_decor->setSize(width_combo_box_decor * 1.28, height_combo_box_decor * 1.28);
        combo_box_decor->setPosition(pos_x_combo_box_decor * 1.28, pos_y_combo_box_decor * 1.28);
        combo_box_decor->setTextSize(20 * 1.28);
    }
    else if (screen_size == "1280x1024") {
        combo_box_decor->setSize(width_combo_box_decor * 1.6, height_combo_box_decor * 1.7024);
        combo_box_decor->setPosition(pos_x_combo_box_decor * 1.6, pos_y_combo_box_decor * 1.7024);
        combo_box_decor->setTextSize(20 * 1.65);
    }
    else  if (screen_size == "1600x1200") {
        combo_box_decor->setSize(width_combo_box_decor * 2, height_combo_box_decor * 1.9918);
        combo_box_decor->setPosition(pos_x_combo_box_decor * 2, pos_y_combo_box_decor * 1.9918);
        combo_box_decor->setTextSize(20 * 2);
    }
    else if (screen_size == "1920x1080") {
        combo_box_decor->setSize(width_combo_box_decor * 2.4, height_combo_box_decor * 1.79262);
        combo_box_decor->setPosition(pos_x_combo_box_decor * 2.4, pos_y_combo_box_decor * 1.79262);
        combo_box_decor->setTextSize(20 * 2.1);
    }
}

void Combo_box_decor::set_options_decor() {
    sf::String str = combo_box_decor->getSelectedItem();
    combo_box_decor->removeAllItems();
    boost::filesystem::path path_to_folder("elements_of_decor");

    for (auto i = boost::filesystem::directory_iterator(path_to_folder); i != boost::filesystem::directory_iterator(); i++) {
        std::string item = i->path().filename().string();
        combo_box_decor->addItem(item);
    }
    if (show_first_element) {
        combo_box_decor->setSelectedItemByIndex(0);
        show_first_element = false;
    }
    else {
        combo_box_decor->setSelectedItem(str);
    }
}

Label_weight::Label_weight(tgui::Gui& GUI) {
    label_weight = tgui::Label::create();
    label_weight->setVisible(true);
    label_weight->setPosition(pos_x_label_weight, pos_y_label_weight);
    label_weight->setText("0");
    label_weight->setTextSize(30);
    GUI.add(label_weight);
}

void Label_weight::set_offset(std::string screen_size) {
    if (screen_size == "800x600") {
        label_weight->setTextSize(30);
        label_weight->setPosition(pos_x_label_weight, pos_y_label_weight);
    }
    else if (screen_size == "1024x768") {
        label_weight->setTextSize(30 * 1.28);
        label_weight->setPosition(pos_x_label_weight * 1.28, pos_y_label_weight * 1.28);
    }
    else if (screen_size == "1280x1024") {
        label_weight->setTextSize(30 * 1.65);
        label_weight->setPosition(pos_x_label_weight * 1.6, pos_y_label_weight * 1.7024);
    }
    else  if (screen_size == "1600x1200") {
        label_weight->setTextSize(30 * 2);
        label_weight->setPosition(pos_x_label_weight * 2, pos_y_label_weight * 1.9918);
    }
    else if (screen_size == "1920x1080") {
        label_weight->setTextSize(30 * 2.1);
        label_weight->setPosition(pos_x_label_weight * 2.4, pos_y_label_weight * 1.79262);
    }

}

Slider_weight_setting::Slider_weight_setting(tgui::Gui& GUI) {
    slider_weight_setting = tgui::Slider::create();
    slider_weight_setting->setRenderer(theme.getRenderer("Slider"));
    slider_weight_setting->setVisible(false);
    slider_weight_setting->setSize(width_slider_weight_setting,height_slider_weight_setting);
    slider_weight_setting->setPosition(pos_x_slider_weight_setting, pos_y_slider_weight_setting);
    slider_weight_setting->setMinimum(1);
    slider_weight_setting->setMaximum(999);
    slider_weight_setting->setStep(1);
    GUI.add(slider_weight_setting);
}

void Slider_weight_setting::set_offset(std::string screen_size) {
    if (screen_size == "800x600") {
        slider_weight_setting->setSize(width_slider_weight_setting, height_slider_weight_setting);
        slider_weight_setting->setPosition(pos_x_slider_weight_setting, pos_y_slider_weight_setting);
        slider_weight_setting->setTextSize(20);
    }
    else if (screen_size == "1024x768") {
        slider_weight_setting->setSize(width_slider_weight_setting * 1.28, height_slider_weight_setting * 1.28);
        slider_weight_setting->setPosition(pos_x_slider_weight_setting * 1.28, pos_y_slider_weight_setting * 1.28);
        slider_weight_setting->setTextSize(20 * 1.28);
    }
    else if (screen_size == "1280x1024") {
        slider_weight_setting->setSize(width_slider_weight_setting * 1.6, height_slider_weight_setting * 1.7024);
        slider_weight_setting->setPosition(pos_x_slider_weight_setting * 1.6, pos_y_slider_weight_setting * 1.7024);
        slider_weight_setting->setTextSize(20 * 1.65);
    }
    else  if (screen_size == "1600x1200") {
        slider_weight_setting->setSize(width_slider_weight_setting * 2, height_slider_weight_setting * 1.9918);
        slider_weight_setting->setPosition(pos_x_slider_weight_setting * 2, pos_y_slider_weight_setting * 1.9918);
        slider_weight_setting->setTextSize(20 * 2);
    }
    else if (screen_size == "1920x1080") {
        slider_weight_setting->setSize(width_slider_weight_setting * 2.4, height_slider_weight_setting * 1.79262);
        slider_weight_setting->setPosition(pos_x_slider_weight_setting * 2.4, pos_y_slider_weight_setting * 1.79262);
        slider_weight_setting->setTextSize(20 * 2.1);
    }

}

Images_elements::Images_elements(sf::RenderWindow& window) {
    if (!t_fone_menu.loadFromFile("images/menu.png")) { std::cout << "t_fone_menu error loading texture\n"; };
    s_fone_menu.setTexture(t_fone_menu);
    s_fone_menu.setPosition(10,10); 
    if (!t_target.loadFromFile("images/target.png")) { std::cout << "t_target error loading texture\n"; };
    s_target.setTexture(t_target);
    int pos_x = window.getSize().x/2 - t_target.getSize().x/2;
    int pos_y = window.getSize().y/2 - t_target.getSize().y/2;
    s_target.setPosition(pos_x,pos_y);
}

DisplayingSelectedItem::DisplayingSelectedItem() {
    RectangleShape.setFillColor(sf::Color(100,250,50));
}

void DisplayingSelectedItem::update_position(sf::RenderWindow& window,sf::RectangleShape& shape, std::list<gobj::ObjectFactory*>::iterator::value_type it) {
    shape.setPosition(dynamic_cast<gobj::Rectangle*>(it)->body_rect->GetPosition().x * 30.f, dynamic_cast<gobj::Rectangle*>(it)->body_rect->GetPosition().y * 30.f);
    shape.setRotation(57.29577f * dynamic_cast<gobj::Rectangle*>(it)->body_rect->GetAngle());
    window.draw(shape);
}

Decor_elements::Decor_elements(std::string file_name,float x, float y):x_pos(x),y_pos(y),filepath(file_name) {
    if (!t_decor.loadFromFile("elements_of_decor/"+file_name)) { std::cout << "elements_of_decor error loading texture\n"; };
    s_decor.setTexture(t_decor);
    s_decor.setPosition(x_pos, y_pos);
}

Decor_elements::Decor_elements( float x, float y,float scale_x,float scale_y, std::string file_name ):x_pos(x), y_pos(y),filepath(file_name) {
    if (!t_decor.loadFromFile("elements_of_decor/" + filepath)) { std::cout << "elements_of_decor error loading texture\n"; };
    s_decor.setScale(scale_x,scale_y);
    s_decor.setTexture(t_decor);
    s_decor.setPosition(x_pos, y_pos);
}



Decor_elements* DecorativeObjectsWorld::get_decor_object_world(int i) {
    auto it = list_decor_elements.begin();
    std::advance(it, i);
    return *it;
}
