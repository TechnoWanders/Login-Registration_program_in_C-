#include<iostream>
#include<fstream>
using namespace std;
void login();
void registe();
void forgotten();
int main()
{
    cout<<"                     X------------------------------------------------X\n";
    cout<<"                     X------------------------------------------------X\n";
    cout<<"                     X------------------------------------------------X\n";
    cout<<"                     X------------------------------------------------X\n";
    cout<<"                     X------------------------------------------------X\n";
    cout<<"                                Welcome to the ADMIRAL GROUPS            \n"<<endl;
    cout<<"1.  Login your account\n";
    cout<<"2.  Sign in/ Registration \n";
    cout<<"3.  Exit\n";
    int a;
    cin>>a;

    switch(a)
    {
    case 1:
        login();
        break;

    case 2:
        registe();
        break;

    case 3:
        cout<<"You are exiting the program\n";
        exit(0);
        break;
    }

}
int count=0;
void login()
{
    int i=0,a,bc;
    string user,pass,detect[3];
    cout<<"X----------LOGIN PAGE----------X\n"<<endl;
    cout<<"USERNAME: ";
    cin>>user;
    cout<<endl;
    cout<<"PASSWORD: ";
    cin>>pass;
    cout<<endl;

    ifstream fout;
    fout.open("details.txt");
    string arr;
    while(fout.eof()==0)
    {
        fout>>arr;
        detect[i]=arr;
        i++;
    }
    fout.close();



    if(user==detect[1] && pass == detect[2])
    {
        cout<<"LOGIN SUCCESSFUL\n";
    }
    else
    {
        count++;
        if(count==2)
            {
                cout<<"Failed to Login\n";
                cout<<"System closing itself\n";
                exit(0);
            }
        cout<<"PLEASE CHECK YOUR USERNAME AND PASSWORD\n";
        cout<<endl<<"Forgotten password??";
        cout<<endl<<"Enter 1 to see password or 0 to continue\n";
        cin>>bc;
        cout<<endl;
        if(bc==1)
        {
            forgotten();
        }
        else
        {
            login();
        }
        cout<<endl;
    }


}

void registe()
{
    string email,user1,pass1;
    cout<<"X----------REGISTRATION PAGE-----------X\n"<<endl;
    cout<<"Enter your email id = ";
    cin>>email;
    cout<<endl;
    cout<<"Enter a Username = ";
    cin>>user1;
    cout<<endl;
    cout<<"Enter the password (more then 8 characters and must contain a special character) = ";
    cin>>pass1;
    cout<<endl;
    ofstream fin;
    fin.open("details.txt");
    fin<<email;
    fin<<endl;
    fin<<user1;
    fin<<endl;
    fin<<pass1;
    fin.close();
    cout<<"ACCOUNT CREATED SUCCEFULLY\n"<<endl;
    main();
}

void forgotten()
{
    cout<<"X-------------REMEMBERING PASSWORD ----------------X"<<endl;
    string user;
    ifstream fin;
    fin.open("details.txt");
    cout<<"Enter your email-id = ";
    cin>>user;
    cout<<endl;

    int i=0;
    string arr,detect[3];
    while(fin.eof()==0)
    {
        fin>>arr;
        detect[i]=arr;
        i++;
    }
    fin.close();

    if(user==detect[0])
    {
        cout<<"UNLOCKING SUCCESSFUL\n";
        cout<<endl;
        cout<<"Your passsword was\n";
        cout<<detect[2];
        cout<<endl;
        main();
    }
    else
    {
        cout<<"Cracking Failed\n";
        cout<<"Initializing Protection\n";
        exit(0);
    }

}
