#include <SFML/Graphics.hpp>
#include <iostream>
#include <box2d/box2d.h>
#include "scene.h"



bool GameBackground::upload_background(std::string path_to_image) {
	if (!background_texture.loadFromFile(path_to_image)) {  return false; }
	background_sprite.setTexture(background_texture);
}

void GameBackground::draw(sf::RenderTarget&target,sf::RenderStates states)const {
	target.draw(background_sprite,states);
}

void GameBackground::set_scale_background() {
	float width = background_texture.getSize().x;
	float height = background_texture.getSize().y;
	if (width == 800 && height == 600) {         background_sprite.setScale(2.4,1.8);}
	else if (width == 1024 && height == 768) { background_sprite.setScale(1.875,1.4); }
	else if (width == 1280 && height == 1024) { background_sprite.setScale(1.875,1.4); }
	else if (width == 1600 && height == 1200) { background_sprite.setScale(1.875,1.4);  }
	else if (width == 1920 && height == 1080) { background_sprite.setScale(1.875,1.4);  }
}



GraphicsPlayer::GraphicsPlayer() {
	player_sprite.setOrigin(45.0, 45.0);
	upload_texture("scin_player/face_left.png", "scin_player/face_right.png");
	set_texture();
}

bool GraphicsPlayer::upload_texture(std::string left_image,std::string right_image){
	if (!texture_left.loadFromFile(left_image))  { return false; }
	if (!texture_right.loadFromFile(right_image)){ return false; }
	return true;
}

void GraphicsPlayer::set_texture(){
	player_sprite.setTexture(texture_left);
}

PhysicsPlayer::PhysicsPlayer(b2World& world) {
	bcicrle_player.m_radius = 45/SCALE;
	bdef_player.position.Set(200/SCALE,300/SCALE);
	bdef_player.type = b2_dynamicBody;
	body_player = world.CreateBody(&bdef_player);
	body_player->CreateFixture(&bcicrle_player, 15.0);
}

void PhysicsPlayer::keyboard_interaction(GraphicsPlayer& player) {
	b2Vec2  vel = body_player->GetLinearVelocity();
	float angVel = body_player->GetAngularVelocity();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (single_press) {
			player.get_sprite().setTexture(player.get_right_texture_display());
			single_press = false;
		}
		if (vel.x > -10) body_player->ApplyForceToCenter(b2Vec2(-2000, 0), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (!single_press) {
			player.get_sprite().setTexture(player.get_left_texture_display());
			single_press = true;
		}
		if (vel.x < 10) body_player->ApplyForceToCenter(b2Vec2(2000, 0), true);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) if (on_ground) {
		body_player->ApplyForceToCenter(b2Vec2(0, -100000), true);
	}
}

void PhysicsPlayer::jump(b2World& world) {
	on_ground = false;
	b2Vec2 pos = body_player->GetPosition();
	pos.y += 91 / SCALE;
	for (b2Body* it = world.GetBodyList(); it != 0; it = it->GetNext()) {
		for (b2Fixture* fixture = it->GetFixtureList(); fixture != 0; fixture = fixture->GetNext()) {
			if (fixture->TestPoint(pos)) {
				on_ground = true;
			}
		}
	}

}

void PhysicsPlayer::update(sf::RenderWindow& window, sf::Sprite& sprite) {
	pos = body_player->GetPosition();
	float angle = body_player->GetAngle();
	sprite.setPosition(pos.x * SCALE, pos.y * SCALE);
	sprite.setRotation(DEG * angle);
	window.draw(sprite);
}

gobj::Rectangle::Rectangle(b2World& world, float h, float w, float x, float y, std::string path_to_file, b2BodyType bdef, int id_visible_object) :height_shape(h), width_shape(w), pos_x(x), pos_y(y) {
	s_rect.setOrigin(height_shape / 2, width_shape / 2);
	if (!t_rect.loadFromFile(path_to_file)) {
		std::cout << "The texture path is not correct\n";
	}
	s_rect.setTexture(t_rect);
	switch (id_visible_object) {
	case 1: {
		s_rect.setColor(sf::Color::Transparent);
		break;
	}
	case 2:
		s_rect.setColor(sf::Color::White);
		break;
	}

	bshape_rect.SetAsBox(height_shape / 2 / SCALE, width_shape / 2 / SCALE);
	bdef_rect.type = bdef;
	bdef_rect.position.Set(x / 30.f, y / 30.f);
	body_rect = world.CreateBody(&bdef_rect);
	body_rect->CreateFixture(&bshape_rect, density);

}

