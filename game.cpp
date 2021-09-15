//============================================================================
// Name        : game.cpp
// Author      : Hassan Mustafa
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> 
#include <iostream>
#include <string> 
#include <fstream> // for basic math functions such as cos, sin,sqrt
using namespace std;
/*HIghScores----Variables*/
int high_Scores[10];
int speedcounts=0;
int menux=30;
int counts_score=0;
bool gifts=false;
bool excolor=true;
bool startup=false;
bool change_level=true;
/*Real menu*/
bool menus=true;
bool rnew=false;
bool rhelp=false;
bool rexit=false;
bool rhigh=false;
/*--PLAYER AXIS---*/
	float x2 = 350; 
	float y2 = 55; 
	float width2 = 10; 
	float height2 = 6;
/*---------------*/

/*----OPPO------*/
	float x = 470; 
	float y = 55; 
	float width = 10; 
	float height = 6;
/*--------------*/
/*----OPPO2------*/
	float x3 = 470; 
	float y3 = 680; 
	float width3 = 10; 
	float height3 = 6;
int jump8=0;
int jump7=0;
int count7=0;
bool wait9=true;
bool up2=false;
bool down2=false;
bool lefts2=false;
bool rights2=false;
bool wait6=true;
bool wait7=true;
/*--------------*/
/*ARENA-------*/
	int gap_turn = 60;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
/*-------------*/


/*------Menu variables----*/
	bool options=false;	
	bool cont=false;
	bool newgame=false;
	bool help=false;
	bool high=false;
/*-----------------------*/
bool checks=true;
bool x_dotsi[4][4];
bool x_dotsj[4][4];
bool x_dotsk[4][4];
bool x_dotsl[4][4];
int speed=1;

/*player1*/
bool wait=true;
bool up1=false;
bool down1=false;
bool left1=false;
bool right1=false;
bool wait2=true;

int jump=0;
int count3=0;
int count1=0;
/*-------*/

/*----OPPO----*/
bool up=false;
bool down=false;
bool wait4=true;
/*-----------*/
int score=0;
int levels=6;
int lives=3;
int Highest[10];
int highcounts=60;
string scores;
int jump3=0;
int jump2=0;
int count2=0;
bool pausefordeath=false;
bool collide1=false;
bool back=false;
bool won=false;

