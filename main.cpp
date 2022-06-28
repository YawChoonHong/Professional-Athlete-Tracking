#include <iostream>
#include <fstream>
using namespace std;


class Sports
{
    private:
        string sportName, sportType, IndoorOutDoor, teamName;
        int numPlayer;

    public:
        Sports(string name ="", string type ="", string io = "", int n = 1) : sportName(name), sportType(type), IndoorOutDoor(io), numPlayer(n){
            teamName = "";
        }

        void inOut(char in_out){
            IndoorOutDoor = in_out;
        }
        void setSName(string sport_name){
            sportName = sport_name;
        }
        void setSportType(string sport_type){
            sportType = sport_type;
        }
        
        string getSName(){
            return sportName;
        }
        string getSType(){
            return sportType;
        }
        string getinOut(){
            return IndoorOutDoor;
        }
        virtual void print(){}
        void setTeamName(string name){
            teamName = name;
        }
        string getTeamName(){
            return teamName;
        }
        void setNumPlayers(int n){
            numPlayer = n;
        }
        int getNumPlayers(){
            return numPlayer;
        }
};

class Single: public Sports{
    public:
        Single(string sName, string sType, string io): Sports(sName, sType, io, 1){}
        void print(){
            cout << "Sport Name:" << getSName() << endl;
            cout << "Type of Sport: " << getSType() << endl;
            cout << "Indoor(I) or Outdoor(O) Sport: " << getinOut() << endl;
            cout << "Number of Player(s): " << getNumPlayers() << endl;
        }
};

class Team: public Sports{
    private:
        string teamname;
        
    public:
        Team(string sName = "", string sType = "", string io = "", string teamName = "", int n = 2): Sports(sName, sType, io, n), teamname(teamName){}
        void setTeamName(string nameTeam){
            teamname = nameTeam;
        }
        void print(){
            cout << "Sport Name:" << getSName() << endl;
            cout << "Type of Sport: " << getSType() << endl;
            cout << "Indoor(I) or Outdoor(O) Sport: " << getinOut() << endl;
            cout << "Number of Player(s): " << getNumPlayers() << endl;
            cout << "Team's Name: " << getTeamName() << endl;
        }
};


class Name{
    string firstName, lastName, surName, nickName; 

    public:
        Name(string first = " ", string last = " ", string sur = " ", string nick = " "){
            firstName = first;
            lastName = last;
            surName = sur;
            nickName = nick;
        }

        string getFirstName(){
            return firstName;
        }

        string getLastName(){
            return lastName;
        }   

        string getSurName(){
            return surName;
        }

        string getNickName(){
            return nickName;
        }
        
};

class PreferredEquipment{
    string manufacturer, model;
    double price, rating;

    public:
        PreferredEquipment(string _manufacturer = " ", string _model = " ", double _price = 0.00, double _rating = 0.0){
            manufacturer = _manufacturer;
            model = _model;
            price = _price;
            rating = _rating; 
        }
    
        string getManufacturer(){
            return manufacturer;
        }

        string getModel(){
            return model;
        }
        
        double getPrice(){
            return price;
        }

        double getRating(){
            return rating;
        }
};

class Athlete{
    private:
        int age, height;
        string bPlace;
        char gender;
        double acPoint;
        Name athleteName;
        PreferredEquipment *p;
        
    public:
        Athlete(int _age = 0, int _height = 0, string _bPlace = "", char _gender = 'm', double _acp = 0.0, string firstName = "", string lastName = "", string surName= "", string nickName = "")
        :athleteName(firstName, lastName, surName, nickName), age(_age), height(_height), bPlace(_bPlace), gender(_gender), acPoint(_acp){
            p = NULL;
        }
        int getAge() const {return age;}
        int getHeight() const {return height;}
        char getGender() const {return gender;}
        double getAcPoint() const {return acPoint;}
        string getbPlace()  const {return bPlace;}
        
        void equipment(PreferredEquipment *equipment){
            p = equipment;
        }
        
