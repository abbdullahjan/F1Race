//Libraries
#include <SFML/Graphics.hpp>
#include <iostream>
#include<time.h>
using namespace std;

//Glboal variables, functions, classes
float CarXPos = 327, CarYPos=610, CarXpos[5][7], CarYpos[5][7];

float hardnessLevel=1;
int maxAllowedCars=10,RandomLanes=100,RandomCars=20;
int storeSCOREtemp=10;
bool flying = 0;
int flyFrame = 0;
int SCORE = 0 ,LEVEL = 0 ,FLY = 0 ;
int Sdig[3];

bool IsCrash();
void moveShape(sf::Shape& shape, float offsetX, float offsetY);
void location(sf::Event event,bool state);
void SeperateScore();


int main()
{	
label1:

//restart values of Game when game restarted
	hardnessLevel = 1;
	SCORE = 0 ;
	LEVEL = 0 ;
	FLY = 0 ;
	CarXPos = 327; 
	CarYPos=610; 
	bool used[5][7] = {0};
	float moved[5][7] = {0};
	maxAllowedCars=10;
	RandomLanes=100;
	RandomCars=20;
	Sdig[1]=10;
	Sdig[2]=10;
	Sdig[0]=10;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<7;j++)
		{ 
			CarXpos[i][j] = -100;
			CarYpos[i][j] = -100;
		}
	}
	

	srand((unsigned) time(NULL));
	int LaneNum;
	int CarNum;
	//Creating the window
	sf::RenderWindow window(sf::VideoMode(1000, 700), "F1-RACE");

	//Settign the framerate limit to 60 FPS
	window.setFramerateLimit(60);

	//window.setKeyRepeatEnabled(false);
	sf::Event event;
	
	//Variable that keeps the game loop running
	bool play = true;

	//Event object holding all events
	

	//States for button/events


	//Variables
	int streetCount=0;
	int MovingCarcounter = 0; 

		//Images
		sf::Texture background; //Image/texture object
		if (background.loadFromFile("Assets/back.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load";
		}

		//Game Logo
		sf::Texture logo; 
		if (logo.loadFromFile("Assets/logo.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load";
		}

		//street for movement
		sf::Texture street; 
		if (street.loadFromFile("Assets/street.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load Street\n";
		}

		//PlayerCar
		sf::Texture PlayCar; 
		if (PlayCar.loadFromFile("Assets/Car.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load playerCar\n";
		}

		//PlayerCarfly
		sf::Texture PlayCarfly; 
		if (PlayCarfly.loadFromFile("Assets/Fly.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load playerCarfly\n";
		}

		//PlayerCarCrash
		sf::Texture PlayCarCrash; 
		if (PlayCarCrash.loadFromFile("Assets/Crash.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load playerCarCrash\n";
		}


		
		//Car0
		sf::Texture Carimg[7]; 
		if (Carimg[0].loadFromFile("Assets/Car0.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load Car0\n";
		}


		//Car1
		if (Carimg[1].loadFromFile("Assets/Car1.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load Car1\n";
		}


		//Car2
		if (Carimg[2].loadFromFile("Assets/Car2.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load Car2\n";
		}

		//Car3
		if (Carimg[3].loadFromFile("Assets/Car3.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load Car3\n";
		}

		//Car4
		if (Carimg[4].loadFromFile("Assets/Car4.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load Car4\n";
		}

		//Car5
		if (Carimg[5].loadFromFile("Assets/Car5.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load Car5\n";
		}

		//Car6
		if (Carimg[6].loadFromFile("Assets/Car6.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load Car6\n";
		}

		sf::Texture num[10]; 
		//Num0
		if (num[0].loadFromFile("Assets/0.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load 0\n";
		}

		//Num1
		if (num[1].loadFromFile("Assets/1.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load 0\n";
		}
		
		//Num2
		if (num[2].loadFromFile("Assets/2.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load 0\n";
		}
		
		//Num3
		if (num[3].loadFromFile("Assets/3.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load 0\n";
		}
		
		//Num4
		if (num[4].loadFromFile("Assets/4.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load 0\n";
		}
		
		//Num5
		if (num[5].loadFromFile("Assets/5.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load 0\n";
		}
		
		//Num6
		if (num[6].loadFromFile("Assets/6.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load 0\n";
		}
		
		//Num7
		if (num[7].loadFromFile("Assets/7.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load 0\n";
		}
		
		//Num8
		if (num[8].loadFromFile("Assets/8.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load 0\n";
		}
		
		//Num9
		if (num[9].loadFromFile("Assets/9.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load 9\n";
		}

		//Name
		sf::Texture name; 
		if (name.loadFromFile("Assets/name.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load playerCarfly\n";
		}

		//cont
		sf::Texture cont; 
		if (cont.loadFromFile("Assets/continue.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load continue\n";
		}

		//Exitt
		sf::Texture exit; 
		if (exit.loadFromFile("Assets/exit.png") == 0) //Load an image, if not close the program
		{
			cout<<"Unable To Load exit\n";
		}
	//Render shapes
	//Rectangle shape
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(1000,700));
	rect.setPosition(0,0);
	rect.setFillColor(sf::Color::White); //White fill color so we don't change the images colors
	rect.setTexture(&background);

	//Game Logo
	sf::RectangleShape RectLogo;
	RectLogo.setSize(sf::Vector2f(265,219));
	RectLogo.setPosition(735,1);
	RectLogo.setTexture(&logo);

	//Street 
	sf::RectangleShape RectStreet;
	RectStreet.setSize(sf::Vector2f(599,768));
	RectStreet.setPosition(51,-67);
	RectStreet.setTexture(&street);

	//Line 
	sf::RectangleShape Line;
	Line.setSize(sf::Vector2f(658,5));
	Line.setFillColor(sf::Color(0,0,0));
	Line.setPosition(0,0);

	//Car
	sf::RectangleShape PlayerCar;
	PlayerCar.setSize(sf::Vector2f(65,75));
	PlayerCar.setPosition(327,610);
	PlayerCar.setTexture(&PlayCar);
	
	//Carfly
	sf::RectangleShape PlayerCarfly;
	PlayerCarfly.setSize(sf::Vector2f(75,85));
	PlayerCarfly.setPosition(327,610);
	PlayerCarfly.setTexture(&PlayCarfly);

	//Cars
	sf::RectangleShape Car[7];
	for(int i=0;i<7;i++)
	{Car[i].setSize(sf::Vector2f(50,60));
	Car[i].setTexture(&Carimg[i]);
	Car[i].setPosition(30,12);
	}
	Car[0].setSize(sf::Vector2f(80,90));
	Car[4].setSize(sf::Vector2f(65,75));
	Car[0].setPosition(312, -40);
	
	//SCORE SQUARES
	sf::RectangleShape Num[4];
	for(int i=0;i<4;i++)
	{Num[i].setSize(sf::Vector2f(40,40));
	Num[i].setPosition(908 - 50*i, 316);
	}
	Num[0].setTexture(&num[0]);

	//LEVEL
	sf::RectangleShape level;
	level.setSize(sf::Vector2f(40,39));
	level.setPosition(908,424);

	//FLY
	sf::RectangleShape fly;
	fly.setSize(sf::Vector2f(40,37));
	fly.setPosition(908,537);

	//NAME
	sf::RectangleShape Name;
	Name.setSize(sf::Vector2f(220,100));
	Name.setPosition(735,210);
	Name.setTexture(&name);

	//continuoes
	sf::RectangleShape Cont;
	Cont.setSize(sf::Vector2f(400,200));
	Cont.setPosition(160,400);
	Cont.setTexture(&cont);

	//exit
	sf::RectangleShape Exit;
	Exit.setSize(sf::Vector2f(400,200));
	Exit.setPosition(160,150);
	Exit.setTexture(&exit);
	//Circle shape
	

	//Game loop
	while (play == true)
	{	
		
		if(SCORE > 0 && SCORE%90 == 0)
		{
			if(storeSCOREtemp != SCORE) //before SCORE 90 moves to 100, this condition was being satisfied multiple times, let it come insode once only
			{
			storeSCOREtemp = SCORE ;
			if(LEVEL < 9)
			{
				LEVEL++;
				hardnessLevel += 0.1 ;
			}
		maxAllowedCars+=2;
		if(RandomLanes>10)
		{RandomLanes= RandomLanes-6;
		RandomCars--;}
		if(RandomLanes>6 && RandomLanes <10)
			RandomLanes--;
		if(FLY < 9)
			FLY++;
			}
		}

		if(streetCount==74)
		{
			RectStreet.setPosition(51,-67);
			streetCount=0;
		}
		moveShape(RectStreet, 0, 2.0f);
		streetCount+=2;
		//EVENTS
		while (window.pollEvent(event))
		{



			if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
			{	if(CarXPos<650-50)
				{moveShape(PlayerCar, 3.0f*hardnessLevel,0);
				CarXPos+=3*hardnessLevel;
				}
			}
			if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
			{	
				if(CarXPos>50)
				{
				moveShape(PlayerCar, -3.0f*hardnessLevel,0);
				CarXPos-=3*hardnessLevel;
				}
			}
			if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
			{
				if(CarYPos>6)
				{
				moveShape(PlayerCar, 0,-3.5f*hardnessLevel);
				CarYPos-=3.5*hardnessLevel;
				}
			}
			if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
			{	if(CarYPos<694-60)
				{
				moveShape(PlayerCar, 0,3.5f*hardnessLevel);
				CarYPos+=3.5*hardnessLevel;
				}
			}

			if((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space))
			{
				if(flying == 0 && FLY>0)
				{
					FLY--;
					flying = 1;
				}
			}
//Show Cursor 
//FUNCTION
//IS HERE
			location(event,play);
			
			//Event type is window closed
			if (event.type == sf::Event::Closed)
			{
				//Set play to false in order to stop the game loop
				play = false;
			}
		}

		//LOGIC

	
		LaneNum = rand()%RandomLanes;
		CarNum = rand()%RandomCars;
		



		if(LaneNum<5)
		{
			if(CarNum<7)
			{
				if(used[LaneNum][CarNum] == 0 && MovingCarcounter<maxAllowedCars)
				{
					used[LaneNum][CarNum] = 1;
					CarXpos[LaneNum][CarNum] = 70+(rand()%10)+(125*LaneNum);
					CarYpos[LaneNum][CarNum] = -90 ;
					MovingCarcounter++;
				}
			}
		}
		
		moveShape(Car[0], 0,3.0f);

		
		//RENDERING
		if(flying == 1)
		{flyFrame ++ ;
		if(flyFrame ==73)
		{flying = 0 ;
		flyFrame = 0;}
		}

		


		if(flying == 0)
		if(IsCrash())
	{
		PlayerCar.setTexture(&PlayCarCrash);

		
		
	//This displays in crash//Display Next Frame
							window.clear();

							window.draw(rect);
							window.draw(RectLogo);
							window.draw(RectStreet);
							Line.setPosition(0,0);
							window.draw(Line);
							Line.setPosition(0,695);
							window.draw(Line);
							window.draw(Num[0]);
	//This Is Crash Frame
							for(int i=0;i<5;i++)
							{
								for(int j=0;j<7;j++)
								{
									if(used[i][j] == 1)
									{
										Car[j].setPosition(CarXpos[i][j],CarYpos[i][j]);
										if(j==2)
										{
										window.draw(Car[j]);
										moveShape(Car[j], 0,4.0f);
										CarYpos[i][j] += 4; 
										moved[i][j] += 4 ;
										}
	//This is Crash Frame
										else if(j==5)
										{
										window.draw(Car[j]);
										moveShape(Car[j], 0,3.4f);
										CarYpos[i][j] += 3.4; 
										moved[i][j] += 3.4 ;
										}
										else if(j==0)
										{
										window.draw(Car[j]);
										moveShape(Car[j], 0,2.5f);
										CarYpos[i][j] += 2.5; 
										moved[i][j] += 2.5 ;
										}
//Thhis is crash Frame						
										else if(j==6)
										{
										window.draw(Car[j]);
										moveShape(Car[j], 0,3.1f);
										CarYpos[i][j] += 3.1; 
										moved[i][j] += 3.1 ;
										}
										else{
										window.draw(Car[j]);
										moveShape(Car[j], 0,2.8f);
										CarYpos[i][j] += 2.8; 
										moved[i][j] += 2.8 ;}
//This Is Crash Frame
										if(moved[i][j] > 800)
										{
											used[i][j] = 0;
											moved[i][j] = 0; 
											MovingCarcounter--;
											CarYpos[i][j] = -60;
										}
									}
								}
							}
							//window.draw(circle); //Draw the circle shape
							window.draw(PlayerCar);
							SeperateScore();
							for(int i=0;i<3;i++)
							{
								if(Sdig[i] < 10)
								{	
									Num[i+1].setTexture(&num[Sdig[i]]);
									window.draw(Num[i+1]);
								}
								
							}

							level.setTexture(&num[LEVEL]);
							window.draw(level);
					
							fly.setTexture(&num[FLY]);
							window.draw(fly);
							window.draw(Exit);
							window.draw(Cont);
							window.display();
							



//C to continue, enter to exit

		while(1)
		{
		while (window.pollEvent(event))
			window.clear();
			if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
			{
				return 0;
			}
			if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::C)
			{
				goto label1;
			}
		}
	}

		window.clear();

		window.draw(rect);
		window.draw(RectLogo);
		window.draw(RectStreet);
		Line.setPosition(0,0);
		window.draw(Line);
		Line.setPosition(0,695);
		window.draw(Line);
		window.draw(Num[0]);
		window.draw(Name);
		//draw player car above other, helpful for flying

		for(int i=0;i<5;i++)
		{
			for(int j=0;j<7;j++)
			{
				if(used[i][j] == 1)
				{
					Car[j].setPosition(CarXpos[i][j],CarYpos[i][j]);
					if(j==2)
					{
					window.draw(Car[j]);
					moveShape(Car[j], 0,4.0f*hardnessLevel);
					CarYpos[i][j] += 4*hardnessLevel; 
					moved[i][j] += 4 *hardnessLevel;
					}
					else if(j==5)
					{
					window.draw(Car[j]);
					moveShape(Car[j], 0,3.4f*hardnessLevel);
					CarYpos[i][j] += 3.4*hardnessLevel; 
					moved[i][j] += 3.4*hardnessLevel ;
					}
					else if(j==0)
					{
					window.draw(Car[j]);
					moveShape(Car[j], 0,2.5f*hardnessLevel);
					CarYpos[i][j] += 2.5*hardnessLevel; 
					moved[i][j] += 2.5 *hardnessLevel;
					}
					else if(j==6)
					{
					window.draw(Car[j]);
					moveShape(Car[j], 0,3.1f*hardnessLevel);
					CarYpos[i][j] += 3.1*hardnessLevel; 
					moved[i][j] += 3.1*hardnessLevel ;
					}
					else{
					window.draw(Car[j]);
					moveShape(Car[j], 0,2.8f*hardnessLevel);
					CarYpos[i][j] += 2.8*hardnessLevel; 
					moved[i][j] += 2.8 *hardnessLevel;}

					if(moved[i][j] > 800)
					{
						used[i][j] = 0;
						moved[i][j] = 0; 
						MovingCarcounter--;
						CarYpos[i][j] = -60;
						SCORE+=10;
						if(FLY<9)
							FLY++;
						cout<<"Score::"<<SCORE<<"Fly::"<<FLY<<endl;
					}
				}
			}
		}
		//window.draw(circle); //Draw the circle shape
		if(flying == 1)
		{PlayerCarfly.setPosition(CarXPos,CarYPos);
		window.draw(PlayerCarfly);}
		else
		window.draw(PlayerCar);
		
		SeperateScore();
		for(int i=0;i<3;i++)
		{
			if(Sdig[i] < 10)
			{	
				Num[i+1].setTexture(&num[Sdig[i]]);
				window.draw(Num[i+1]);
			}
			
		}

		level.setTexture(&num[LEVEL]);
		window.draw(level);

		fly.setTexture(&num[FLY]);
		window.draw(fly);

		window.display();
	}
	///////////
	
	//Clean up and close the window
	window.close();

	//Close the program
	return 0;
}



void moveShape(sf::Shape& shape, float offsetX, float offsetY)
{
    sf::Vector2f currentPosition = shape.getPosition();
    shape.setPosition(currentPosition.x + offsetX, currentPosition.y + offsetY);
}

void location(sf::Event event,bool state)
{
	//variables
	bool enterReleased = false ;
	int clickCount = 0;
	bool left = false;
	bool right = false;
	int MouseX=0,MouseY=0;
	int steadyMouseX =0, steadyMouseY = 0;
	int xmove =0,ymove=0;

	


	//Events
		
			if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
			{
				enterReleased = true ;
			}
			if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				left = true;
			}
			if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
			{
				right = true;
			}
			if(event.type == sf::Event::MouseMoved)
			{
			MouseX = event.mouseMove.x;
			MouseY = event.mouseMove.y; 
			}
			if(event.type == sf::Event::Closed)
			{
			state = false ;
			}
		

		//logic

		if(enterReleased)
		{
			cout<<"Enter is Released\n";
			enterReleased = false;
		}
		if(left)
		{
			if(MouseX < 200)
			{state = false;}
			else
			{clickCount++;
			left =false;
			cout<<"Mouse Click Count :" << clickCount <<"\n";}
		}
		if(right)
		{
			clickCount--;
			right =false;

			cout<<"Right Click\nMouse Click Count :" << clickCount <<endl;
		}
		if(MouseX != steadyMouseX || MouseY != steadyMouseY)
		{
		cout<<"MouseX = "<<MouseX<<"	MouseY = "<<MouseY<<endl;
		steadyMouseX = MouseX ; 
		steadyMouseY = MouseY ;
		}
}

bool IsCrash()
{

	for(int i=0;i<5;i++)
	{
		for(int j=0;j<7;j++)
		{	if(CarXpos[i][j] != -100){
			if(j==0)
			{
			if(CarXPos <= CarXpos[i][j]+80 && (CarXPos+65) > CarXpos[i][j] )
			{
				if(CarYPos <= CarYpos[i][j]+90 && (CarYPos+60) > CarYpos[i][j] )
					return 1;
			}
			}
			
			else if(CarXPos <= CarXpos[i][j]+50 && (CarXPos+65) > CarXpos[i][j] )
			{
				if(CarYPos <= CarYpos[i][j]+60 && (CarYPos+60) > CarYpos[i][j] )
					return 1;
			}}
		}
	}
	return 0;
}

void SeperateScore()
{
	int j=0;
	for(int i=SCORE/10 ; i>0 ;i/=10)
	{
		Sdig[j] = i%10;
		j++;
	}
}