bool ncolor=false;
bool hcolor=false;
bool ehelp=false;
bool ecolor=false;
/*Move oppo*/
bool lefts=false;
bool rights=false;
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
int HighScoreSorting()
{
	int temp=0;

	int duplicate[10]={0,0,0,0,0,0,0,0,0,0};
	for(int x=0;x<10;x++)
		{
			for(int y=x+1;y<10;y++)
				{
					if(high_Scores[x]<high_Scores[y])
					{
						temp=high_Scores[x];
						high_Scores[x]=high_Scores[y];
						high_Scores[y]=temp;
					}
				}
		}
	for(int x=0;x<10;x++)
	{
		if(high_Scores[x]>score)
		{
			duplicate[x]=high_Scores[x];
		}
		else
		{
			duplicate[x]=score;
			for(int i=x+1;i<10;i++)
			{
				duplicate[i]=high_Scores[i-1];
			}
			break;
		}
	}
	for(int x=0;x<10;x++)
		{
			high_Scores[x]=duplicate[x];
		}
return 0;
}
int ScoreRead()
{
		//reading from a file
	int vent=0;
	int scoress=0;
	string reads;
	string scor;
	ifstream fin ("high score.txt"); //name of the file it is supposed to read
	if (fin.is_open())
	{
		while ( getline (fin,scor) ) //this loop will run depending on the number of lines in the file
		{
			scoress=stoi(scor);
			high_Scores[vent]=scoress;
			vent++;
		}
		fin.close();
	}
	return 0;
}
int ScoreWrite()
{ //scores array
	
	//writing to a file
	ofstream fout;
	fout.open ("high score.txt"); //this function takes the name of the file that you are writing to
	
	for (int i = 0; i < 10; i++){
		fout << high_Scores[i] << endl;
	}
		
	fout.close();
	return 0;
}
void levelInc()
{
		if(levels==4)
		{
			sleep(2);
			HighScoreSorting();
			ScoreWrite();
			score=0;
			startup=false;
			won=true;
			menus=true;
		}
	else
					{levels++;
					checks=true;
					jump=0;
					count3=0;
					count1=0;
					startup=false;
					jump3=0;
					jump2=0;
					count2=0;
					counts_score=0;
					won=false;
					x2 = 360; 
					y2 = 55; 
					width2 = 10; 
					height2 = 6;
					x = 450; 
					y = 55; 
					width = 10; 
					height = 6;
		}
glutPostRedisplay();
				
}
void collide()
{
	/*if(score==320)
	{
		
			x2=380;
			y2=55;
			x=470;
			y=55;
			count1=0;
			jump2=0;
			count2=0;
			jump=0;
			count3=0;
			count1=0;	
			startup=false;
			checks=true;
	}*/
	int u=x2;
	int v=x;
	int u2=y2;
	int v2=y;
	int w=x3;
	int w2=y3;
	if(levels==1){
	if((u>=v-5 && u<=v+5) && (u2>=v2-5 && u2<=v2+5))
		{
			if(lives>0)
			system("canberra-gtk-play -f gifts.wav");
			x2=380;
			y2=55;
			x=470;
			y=55;
			lives--;
			count1=0;
			jump2=0;
			count2=0;
			jump=0;
			checks=true;
			count3=0;
			count1=0;
			counts_score=0;
			wait=true;
			up1=false;
			down1=false;
			left1=false;
			right1=false;
			wait2=true;
			x3 = 470; 
			y3 = 45+80*8;
			width3 = 10; 
			height3 = 6;
			jump8=0;
			jump7=0;
			count7=0;
			wait9=true;
			up2=false;
			down2=false;
			lefts2=false;
			rights2=false;
			wait6=true;
			speed=1;
			wait7=true;
			lefts=false;
			rights=false;
			if(lives==0)
			{
				system("canberra-gtk-play -f j.wav");
				HighScoreSorting();
				ScoreWrite();
				score=0;
			}	
			startup=false;
			sleep(1);
			speed=1;
		}
	}
	else if(levels==2)
	{
		if((u>=v-5 && u<=v+5) && (u2>=v2-5 && u2<=v2+5))
		{
			if(lives>0)
			system("canberra-gtk-play -f gifts.wav");
			x2=380;
			y2=55;
			x=470;
			y=55;
			lives--;
			count1=0;
			jump2=0;
			count2=0;
			jump=0;
			checks=true;
			count3=0;
			count1=0;
			counts_score=0;
			wait=true;
			up1=false;
			down1=false;
			left1=false;
			right1=false;
			wait2=true;
			x3 = 470; 
			y3 = 45+80*8; 
			width3 = 10; 
			height3 = 6;
			jump8=0;
			jump7=0;
			count7=0;
			wait9=true;
			up2=false;
			down2=false;
			lefts2=false;
			rights2=false;
			wait6=true;
			wait7=true;
			lefts=false;
			rights=false;
			speed=1;
			if(lives==0)
			{
				system("canberra-gtk-play -f j.wav");
				HighScoreSorting();
				ScoreWrite();
				score=0;
			}	
			startup=false;
			sleep(1);
			speed=1;
		}
	}
	else if(levels==3)
	{
		if((u>=v-10 && u<=v+10) && (u2>=v2-10 && u2<=v2+10))
		{
			if(lives>0)
			system("canberra-gtk-play -f gifts.wav");
			x2=380;
			y2=55;
			x=470;
			y=55;
			lives--;
			count1=0;
			jump2=0;
			count2=0;
			jump=0;
			checks=true;
			count3=0;
			count1=0;
			counts_score=0;
			wait=true;
			up1=false;
			down1=false;
			left1=false;
			right1=false;
			wait2=true;
			x3 = 470; 
			y3 = 45+80*8;
			jump8=0;
			jump7=0;
			count7=0;
			wait9=true;
			up2=false;
			down2=false;
			lefts2=false;
			rights2=false;
			wait6=true;
			wait7=true;
			lefts=false;
			rights=false;
			speed=1;
			if(lives==0)
			{
				system("canberra-gtk-play -f j.wav");
				HighScoreSorting();
				ScoreWrite();
				score=0;
			}	
			startup=false;
			sleep(1);
			speed=1;
		}
	}
	else if(levels==4)
	{
		if(((u>=v-10 && u<=v+10) && (u2>=v2-10 && u2<=v2+10)) ||((u>=w-15 && u<=w+15) && (u2>=w2-15 && u2<=w2+15)))
		{
			if(lives>0)
			system("canberra-gtk-play -f gifts.wav");
			x2=380;
			y2=55;
			x=470;
			y=55;
			lives--;
			count1=0;
			jump2=0;
			count2=0;
			jump=0;
			checks=true;
			count3=0;
			count1=0;
			counts_score=0;
			wait=true;
			up1=false;
			down1=false;
			left1=false;
			right1=false;
			wait2=true;
			x3 = 470; 
			y3 = 45+80*8;
			jump8=0;
			jump7=0;
			count7=0;
			wait9=true;
			up2=false;
			down2=false;
			lefts2=false;
			rights2=false;
			wait6=true;
			wait7=true;
			lefts=false;
			rights=false;
			speed=1;
			if(lives==0)
			{
				system("canberra-gtk-play -f j.wav");
				HighScoreSorting();
				ScoreWrite();
				score=0;
			}	
			startup=false;
			sleep(1);
			speed=1;
		}
	}
	glutPostRedisplay();
	
}
void page()
{
				float* fcolor = colors[DARK_GRAY];
				DrawRectangle(0,0,845,845,fcolor);
				fcolor = colors[DARK_SALMON];
				DrawRectangle(40,0,10,840,fcolor);
}
void menuDesign()
{
				float* fcolor = colors[DARK_GRAY];
				DrawRectangle(0,0,845,845,fcolor);
				fcolor = colors[DARK_SALMON];
				DrawRectangle(70,100,10,140,fcolor);
				for(int x=0;x<50;x++)
				{
					DrawRectangle(60+x,110,10,10,fcolor);
				}
				for(int x=0;x<50;x++)
				{
					DrawRectangle(60+x,110+105,10,10,fcolor);
				}
				DrawRectangle(60+60,115,10,105,fcolor);
				fcolor = colors[DARK_RED];
				DrawRectangle(70-5,100+5,10,140,fcolor);
				for(int x=0;x<50;x++)
				{
					DrawRectangle(60+x-4,110+5,10,10,fcolor);
				}
				for(int x=0;x<50;x++)
				{
					DrawRectangle(60+x-4,110+105+5,10,10,fcolor);
				}
				DrawRectangle(60+60-4,115+5,10,105,fcolor);
				fcolor = colors[DARK_SALMON];
				for(int x=0;x<30;x++)
				{
					DrawRectangle(70+80+x+2,110,10,10,fcolor);
				}
				for(int x=0;x<30;x++)
				{
					DrawRectangle(60+75+x+2,110+35,10,10,fcolor);
				}
				for(int x=0;x<30;x++)
				{
					DrawRectangle(60+75+2,110+x,10,10,fcolor);
				}
				for(int x=0;x<30;x++)
				{
					DrawRectangle(60+80+30+10+2,110+x,10,10,fcolor);
				}
				fcolor = colors[DARK_RED];
				for(int x=0;x<30;x++)
				{
					DrawRectangle(70+80+x-2,110+5,10,10,fcolor);
				}
				for(int x=0;x<30;x++)
				{
					DrawRectangle(60+75+x-2,110+35+5,10,10,fcolor);
				}
				for(int x=0;x<30;x++)
				{
					DrawRectangle(60+75-2,110+x+5,10,10,fcolor);
				}
				for(int x=0;x<30;x++)
				{
					DrawRectangle(60+80+30-2+10,110+x+4,10,10,fcolor);
				}
				for(int x=0;x<30;x++)
				{
					fcolor = colors[DARK_SALMON];
					DrawRectangle(60+80+30-2+10+40+80,110+70+x+4,10,25,fcolor);
					DrawRectangle(60+80+30-2+10+40+40+80,60+x+4,10,150,fcolor);
					DrawRectangle(70+80+x-2+80,80,80,10,fcolor);
					DrawRectangle(70+80+x-2+80,80+20,80,10,fcolor);
					DrawRectangle(70+80+x-2+80,80+20,100,10,fcolor);
					DrawRectangle(70+80+x-2+150,80+20+130,30,10,fcolor);
					DrawRectangle(70+80+x-2+150,130+50,30,10,fcolor);
					DrawRectangle(60+80+30+60,91,10,8,fcolor);

					fcolor = colors[DARK_RED];
					DrawRectangle(60+80+30-2+10+40+80-4,110+70+x+4-2,10,25,fcolor);
					DrawRectangle(60+80+30-2+10+40+40+80-4-2,60+x+4,10,150,fcolor);
					DrawRectangle(70+80+x-2+80-4,80,80,10-2,fcolor);
					DrawRectangle(70+80+x-2+80-4,80+20-2,80,10,fcolor);
					DrawRectangle(70+80+x-2+80-4,80+20-2,100,10,fcolor);
					DrawRectangle(70+80+x-2+150-4,80+20+130-2,30,10,fcolor);
					DrawRectangle(70+80+x-2+150,130+50-4,30,10,fcolor);
					DrawRectangle(60+80+30+60-4,91-2,10,8,fcolor);
				}
				fcolor = colors[DARK_SALMON];
				DrawRectangle(70+100+40,10+130,50,10,fcolor);
				DrawRectangle(70+100+40,10+130,10,56,fcolor);
				DrawRectangle(70+100+40,30+130+40,50,10,fcolor);
				DrawRectangle(70+100+40+50,130+10,10,156,fcolor);
				fcolor = colors[DARK_RED];
				DrawRectangle(70+100+40-4,10+130-4,50,10,fcolor);
				DrawRectangle(70+100+40-4,10+130-4,10,56,fcolor);
				DrawRectangle(70+100+40-4,30+130+40-4,50,10,fcolor);
				DrawRectangle(70+100+40+50-4,130+10-4,10,156,fcolor);
				
				fcolor = colors[DARK_SALMON];
				DrawRectangle(70+100+40+50-4+130,130+10-4,10,80,fcolor);
				DrawRectangle(70+100+40+50-4+130,130+10-4,60,10,fcolor);
				DrawRectangle(70+100+40+50-4+130,130+10-4+80,60,10,fcolor);
				DrawRectangle(70+100+40+50-4+130,130+10-4+40,60,10,fcolor);
				DrawRectangle(70+100+40+50-4+130+60,130+10-4+40,10,50,fcolor);
				DrawRectangle(70+100+40+50-4+130+60,130+10-4,10,20,fcolor);
				fcolor = colors[DARK_RED];
				DrawRectangle(70+100+40+50-4+130-4,130+10-4-4,10,80,fcolor);
				DrawRectangle(70+100+40+50-4+130-4,130+10-4-4,60,10,fcolor);
				DrawRectangle(70+100+40+50-4+130-4,130+10-4+80-4,60,10,fcolor);
				DrawRectangle(70+100+40+50-4+130-4,130+10-4+40-4,60,10,fcolor);
				DrawRectangle(70+100+40+50-4+130+60-4,130+10-4+40-4,10,50,fcolor);
				DrawRectangle(70+100+40+50-4+130+60-4,130+10-4-4,10,20,fcolor);

				DrawRectangle(70+100+40+50-4+130+150,120,10,200,fcolor);
				DrawRectangle(70+100+40+50-4+130+130,220+70,110,10,fcolor);
				DrawRectangle(70+100+40+50-4+130+150,220+70-80,70,10,fcolor);
				DrawRectangle(70+100+40+50-4+130+130,220+70-80*2,110,10,fcolor);
				fcolor = colors[DARK_SALMON];
				
				DrawRectangle(70+100+40+50-4+130+150+130,120,10,100,fcolor);
				DrawRectangle(70+100+40+50-4+130+150+130+110,120,10,100,fcolor);
				for(int x=0;x<60;x++)
				{
					DrawRectangle(70+100+40+50-4+130+150+130+x,220-x,10,10,fcolor);
					fcolor = colors[DARK_RED];
					DrawRectangle(70+100+40+50-4+130+150+100+x/4,240+x-10,10,10,fcolor);
					fcolor = colors[DARK_SALMON];		
					DrawRectangle(70+100+40+50-4+130+150+130+x+50,220+x-60,10,10,fcolor);	
				}
				
				DrawRectangle(70+100+40+50-4+130+150+4,120-4,10,200,fcolor);
				DrawRectangle(70+100+40+50-4+130+130+4,220+70-4,110,10,fcolor);
				DrawRectangle(70+100+40+50-4+130+150+4,220+70-80-4,70,10,fcolor);
				DrawRectangle(70+100+40+50-4+130+130+4,220+70-80*2-4,110,10,fcolor);
				fcolor = colors[DARK_RED];
				DrawRectangle(70+100+40+50-4+130+150+130-4,120-4,10,100,fcolor);
				DrawRectangle(70+100+40+50-4+130+150+130+110-4,120-4,10,100,fcolor);
				for(int x=0;x<60;x++)
				{
					DrawRectangle(70+100+40+50-4+130+150+130+x-4,220-x-4,10,10,fcolor);
					fcolor = colors[DARK_SALMON];
					DrawRectangle(70+100+40+50-4+130+150+100+x/4,240+x-10,8,8,fcolor);
					fcolor = colors[DARK_RED];	
					DrawRectangle(70+100+40+50-4+130+150+130+x+50-4,220+x-60-4,10,10,fcolor);	
				}
				int loop=1000;
				static int xx=840;
				for(int x=0;x<105;x++)
				{
					if(x%2==0){
					float* fcolor = colors[DARK_RED];
					}
					else
					 float* fcolor = colors[BLACK]; 
					DrawRectangle(x*8,40,20,20,fcolor);
					float* fcolor = colors[WHITE];
					DrawRectangle(x*8+4,40,20,20,fcolor);
				}
				
				for(int x=0;x<105;x++)
				{
					if(x%2==0){
					float* fcolor = colors[DARK_RED];
					}
					else
					 float* fcolor = colors[BLACK];
					DrawRectangle(x*8,780,20,20,fcolor);
					float* fcolor = colors[WHITE];
					DrawRectangle(x*8+4,780,20,20,fcolor);
				}
				for(int x=0;x<105;x++)
				{
					float* fcolor = colors[DARK_RED];
					DrawRectangle(20,0+x*8+3.2,20,20,fcolor);
					fcolor = colors[PINK];
					DrawRectangle(24,0+x*8,20+4,20,fcolor);
				}
				
				for(int x=0;x<105;x++)
				{
					float* fcolor = colors[DARK_RED];
					DrawRectangle(22+780,0+x*8+3.2,20,20,fcolor);
					fcolor = colors[PINK];
					DrawRectangle(26+780,0+x*8,20+4,20,fcolor);
				}
				static int xvariable=20;
				static int yvariable=-100;
				if(yvariable==870)
				{
					yvariable=-100;
				}
				DrawSquare(xvariable,yvariable+20,28,colors[DARK_RED]); 
				DrawSquare(xvariable+785,800-yvariable,26,colors[DARK_RED]); 
				yvariable+=5;
				fcolor = colors[DARK_RED];
				DrawRectangle(270,400,300,300,fcolor);
				fcolor = colors[PINK];
				DrawRectangle(275,405,290,290,fcolor);
				if(menus==true && options==false){
				if(ncolor==true){
				DrawString(300+60,630,2,2,  " New Game ",colors[BLACK]);
				}
				else
				DrawString(300+60,630,2,2,  " New Game ",colors[DARK_RED]);
				
				if(hcolor==true)
				DrawString( 300+60, 630-60, "High Scores", colors[BLACK]);
				else
				DrawString( 300+60, 630-60, "High Scores", colors[DARK_RED]);
				if(ehelp==true)
				{
				DrawString( 300+60, 630-120,"   Help    ", colors[BLACK]);
				}
				else
				DrawString( 300+60, 630-120,"   Help    ", colors[DARK_RED]);
				if(ecolor==true)
				DrawString( 300+60, 630-180,"   Exit    ", colors[BLACK]);
				else				
				DrawString( 300+60, 630-180,"   Exit    ", colors[DARK_RED]);
				}
				if(menus==false && options==true)
				{
					if(ncolor==true){
					DrawString(300+60,630+30,2,2,  "  Continue ",colors[BLACK]);
					}
					else
					DrawString(300+60,630+30,2,2,  "  Continue ",colors[DARK_RED]);
				
					if(hcolor==true)
					DrawString( 300+60, 630-30, " New Game",colors[BLACK]);
					else
					DrawString( 300+60, 630-30, " New Game", colors[DARK_RED]);
					if(ehelp==true)
					{
					DrawString( 300+60, 630-120+30,"High Scores    ", colors[BLACK]);
					}
					else
					DrawString( 300+60, 630-120+30,"High Scores   ", colors[DARK_RED]);
					if(ecolor==true)
					DrawString( 300+60, 630-180+30,"    Help    ", colors[BLACK]);
					else				
					DrawString( 300+60, 630-180+30,"    Help    ", colors[DARK_RED]);
					if(excolor==false)
					DrawString( 300+60, 630-180+30-60,"    Exit    ", colors[BLACK]);
					else				
					DrawString( 300+60, 630-180-60+30,	  "    Exit    ", colors[DARK_RED]);
						
				}

		glutPostRedisplay();
}
void LevelInc()
{


}
void RestorePoint()
{
				menus=false;
				rnew=false;
				rhigh=false;
				rhelp=false;
				rexit=false;
				newgame=false;
				options=false;
				speed=1;
				levels=1;
				lives=3;
				checks=true;
				jump=0;
				count3=0;
				count1=0;
				jump3=0;
				jump2=0;
				count2=0;
				score=0;
				won=false;
				x2 = 360; 
				y2 = 55; 
				width2 = 10; 
				height2 = 6;
				x = 450; 
				y = 55; 
				width = 10; 
				height = 6;
				wait=true;
				up1=false;
				down1=false;
				left1=false;
				right1=false;
				wait2=true;
				string scores;
				lefts=false;
				rights=false;
					x2=380;
					y2=55;
					x=470;
					y=55;
					lives=3;
					count1=0;
					jump2=0;
					count2=0;
					jump=0;
					checks=true;
					count3=0;
					count1=0;
					counts_score=0;
					wait=true;
					up1=false;
					down1=false;
					left1=false;
					right1=false;
					wait2=true;
					x3 = 470; 
					y3 = 680;
					jump8=0;
					jump7=0;
					count7=0;
					wait9=true;
					up2=false;
					down2=false;
					lefts2=false;
					rights2=false;
					wait6=true;
					wait7=true;
					lefts=false;
					rights=false;
					speed=1;
	glutPostRedisplay();
}
void HelpMenu()
{
				float* fcolor = colors[BROWN]; 
				DrawString(360,780,2,2,"Help Centre",colors[BROWN]);
				DrawString(60,700-10,2,2,"This game was developed by Abuzar when he was doing his first semester in",colors[BLACK]);
				DrawString(60,700-40-10,2,2,"FAST NUCES Islamabad in December 2019 in Pakistan.Basically,This ",colors[BLACK]);
				DrawString(60,660-40-10,2,2,"game contains four levels.In first level the opponent is less active  and can take ",colors[BLACK]);
				DrawString(60,620-40-10,2,2,"just up and down turn and player car move in 4 directions just for dodge.But,",colors[BLACK]);
				DrawString(60,580-40-10,2,2,"In 2nd round is challenging and can can take any turn and can make Decisions.",colors[BLACK]);
				DrawString(60,580-40-10-40-10,2,2,"In 3rd round is challenging enough and speed is doubled.In 4th round there ",colors[BLACK]);	
				DrawString(60,580-40-10-40-10-40-10,2,2,"would be 2 opponent cars. So enjoy this game...",colors[BLACK]);

				DrawString(60,580-40-10-40-10-40-10-50,2,2,"Shortcut Keys",colors[DARK_RED]);	
				DrawString(60,580-40-10-40-10-40-10-50-50,2,2,  "1- New Game    : N",colors[BLACK]);
				DrawString(60,580-40-10-40-10-40-10-50-50*2,2,2,"2- Help              : H",colors[BLACK]);
				DrawString(60,580-40-10-40-10-40-10-50-50*3,2,2,"3- High Scores  : L",colors[BLACK]);
				DrawString(60,580-40-10-40-10-40-10-50-50*4,2,2,"4- Exit               : E",colors[BLACK]);
				DrawString(60+300,580-40-10-40-10-40-10-50-50*2-25,2,2,"5 - Back  :  Backspace",colors[DARK_RED]);		
				DrawString(60,580-40-10-40-10-40-10-50-50*5,2,2,"Control Keys",colors[DARK_RED]);
				DrawString(60,580-40-10-40-10-40-10-50-50*5-50,2,2,"1- Speed Double : Space Bar",colors[BLACK]);
				DrawString(60,580-40-10-40-10-40-10-50-50*5-50*2,2,2,"=> Shift Lanes :",colors[DARK_RED]);
				DrawString(60+180,580-40-10-40-10-40-10-50-50*5-50*2,2,2,"Up/Down && Left/Right key ",colors[BLACK]);
}
void ScoreToString()
{
				DrawString( 300, 750,"HIGH SCORES", colors[BROWN]);
				for(int x=0;x<10;x++)
					{
						HighScoreSorting();
						string highw=Num2Str(x+1);
						DrawString( 280, 700-x*50,highw, colors[BLACK]);
						DrawString( 285, 700-x*50,"    -   ", colors[BLACK]);					
						highw=Num2Str(high_Scores[x]);
						DrawString( 330, 700-x*50,highw, colors[BLACK]);
					}
}
void realMenu()
{
	if(menus==true)
		{
			if(rnew==false && rhelp==false && rhigh==false && rexit==false)
			{
				menuDesign();
			}

			if(rnew==true)
			{
				RestorePoint();			
			}
			else if(rhigh==true)
			{
				page();
				ScoreToString();
			}
			else if(rhelp==true)
			{
				page();
				HelpMenu();
			}
			if(rexit==true)
			{
				exit(1);
			}
	}
	glutPostRedisplay();
}
void oppoLevel_1()
{static int long glit=0;
if(up==false && down==false && rights==false && lefts==false){
		if(x>50+jump2 && x<760-jump2 && y<=61+jump2)
		{
			for(int x1=1;x1<=500 && x<760-jump2;x1++)
			{	
				x+=0.01;		
			}
		}
		else if(x>758-jump2 && y<675-jump2)
		{
		for(int x1=1;x1<=50 && y<675-jump2;x1++)
			{
				y+=0.1;
			}
		}
		else if(y<690-jump2 && x>51+jump2 && x<=761-jump2)
		{
			for(int x1=1;x1<=500 && x>51+jump2;x1++)
			{
					x-=0.01;
			}
		}
		else if(x>=50+jump2 && y>60+jump2 && y<690)
		{
			for(int x1=1;x1<=500 && y>61+jump2;x1++)
			{
				y-=0.01;
			}
		}
	}








static int count6=0;
if(up==false && down==false && rights==false && lefts==false && glit==0){		
	if((y2>70 && y2<800) && x>370 && x<460 && y2>y &&(y<260 || y>420)){
		up=true;}}
	if(up==true && down==false && rights==false && lefts==false)
	{
		if(y<310 && y>40)
			{
				if(wait4==true){
				y+=5;
				count6+=5;
				wait4=false;}
				if(count6==80)
				{
					up=false;
					glit=100;
					jump2+=80;
					count6=0;
				}
			}
			if(y<800 && y>410)
			{
				if(wait4==true){
				y+=5;
				count6+=5;
				wait4=false;}
				if(count6==80)
				{
					up=false;
					glit=100;
					jump2-=80;
					count6=0;
				}
			}
	}
if(up==false && down==false && rights==false && lefts==false && glit==0){		
	if(y2>0 && y2<750-80 && ((x2>80 && x2<750) ||(x2>500)) && x>360 && x<450 && y2<y && y<760 &&(y<320 || y>510)){
		down=true;}}
	if(down==true && up==false && rights==false && lefts==false)
	{
		if(y<350 && y>55)
			{
				if(wait4==true)
				{
				y-=5;
				count6+=5;
				wait4=false;
				}
				if(count6==80)
				{
					down=false;
					glit=100;
					jump2-=80;
					count6=0;
				}
			}
			if(y<750 && y>400)
			{
				if(wait4==true){
				y-=5;
				count6+=5;
				wait4=false;}
				if(count6==80)
				{
					down=false;
					glit=100;
					jump2+=80;
					count6=0;
				}
			}
	}
	if(glit!=0){
	glit--;}
	glutPostRedisplay();
}


