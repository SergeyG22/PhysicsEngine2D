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
	bool upload_background(std::string);
	sf::Sprite& get_sprite() { return background_sprite; }
	void set_scale_background();
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

namespace gobj {
	//gobj - geometric object

struct ObjectFactory {
  virtual ~ObjectFactory() = default;
  virtual sf::Sprite& get_sprite() =0;
  virtual sf::Texture& get_texture() =0;
  virtual void update_position(sf::RenderWindow&, float) =0;
  virtual void update_position(sf::RenderWindow&) =0;
  virtual sf::Vector2f upperleft_coord_sprite() =0;
  virtual float set_angle(float) =0;
  virtual float get_angle() =0;
  virtual void set_state_select_object(bool) =0;
  virtual void reset_state() = 0;
  virtual bool get_state() = 0;
  virtual b2Body* get_body_pointer() = 0;
};

	class Rectangle :public Physics_parameters, public ObjectFactory {
		float pos_x;
		float pos_y;
		float x_top_left;
		float y_top_left;
		float height_shape;
		float width_shape;
		sf::Sprite s_rect;
		sf::Texture t_rect;
		float current_angle;		
		bool select_mouse = false;		
	public:	
		b2Body* body_rect;
		b2PolygonShape bshape_rect;
		b2BodyDef bdef_rect;
		b2Body* get_body_pointer()   override { return body_rect; }		
		sf::Texture& get_texture()   override { return t_rect; }
		sf::Sprite& get_sprite()     override { return s_rect; }
		float density = 10.0;
		float set_angle(float angle) override { current_angle += angle; return current_angle; }
		float get_angle()            override { return current_angle; }
		void update_position(sf::RenderWindow&, float) override;
		void update_position(sf::RenderWindow&)        override;
		void set_state_select_object(bool condition) override { select_mouse = condition; };
		void reset_state() override { select_mouse = false; }
		bool get_state() override { return select_mouse; };

		Rectangle(b2World&, float, float, float, float, b2BodyType bdef);
		Rectangle(b2World& world, float h, float w, float x, float y, std::string, b2BodyType bdef, int);
		sf::Vector2f upperleft_coord_sprite() override {
			sf::Vector2f vec;
			vec.x = x_top_left;
			vec.y = y_top_left;
			return vec;
		}
		bool constructor_test(b2World& world, float h, float w, float x, float y, std::string);
	};

	class Circle :public Physics_parameters, public ObjectFactory {
		float pos_x;
		float pos_y;
		float x_top_left;
		float y_top_left;
		float height_circle;
		float width_circle;
		float radius;
		sf::Sprite s_circle;
		sf::Texture t_circle;
		float current_angle;		
		bool select_mouse = false;		
	public:	
		b2Body* body_circle;
		b2CircleShape bshape_circle;
		b2BodyDef bdef_circle;
		b2Body* get_body_pointer()    override { return body_circle; }
		sf::Texture& get_texture()   override { return t_circle; }
		sf::Sprite& get_sprite()     override { return s_circle; }
		float density = 10.0;
		float set_angle(float angle) override { current_angle += angle; return current_angle; }
		float get_angle()            override { return current_angle; }
		void update_position(sf::RenderWindow&, float) override;
		void update_position(sf::RenderWindow&)        override;
		void set_state_select_object(bool condition)   override {  select_mouse = condition; };
		void reset_state() override { select_mouse = false; }
		bool get_state() override { return select_mouse; }
		Circle(b2World&, float,float,float, b2BodyType bdef);
		Circle(b2World& world, float x, float y, std::string, b2BodyType bdef, int);
		sf::Vector2f upperleft_coord_sprite()  override {
			sf::Vector2f vec;
			vec.x = x_top_left;
			vec.y = y_top_left;
			return vec;
		}
	};
}

struct TransferObjects {
sf::Vector2f get_mouse_coordinte(sf::RenderWindow&);
 bool can_be_moved = false;
 float deltaX=0;
 float deltaY=0;
};

struct ObjectsWorld {
	void to_generate_objects_in_the_world(b2World&);
	gobj::ObjectFactory* get_object_world(int);
	std::list<gobj::ObjectFactory*>list_object; 
};
