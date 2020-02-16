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
	note(char n,int o,bool s):notation(n),oct(o),sharp(s){}
	friend ostream&operator<<(ostream&out,const note&rhs){
		out<<rhs.notation;
		if(rhs.oct)out<<rhs.oct;
		if(rhs.sharp)out<<'#';
		if(!rhs.oct)out<<' ';
		if(!rhs.sharp)out<<' ';
		return out;
	}
};
note guitar[7][25];
void initstring(int str,note no){
	int cnt=0;
	for(int i=0;i<7;i++){
		if(no.notation=='e'||no.notation=='b'){
			guitar[str][cnt++]=no;
		}
		else{
			guitar[str][cnt++]=no;
			no.sharp=true;
			guitar[str][cnt++]=no;	
			no.sharp=false;
		}
		if(++no.notation>'g'){
			no.notation='a';
			no.oct++;
		}
	}
}
void initguitar(){
	note no={'e',0,false};
	initstring(6,no);
	no={'a',1,false};
	initstring(5,no);
	no={'d',1,false};
	initstring(4,no);
	no={'g',1,false};
	initstring(3,no);
	no={'b',2,false};
	initstring(2,no);
	no={'e',2,false};
	initstring(1,no);
	for(int i=1;i<=6;i++){
		for(int j=12;j<=24;j++){
			guitar[i][j]=guitar[i][j%12];
			guitar[i][j].oct+=j/12;
		}
	}
}
void showguitar(){
	cout<<"guitar"<<endl;
	for(int i=1;i<=6;i++){
		for(int j=0;j<24;j++)
			cout<<' '<<guitar[i][j];
		cout<<endl;
	}
}
void showguitar(int l,int r){
	cout<<"guitar"<<endl;
	for(int i=1;i<=6;i++){
		for(int j=l;j<=r;j++)
			cout<<' '<<guitar[i][j];
		cout<<endl;
	}
}
int main(){
	srand(time(NULL));
	initguitar();
	showguitar();
	return 0;
}