void oppoLevel_2()
{
	static int long glit=0;
if(up==false && down==false && rights==false && lefts==false){
		if(x>50+jump2 && x<760-jump2 && y<=61+jump2)
		{
			for(int x1=1;x1<=500 && x<760-jump2;x1++)
			{	
				x+=0.01;		
			}
		}
		else if(x>758-jump2 && y<675-jump2)
		{
		for(int x1=1;x1<=50 && y<675-jump2;x1++)
			{
				y+=0.1;
			}
		}
		else if(y<690-jump2 && x>51+jump2 && x<=761-jump2)
		{
			for(int x1=1;x1<=500 && x>51+jump2;x1++)
			{
					x-=0.01;
			}
		}
		else if(x>=50+jump2 && y>60+jump2 && y<690)
		{
			for(int x1=1;x1<=500 && y>61+jump2;x1++)
			{
				y-=0.01;
			}
		}
	}


















static int count6=0;
if(up==false && down==false && rights==false && lefts==false && glit==0){		
	if((y2>70 && y2<800) && ((x2>80 && x2<750) || (x2<300)) && x>370 && x<460 && y2>y && y<670 &&(y<260 || y>410)){
		up=true;}}
	if(up==true && down==false && rights==false && lefts==false)
	{
		if(y<310 && y>40)
			{
				if(wait4==true){
				y+=5;
				count6+=5;
				wait4=false;}
				if(count6==80)
				{
					up=false;
					glit=50;
					jump2+=80;
					count6=0;
				}
			}
			if(y<770 && y>410)
			{
				if(wait4==true){
				y+=5;
				count6+=5;
				wait4=false;}
				if(count6==80)
				{
					up=false;
					glit=50;
					jump2-=80;
					count6=0;
				}
			}
	}
if(up==false && down==false && rights==false && lefts==false && glit==0){		
	if(y2>0 && y2<750-80 && ((x2>80 && x2<750) ||(x2>500)) && x>360 && x<450 && y2<y && y<760 &&(y<320 || y>510)){
		down=true;}}
	if(down==true && up==false && rights==false && lefts==false)
	{
		if(y<350 && y>55)
			{
				if(wait4==true)
				{
				y-=5;
				count6+=5;
				wait4=false;
				}
				if(count6==80)
				{
					down=false;
					glit=50;
					jump2-=80;
					count6=0;
				}
			}
			if(y<750 && y>400)
			{
				if(wait4==true){
				y-=5;
				count6+=5;
				wait4=false;}
				if(count6==80)
				{
					down=false;
					glit=50;
					jump2+=80;
					count6=0;
				}
			}
	}
static int count4=0;
if(up==false && glit==0 && down==false && rights==false && lefts==false){		
	if(x2<x && (y>330 && y<400) && !(x>280 && x<510) && x>70){
		lefts=true;}}
	if(up==false && down==false && rights==false && lefts==true)
	{
		if(x<350)
			{
				if(wait4==true)
				{
				x-=5;
				count4+=5;
				wait4=false;
				}
				if(count4==80)
				{
					lefts=false;
					glit=50;
					jump2-=80;
					count4=0;
				}
			}	
		if(x>450)
			{
				if(wait4==true)
				{
				x-=5;
				count4+=5;
				wait4=false;
				}
				if(count4==80)
				{
					lefts=false;
					glit=50;
					jump2+=80;
					count4=0;
				}
			}
}
	if(up==false && glit==0 && down==false && rights==false && lefts==false){		
	if(x2>x && (y>330 && y<400) && !(x>260 && x<470) && x<750){
	rights=true;}}
	if(up==false && down==false && rights==true && lefts==false)
	{
		if(x>0 && x<350)
			{
				if(wait4==true)
				{
				x+=5;
				count4+=5;
				wait4=false;
				}
				if(count4==80)
				{
					rights=false;
					glit=50;
					jump2+=80;
					count4=0;
				}
			}	
		if(x>400 && x<800)
			{
				if(wait4==true)
				{
				x+=5;
				count4+=5;
				wait4=false;
				}
				if(count4==80)
				{
					rights=false;
					glit=50;
					jump2-=80;
					count4=0;
				}
			}	
	}	
	if(glit!=0){
	glit--;}
}
void OppoLevel3()
{
	static int glit=0;
	if(up==false && down==false && rights==false && lefts==false){
		if(x>50+jump2 && x<760-jump2 && y<=61+jump2)
		{
			for(int x1=1;x1<=700 && x<760-jump2;x1++)
			{	
				x+=0.01;		
			}
		}
		else if(x>758-jump2 && y<675-jump2)
		{
		for(int x1=1*2;x1<=700 && y<675-jump2;x1++)
			{
				y+=0.01;
			}
		}
		else if(y<690-jump2 && x>51+jump2 && x<=761-jump2)
		{
			for(int x1=1*2;x1<=700 && x>51+jump2;x1++)
			{
					x-=0.01;
			}
		}
		else if(x>=50+jump2 && y>60+jump2 && y<690)
		{
			for(int x1=1*2;x1<=700 && y>61+jump2;x1++)
			{
				y-=0.01;
			}
		}
	}













static int count6=0;
if(up==false && down==false && rights==false && lefts==false && glit==0){		
	if((y2>70 && y2<800) && ((x2>80 && x2<750) || (x2<300)) && x>370 && x<460 && y2>y && y<670 &&((y>70 && y<230) || (y>410 && y<690))){
		up=true;}}
	if(up==true && down==false && rights==false && lefts==false)
	{
		if(y<310 && y>40)
			{
				if(wait4==true){
				y+=5;
				count6+=5;
				wait4=false;}
				if(count6==80)
				{
					up=false;
					glit=50;
					jump2+=80;
					count6=0;
				}
			}
			if(y<770 && y>410)
			{
				if(wait4==true){
				y+=5;
				count6+=5;
				wait4=false;}
				if(count6==80)
				{
					up=false;
					glit=50;
					jump2-=80;
					count6=0;
				}
			}
	}
if(up==false && down==false && rights==false && lefts==false && glit==0){		
	if(y2>0 && y2<750-80 && ((x2>80 && x2<750) ||(x2>500)) && x>360 && x<450 && y2<y && y<760 &&(y<320 || y>510)){
		down=true;}}
	if(down==true && up==false && rights==false && lefts==false)
	{
		if(y<350 && y>55)
			{
				if(wait4==true)
				{
				y-=5;
				count6+=5;
				wait4=false;
				}
				if(count6==80)
				{
					down=false;
					glit=50;
					jump2-=80;
					count6=0;
				}
			}
			if(y<750 && y>400)
			{
				if(wait4==true){
				y-=5;
				count6+=5;
				wait4=false;}
				if(count6==80)
				{
					down=false;
					glit=50;
					jump2+=80;
					count6=0;
				}
			}
	}
static int count4=0;
if(up==false && glit==0 && down==false && rights==false && lefts==false){		
	/*if(x2<x && (y>330 && y<410) && !(x>340 && x<500) && (x<360 && x>500)  && x>50+jump2 && x<760-jump2){*/
	if(x2<x && (y>330 && y<400) && !(x>280 && x<520) && x>70){
		lefts=true;}}
	if(up==false && down==false && rights==false && lefts==true)
	{
		if(x<350)
			{
				if(wait4==true)
				{
				x-=5;
				count4+=5;
				wait4=false;
				}
				if(count4==80)
				{
					lefts=false;
					glit=50;
					jump2-=80;
					count4=0;
				}
			}	
		if(x>450)
			{
				if(wait4==true)
				{
				x-=5;
				count4+=5;
				wait4=false;
				}
				if(count4==80)
				{
					lefts=false;
					glit=50;
					jump2+=80;
					count4=0;
				}
			}
}
	if(up==false && glit==0 && down==false && rights==false && lefts==false){
	/*		
	if(x2>x && (y>330 && y<410) && !(x>280 && x<470) && ((x2>0 && x2<360) || (x2>400))  && x>50+jump2 && x<760-jump2){*/
	if(x2>x && (y>330 && y<400) && !(x>260 && x<480) && x<750){
		rights=true;}}
	if(up==false && down==false && rights==true && lefts==false)
	{
		if(x>0 && x<350)
			{
				if(wait4==true)
				{
				x+=5;
				count4+=5;
				wait4=false;
				}
				if(count4==80)
				{
					rights=false;
					glit=50;
					jump2+=80;
					count4=0;
				}
			}	
		if(x>400 && x<800)
			{
				if(wait4==true)
				{
				x+=5;
				count4+=5;
				wait4=false;
				}
				if(count4==80)
				{
					rights=false;
					glit=50;
					jump2-=80;
					count4=0;
				}
			}	
	}	
	if(glit!=0){
	glit--;}
}

