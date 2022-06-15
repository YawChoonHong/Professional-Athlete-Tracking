#include <iostream>
using namespace std;
//#define single_numP = 1;

class Sports
{
    private:
        string sportName, sportType;
        string IndoorOutDoor, teamName;
    
    public:
        Sports(string name ="", string type ="", string io = "") : sportName(name), sportType(type), IndoorOutDoor(io){}

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
        virtual void setNumPlayers(int n);

};

class Single: public Sports
{
    private:
        int numPlayer;
    
    public:
        Single(){}
        Single(string sName , string sType, string io): Sports(sName, sType, io){
            numPlayer = 1;
        }
        void setnumPlayer(int n){
            numPlayer = 1;
        }
        void print(){
            cout << "Sport Name:" << getSName() << endl;
            cout << "Type of Sport: " << getSType() << endl;
            cout << "Indoor(I) or Outdoor(O) Sport: " << getinOut() << endl;
            cout << "Number of Player(s): " << numPlayer << endl;
        }
};

class Team: public Sports
{
    private:
        int numPlayer;
        string teamName;
        
    public:
        Team(string TName = "", string sName = "", string sType = "", string io = "", int num = 0): Sports(TName, sName, sType, io), numPlayer(num), teamName(TName){}
        void setnumPlayer(int numP){
            numPlayer = numP;
        }
        void setTeamName(string nameTeam)
        {
            teamName = nameTeam;
        }
        void setNumPlayers(int n){
            numPlayer = n;
        }
        void print(){
            cout << "Sport Name:" << getSName() << endl;
            cout << "Type of Sport: " << getSType() << endl;
            cout << "Indoor(I) or Outdoor(O) Sport: " << getinOut() << endl;
            cout << "Number of Player(s): " << numPlayer << endl;
            cout << "Team's Name: " << teamName << endl;
        }
};


class Name{
    string firstName, lastName, surName, nickName; 

    public:
        Name(string firstName = " ", string lastName = " ", string surName = " ", string nickName = " "){
            this->firstName = firstName;
            this->lastName = lastName;
            this->surName = surName;
            this->nickName = nickName;
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
        PreferredEquipment(string _manufacturer = " ", string _model = " ", double _price = 0, double _rating = 0){
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
        
        void equipment(PreferredEquipment *equipment){
            p = equipment;
        }
        
        string getEquipmentManufacturer(){
            if(p == NULL){
                return "";
            }
            return p->getManufacturer();
        }
        
        string getEquipmentModel(){
            if(p == NULL){
                return "";
            }
            return p->getModel();
        }
        
        double getEquipmentPrice(){
            if(p == NULL){
                return 0.0;
            }
            return p->getPrice();
        }
        double getEquipmentRating(){
            if(p == NULL){
                return 0.0;
            }
            return p->getRating();
        }
};


int sportMenu()
{
    int choice;
    cout << "[1]. Badminton\n"
    << "[2]. Table Tennis\n"
    << "[3]. Tennis\n"
    << "[4]. Weightlifting\n"
    << "[5]. Football\n" << endl; 
    cin >> choice;
    return choice;
}



int main()
{
    Single b1("Badminton", "Anarobics", "Indoor");
    Single t1("Table Tennis", "Anarobics", "Indoor");
    Single w("Weightlifting", "Aerobics", "Indoor");
    Single T1("Tennis", "Anarobics", "Outdoor");

    Team b2("", "Badminton", "Anarobics", "Indoor",2);
    Team t2("","Table Tennis", "Anarobics", "Indoor",2);
    Team T2("","Tennis", "Anarobics", "Outdoor",2);
    Team f("","Football", "Anarobics", "Outdoor",2);
    
    Sports *S[] = {&b1, &t1, &T1, &w};
    Sports *S1[] = {&b2, &t2, &T2, &f};
    int sportChoice;
    int numPlayer;
    string tName;
    sportChoice = sportMenu();
    do{
        cout << "Enter the number of Player for the sport: ";
        cin >> numPlayer;
        if(numPlayer == 1){
            S[sportChoice - 1]->print();        
        }

        if(numPlayer > 1){
            cout << "Enter the team Name: ";
            getline(cin,tName);
            S1[sportChoice -1 ]->teamName();
            S1[sportChoice - 1]->print();
        }
    }while(numPlayer > 0 );


    system("pause");
    return 0;
}
