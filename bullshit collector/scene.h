#pragma once
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <list>

class PhysicsPlayer;

struct Physics_parameters {
	 const float SCALE = 30.f;
	 const float DEG = 57.29577f;
};

class GameBackground: public sf::Drawable
{
	sf::Texture background_texture;
	sf::Sprite background_sprite;
	virtual void draw(sf::RenderTarget&,sf::RenderStates)const;
public:
	GameBackground();	
	bool upload_background(std::string);
};

class GraphicsPlayer: public Physics_parameters {
	sf::Sprite player_sprite;
	sf::Texture texture_left;
	sf::Texture texture_right;
	float current_x()const { return player_sprite.getPosition().x; }
	void set_texture();
public:
	GraphicsPlayer();
	bool upload_texture(std::string, std::string);
	sf::Texture& get_left_texture_display() { return texture_left; }
	sf::Texture& get_right_texture_display() { return texture_right; }
	sf::Sprite& get_sprite() { return player_sprite; }
};

class PhysicsPlayer : public Physics_parameters {
	b2CircleShape bcicrle_player;
	b2BodyDef bdef_player;
	b2Vec2 pos;
	float angle = 0.0;
	bool on_ground = false;
	bool single_press = true;
public:
	PhysicsPlayer(b2World&);
	PhysicsPlayer() { }
	void update(sf::RenderWindow&, sf::Sprite&);
	void keyboard_interaction(GraphicsPlayer&);
	void jump(b2World&);
	b2Body* body_player = nullptr;
};

struct ObjectFactory {
  virtual ~ObjectFactory(){ }
};

class Rectangle_:public Physics_parameters,public ObjectFactory,public sf::Drawable {
	b2PolygonShape bshape_rect;
	b2BodyDef bdef_rect;
	sf::Texture t_rect;
	sf::Sprite s_rect;
	float pos_x;
	float pos_y;
    float x_top_left;
	float y_top_left;
	float height_shape;
	float width_shape;
public:
	Rectangle_() { };
	b2Body* body_rect;	
	sf::Sprite& get_sprite() {  return s_rect; }
	Rectangle_(b2World&, float, float, float, float);
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	Rectangle_(b2World& world,float h,float w,float x,float y,std::string);	
	float x_initial_coordinates_of_the_sprite()const{ return x_top_left; 
	}
	float y_initial_coordinates_of_the_sprite()const { return y_top_left; 
	}
	bool constructor_test(b2World& world,float h,float w,float x,float y,std::string);
};

class TransferObjects {
public:
sf::Vector2f get_mouse_coordinte(sf::RenderWindow&);
 bool can_be_moved = false;
 float deltaX=0;
 float deltaY=0;
};

struct ObjectsWorld {
	void to_generate_objects_in_the_world(b2World&);
	ObjectFactory* get_object_world(int);
	std::list<ObjectFactory*>list_object; 
private:
};