/*Function Contains the programs and algorithms to run the second opponent car on game in the 4th level*/

void oppo2Level_2()
{
	static int long glit=0;
if(up2==false && down2==false && rights2==false && lefts2==false){
		if(x3>50+jump8 && x3<760-jump8 && y3<=61+jump8)
		{
			for(int x31=1;x31<=500 && x3<760-jump8;x31++)
			{	
				x3+=0.01;		
			}
		}
		else if(x3>758-jump8 && y3<675-jump8)
		{
		for(int x31=1;x31<=50 && y3<675-jump8;x31++)
			{
				y3+=0.1;
			}
		}
		else if(y3<690-jump8 && x3>51+jump8 && x3<=761-jump8)
		{
			for(int x31=1;x31<=500 && x3>51+jump8;x31++)
			{
					x3-=0.01;
			}
		}
		else if(x3>=50+jump8 && y3>60+jump8 && y3<690)
		{
			for(int x31=1;x31<=500 && y3>61+jump8;x31++)
			{
				y3-=0.01;
			}
		}
	}








if(up2==false && down2==false && rights2==false && lefts2==false && glit==0){		
	if((y2>70 && y2<800) && ((x2>80 && x2<750) || (x2<300)) && x3>370 && x3<460 && y2>y3 && y3<670 &&(y3<260 || y3>410)){
		up2=true;}}
	if(up2==true && down2==false && rights2==false && lefts2==false)
	{
		if(y3<310 && y3>40)
			{
				if(wait6==true){
				y3+=5;
				count7+=5;
				wait6=false;}
				if(count7==80)
				{
					up2=false;
					glit=50;
					jump8+=80;
					count7=0;
				}
			}
			if(y3<770 && y3>410)
			{
				if(wait6==true){
				y3+=5;
				count7+=5;
				wait6=false;}
				if(count7==80)
				{
					up2=false;
					glit=50;
					jump8-=80;
					count7=0;
				}
			}
	}
if(up2==false && down2==false && rights2==false && lefts2==false && glit==0){		
	if(y2>0 && y2<750-80 && ((x2>0 && x2<750) ||(x2>500)) && x3>360 && x3<450 && y2<y3 && y3<760 &&(y3<320 || y3>510)){
		down2=true;}}
	if(down2==true && up2==false && rights2==false && lefts2==false)
	{
		if(y3<350 && y3>55)
			{
				if(wait6==true)
				{
				y3-=5;
				count7+=5;
				wait6=false;
				}
				if(count7==80)
				{
					down2=false;
					glit=50;
					jump8-=80;
					count7=0;
				}
			}
			if(y3<750 && y3>400)
			{
				if(wait6==true){
				y3-=5;
				count7+=5;
				wait6=false;}
				if(count7==80)
				{
					down2=false;
					glit=50;
					jump8+=80;
					count7=0;
				}
			}
	}
static int count7=0;
if(up2==false && glit==0 && down2==false && rights2==false && lefts2==false){		
	if(x2<x3 && (y3>330 && y3<400) && !(x3>280 && x3<520) && x3>50){
/*	if(x2<x3 && (y3>330 && y3<410) && !(x3>340 && x3<500) && (x3<340 && x3>500)  && x2>50+80 && x3<780-80){*/
		lefts2=true;}}
	if(up2==false && down2==false && rights2==false && lefts2==true)
	{
		if(x3<350)
			{
				if(wait6==true)
				{
				x3-=5;
				count7+=5;
				wait6=false;
				}
				if(count7==80)
				{
					lefts2=false;
					glit=50;
					jump8-=80;
					count7=0;
				}
			}	
		if(x3>450)
			{
				if(wait6==true)
				{
				x3-=5;
				count7+=5;
				wait6=false;
				}
				if(count7==80)
				{
					lefts2=false;
					glit=50;
					jump8+=80;
					count7=0;
				}
			}
}
	if(up2==false && glit==0 && down2==false && rights2==false && lefts2==false){	
	if(x2>x3 && (y3>330 && y3<400) && !(x3>260 && x3<480) && x3<750)	{
	/*if(x2>x3 && (y3>330 && y3<400) && !(x3>280 && x3<470) && ((x2>0 && x2<360) || (x2>400))  && x3>50 && x3<780){*/
		rights2=true;}}
	if(up2==false && down2==false && rights2==true && lefts2==false)
	{
		if(x3>0 && x3<350)
			{
				if(wait6==true)
				{
				x3+=5;
				count7+=5;
				wait6=false;
				}
				if(count7==80)
				{
					rights2=false;
					glit=50;
					jump8+=80;
					count7=0;
				}
			}	
		if(x3>400 && x3<800)
			{
				if(wait6==true)
				{
				x3+=5;
				count7+=5;
				wait6=false;
				}
				if(count7==80)
				{
					rights2=false;
					glit=50;
					jump8-=80;
					count7=0;
				}
			}	
	}	
	if(glit!=0){
	glit--;}
	glutPostRedisplay();
}

