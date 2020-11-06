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
  virtual sf::Sprite& get_sprite() = 0;
  virtual sf::Texture& get_texture() = 0;
  virtual void update_position(sf::RenderWindow&, float) = 0;
  virtual void update_position(sf::RenderWindow&) = 0;
  virtual sf::Vector2f upperleft_coord_sprite()const = 0;
  virtual float set_angle(float) = 0;
  virtual float get_angle() = 0;
};

 //geometric object
namespace gobj {

	class Rectangle_ :public Physics_parameters, public ObjectFactory, public sf::Drawable {
		float pos_x;
		float pos_y;
		float x_top_left;
		float y_top_left;
		float height_shape;
		float width_shape;
		sf::Sprite s_rect;
		sf::Texture t_rect;
		float current_angle;
	public:
		b2Body* body_rect;
		b2PolygonShape bshape_rect;
		b2BodyDef bdef_rect;
		sf::Texture& get_texture()   override { return t_rect; }
		sf::Sprite& get_sprite()     override { return s_rect; }
		float set_angle(float angle) override { current_angle += angle; return current_angle; };
		float get_angle()            override { return current_angle; }
		void update_position(sf::RenderWindow&, float) override;
		void update_position(sf::RenderWindow&)        override;
		Rectangle_(b2World&, float, float, float, float, b2BodyType bdef);
		virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
		Rectangle_(b2World& world, float h, float w, float x, float y, std::string, b2BodyType bdef, int);
		sf::Vector2f upperleft_coord_sprite() const override {
			sf::Vector2f vec;
			vec.x = x_top_left;
			vec.y = y_top_left;
			return vec;
		}
		bool constructor_test(b2World& world, float h, float w, float x, float y, std::string);
	};
}
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
};
