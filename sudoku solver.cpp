#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
ifstream in("input.txt");

int mat[9][9],end_i,end_j;
int i=0,j=0,k;
bool bl[9][9];

void stampa(){
	cout<<"LA SOLUZIONE DEL SUDOKU E'"<<endl;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

void load(){
	char c;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			in>>c;
			mat[i][j]=c-48;
			bl[i][j]=c-48;
			if(c-48==0){
				end_i=i;
				end_j=j;
			}
		}
	}
}

void forward(){
	if(j==8){
	i++;
	j=0;
	}
	else j++;
}

void back(){
	if(j==0){
		i--;
		j=8;
	}
	else j--;
}

bool can_fit(int i,int j,int k){
	int a,b;
	if(i<=2) a=3;
	else if(i<=5) a=6;
	else a=9;
	if(j<=2) b=3;
	else if(j<=5) b=6;
	else b=9;
	for(int x=a-3;x<a;x++){
		for(int y=b-3;y<b;y++){
			if(mat[x][y]==k) return false;
		}
	}
	for(int x=0;x<9;x++) if(mat[x][j]==k) return false;
	for(int y=0;y<9;y++) if(mat[i][y]==k) return false;
	
	return true;
}

int main(){
	load();
	while(mat[end_i][end_j]==0){
		if(bl[i][j]){
			if(k==10) back();
			else forward();
		}
		else{
			k=mat[i][j]+1;
			while(k<=9 && !can_fit(i,j,k)) k++;
			if(k==10){
				mat[i][j]=0;
				back();
			}
			else{
				mat[i][j]=k;
				forward();
			}
		}
	}
	stampa();
	system("PAUSE");
}
