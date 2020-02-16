#include<iostream>
#include<map>
#include<ctime>
#include<cstdlib>
#include<iomanip>
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
	bool operator==(const note&rhs){
		if(oct==rhs.oct&&sharp==rhs.sharp&&notation==rhs.notation)return true;
		return false;
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
string getTh(int k){
	if(k%10==1)return "st";
	if(k%10==2)return "nd";
	if(k%10==3)return "rd";
	return "th";
}
void showguitar(int l,int r){
	if(l>r)swap(l,r);
	if(r>24)r=24;
	if(l<0)l=0;
	cout<<"guitar"<<endl;
	cout<<"   ";
	for(int i=l;i<=r;i++)
		cout<<setw(4)<<i;
	cout<<endl;
	for(int i=1;i<=6;i++){
		cout<<i<<getTh(i)<<' ';
		for(int j=l;j<=r;j++)
			cout<<' '<<guitar[i][j];
		cout<<endl;
	}
}
void help(){
	string command;
	cout<<"type \"show\" for notations ,\"exit\" to leave."<<endl;
	while(cin>>command){
		if(command=="show"){
			cout<<"type range (frets) like \"0 24\":";
			int l,r;cin>>l>>r;
			showguitar(l,r);
		}
		else if(command=="help")cout<<"u r already in help.what help do you want?"<<endl;
		else if(command=="author")cout<<"rabbittank nothing else. what do you want to know?"<<endl;
		else if(command=="exit")break;
		else if(command=="rabbittank")cout<<"BEST MATCH!!!"<<endl;
		else cout<<"What are you typing?This is not touching screen."<<endl;
	}
}
void showtitle(){
	cout<<"Type h for help or type s to start."<<endl;
}
note getNote(string k){
	int l=k.length();
	note no;
	if(l>=1)no.notation=k[0];
	if(l>=2){
		if(k[1]=='#')no.sharp=true;
		else no.oct=k[2]-'0';
	}
	if(l>=3&&k[2]=='#')no.sharp=true;
	return no;
}
void gameStart(){
	while(1){
		cout<<"The ";
		int str=rand()%6+1;
		cout<<str<<getTh(str)<<" string and ";
		int fret=rand()%25;
		cout<<fret<<getTh(fret)<<" is ";
		string notation;
		cin>>notation;
		if(notation=="exit")return;
		if(guitar[str][fret]==getNote(notation))
			cout<<"Correct!"<<endl;
		else cout<<"Wrong! Correct answer is "<<guitar[str][fret]<<endl;
	}
}
int main(){
	srand(time(NULL));
	initguitar();
	string command;
	while(cin>>command){
		showtitle();
		if(command=="s"){
			gameStart();
		}
		else if(command=="h"){
			help();
		}
	}
	return 0;
}
