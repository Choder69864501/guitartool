#include<iostream>
#include<map>
#include<ctime>
#include<cstdlib>
#define endl '\n'
using namespace std;
class note{
public:
	int oct;
	char notation;
	bool sharp;
	note():oct(0),notation(' '),sharp(false){}
};
char arr[8]="ABCDEFG";
note guitar[7][25];
void initstring(char st){
	int cnt=0;
	for(int i=0;i<7;i++){
		if(st=='E'||st=='B'){
			
		}
		else{

		}
	}
}
void initguitar(){
	
}
int main(){
	srand(time(NULL));
	return 0;
}
