//============================================================================
// Name        : worldcup.cpp
// Author      : Mohammed Wael Abogazia
// section     :7
// Description : simulation of Fifa World Cup draw.
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string input[4][8];
string contint[4][8];              //continental initial position
string output[4][8];
string contfinal[4][8];

	void fillArray(){
		int i,a=0,b=0,c=0,d=0;
		string cntry;
		string cont;
		int clas;
		cout<<"please, enter participating countries in the form: country continent class"<<endl;
		for (i=0;i<32;i++){
		  cin>>cntry>>cont>>clas;
		  if(clas==1){
			  a++;
			  input[0][1-a]=cntry;
			  contint[0][1-a]=cont;
		  }
		  else if(clas==2){
			  b++;
			  input[1][1-b]=cntry;
			  contint[1][1-b]=cont;

		  }
		  else if(clas==3){
			  c++;
			  input[2][1-c]=cntry;
			  contint[2][1-c]=cont;

		  }
		  else {
			  d++;
			  input[3][1-d]=cntry;
			  contint[3][1-d]=cont;

		  	  	  }
		  	  }
		}


int fn1(int o,int r){                 // to check if the place [o][r]is empty
	int place;
	for (int i=0;i<8;i++){
	if (output[o][r]==input[o][i]){
	place=0;
	break;
	}
	else place=1;
	}
	return place;
}


int fn2(int o, int i,int r){       // to check if there is a country from same continental in the group
	int place;
	int emax=0;
	for(int j=0;j<4;j++){
		if(contint[o][i]==contfinal[j][r]){
			if (contint[o][i]== "europe"){
				emax++;
				if(emax==2){
					place=0;
					break;
				}
				else {
					place=1;
				}
			}
			else {
				place=0;
				break;
			}
		}
		else{
			place=1;
		}
	}
	return place;
}
int main() {
 fillArray();
 int r;
 for(int o=0;o<8;o++){
	 for(int i=0;i<4;i++){
		 do{
					 srand(time(0));
					 r=(rand()%8);
				 }
				 while(fn1(o,r)==0||fn2(o,i,r)==0);
		output[o][r]=input[o][i];
		contint[o][r]==contfinal[o][i];
	 }
	for (int k=0;k<4;k++){
		for(int l=0;l<8;l++){
			cout<<output[k][l];
		}
		cout<<endl;
	}
 }

return 0;

}
