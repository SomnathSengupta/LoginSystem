//homework
#include<iostream>
#include<time.h>
#include<vector>
using namespace std;
vector <string> v;
class User{
    string name;
    int age;
    string username;
    string password;
    bool islog = false;
    public:
        //Checking if the usename is already exist or not
        string duplicate(string usernamme){
            string str;
            for(int i=0; i<v.size(); i++){
                if(v[i]==username){
                    str="Username Already Exists.";
                    return str;
                }
            }
            v.push_back(username);
        }
        //Set your necessary details
        void setDetails(){
            cout << "Set your Username: " << endl;
            cin >> this->username;
            if(v.size()<1){
                v.push_back(this->username);
            }
            else{
                string str=duplicate(this->username);
                if(str=="Username Already Exists."){
                    cout << str <<endl;
                    return;
                }
            }
            cout << "Set your Password: " << endl;
            cin >> this->password;
            
        }
        //Default Constructor
        User(string name){
            setDetails();
            if(this->password.empty() == 1){
             setDetails();
             }
            }
        //Set your new password
        void setPassword(){
            int np;
            cout << "Enter your new password: " <<endl;
            cin >> np; 
            password = np;
            cout << "You have changed your password successfully."<< endl;
        }
        //Login yourself
        void login(){
            
            string username, password;
            int captcha;
            cout << "To Login please fill the below details: " << endl;
            cout << "Enter your username: " << endl;
            cin >> username;
            cout << "Enter your password: " << endl;
            cin >> password;
            srand(time(nullptr));
            int random = rand();
            cout << random << endl <<"Enter the above captcha:" << endl;
            cin >> captcha;
            if(this->username == username && this->password == password && random == captcha){
                islog = true;
                cout << "You have logged yourself successfully" << endl;
            }
            else{
                cout << "You have entered wrong details." << endl;
                string op;
                cout << "Please enter your old password to set the new password:" << endl;
                cin >> op;
                if(op == this->password){
                    setPassword();
                }
                else{
                    cout << "Wrong Password." << endl;
                    islog = false;
                }
            }
        }
        //Logout yourself
        void logout(){
            if(islog == false){
                cout << "You are already logged out." << endl;
            }
            else{
                islog = false;
                cout << "You have Logged out successfully." << endl;
            }
            
        }
        //Show your details
        void showDetails(){
            if(islog == true){
                cout << "Showing your details: "<< endl;
                cout << "Name: " << name;
                cout << "Age: " << age;
                cout << "Username: " << username;
            }
            else{
                cout << "At first login yourself." << endl;
            }
        }
};
int main()
{   
    User u1("Somnath");
    u1.login();
    u1.logout();
    u1.showDetails();
    User u2("Ritam");
    u2.login();
    u2.logout();
    return 0;
}