void movemy()
{
	if(up1==false && down1==false && right1==false && left1==false && options==false && startup==true){
	if(x2>51+jump && x2<761-jump && y2<61+jump)
	{
		for(int x=1*speed;x<=50*speed && x2>51+jump;x++)
		{	
			x2-=0.1;	
		}
	}
	else if(x2<51+jump && y2<675-jump)
	{
		for(int x=1*speed;x<=50*speed && y2<675-jump;x++)
			{
				y2+=0.1;
			}
	}
	else if(y2<676-jump && x2>50+jump && x2<759-jump)
	{
		for(int x=1*speed;x<=50*speed && x2<759-jump;x++)
			{
				x2+=0.1;
			}
	}
	else if(x2>758-jump && y2>61+jump)
	{
			for(int x=1*speed;x<=50*speed && y2>61+jump;x++)
			{
				y2-=0.1;
			}
	}
	}
	static int count=0;
	if(up1==true)
	{
		if(x2>370 && x2<460 && ((y2<300&&y2>40) || (y2>420 && y2<680)))
		{
			if(y2<310 && y2>40)
			{
				if(wait==true){
				y2+=5;
				count+=5;
				wait=false;}
				if(count==80)
				{
					up1=false;
					jump+=80;
					count=0;
				}
			}
			if(y2<680 && y2>420)
			{
				if(wait==true){
				y2+=5;
				count+=5;
				wait=false;}
				if(count==80)
				{
					up1=false;
					jump-=80;
					count=0;
				}
			}
	}
		else
		up1=false;
	}
	else if(down1==true && right1==false)
		{
			if(x2>370 && x2<460 && ((y2>40 && y2<400) ||(y2>400 && y2<690)))
			{
				if(y2>40 && y2<400)
				{
					if(count1==80)
					{
						down1=false;
						jump-=80;
						count1=0;
					}
					else if(wait2==true)
					{
						y2-=5;
						count1+=5;
						wait2=false;
					}
				}
				else if(y2>400 && y2<690)
				{
					if(count1==80)
					{
						down1=false;
						jump+=80;
						count1=0;
					}
					else if(wait2==true)
					{
						y2-=5;
						count1+=5;
						wait2=false;
					}
				}
			}
			else 
			down1=false;
		}
	else if(right1==true)
		{
			if(((x2>40 && x2<280) || (x2>450+60 && x2<800)) &&(y2>310 && y2<450))
			{
				if(x2>40 && x2<=300)
				{
					if(count3==80)
					{
						right1=false;
						count3=0;
						wait2=false;
					}
					if(wait2==true)
					{
						x2+=5;
						jump+=5;
						count3+=5;
						wait2=false;
					}
				}
				else if(x2>470 && x2<=770)
				{
					if(count3==80)
					{
						right1=false;
						count3=0;
						wait2=false;
					}
					if(wait2==true)
					{
						x2+=5;
						jump-=5;
						count3+=5;
						wait2=false;
					}
				}
				else 
				right1=false;
			}
			else 
			right1=false;
		}
	else if(left1==true)
		{
			if(((x2>40 && x2<300+80) || (x2>450 && x2<800)) &&(y2>310 && y2<450))
			{
				if(x2>40 && x2<=380)
				{
					if(count3==80)
					{
						left1=false;
						count3=0;
						wait2=false;
					}
					if(wait2==true)
					{
						x2-=5;
						jump-=5;
						count3+=5;
						wait2=false;
					}
				}
				else if(x2>450 && x2<=800)
				{
					if(count3==80)
					{
						left1=false;
						count3=0;
						wait2=false;
					}
					if(wait2==true)
					{
						x2-=5;
						jump+=5;
						count3+=5;
						wait2=false;
					}
				}
				else 
				right1=false;
			}
			else 
			right1=false;
		}
	glutPostRedisplay();
}
void menu()
{
	float* mcolor = colors[WHITE]; 
	if(options==true)
		{
			if(cont==false && newgame==false && help==false)
			{
				menuDesign();
			}
			if(cont==true)
			{
				if(help==false && high==false)
				{
					options=false;
				}
				cont=false;		
			}
			else if(high==true)
			{
				page();
				ScoreToString();
			}
			else if(newgame==true)
			{
				RestorePoint();
				
			}
			else if(help==true)
			{
				page();
				HelpMenu();
			}
		if(rexit==true)
			{
				exit(1);
			}
		}
	glutPostRedisplay();
}
void Centre()
{
	float* ccolor = colors[GRAY]; 	
	if(levels==1){
		ccolor = colors[GRAY];
			}
	else if(levels==2){
		ccolor = colors[MAGENTA];
			}
	else if(levels==3){
		ccolor = colors[DARK_RED];
			}
	else if(levels==4){
		ccolor = colors[ORANGE];
			}
	DrawLine( 370,  350, 470, 350,4,ccolor);
	DrawLine( 370,  395+15, 470, 395+15,4,ccolor);
	DrawRectangle(455,380+10,20,20,ccolor);
	DrawRectangle(367,350,20,20,ccolor);
	DrawRectangle(367,380+10,20,20,ccolor);
	DrawRectangle(455,350,20,20,ccolor);
	glutPostRedisplay();
}
void LINES()
{
	float *scolor;
	if(levels==1){
		scolor = colors[GRAY];
			}
	else if(levels==2){
		scolor = colors[MAGENTA];
			}
	else if(levels==3){
		scolor = colors[DARK_RED];
			}
	else if(levels==4){
		scolor = colors[ORANGE];
			}
	/*3rd quadrant*/
	DrawLine( 20,  40, 360, 40,5,scolor);
	DrawLine( 100,  40+80, 360,40+80,5, scolor);
	DrawLine( 180,  40+80+80, 360, 40+80+80,5, scolor);
	DrawLine( 260,  40+80+80+80, 360, 40+80+80+80,5, scolor);
	
	/*4th quadrant*/
	DrawLine( 820,  40,480, 40,5,scolor);
	DrawLine( 740,  40+80, 480,40+80,5, scolor);
	DrawLine( 660,  40+80+80,480, 40+80+80,5, scolor);
	DrawLine( 580,  40+80+80+80,480, 40+80+80+80, 5, scolor);
	
	/*1st quadrant*/
	DrawLine( 20,700+30, 360,700+30,5,scolor);
	DrawLine( 100,620+30, 360,620+30,5, scolor);
	DrawLine( 180,540+30, 360,540+30,5, scolor);
	DrawLine( 260,460+30, 360,460+30, 5, scolor);
	
	/*2nd quadrant*/
	DrawLine( 820,730,480,730,5,scolor);
	DrawLine( 740,650,480,650,5, scolor);
	DrawLine( 660,570,480,570,5, scolor);
	DrawLine( 580,490,480,490, 5, scolor);
	glutPostRedisplay();

}

