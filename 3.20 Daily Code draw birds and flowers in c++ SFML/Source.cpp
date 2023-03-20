#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;

//function declaration
void drawBirb(int xpos, int ypos, int color[3]);
void drawFlower(int xpos, int ypos, int color[3]);

sf::RenderWindow window(sf::VideoMode(800, 800), "Happy Spring!"); //set up game window

int main() {//////////////////////////////////////////////////////////////////////////////////////////////////

	//this next line is an array. Arrays are a lot like python lists.
	int birbColor1[] = { 190, 210, 255 }; //set up an array of colors to make your birb PINK!
	int birbColor2[] = { 255, 200, 200 };
	int birbColor3[] = { 160, 200, 100 };
	int birbColor4[] = { 250, 160, 120 };
	int flowerColor1[] = { 255, 245, 240 };
	int flowerColor2[] = { 229, 120, 29 };
	int flowerColor3[] = { 193, 0, 19 };
	int flowerColor4[] = { 40, 162, 219 };
	while (1) {//GAME LOOP OMG-------------------------------------

		drawBirb(100, 200, birbColor1); //function call
		drawBirb(200, 300, birbColor2);
		drawBirb(300, 200, birbColor3);
		drawBirb(200, 100, birbColor4);
		drawFlower(500, 500, flowerColor1);
		drawFlower(400, 400, flowerColor2);
		drawFlower(300, 500, flowerColor3);
		drawFlower(200, 400, flowerColor4);
		window.display();
	}//end game loop-----------------------------------------------

}//////////////////////////////////////////////////////////////////////////////////////////////////


//function definition
void drawBirb(int xpos, int ypos, int color[3]) {
	//SFML stuff
	sf::CircleShape body;
	sf::CircleShape beak; //SFML lets you set the number of sides of a circle, so this is how we make a triangle!
	sf::RectangleShape feets;

	//leggies
	feets.setPosition(xpos + 10, ypos + 35);
	feets.setFillColor(sf::Color(200, 150, 0));
	feets.setSize(sf::Vector2f(5, 15));
	window.draw(feets); //first leg
	feets.setPosition(xpos + 25, ypos + 35);
	window.draw(feets); //second leg

	//body 
	body.setRadius(20);
	body.setFillColor((sf::Color(color[0], color[1], color[2]))); //noticing accessing slots of an array is just like getting to slots of a list
	body.setPosition(xpos, ypos);
	window.draw(body);

	//birb eyes
	body.setRadius(4);
	body.setFillColor((sf::Color(0, 0, 0))); //black
	body.setPosition(xpos + 15, ypos + 10);
	window.draw(body); //first eye
	body.setPosition(xpos + 30, ypos + 10);
	window.draw(body); //second eye

	//birb beak
	beak.setPointCount(3); //make it a triangle
	beak.setRadius(10);
	beak.setFillColor((sf::Color(200, 150, 0))); //orange
	beak.setPosition(xpos + 17, ypos + 10);
	window.draw(beak);

}
void drawFlower(int xpos, int ypos, int color[3]) {
	//SFML stuff
	sf::CircleShape outerCircle;
	sf::CircleShape innerCircle; //SFML lets you set the number of sides of a circle, so this is how we make a triangle!
	sf::RectangleShape stem;

	//stem
	stem.setPosition(xpos + 15, ypos + 35);
	stem.setFillColor(sf::Color(133, 163, 126));
	stem.setSize(sf::Vector2f(5,35));
	window.draw(stem);

	//body 
	outerCircle.setRadius(20);
	outerCircle.setFillColor((sf::Color(color[0], color[1], color[2]))); //noticing accessing slots of an array is just like getting to slots of a list
	outerCircle.setPosition(xpos, ypos);
	window.draw(outerCircle);

	//birb eyes
	//outerCircle.setRadius(4);
	//outerCircle.setFillColor((sf::Color(0, 0, 0))); //black
	//outerCircle.setPosition(xpos + 15, ypos + 10);
	//window.draw(outerCircle); //first eye
	//outerCircle.setPosition(xpos + 30, ypos + 10);
	//window.draw(outerCircle); //second eye

	//birb beak
	innerCircle.setPointCount(5); //make it a triangle
	innerCircle.setRadius(10);
	innerCircle.setFillColor((sf::Color(230, 179, 44))); //orange
	innerCircle.setPosition(xpos + 10, ypos + 10);
	window.draw(innerCircle);

}