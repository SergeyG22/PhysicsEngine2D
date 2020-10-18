#include "pch.h"
#include "../bullshit collector/scene.h"

   //arrange act assert
TEST(TestRealization, PlayerUploadTexture) {	
	GraphicsPlayer player;
	ASSERT_TRUE(player.upload_texture("C:/Users/Dolba/source/repos/bullshit collector/bullshit collector/face_left.png",
		                              "C:/Users/Dolba/source/repos/bullshit collector/bullshit collector/face_right.png"
	));	
}

TEST(TestRealization, GamebackgroundUploadTexture) {
	GameBackground fone;
	ASSERT_TRUE(fone.upload_background("C:/Users/Dolba/source/repos/bullshit collector/bullshit collector/fone.png"));
}

TEST(TestRealization, ConstructorTestWALL) {
	b2Vec2 gravity(0.f, 9.8f);
	b2World world(gravity);
	Rectangle_ wall;
	ASSERT_TRUE(wall.constructor_test(world, 300, 40, 200, 200, "C:/Users/Dolba/source/repos/bullshit collector/bullshit collector/wall.png"));
}
















//1)Создать основной проект
//2)Подключить к основному проекту исходные библиотеки
//3)Создать проект google test
//4)При создании подключить ссылку на основной проект (выбрать вверху)
//5)Подключить библиотеки к google test проекту
//6)Подключить заголовочный файл тестируемого файлы (в инклюд написать)("../") и перейти на папку выше
//7)Добавить исходные файлы в проект (правой кнопки мыши на google test --> добавить--> добавить существующий элемент).Выбрать .h и .cpp
//8)Отключить предварительно откомпилированный заголовок в проекте google test( C/C++ ---> ВСЕ ПАРАМЕТРЫ ----> Предварительно откомп заголовок)
//  Иначе вывалится ошибка!!!