void WALLS()
{
	float *wcolor;
	if(levels==1){
		wcolor = colors[GRAY];
			}
	else if(levels==2){
		wcolor = colors[MAGENTA];
			}
	else if(levels==3){
		wcolor = colors[DARK_RED];
			}
	else if(levels==4){
		wcolor = colors[ORANGE];
			}
	/*3RD*/
	DrawRectangle(15,40,20,280,wcolor);
	DrawRectangle(15+80,40+80,20,200,wcolor);
	DrawRectangle(15+80+80,40+80+80,20,120,wcolor);
	DrawRectangle(15+80+80+80,40+80+80+80,20,40,wcolor);

	/*4TH*/
	DrawRectangle(808,40,20,280,wcolor);
	DrawRectangle(808-80,40+80,20,200,wcolor);
	DrawRectangle(808-80-80,40+80+80,20,120,wcolor);
	DrawRectangle(808-80-80-80,40+80+80+80,20,40,wcolor);

	/*1st*/
	DrawRectangle(15,450,20,280,wcolor);
	DrawRectangle(15+80,450,20,200,wcolor);
	DrawRectangle(15+80+80,450,20,120,wcolor);
	DrawRectangle(15+80+80+80,450,20,40,wcolor);
	
	/*4TH*/
	DrawRectangle(808,450,20,280,wcolor);
	DrawRectangle(808-80,450,20,200,wcolor);
	DrawRectangle(808-80-80,450,20,120,wcolor);
	DrawRectangle(808-80-80-80,450,20,40,wcolor);

	glutPostRedisplay();
}