        string getEquipmentManufacturer(){
            if(p == NULL){
                return "";
            }
            else{
                return p->getManufacturer(); 
            }
        }
        
        string getEquipmentModel(){
            if(p == NULL){
                return "";
            }
            else{
                return p->getModel();
            }
        }
        
        double getEquipmentPrice(){
            if(p == NULL){
                return 0.0;
            }
            else{            
                return p->getPrice();
            }
        }
        double getEquipmentRating(){
            if(p == NULL){
                return 0.0;
            }else{
                return p->getRating();
            }
        }
        void print(){
            cout << "\n=========Athlete Information=========" << endl;
            cout << "Age: " << getAge()
                << "\nGender: " << getGender()
                << "\nHeight: " << getHeight()
                << "\nBirthPlace: " << getbPlace()
                << "\nAccumulative Points: " << getAcPoint()
                << "\nFirst Name: " << athleteName.getFirstName()
                << "\nLast Name: " << athleteName.getLastName()
                << "\nSurname: " << athleteName.getSurName()
                << "\nNickname: " << athleteName.getNickName() << endl;
            cout << "\n=========Preferred Equipment========="
                << "\nBrand:" << getEquipmentManufacturer()
                << "\nModel: " <<getEquipmentModel()
                << "\nPrice: " << getEquipmentPrice()
                << "\nRating: " << getEquipmentRating() << endl;
        }
};


int sportMenu(ifstream &inputData)
{
    int choice;
    cout << "[1]. Badminton\n"
    << "[2]. Table Tennis\n"
    << "[3]. Tennis\n"
    << "[4]. Weightlifting\n"
    << "[5]. Football\n" << endl; 
    cout << "\nSelect an option: ";
    cin >> choice;
    if(choice ==1 ){
        inputData.open("dataSingleBad.txt");
    }

    return choice;
}



int main()
{
    ifstream textfile;
    int a,h;
    string place, first,last,sur,nick;
    char gen;
    double pt;


    Single b1("Badminton", "Anarobics", "Indoor");
    Single t1("Table Tennis", "Anarobics", "Indoor");
    Single w("Weightlifting", "Aerobics", "Indoor");
    Single T1("Tennis", "Anarobics", "Outdoor");

    Team b2("Badminton", "Anarobics", "Indoor");
    Team t2("Table Tennis", "Anarobics", "Indoor");
    Team T2("Tennis", "Anarobics", "Outdoor");
    Team f("Football", "Anarobics", "Outdoor");

    PreferredEquipment eq("Jenama X", "Model X", 25.25, 2.5);

    
    Sports *S[4] = {&b1, &t1, &T1, &w};
    Sports *S1[4] = {&b2, &t2, &T2, &f};
    int sportChoice;
    int numPlayer;
    string tName;

    //Athlete ath[numPlayer];

    do{
        sportChoice = sportMenu(textfile);
        if (!textfile){
        cout << "Failed" << endl;
        system("pause");
        exit(0);
        }
        cout << "Enter the number of Player for the sport: ";
        cin >> numPlayer;
        if(numPlayer == 1){
            S[sportChoice - 1]->print();        
        }

        if(numPlayer > 1){
            cout << "Enter the team Name: ";
            cin >> tName;
            S1[sportChoice - 1]->setTeamName(tName);
            S1[sportChoice - 1]->setNumPlayers(numPlayer);
            S1[sportChoice - 1]->print();
        }
    }while(numPlayer < 0 );

    Athlete ath[numPlayer];

    for (int i=0; i< numPlayer; i++){
        textfile >> a >> h >> place >> gen>> pt >> first >> last >> sur >> nick;
        ath[i] = {Athlete(a, h, place, gen, pt, first,last,sur, nick)};
        textfile.ignore();
    }


    for(int i=0; i<numPlayer; i++)
    {
        ath[i].equipment(&eq);
        ath[i].print();
    }
    
    





    system("pause");
    return 0;
}
