/*
 * main.cpp
 *
 *  Created on: Jul 11, 2020
 *      Author: ArunRaj A
 */

#include<iostream>
#include <conio.h>
using namespace std;

bool gameOver;
const int width=20,height=20;
int x,y,fruitX,fruitY,score;
int tailX[100],tailY[100];
int nTail;
enum eDirection{STOP=0,UP,DOWN,LEFT,RIGHT};
eDirection dir;

void Setup(){
 gameOver = false;
 dir = STOP;
 x = width/2;
 y = height/2;
 fruitX = rand()%width;
 fruitY = rand()%height;
 score=0;
}
void Draw(){
system("cls");
	for(int i=0; i<width+2; i++)
		cout << "#";
	cout << endl;
	
	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			if(j==0)
				cout << "#"; 
			if(i==y && j==x) 
				cout << "$";
			else if(i==fruitY && j==fruitX)
				cout << "*";
			else{
				bool print =false;
				for(int k=0; k<nTail; k++){
					if(tailX[k]==j && tailY[k]==i){
						cout << "o" ;
						print=true;
					}
				}
				if(!print)
					cout << " ";
			}
				
			if(j==width-1)
				cout << "#";
		}
		cout << endl;
	}
	
	for(int i=0; i<width+2; i++)
		cout << "#";
	cout << endl;
	
	
}
void Input(){
	if(_kbhit()){
			switch(getch()){
			case 'i':
					dir =UP;
					break;
			case 'j':
					dir =LEFT;
					break;
			case 'l':
					dir =RIGHT;
					break;
			case 'k':
					dir =DOWN;
					break;
			case 'p':
					gameOver = true;
					break;
			}
	}
}
void Logic(){
	int prevX=tailX[0];
	int prevY=tailY[0];
	int prev2X, prev2Y;
	tailX[0]=x;
	tailY[0]=y;
	for(int i=1; i<nTail; i++){
		prev2X=tailX[i];
		prev2Y=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY; //0oooo
		prevX=prev2X;
		prevY=prev2Y;
	}
	switch(dir){
		case UP:
				y--;
				break;
		case LEFT:
				x--;
				break;
		case RIGHT:
				x++;
				break;
		case DOWN:
				y++;
				break;
		default:
				break;
			
	}
	if(x>width || x<0 || y>height || y<0)
	  gameOver=true;
	for(int i=0; i<nTail ;i++){
		if(tailX[i]==x && tailY[i]==y)
			gameOver=true;
	}
	
	if(x==fruitX && y==fruitY){	
		nTail++;
		score+=10;
		fruitX=rand()%width;
		fruitY=rand()%height;
	}	
}
int main(){
	Setup();
	while(!gameOver){
		Draw();
		Input();
		Logic();
		//Sleep(10);
	}
	cout << "GAMEOVER" << endl;
	cout << "Score is :" << score << endl;
	return 0;
}