void DOTS()
{

	float *Dcolor = colors[WHITE];
	if(levels==1){	
	Dcolor = colors[WHITE];}
	else if(levels==2){
	Dcolor = colors[WHITE];
	}
	else if(levels==3){
	Dcolor = colors[GRAY];
	}
	else if(levels==4){
	Dcolor = colors[RED];
	}
	//2nd lane
	for(int j=0;j<4;j++)
	{
		for(int i=0;i<4;i++)
		{
			if(x_dotsi[j][i]==true)
			{
				DrawLine( 320-i*80,80+j*80,300-i*80,80+j*80,7,Dcolor);
				if((x2<=320-i*80+10 && x2>=300-i*80-10) && (y2>=55+j*80 && y2<=80+j*80))
				{
					x_dotsi[j][i]=false;
					counts_score++;
					score+=5;	
				}
			}
		}	
	}
	for(int j=0;j<4;j++)
	{
		for(int i=0;i<4;i++){
		if(x_dotsj[j][i]==true)
		{
		DrawLine( 780-i*80,80+j*80,760-i*80,80+j*80,7,Dcolor);
		if((x2<=780-i*80+10 && x2>=760-i*80-10) && (y2>=55+j*80 && y2<=80+j*80))
			{
					x_dotsj[j][i]=false;
					counts_score++;
					score+=5;
			}
		}
					}	
	}

	for(int j=0;j<4;j++)
	{
		for(int i=0;i<4;i++)
		{
			if(x_dotsk[j][i]==true)
			{
				DrawLine( 780-i*80,440+j*80,760-i*80,440+j*80,7,Dcolor);
				if((x2<=780-i*80+10 && x2>=760-i*80-10) && (y2>=440+80*j-5 && y2<=440+80*j+5))//(y2>=50+j*80 && y2<=70+j*80))
				{
					x_dotsk[j][i]=false;
					counts_score++;
					score+=5;
				}		
			}
		}	
	}
	for(int j=0;j<4;j++)
	{
		for(int i=0;i<4;i++)
		{
		if(x_dotsl[j][i]==true)
			{
			DrawLine( 320-i*80,440+j*80,300-i*80,440+j*80,7,Dcolor);
			if((x2<=320-i*80+10 && x2>=300-i*80-10) && (y2>=440+80*j-5 && y2<=440+80*j+5))//(y2>=50+j*80 && y2<=70+j*80))
					{	
						x_dotsl[j][i]=false;
						counts_score++;
						score+=5;
					}
						
			}
		}	
	}
	if(counts_score==64)
	{
		levelInc();
	}





	glutPostRedisplay();
}
void OppoBody()
{
	float* color = colors[DARK_SALMON];
	if(levels==1) 
	color = colors[BLACK];
	if(levels==2) 
	color = colors[PINK];
	if(levels==3) 
	color = colors[ORANGE];
	if(levels==4) 
	color = colors[GRAY];
	float radius = 5.0;
	DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
	color = colors[BLUE]; 
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect
}

void OppoBody2()
{
	float* color3 = colors[OLIVE]; 
	float radius3 = 5.0;
	DrawRoundRect(x3,y3,width3,height3,color3,radius3); // bottom left tyre
	DrawRoundRect(x3+width3*3,y3,width3,height,color3,radius3); // bottom right tyre
	DrawRoundRect(x3+width3*3,y3+height3*4,width,height,color3,radius3); // top right tyre
	DrawRoundRect(x3,y3+height3*4,width3,height,color3,radius3); // top left tyre
	color3 = colors[BLACK]; 
	DrawRoundRect(x3, y3+height3*2, width3, height3, color3, radius3/2); // body left rect
	DrawRoundRect(x3+width3, y3+height3, width3*2, height3*3, color3, radius3/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color3, radius3/2); // body right rect
}



void playerBody()
{
	float* color2 = colors[SKY_BLUE]; 
	float radius2 = 5.0;
	DrawRoundRect(x2,y2,width2,height2,color2,radius2); // bottom left tyre
	DrawRoundRect(x2+width2*3,y2,width2,height2,color2,radius2); // bottom right tyre
	DrawRoundRect(x2+width2*3,y2+height2*4,width2,height2,color2,radius2); // top right tyre
	DrawRoundRect(x2,y2+height2*4,width2,height2,color2,radius2); // top left tyre
	color2 = colors[DARK_SALMON]; 
	DrawRoundRect(x2, y2+height2*2, width2, height2, color2, radius2/2); // body left rect
	DrawRoundRect(x2+width2, y2+height2, width2*2, height*3, color2, radius2/2); // body center rect
	DrawRoundRect(x2+width2*3, y2+height2*2, width2, height, color2, radius2/2); // body right rect
	glutPostRedisplay();	
}

















