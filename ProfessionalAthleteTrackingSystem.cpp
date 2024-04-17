#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

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
            cout << "Age                     : " << getAge()
                << "\nGender[M-Male, F-Female]: " << getGender()
                << "\nHeight[cm]              : " << getHeight()
                << "\nBirthPlace              : " << getbPlace()
                << "\nAccumulative Points     : " << getAcPoint()
                << "\nFirst Name              : " << athleteName.getFirstName()
                << "\nLast Name               : " << athleteName.getLastName()
                << "\nSurname                 : " << athleteName.getSurName()
                << "\nNickname                : " << athleteName.getNickName() << endl;
            cout << fixed << setprecision(2);
            cout << "\n******************Preferred Equipment**********************************"
                << "\nBrand                   : " << getEquipmentManufacturer()
                << "\nModel                   : " <<getEquipmentModel()
                << "\nPrice[RM]               : " << getEquipmentPrice()
                << "\nRating[0-5]             : " << getEquipmentRating() << endl;
        }
};

class Sports{
    private:
        string sportName, sportType, IndoorOutDoor, teamName;
        int numPlayer;
        Athlete ath;

    public:
        Sports(string name ="", string type ="", string io = "", int n = 1,int age = 0, int height = 0, string bPlace= "", char gender = 'm', double acp =0.0, string firstName= "", string lastName= "",string surName= "", string nickName= ""):ath(age, height, bPlace, gender, acp, firstName, lastName, surName, nickName), sportName(name), sportType(type), IndoorOutDoor(io), numPlayer(n){
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
            cout << "\n\n##################Selected Sport#######################################";
            cout << "\nSport Name              : " << getSName() << endl;
            cout << "Type of Sport           : " << getSType() << endl;
            cout << "Indoor or Outdoor Sport : " << getinOut() << endl;
            cout << "Number of Player(s)     : " << getNumPlayers() << endl;
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
            cout << "\n\n##################Selected Sport#######################################";
            cout << "\nSport Name              : " << getSName() << endl;
            cout << "Type of Sport           : " << getSType() << endl;
            cout << "Indoor or Outdoor Sport : " << getinOut() << endl;
            cout << "Number of Player(s)     : " << getNumPlayers() << endl;
            cout << "Team's Name             : " << getTeamName() << endl;
        }

};

int sportMenu(){
    int choice;
    cout << "[1]. Badminton\n"
    << "[2]. Table Tennis\n"
    << "[3]. Tennis\n"
    << "[4]. Football\n" << endl; 
    do{
        cout << "\nSelect an option: ";
        cin >> choice;
        try{
            if(choice < 1 || choice > 4){
                throw choice;
            }
        }
        catch (const int n){
            cout << n << " is an invalid input." << endl;
        }
    }while(choice < 1 || choice > 4);
    return choice;
}

