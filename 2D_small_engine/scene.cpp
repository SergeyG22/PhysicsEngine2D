#include <SFML/Graphics.hpp>
#include <iostream>
#include <box2d/box2d.h>
#include "scene.h"




GameBackground::GameBackground() {
	upload_background("background/fone.png");
	background_sprite.setTexture(background_texture);
}

bool GameBackground::upload_background(std::string path_to_image) {
	if (!background_texture.loadFromFile(path_to_image)) {  return false; }
	return true;
}

void GameBackground::draw(sf::RenderTarget&target,sf::RenderStates states)const {
	target.draw(background_sprite,states);
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
	pos = this->body_player->GetPosition();
	float angle = this->body_player->GetAngle();
	sprite.setPosition(pos.x * SCALE, pos.y * SCALE);
	sprite.setRotation(DEG * angle);
	window.draw(sprite);
}

Rectangle_::Rectangle_(b2World& world,float h,float w,float x,float y, std::string path_to_file, b2BodyType bdef,int id_visible_object):height_shape(h),width_shape(w),pos_x(x),pos_y(y) {
	s_rect.setOrigin(height_shape/2,width_shape/2);
	if (!t_rect.loadFromFile(path_to_file)) {
         std::cout << "The texture path is not correct\n";
	}
	s_rect.setTexture(t_rect);	
	center.x = 0 / SCALE;

	switch (id_visible_object) {
	case 1: {
		s_rect.setColor(sf::Color::Transparent);
		break;
	}
	case 2:
		s_rect.setColor(sf::Color::White);
		break;
	}
	center.y = 0 / SCALE;
	bshape_rect.SetAsBox(height_shape/2/SCALE,width_shape/2/SCALE,center,0);
	bdef_rect.type = bdef;
	body_rect = world.CreateBody(&bdef_rect);
	body_rect->CreateFixture(&bshape_rect, 5.0);
}

Rectangle_::Rectangle_(b2World& world, float h, float w, float x, float y, b2BodyType bdef) :height_shape(h), width_shape(w), pos_x(x), pos_y(y){
	b2Vec2 center;
	center.x = x / SCALE;
	center.y = y / SCALE;
	bdef_rect.type = bdef; 
	bshape_rect.SetAsBox(height_shape / SCALE, width_shape / SCALE, center, 0);
	body_rect = world.CreateBody(&bdef_rect);
	body_rect->CreateFixture(&bshape_rect, 5.0);
}

bool Rectangle_::constructor_test(b2World& world, float h, float w, float x, float y, std::string path_to_file ) {
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

void Rectangle_::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	target.draw(s_rect, states);
}

void Rectangle_::update_position(sf::RenderWindow& window, sf::Sprite& sprite) {   
	s_rect.setPosition(body_rect->GetPosition().x * SCALE, body_rect->GetPosition().y * SCALE);
	s_rect.setRotation(DEG * body_rect->GetAngle());
	window.draw(sprite);
}

sf::Vector2f TransferObjects::get_mouse_coordinte(sf::RenderWindow& window) {
	sf::Vector2i pixel_position = sf::Mouse::getPosition(window);
	sf::Vector2f pos = window.mapPixelToCoords(pixel_position);
	return pos;
}

void ObjectsWorld::to_generate_objects_in_the_world(b2World& world) {
	list_object.push_back(new Rectangle_(world, 800, 25, 0, 580,b2_staticBody));
	list_object.push_back(new Rectangle_(world, 10, 600, 0, 0, b2_staticBody));
	list_object.push_back(new Rectangle_(world, 10, 600, 800, 0,b2_staticBody));
}		                                           

ObjectFactory* ObjectsWorld::get_object_world(int n) {
	auto it = list_object.begin();
	std::advance(it, n);
	return *it;
}



























