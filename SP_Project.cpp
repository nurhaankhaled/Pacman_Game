// SP_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<sstream>
using namespace std;
#define time 0.005
struct distance {
	float postionx;
	float postiony;
}blocks[31][28];

void movement(sf::Sprite& p, int a, int b, float c, float x, int y, float t, float u)
{
	p.setOrigin(a, b);
	p.setScale(c, x);
	p.setRotation(y);
	p.setPosition(t, u);
}

int main()
{
	int q, c;
	for (q = 0; q < 31; q++)
	{
		for (c = 0; c < 28; c++)
		{
			blocks[q][c].postionx = 23.21428571428571 * c;
			blocks[q][c].postiony = 20.96774193548387 * q;
		}
	}
	const int z = 1;

	int arrai[31][28] =
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,1,
1,2,2,2,1,2,2,2,2,2,2,2,1,2,2,2,2,1,1,1,1,1,1,1,2,1,2,1,
1,2,1,1,1,2,2,2,2,2,2,2,1,2,2,2,2,1,2,2,2,2,2,2,2,1,2,1,
1,2,1,2,2,2,2,2,2,1,2,2,1,2,2,1,2,1,2,1,1,1,1,1,2,1,2,1,
1,2,1,2,2,1,1,1,2,1,2,2,1,2,2,1,2,1,2,1,2,2,2,2,2,1,2,1,
1,2,1,2,2,1,2,2,2,1,2,2,1,2,2,1,2,2,2,1,1,1,1,1,2,1,2,1,
1,2,1,2,2,1,2,2,2,1,2,2,1,2,2,1,2,1,2,2,2,2,3,1,2,1,2,1,
1,2,1,2,2,1,2,2,2,1,2,2,1,2,2,1,2,1,2,1,1,1,1,1,2,1,2,1,
1,2,1,2,2,1,2,2,2,1,2,2,1,2,2,1,2,1,2,1,2,2,2,2,2,1,2,1,
1,2,1,2,2,1,2,2,2,1,2,1,1,1,2,1,2,1,2,1,1,1,1,1,2,2,2,1,
1,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,1,2,1,2,1,
1,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1,
1,1,1,1,1,1,2,2,2,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,2,1,
1,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,1,
1,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,1,2,2,1,2,2,2,2,2,2,1,
1,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,1,2,2,1,2,2,2,2,2,2,1,
1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,2,2,2,2,2,2,1,
1,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,1,
1,2,1,2,1,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,1,2,1,1,1,1,1,1,
1,2,1,2,1,1,1,2,1,2,2,2,2,2,2,2,2,2,2,2,1,2,1,2,2,2,2,1,
1,2,1,2,2,2,1,2,1,2,2,1,2,1,1,1,2,1,2,2,1,2,1,2,2,1,2,1,
1,2,2,2,1,2,1,2,1,2,2,1,2,2,1,2,2,1,2,2,1,2,1,2,2,1,2,1,
1,2,1,2,1,2,2,2,1,2,2,1,2,2,1,2,2,1,2,2,1,2,1,2,2,1,2,1,
1,2,1,2,1,1,1,2,1,2,2,1,2,2,1,2,2,1,2,2,2,2,1,2,2,1,2,1,
1,2,1,2,2,3,1,2,2,2,2,1,2,2,1,2,2,1,2,2,2,2,1,2,2,1,2,1,
1,2,1,2,1,1,1,2,1,2,2,1,2,2,1,2,2,1,2,2,1,1,1,2,2,1,2,1,
1,2,1,2,1,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,1,2,1,
1,2,1,2,1,1,1,2,1,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1,1,1,2,1,
1,2,2,2,2,2,1,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };


	int p = 1;
	int e = 1;
	int count = 0;
	int points = 0;
	int score = 0;
	int lives = 3;
	int ghostPosition = 15;
	int h = 12;
	int m = 15;
	int n = 11;
	int d = 15;
	int f = 13;
	int w = 15;
	int r = 14;
	bool isruning = true;

	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 28; j++)
		{
			if (arrai[i][j] == 2)
			{
				points++;
			}
			else if (arrai[i][j] == 3) {
				points += 10;
			}
		}
	}

	cout << "[p] for Pause the game" << endl;
	cout << "[R] for Resume the game" << endl;
	cout << "[Esc] for Exit the game" << endl;
	//window creation:
	sf::RenderWindow window(sf::VideoMode(650, 700), "Pacman", sf::Style::Default);
	window.setFramerateLimit(8);

	//player and its texture creation:
	sf::Texture playertexture;

	if (!playertexture.loadFromFile("tileset_pacman_player.png"))
	{
		cout << "Error loading playertexture" << endl;
	}
	sf::IntRect rectSourceSprite(0, 0, 15, 15);
	sf::Sprite player(playertexture, rectSourceSprite);
	player.setPosition(blocks[p][e].postionx, blocks[p][e].postiony);
	playertexture.setSmooth(true);

	//Background texture creation:
	sf::Texture background;
	if (!background.loadFromFile("tileset_pacman_map.png"))
	{
		cout << "Error loading background" << endl;
	}
	sf::IntRect rectSourceSpace(0, 0, 15, 15);
	sf::IntRect rectSourceDots(15, 0, 15, 15);
	sf::IntRect rectSourceBlock(45, 0, 15, 15);
	sf::IntRect rectSourcesuperdot(29, 0, 15, 15);
	background.setSmooth(true);

	//ghost texture creation:
	sf::RectangleShape ghost1(sf::Vector2f(15, 15));
	sf::RectangleShape ghost2(sf::Vector2f(15, 15));
	sf::RectangleShape ghost3(sf::Vector2f(15, 15));
	sf::RectangleShape ghost4(sf::Vector2f(15, 15));
	sf::Texture ghosttexture1; sf::Texture ghosttexture2;
	sf::Texture ghosttexture3; sf::Texture ghosttexture4;
	ghost1.setTexture(&ghosttexture1); ghost2.setTexture(&ghosttexture1);
	ghost3.setTexture(&ghosttexture1); ghost4.setTexture(&ghosttexture1);
	ghosttexture1.loadFromFile("tileset_pacman_ghost.png");
	sf::Vector2u ghosttexturesize = ghosttexture1.getSize();
	ghosttexturesize.x /= 15; ghosttexturesize.y /= 1;
	sf::IntRect rectSourceghost(0, 0, 15, 15);
	ghost1.setTextureRect(rectSourceghost);
	ghost2.setTextureRect(rectSourceghost);
	ghost3.setTextureRect(rectSourceghost);
	ghost4.setTextureRect(rectSourceghost);
	ghosttexture1.setSmooth(true); ghosttexture2.setSmooth(true);
	ghosttexture3.setSmooth(true); ghosttexture4.setSmooth(true);
	ghost1.setPosition(blocks[m][n].postionx, blocks[m][n].postiony);
	ghost2.setPosition(blocks[ghostPosition][h].postionx, blocks[ghostPosition][h].postiony);
	ghost3.setPosition(blocks[d][f].postionx, blocks[d][f].postiony);
	ghost4.setPosition(blocks[w][r].postionx, blocks[w][r].postiony);

	//lives texture creation:
	sf::RectangleShape live(sf::Vector2f(15, 15));
	sf::Texture livetexture;
	live.setTexture(&livetexture);
	livetexture.loadFromFile("tileset_pacman_map.png");
	sf::Vector2u livetexturesize = livetexture.getSize();
	livetexturesize.x /= 15; livetexturesize.y /= 1;
	live.setTextureRect(sf::IntRect(75, 0, 15, 15));

	//loading font for all texts:
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		cout << "Error loading font" << endl;
	}

	// you win text:
	sf::Text textwin("You Win", font);
	textwin.setCharacterSize(30);
	textwin.setStyle(sf::Text::Bold);
	textwin.setFillColor(sf::Color::White);

	// you win text:
	sf::Text textlose("Game Over", font);
	textlose.setCharacterSize(30);
	textlose.setStyle(sf::Text::Bold);
	textlose.setFillColor(sf::Color::White);

	//score text:
	sf::Text scoretext("Score", font);
	scoretext.setCharacterSize(30);
	scoretext.setStyle(sf::Text::Bold);
	scoretext.setFillColor(sf::Color::White);
	stringstream s;

	//game paused text: 
	sf::Text textpaused("Game is paused", font);
	textpaused.setCharacterSize(30);
	textpaused.setStyle(sf::Text::Bold);
	textpaused.setFillColor(sf::Color::White);

	//Sound creation for dot:
	sf::SoundBuffer bufferdot;
	bufferdot.loadFromFile("pacman_ball.wav");
	if (!bufferdot.loadFromFile("pacman_ball.wav"))
	{
		cout << "Error loading buffer dot" << endl;
	}
	sf::Sound sounddot;
	sounddot.setBuffer(bufferdot);
	
	//Sound creation for super dot:
	sf::SoundBuffer buffersuperdot;
	buffersuperdot.loadFromFile("pacman_powerup.wav");
	if (!buffersuperdot.loadFromFile("pacman_powerup.wav"))
	{
		cout << "Error loading buffer super dot" << endl;
	}
	sf::Sound soundsuperdot;
	soundsuperdot.setBuffer(buffersuperdot);

	//Sound creation for dead:
	sf::SoundBuffer bufferdead;
	bufferdead.loadFromFile("pacman_dead.wav");
	if (!bufferdead.loadFromFile("pacman_dead.wav"))
	{
		cout << "Error loading buffer dead" << endl;
	}
	sf::Sound sounddead;
	sounddead.setBuffer(bufferdead);

	//Animation time initialization:
	sf::Clock clock;
	sf::Clock ghostsclock;
	sf::Clock timer;
	sf::Clock ghostanimation;

	while (window.isOpen())
	{
		// to clost the window
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			window.close();
		}

		if (isruning == false)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
			{
				isruning = true;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
			{
				textpaused.setPosition(250, 650);
				window.draw(textpaused);
			}

			continue;
		}



		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			if (arrai[p][e - 1] != z)
			{
				movement(player, 15, 0, -1.0, 1.0, 0, blocks[p][e - 1].postionx, blocks[p][e - 1].postiony);
				e -= 1;
			}

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			if (arrai[p][e + 1] != z)
			{
				movement(player, 0, 0, 1.0, 1.0, 0, blocks[p][e + 1].postionx, blocks[p][e + 1].postiony);
				e += 1;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{

			if (arrai[p - 1][e] != z)
			{
				movement(player, 15, 0, 1.0, 1.0, 270, blocks[p - 1][e].postionx, blocks[p - 1][e].postiony);
				p -= 1;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{

			if (arrai[p + 1][e] != z)
			{
				movement(player, 0, 15, 1.0, 1.0, 90, blocks[p + 1][e].postionx, blocks[p + 1][e].postiony);
				p += 1;
			}
		}
		if (arrai[p][e] == 2)
		{
			arrai[p][e] = 0;
			sounddot.play();
			count++;
			score = count * 1;
		}
		if (arrai[p][e] == 3)
		{
			arrai[p][e] = 0;
			soundsuperdot.play();
			count += 10;
			score = count * 1;
			lives++;
		}
		// ghost movement
		int randomx, inner = 0;
		randomx = rand() % 1000 + 1;
		//up

		if (randomx >= 750) {
			for (; inner < 6; inner++) {

				if (ghostsclock.getElapsedTime().asMicroseconds() > time) {
					if (arrai[m - 1][n] != z) {
						ghost1.setPosition(blocks[m - 1][n].postionx, blocks[m - 1][n].postiony);
						m -= 1;

					}ghostsclock.restart();

				}
				if (ghostsclock.getElapsedTime().asMicroseconds() > time) {
					if (arrai[ghostPosition][h + 1] != z) {
						ghost2.setPosition(blocks[ghostPosition][h + 1].postionx, blocks[ghostPosition][h + 1].postiony);
						h += 1;

					} ghostsclock.restart();
				}
				if (ghostsclock.getElapsedTime().asMicroseconds() > time) {
					if (arrai[d + 1][f] != z) {
						ghost3.setPosition(blocks[d + 1][f].postionx, blocks[d + 1][f].postiony);
						d += 1;;

					}ghostsclock.restart();
				}
				if (ghostsclock.getElapsedTime().asMicroseconds() > time) {
					if (arrai[w][r - 1] != z) {
						ghost4.setPosition(blocks[w][r - 1].postionx, blocks[w][r - 1].postiony);
						r -= 1;
					}ghostsclock.restart();
				}

			}

		}
		//down
		else if (randomx >= 500) {
			for (; inner < 6; inner++) {

				if (ghostsclock.getElapsedTime().asMicroseconds() > time) {
					if (arrai[m + 1][n] != z) {
						ghost1.setPosition(blocks[m + 1][n].postionx, blocks[m + 1][n].postiony);
						m += 1;;

					}ghostsclock.restart();
				}
				if (ghostsclock.getElapsedTime().asMicroseconds() > time) {
					if (arrai[ghostPosition][h - 1] != z) {
						ghost2.setPosition(blocks[ghostPosition][h - 1].postionx, blocks[ghostPosition][h - 1].postiony);
						h -= 1;
					}ghostsclock.restart();
				}
				if (ghostsclock.getElapsedTime().asMicroseconds() > time) {
					if (arrai[d - 1][f] != z) {
						ghost3.setPosition(blocks[d - 1][f].postionx, blocks[d - 1][f].postiony);
						d -= 1;

					}ghostsclock.restart();

				}
				if (ghostsclock.getElapsedTime().asMicroseconds() > time) {
					if (arrai[w][r + 1] != z) {
						ghost4.setPosition(blocks[w][r + 1].postionx, blocks[w][r + 1].postiony);
						r += 1;

					} ghostsclock.restart();
				}

			}

		}
		//left
		else if (randomx >= 250) {

			for (; inner < 5; inner++) {
				if (ghostsclock.getElapsedTime().asMicroseconds() > time) {
					if (arrai[m][n - 1] != z) {
						ghost1.setPosition(blocks[m][n - 1].postionx, blocks[m][n - 1].postiony);
						n -= 1;
					}ghostsclock.restart();
				}
				if (ghostsclock.getElapsedTime().asMicroseconds() > time) {
					if (arrai[ghostPosition - 1][h] != z) {
						ghost2.setPosition(blocks[ghostPosition - 1][h].postionx, blocks[ghostPosition - 1][h].postiony);
						ghostPosition -= 1;

					}ghostsclock.restart();

				}
				if (ghostsclock.getElapsedTime().asMicroseconds() > time) {
					if (arrai[d][f + 1] != z) {
						ghost3.setPosition(blocks[d][f + 1].postionx, blocks[d][f + 1].postiony);
						f += 1;

					} ghostsclock.restart();
				}
				if (ghostsclock.getElapsedTime().asMicroseconds() > time) {
					if (arrai[w + 1][r] != z) {
						ghost4.setPosition(blocks[w + 1][r].postionx, blocks[w + 1][r].postiony);
						w += 1;;

					}ghostsclock.restart();
				}
			}

		}
		//right
		else {
			for (; inner < 4; inner++) {
				if (ghostsclock.getElapsedTime().asMicroseconds() > time) {
					if (arrai[m][n + 1] != z) {
						ghost1.setPosition(blocks[m][n + 1].postionx, blocks[m][n + 1].postiony);
						n += 1;

					} ghostsclock.restart();
				}
				if (ghostsclock.getElapsedTime().asMicroseconds() > time) {
					if (arrai[ghostPosition + 1][h] != z) {
						ghost2.setPosition(blocks[ghostPosition + 1][h].postionx, blocks[ghostPosition + 1][h].postiony);
						ghostPosition += 1;;

					}ghostsclock.restart();
				}
				if (ghostsclock.getElapsedTime().asMicroseconds() > time) {
					if (arrai[d][f - 1] != z) {
						ghost3.setPosition(blocks[d][f - 1].postionx, blocks[d][f - 1].postiony);
						f -= 1;
					}ghostsclock.restart();
				}
				if (ghostsclock.getElapsedTime().asMicroseconds() > time) {
					if (arrai[w - 1][r] != z) {
						ghost4.setPosition(blocks[w - 1][r].postionx, blocks[w - 1][r].postiony);
						r -= 1;

					}
					ghostsclock.restart();

				}
			}



		}


		if (player.getPosition() == ghost1.getPosition() || player.getPosition() == ghost2.getPosition() || player.getPosition() == ghost3.getPosition() || player.getPosition() == ghost4.getPosition())
		{
			lives--;
			sounddead.play();
			p = 1;
			e = 1;
			ghostPosition = 15;
			h = 12;
			m = 15;
			n = 11;
			d = 15;
			f = 13;
			w = 15;
			r = 14;
			player.setPosition(blocks[p][e].postionx, blocks[p][e].postiony);
			ghost1.setPosition(blocks[m][n].postionx, blocks[m][n].postiony);
			ghost2.setPosition(blocks[ghostPosition][h].postionx, blocks[ghostPosition][h].postiony);
			ghost3.setPosition(blocks[d][f].postionx, blocks[d][f].postiony);
			ghost4.setPosition(blocks[w][r].postionx, blocks[w][r].postiony);

		}

		if (clock.getElapsedTime().asSeconds() > 0.1f)
		{
			if (rectSourceSprite.left == 45)
				rectSourceSprite.left = 0;
			else
				rectSourceSprite.left += 15;

			player.setTextureRect(rectSourceSprite);
			clock.restart();
		}

		if (ghostanimation.getElapsedTime().asSeconds() > 0.1)
		{
			if (rectSourceghost.left == 45)
				rectSourceghost.left = 0;
			else
				rectSourceghost.left += 15;

			ghost1.setTextureRect(rectSourceghost);
			ghost2.setTextureRect(rectSourceghost);
			ghost3.setTextureRect(rectSourceghost);
			ghost4.setTextureRect(rectSourceghost);


		}

		window.clear();

		int counter = 1;

		if (counter == 1)
		{
			counter++;
			for (int y = 0; y < 31; y++)
			{
				for (int x = 0; x < 28; x++)
				{

					if (arrai[y][x] == 2)
					{

						sf::Sprite block(background, rectSourceDots);
						block.setScale(1.0f, 1.0f);
						block.setPosition(blocks[y][x].postionx, blocks[y][x].postiony);
						window.draw(block);
					}

					else if (arrai[y][x] == 1)
					{
						sf::Sprite block(background, rectSourceBlock);
						block.setScale(1.2f, 1.2f);
						block.setPosition(blocks[y][x].postionx, blocks[y][x].postiony);
						window.draw(block);
					}

					else if (arrai[y][x] == 0)
					{
						sf::Sprite block(background, rectSourceSpace);
						block.setScale(1.0f, 1.0f);
						block.setPosition(blocks[y][x].postionx, blocks[y][x].postiony);
						window.draw(block);
					}
					else if (arrai[y][x] == 3)
					{
						sf::Sprite block(background, rectSourcesuperdot);
						block.setScale(1.2f, 1.2f);
						block.setPosition(blocks[y][x].postionx, blocks[y][x].postiony);
						window.draw(block);
					}
				}
			}
		}

		s.str("");
		s << "Score:" << score;
		scoretext.setString(s.str());
		scoretext.setPosition(0, 650);

		window.draw(scoretext);

		if (isruning == true)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
			{
				textpaused.setPosition(225, 650);
				window.draw(textpaused);
				isruning = false;
			}
		}

		if (count == points)
		{
			textwin.setPosition(250, 650);
			window.draw(textwin);
			isruning = false;
		}

		if (lives == 0)
		{

			textlose.setPosition(250, 650);
			window.draw(textlose);
			isruning = false;
		}
		int t = 0;
		for (int l = 0; l < lives; l++)
		{
			live.setPosition(500 + t, 660);
			live.setScale(1.0f, 1.0f);
			window.draw(live);
			t += 15;
		}
		window.draw(ghost1);
		window.draw(ghost2);
		window.draw(ghost3);
		window.draw(ghost4);
		window.draw(player);
		window.display();

	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