int main(){
    ifstream textfile;  // Athlete Data File
    int a,h;
    string place, first,last,sur,nick;
    char gen;
    double pt;

    ifstream textfile2; // Athletes' Preferred Equipment Data File
    string manu,mod;
    double pri,rat;

    Single b1("Badminton", "Anarobics", "Indoor");
    Single t1("Table Tennis", "Anarobics", "Indoor");
    Single T1("Tennis", "Anarobics", "Outdoor");

    Team b2("Badminton", "Anarobics", "Indoor");
    Team t2("Table Tennis", "Anarobics", "Indoor");
    Team T2("Tennis", "Anarobics", "Outdoor");
    Team f("Football", "Anarobics", "Outdoor");

    Sports *S[3] = {&b1, &t1, &T1};
    Sports *S1[4] = {&b2, &t2, &T2, &f};
    int sportChoice;
    int numPlayer;
    string tName;
    int TeamNumber;
    char decision;
    char program_decision;

    string teamChoice[2] = {"Team A", "Team B"};

    cout << setw(85) << "Welcome to Professional Athletes Tracking System\n\n" << endl;
    cout << "Developed by: Section 4 (Group 9)" << endl;
    cout << "Developers  : 1) LOH WEI HUAN (A21EC0048)"
        << "\n\t      2) RASIDIN BIN HATTA (A21EC0126)"
        << "\n\t      3) YAW CHOON HONG (A21EC0240)" << endl << endl;
    
    do{
        do{
            sportChoice = sportMenu();
            if(sportChoice == 4){
                numPlayer = 11;
                cout << "[1] Team A\n"
                    << "[2] Team B\n";
                cout << "Choose a team: ";
                cin >> TeamNumber;
                if(TeamNumber == 1){
                    
                    textfile.open("TeamA-Football-Athletes.txt");
                    textfile2.open("TeamA-Football-Equipments.txt");
                }
                else{
                    textfile.open("TeamB-Football-Athletes.txt");
                    textfile2.open("TeamB-Football-Equipments.txt");
                }
                
                tName = teamChoice[TeamNumber-1];
                S1[3]->setTeamName(tName);
                S1[3]->setNumPlayers(numPlayer);
                S1[3]->print();
            }
            else{
                do
                {
                    cout << "Enter [S/s] for Single or [T/t] for Team: ";
                    cin >> decision;
                    if (decision == 'S' || decision == 's')
                        numPlayer = 1;
                    else{
                        numPlayer = 2;
                    }
                }while(!(decision == 'S' || decision  == 's' || decision == 'T' || decision == 't'));

                if(numPlayer == 1){
                    if (sportChoice == 1){
                        textfile.open("Single-Badminton-Athlete.txt");
                        textfile2.open("Single-Badminton-Equipment.txt");
                    }
                    if (sportChoice == 2){
                        textfile.open("Single-TableTennis-Athlete.txt");
                        textfile2.open("Single-TableTennis-Equipment.txt");
                    }
                    if (sportChoice == 3){
                        textfile.open("Single-Tennis-Athlete.txt");
                        textfile2.open("Single-Tennis-Equipment.txt");
                    }
                    S[sportChoice - 1]->print();        
                }
                else{
                    cout << "[1] Team A\n"
                        << "[2] Team B\n";
                    cout << "Choose a team: ";
                    cin >> TeamNumber;
                    if(TeamNumber == 1){
                        if (sportChoice == 1){
                            textfile.open("TeamA-Badminton-Athletes.txt");
                            textfile2.open("TeamA-Badminton-Equipments.txt");
                        }
                        if (sportChoice == 2){
                            textfile.open("TeamA-TableTennis-Athletes.txt");
                            textfile2.open("TeamA-TableTennis-Equipments.txt");
                        }
                        if (sportChoice == 3){
                            textfile.open("TeamA-Tennis-Athletes.txt");
                            textfile2.open("TeamA-Tennis-Equipments.txt");
                        }
                    }
                    else{
                        if (sportChoice == 1){
                            textfile.open("TeamB-Badminton-Athletes.txt");
                            textfile2.open("TeamB-Badminton-Equipments.txt");
                        }
                        if (sportChoice == 2){
                            textfile.open("TeamB-TableTennis-Athletes.txt");
                            textfile2.open("TeamB-TableTennis-Equipments.txt");
                        }
                        if (sportChoice == 3){
                            textfile.open("TeamB-Tennis-Athletes.txt");
                            textfile2.open("TeamB-Tennis-Equipments.txt");
                        }
                    }
                    tName = teamChoice[TeamNumber-1];
                    S1[sportChoice - 1]->setTeamName(tName);
                    S1[sportChoice - 1]->setNumPlayers(numPlayer);
                    S1[sportChoice - 1]->print(); 
                }
            }

        }while(numPlayer < 0 );

        Athlete ath[numPlayer];

        for (int i=0; i< numPlayer; i++){
            textfile >> a >> h >> place >> gen>> pt >> first >> last >> sur >> nick;
            ath[i] = Athlete(a, h, place, gen, pt, first,last,sur, nick);
            textfile.ignore();
        }

        PreferredEquipment eq[numPlayer];

        for (int i=0; i< numPlayer; i++){
            textfile2 >> manu >> mod >> pri >> rat;
            eq[i] = PreferredEquipment(manu, mod, pri, rat);
            ath[i].equipment(&eq[i]);
            textfile.ignore();
        }

        for(int i=0; i<numPlayer; i++){
            if (numPlayer == 1){
                cout << "\n==================Athlete Information==================================" << endl;
                ath[i].print();
            }
            else{
                cout << "\n==================Athlete #"<< (i+1) << " Information==============================" << endl;
                ath[i].print();
            }
        }

        cout << "\nDo you wish to search for other sport? [Y/N]: ";
        cin >>program_decision;
        cout << endl << endl;
        textfile.close();
        textfile2.close();
    }while(program_decision == 'Y' || program_decision == 'y');

    cout << "\n######################################################################################################################" << endl;
    cout << setw(75) << "Thank you for using our system!" << endl;
    cout << "######################################################################################################################" << endl;

    system("pause");
    return 0;
}