void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(3, width, 3, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on


void Level1BackGround()
{
		glClearColor(0.48/*Red Component*/, 0.255,	//148.0/255/*Green Component*/,
					0.1/*Blue Component*/, 0.2 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
			glClear (GL_COLOR_BUFFER_BIT);
}
void Level2Background()
{
		glClearColor(0.21, 0.1,0.3, 0.4);
			glClear (GL_COLOR_BUFFER_BIT);
}
void Level3Background()
{
		glClearColor(0.11, 0.2,0.4, 0.6);
			glClear (GL_COLOR_BUFFER_BIT);
}
void Level4Background()
{
		glClearColor(0.11, 0.1,0.1, 0.1);
			glClear (GL_COLOR_BUFFER_BIT);
}

/*
 * Main Canvas drawing function.
 * */
//Board *b;
void GameDisplay()/**/{
		if(levels==1){
			Level1BackGround();
				}
		else if(levels==2){
				Level2Background();
			}
		else if(levels==3){
				Level3Background();
			}
		else if(levels==4){
				Level4Background();
			}
	realMenu();
	menu();
	if(menus==false){
	if(options==false){
	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	if(options==false){	
	if(checks==true)
	{


		for(int j=0;j<4;j++)
			{
				for(int i=0;i<4;i++)
				{
					x_dotsi[j][i]=true;
					x_dotsj[j][i]=true;
					x_dotsk[j][i]=true;
					x_dotsl[j][i]=true;
				}
			}
		checks=false;
	}
	if(speed==1)
	{
		speedcounts=300;
	}
	else if(speed==2 && speedcounts==0)
	{speed=1;
	speedcounts=600;	
	}
	if(!(speedcounts<0))	
	speedcounts--;
	static int wonCounts=0;
	wonCounts=2000;
	if(won==true){
	DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	if(wonCounts==0)
	{
		won=false;
		HighScoreSorting();
		ScoreWrite();
		menus=true;
	}		
	}
	if(lives==0)
	{
		score=0;
	}
	
	if(lives==3)
		{
			float *lcolor = colors[GOLD];
			DrawLine(280,740,340,740,7,lcolor);
			DrawLine(300,770,340,770,7,lcolor);
			DrawLine(280,800,340,800,7,lcolor);
			DrawRectangle(321,740,20,60,lcolor);
		}
	else if(lives==0)
		{
			float *hcolor = colors[SKY_BLUE];
			DrawRectangle(280,740,20,60,hcolor);
			DrawLine(280,740,340,740,7,hcolor);
			DrawLine(280,800,340,800,7,hcolor);
			DrawRectangle(321,740,20,60,hcolor);
		}
	else if(lives==2)
		{
			float *ocolor = colors[SKY_BLUE];
			DrawLine(280,740,340,740,7,ocolor);
			DrawLine(280,770,340,770,7,ocolor);
			DrawLine(280,800,340,800,7,ocolor);
			DrawRectangle(280,740,20,30,ocolor);
			DrawRectangle(321,770,20,30,ocolor);
		}
	else if(lives==1)
		{
			
			float *icolor = colors[DARK_SALMON];
			DrawRectangle(300,740,20,60,icolor);
			DrawLine(280,740,335,740,7,icolor);
			DrawLine(280,780,300,780,0,icolor);
		}
	scores=Num2Str(score);
	DrawString( 480, 800,"Score : ", colors[MISTY_ROSE]);
	DrawString( 550, 800,scores, colors[MISTY_ROSE]);
	DrawString( 480, 770,"Level : ", colors[MISTY_ROSE]);
	string levelss=Num2Str(levels);
	DrawString( 550, 770,levelss,colors[MISTY_ROSE]);
	DOTS();
	if(levels==4)
	OppoBody2();
	OppoBody();
	playerBody();
	if(startup==true){
	if(levels==1){
	oppoLevel_1();
	movemy();
	}
	if(levels==2){
	movemy();
	oppoLevel_2();
	}
	else if(levels==3)
	{
		OppoLevel3();
		movemy();
	}
	else if(levels==4)
	{
		movemy();
		oppo2Level_2();
		oppoLevel_2();
	}
}
	
	collide();
	LINES();
	 WALLS();
	Centre();
	if(startup==false){
	DrawString( 30, 750, "Press S to Start", colors[MISTY_ROSE]);
	if(lives==0 && startup!=true)
			{
				DrawString(360,600,2,2,"Game Over",colors[MISTY_ROSE]);
				menus=true;
			}	
	}
	}
	}
	}
	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
}












/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
static int timerss=0;	
if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
	// what to do when left key is pressed...
	if(left1==false && up1==false && down1==false && right1==false && startup==true){
		if(((x2>40+60 && x2<300+60)||(x2>450+80 && x2<770)) && (y2>320 && y2<410)){
			left1=true;
		}	}
	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

		if(left1==false && up1==false && down1==false && right1==false && startup==true){
		if(((x2>40 && x2<280)||(x2>450+60+10 && x2<800)) && (y2>330 && y2<410)){
			right1=true;
		}	}



	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
	if(left1==false && up1==false && down1==false && right1==false && startup==true){	
	if(((y2>430 && y2<650) || (y2>40 && y2<270)) && (x2>370 && x2<450)){	
	up1=true;}
	}}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
	if(left1==false && up1==false && down1==false && right1==false && startup==true){	
	if(((y2>430+80 && y2<650+80) || (y2>120 && y2<340)) && (x2>370 && x2<450)){	
	down1=true;}
	}}	
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		system("canberra-gtk-play -f beep2.wav");
		sleep(1);
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B')
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	if((key=='N' || key=='n') && (menus==true))
		{
			rnew=true;
			system("canberra-gtk-play -f beep2.wav");
							sleep(1);
		}
	else if(menus==true && (key=='H' || key=='h'))
		{
			rhelp=true;
			system("canberra-gtk-play -f beep2.wav");
							sleep(1);
		}
	else if(menus==true && rhelp==true && key==8)
		{
			rhelp=false;
			system("canberra-gtk-play -f beep2.wav");
							sleep(1);	
		}
	else if(menus==true && (key=='L' || key=='l'))
		{
			rhigh=true;
			system("canberra-gtk-play -f beep2.wav");
							sleep(1);
		}
	else if(menus==true && rhigh==true && key==8)
		{
			rhigh=false;
			system("canberra-gtk-play -f beep2.wav");
							sleep(1);
		}
	else if(menus==false)
		{
			if(key=='P' || key=='p')
				{
					options=true;
					system("canberra-gtk-play -f beep2.wav");
							sleep(1);
					
				}
				else if(options==true && menus==false)
					{
					if((key=='H' || key=='h') && high==false && newgame==false && cont==false)
						{
							help=true;
							system("canberra-gtk-play -f beep2.wav");
							sleep(1);
						}
					else if((key=='L' || key=='l') && help==false && newgame==false && cont==false)
						{
							high=true;
							system("canberra-gtk-play -f beep2.wav");
							sleep(1);
			
						}
					else if((key=='C' || key=='c') && help==false && newgame==false && high==false)
						{
							options=false;
							system("canberra-gtk-play -f beep2.wav");
							sleep(1);
						}
					else if((key=='N' || key=='n') && help==false && high==false && cont==false)
						{
							
							newgame=true;
							system("canberra-gtk-play -f beep2.wav");
							sleep(1);
						}
					else if(key==8 && options==true && high==true && newgame==false && cont==false && help==false)
						{
							high=false;
							system("canberra-gtk-play -f beep2.wav");
							sleep(1);
						}
					else if(key==8 && options==true && help==true && newgame==false && cont==false && high==false)
						{
							help=false;
							system("canberra-gtk-play -f beep2.wav");
							sleep(1);
						}
				}
		}


		
	if(key==' ')
		{
			speed=2;
		}
	if((key=='S' || key=='s') && menus==false && options==false)
	{
		startup=true;
		if(lives==0)
		{
			lives=3;
			checks=true;
		}
	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {
	// implement your functionality here
	// once again we tell the library to call our Timer function after next 1000/FPS	
		glutTimerFunc(1.0, Timer, 0);	
		wait2=true;
		wait4=true;
		wait=true;
		wait6=true;
		wait7=true;
}
/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	if(menus==true){
	if(x>350 && x<600 && y<271 && y>221)
		{
			rhelp=false;
			rhigh=false;
			rexit=false;
			rnew=true;
		}
	else if(x>325 && x<506 && y<271+70 && y>221+70)
		{
			rhelp=false;
			rhigh=true;
			rexit=false;
			rnew=false;
		}
	else if(x>325 && x<506 && y<271+70+70 && y>221+70+70)
		{
			rhelp=true;
			rhigh=false;
			rexit=false;
			rnew=false;
		}
	else if(x>325 && x<506 && y<271+70+70+70 && y>221+70+70+70)
		{
			rhelp=true;
			rhigh=false;
			rexit=true;
			rnew=false;
		}
	else 
		{
			ecolor=false;
			ehelp=false;
			ncolor=false;
			hcolor=false;
		}
}
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	cout<<x<<" "<<y<<endl;
	if(menus==true || options==true){
	if(menus==true && options==false){
	if(x>356 && x<485 && y<175 && y>140)
		{
			ehelp=false;
			ecolor=false;
			ncolor=true;
			hcolor=false;
		}
	else if(x>356 && x<485 && y<175+60 && y>140+50)
		{
			ehelp=false;
			ecolor=false;
			ncolor=false;
			hcolor=true;
		}
	else if(x>356 && x<485 && y<175+60+60 && y>140+50+50)
		{
			ehelp=true;
			ecolor=false;
			ncolor=false;
			hcolor=false;
		}
	else if(x>356 && x<485 && y<175+60*3 && y>140+50*3)
		{
			ecolor=true;
			ehelp=false;
			ncolor=false;
			hcolor=false;
		}
	else 
		{
			ecolor=false;
			ehelp=false;
			ncolor=false;
			hcolor=false;
		}
	}
	if(options==true && menus==false){
	if(x>356 && x<485 && y<175-30 && y>140-20)
		{
			ehelp=false;
			ecolor=false;
			ncolor=true;
			hcolor=false;
			excolor=true;
		}
	else if(x>356 && x<485 && y<175+40 && y>140+30)
		{
			ehelp=false;
			ecolor=false;
			ncolor=false;
			hcolor=true;
			excolor=true;
		}
	else if(x>356 && x<485 && y<175+40*2 && y>140+30*2)
		{
			ehelp=true;
			ecolor=false;
			ncolor=false;
			hcolor=false;
			excolor=true;
		}
	else if(x>356 && x<485 && y<175+40*3 && y>140+30*3)
		{
			ecolor=true;
			ehelp=false;
			ncolor=false;
			hcolor=false;
			excolor=true;
		}
	else if(x>356 && x<485 && y<175+40*4 && y>140+30*4)
		{
			ecolor=false;
			ehelp=false;
			ncolor=false;
			hcolor=false;
			excolor=false;
		}
	else 
		{
			ecolor=false;
			ehelp=false;
			ncolor=false;
			hcolor=false;
			excolor=true;
		}
	}
	}
		
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
				cout << GLUT_DOWN << " " << GLUT_UP << endl;
if(menus==true || options==true){
	if(x>356 && x<485 && y<175 && y>140)
		{
			rnew=true;
			system("canberra-gtk-play -f beep2.wav");
			sleep(1);
		}
	else if(x>356 && x<485 && y<175+60 && y>140+50)
		{
			rhigh=true;
			system("canberra-gtk-play -f beep2.wav");
			sleep(1);
		}
	else if(x>356 && x<485 && y<175+60+60 && y>140+50+50)
		{
			rhelp=true;
			system("canberra-gtk-play -f beep2.wav");
			sleep(1);
		}
	else if(x>356 && x<485 && y<175+60*3 && y>140+50*3)
		{
			system("canberra-gtk-play -f beep2.wav");
			sleep(1);
			rexit=true;
		}
	}
if(options==true && menus==false){
	if(x>356 && x<485 && y<175-30 && y>140-20)
		{
			cont=true;
			newgame=false;
			help=false;
			high=false;
			rexit=false;
			system("canberra-gtk-play -f beep2.wav");
			sleep(1);
		}
	else if(x>356 && x<485 && y<175+40 && y>140+30)
		{
			cont=false;
			newgame=true;
			help=false;
			high=false;
			rexit=false;
			system("canberra-gtk-play -f beep2.wav");
			sleep(1);
		}
	else if(x>356 && x<485 && y<175+40*2 && y>140+30*2)
		{
			cont=false;
			newgame=false;
			help=false;
			high=true;
			rexit=false;
			system("canberra-gtk-play -f beep2.wav");
			sleep(1);
		}
	else if(x>356 && x<485 && y<175+40*3 && y>140+30*3)
		{
			system("canberra-gtk-play -f beep2.wav");
			sleep(1);
			cont=false;
			newgame=false;
			help=true;
			high=false;
			rexit=false;
		}
	else if(x>356 && x<485 && y<175+40*4 && y>140+30*4)
		{
			system("canberra-gtk-play -f beep2.wav");
			sleep(1);
			cont=false;
			newgame=false;
			help=false;
			high=false;
			rexit=true;
		}
	else 
		{
			ecolor=false;
			ehelp=false;
			ncolor=false;
			hcolor=false;
			excolor=true;
		}
	}

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
	//b = new Board(60, 60); // create a new board object to use in the Display Function ...
	int width = 840, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Dodge-E'm"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
	ScoreRead();
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII 
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