gobj::Rectangle::Rectangle(b2World& world, float h, float w, float x, float y, b2BodyType bdef) :height_shape(h), width_shape(w), pos_x(x), pos_y(y) {
	bdef_rect.type = bdef;
	bshape_rect.SetAsBox(height_shape / SCALE, width_shape / SCALE);
	bdef_rect.position.Set(x / 30.f, y / 30.f);
	body_rect = world.CreateBody(&bdef_rect);
	body_rect->CreateFixture(&bshape_rect, density);
}

bool gobj::Rectangle::constructor_test(b2World& world, float h, float w, float x, float y, std::string path_to_file ) {
		if (!t_rect.loadFromFile(path_to_file)) {
			try {
				throw "The texture path is not correct\n";
			}
			catch (const char* exception) {
				std::cerr << "The texture path " + path_to_file + " is not correct\n";
			} 
			return false;
		}
	return true;
}

void gobj::Rectangle ::update_position(sf::RenderWindow& window) {
	s_rect.setPosition(body_rect->GetPosition().x * SCALE, body_rect->GetPosition().y * SCALE);
	s_rect.setRotation(DEG * body_rect->GetAngle());
	window.draw(s_rect);
}

void gobj::Rectangle::update_position(sf::RenderWindow& window, float angle) {
	body_rect->SetTransform(body_rect->GetPosition(), angle / DEG);
	s_rect.setPosition(body_rect->GetPosition().x * SCALE, body_rect->GetPosition().y * SCALE);
	s_rect.setRotation(DEG * body_rect->GetAngle());
}

gobj::Circle::Circle(b2World& world, float x, float y, std::string path_to_file, b2BodyType bdef, int id_visible_object) : pos_x(x), pos_y(y) {

	if (!t_circle.loadFromFile(path_to_file)) {
		std::cout << "The texture path is not correct\n";
	}
	s_circle.setTexture(t_circle);
	s_circle.setOrigin(t_circle.getSize().x/2,t_circle.getSize().y/2);
	switch (id_visible_object) {
	case 1: {
		s_circle.setColor(sf::Color::Transparent);
		break;
	}
	case 2:
		s_circle.setColor(sf::Color::White);
		break;
	}

	bdef_circle.type = bdef;
	bshape_circle.m_radius = t_circle.getSize().x / 2 / SCALE;
	bdef_circle.position.Set(x / 30.f, y / 30.f);
	body_circle = world.CreateBody(&bdef_circle);
	body_circle->CreateFixture(&bshape_circle, density);
}

gobj::Circle::Circle(b2World& world, float radius_circle, float x, float y, b2BodyType bdef):radius(radius_circle), pos_x(x), pos_y(y) {
	bdef_circle.type = bdef;
	bshape_circle.m_radius = radius / 2 / SCALE;
	bdef_circle.position.Set(x / 30.f, y / 30.f);
	body_circle = world.CreateBody(&bdef_circle);
	body_circle->CreateFixture(&bshape_circle, density);
}

void gobj::Circle::update_position(sf::RenderWindow& window) {
	s_circle.setPosition(body_circle->GetPosition().x * SCALE, body_circle->GetPosition().y * SCALE);
	s_circle.setRotation(DEG * body_circle->GetAngle());
	window.draw(s_circle);
}

void gobj::Circle::update_position(sf::RenderWindow& window, float angle) {
	body_circle->SetTransform(body_circle->GetPosition(), angle / DEG);
	s_circle.setPosition(body_circle->GetPosition().x * SCALE, body_circle->GetPosition().y * SCALE);
	s_circle.setRotation(DEG * body_circle->GetAngle());
}

sf::Vector2f TransferObjects::get_mouse_coordinte(sf::RenderWindow& window) {
	sf::Vector2i pixel_position = sf::Mouse::getPosition(window);
	sf::Vector2f pos = window.mapPixelToCoords(pixel_position);
	return pos;
}

void ObjectsWorld::to_generate_objects_in_the_world(b2World& world) {
	list_object = { new gobj::Rectangle(world, 1900, 25, 0, 1060,b2_staticBody),
		            new gobj::Rectangle(world, 20, 1060, 0, 0, b2_staticBody),
		            new gobj::Rectangle(world, 20, 1060, 1900, 0,b2_staticBody) };
}		                                           

gobj::ObjectFactory* ObjectsWorld::get_object_world(int n) {
	auto it = list_object.begin();
	std::advance(it, n);
	return *it;
}




























