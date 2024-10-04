#include <SFML/Graphics.hpp>
#include<iostream>

//
//class Button {
//public:
//	Button(sf::Vector2f position, float size, sf::Color color) {
//		mShape.setPosition(position);
//		mShape.setRadius(size);
//		mShape.setFillColor(color);
//	}
//
//	void draw(sf::RenderWindow& window) {
//		window.draw(mShape);
//	}
//
//	bool isClicked(sf::RenderWindow& window) {
//		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//
//		if (mShape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) &&
//			sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//			return true;
//		}
//		return false;
//	}
//
//	void moveButton(sf::Vector2i mousePos, sf::RenderWindow& window) {
//		mousePos = sf::Mouse::getPosition(window);
//
//		if (mousePos.x < 550 && mousePos.x > 500) {
//
//			mShape.setPosition(mousePos.x - 2, 500);
//
//		}
//
//	};
//
//	sf::Vector2f givePosition() {
//
//		return sf::Vector2f(mShape.getPosition().x , 504);
//
//	}
//private:
//	sf::CircleShape mShape;
//};
//
//
//int main() {
//	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML Window");
//
//
//
//	Button button(sf::Vector2f(500, 500), 5.f, sf::Color::Green);
//
//
//	//SoundBar
////---------------------------------------------------------------
//	//sf::CircleShape soundCircle;
//	//soundCircle.setFillColor(sf::Color::Green);
//	//soundCircle.setPosition(500, 500);
//	//soundCircle.setRadius(5.f);
//	//sf::RectangleShape soundRectangleFillColor;
//	//soundRectangleFillColor.setFillColor(sf::Color::Green);
//	//soundRectangleFillColor.setPosition(500, 504);
//	//soundRectangleFillColor.setSize(sf::Vector2f(1, 2));
//
//	sf::RectangleShape soundRectangle;
//	soundRectangle.setFillColor(sf::Color::Red);
//	soundRectangle.setPosition(500, 504);
//	soundRectangle.setSize(sf::Vector2f(50, 1));
//
//
//	sf::VertexArray arr(sf::LinesStrip, 4);
//
//
//	arr[0].position = sf::Vector2f(500, 504);
//	arr[0].color = sf::Color::Green;
//
//	arr[2].position = sf::Vector2f(500,504);//край право
//	arr[2].color = sf::Color::Green;
//
//	arr[1].position = sf::Vector2f(500,504);
//	arr[1].color = sf::Color::Green;
//
//	arr[3].position = sf::Vector2f( 500,504);//край право
//	arr[3].color = sf::Color::Green;
//
//
//	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//
//
//	while (window.isOpen()) {
//
//		sf::Event event;
//
//		while (window.pollEvent(event)) {
//
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//
//
//		window.clear(sf::Color::Black);
//			window.draw(soundRectangle);
//		
//			window.draw(arr);
//		
//		if (button.isClicked(window)) {
//			button.moveButton(mousePos, window);
//			//std::cout << " f ";
//			arr[2].position =  (sf::Vector2f(button.givePosition()));
//			arr[3].position =  (sf::Vector2f(button.givePosition()));
//		}
//
//		button.draw(window);
//
//		window.display();
//	}
//
//	return 0;
//
// 
// }

#include<iostream>
#include<SFML/Graphics.hpp>
namespace UIfunc {
	class Slider
	{

	public:
		Slider() {}

		Slider(sf::Vector2f Position, sf::Vector2f Size) {
			setPosition(Position);
			setSize(Size);
		}

		void Draw(sf::RenderWindow& window) {
			window.draw(mHandle);
		}
		void Update(sf::RenderWindow& window) {

			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			if (mHandle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) &&
				sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (mousePos.x < mPosition.x + mSize.x && mousePos.x > mPosition.x) {
					mHandle.setPosition(mousePos.x - 3, mPosition.y);
				}
			}
		};

		sf::Vector2f getPosition() {

			return sf::Vector2f(mHandle.getPosition().x, mHandle.getPosition().y);

		}

		void setPosition(sf::Vector2f Position) {

			mPosition = Position;
			mHandle.setPosition(Position);
			RectangleBackGround.setPosition(Position);
			RectangleToFill.setPosition(Position);

		}

		void setSize(sf::Vector2f Size) {

			float divided = (Size.y / 3);

			mHandle.setRadius(Size.x / 6);
			RectangleBackGround.setSize(sf::Vector2f(Size.x, divided + (Size.y / 6)));
			RectangleToFill.setSize(sf::Vector2f(Size.x, divided + (Size.y / 6)));
		}

		void setColor(sf::Color FillColor) {
			mHandle.setFillColor(sf::Color::Green);
			RectangleBackGround.setFillColor(sf::Color::Red);
			RectangleToFill.setFillColor(sf::Color::Green);
		}

	private:
		sf::CircleShape mHandle;
		sf::RectangleShape RectangleBackGround;
		sf::RectangleShape RectangleToFill;

		sf::Vector2f mPosition;
		sf::Vector2f mSize;
		sf::Color mFillColor;

	};

	int main() {
		sf::RenderWindow window(sf::VideoMode(1000, 1000), "sfml window");



		std::unique_ptr <UIfunc::Slider> SliderVolume = std::make_unique<UIfunc::Slider>(sf::Vector2f{ 650.f, 650.f }, sf::Vector2f{ 100.f , 10.f });

		


		//soundbar
	//---------------------------------------------------------------
		//sf::circleshape soundcircle;
		//soundcircle.setfillcolor(sf::color::green);
		//soundcircle.setposition(500, 500);
		//soundcircle.setradius(5.f);
		//sf::rectangleshape soundrectanglefillcolor;
		//soundrectanglefillcolor.setfillcolor(sf::color::green);
		//soundrectanglefillcolor.setposition(500, 504);
		//soundrectanglefillcolor.setsize(sf::vector2f(1, 2));



		sf::Vector2i mousepos = sf::Mouse::getPosition(window);


		while (window.isOpen()) {

			sf::Event Event;

			while (window.pollEvent(Event)) {

				if (Event.type == sf::Event::Closed)
					window.close();
			}



			window.clear(sf::Color::Black);
		


		

			window.display();
		}

		return 0;


	}
}