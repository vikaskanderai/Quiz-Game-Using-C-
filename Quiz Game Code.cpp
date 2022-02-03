#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class question
{
    protected:
        string que;
        string opt1,opt2,opt3;
        char ans;
        static float score;
    public:
        void setquestion(string q,string o1,string o2,string o3,char copt)
        {
            que=q;
            opt1=o1;
            opt2=o2;
            opt3=o3;
            ans=copt;
        }
         
        float showscore()
        {
            return(score);
        }
};
float question::score=0;

class hard: public question
{
    public:
    void askquestion()
    {
        cout<<que<<endl;
        cout<<"a."<<opt1<<endl;
        cout<<"b."<<opt2<<endl;
        cout<<"c."<<opt3<<endl;
        
        char choice;
        cout<<"Enter your option:-\n";
        cin>>choice;
        
        if(choice==ans)
        {
            score++;
        }
        else
        {
            score-=0.5;
        }
    }
};

class easy: public question
{
    public:
    void askquestion()
    {
        cout<<que<<endl;
        cout<<"a."<<opt1<<endl;
        cout<<"b."<<opt2<<endl;
        cout<<"c."<<opt3<<endl;
        
        char choice;
        cout<<"Enter your option:-\n";
        cin>>choice;
        
        if(choice==ans)
        {
            score++;
        }
        else
        {
            ;
        }
    }
};

int main()
{
    char in[10]="  ",arr[500];
    int i=0,j=0;
    int check=2;
    string player1,player2;
    int level;
    int player=0;
    
    cout<<"\t\t\tWELCOME TO THE QUIZ\t\t\t\n"<<endl;
    
    //collect player details
    while(check==2)
    {
      
        cout<<"Enter the number of players\n"<<endl;
        cin>>player;
        
        
        while(j<1||j>2)   //to select game level
        {
            cout<<"\nCHOOSE LEVEL\nEnter:\n -->'1' for easy\n -->'2' for hard"<<endl;
            cin>>j;
            
            switch(j)
                {
                case 1: level=1;
                        cout<<"You selected EASY"<<endl;
                        break;
                case 2: level=2;
                        cout<<"You selected HARD"<<endl;
                        break;
                default:cout<<"!!!INVALID INPUT!!!"<<endl;
                break;
                }
        }
        //verify player details
        cout<<"\nEnter \n -->'1' if the given details are correct\n -->'2' to change the details"<<endl;
        cin>>check;
        if(check==2)
        {
            cout<<"Please re-enter the details\n"<<endl;
            i=0;
            j=0;
        }
    }
    
    float p1score=0;
    float p2score=0;
    float p3=0;
    for(i=0;i<player;i++)
    {
        
   
        cout<<"\n\nIt is player"<<i+1<<"'s turn"<<endl;
        
        switch(level)   //asking questions
        {
            case 1:{
                        easy e1,e2,e3,e4,e5;
                        e1.setquestion("\nQ1.How many years are there in one millenium ?","100 years","1000 years","100000 years",'b');
                        e1.askquestion();
                        e2.setquestion("\nQ2.Which is the heaviest metal ?","Osmium","Iridium","Rhenium",'a');
                        e2.askquestion();
                        e3.setquestion("\nQ3.National animal of Argentina is","Emu","Lion","Puma",'c');
                        e3.askquestion();
                        e4.setquestion("\nQ4.True or False?Birds evolved fron Dinosaurs ","False ","True ","Ambiguous ",'b');
                        e4.askquestion();
                        e5.setquestion("\nQ5.Which country gifted ‘Statue of Liberty’","Germany ", "France", "Spain",'b');
                        e5.askquestion();
                        p1score= e5.showscore();
                        p2score=p1score-p3;
                        p3=p1score;
                        ofstream myfile("score_sheet.txt",ios::app);
                        myfile<<p2score;
                        myfile<<in;
                        myfile.close();
                        
                        
                       
                   }
                    break;
            case 2:{
                        hard h1,h2,h3,h4,h5;
                        h1.setquestion("\nQ1.Who is the CEO of YouTube","Susan Wojcicki","Chad Hurley","Jawed Karim",'a');
                        h1.askquestion();
                        h2.setquestion("\nQ2.Who is the youngest PM of India ?","Atal Bihari Vajpayee","V.P.Singh","Rajiv Gandhi",'c');
                        h2.askquestion();
                        h3.setquestion("\nQ3.How many bones are there in an elephant’s trunk ?","One","Zero","Two",'b');
                        h3.askquestion();
                        h4.setquestion("\nQ4.What color does gold leaf appear if you hold it up to the light ?","Gold","Green","Orange",'b');
                        h4.askquestion();
                        h5.setquestion("\nQ5.What is the radius of a cricket ball","2.8 inches","2.6 inches","2.7 inches",'a');
                        h5.askquestion();
                        h5.showscore();
                        p1score= e5.showscore();
                        p2score=p1score-p3;
                        p3=p1score;
                        ofstream myfile("score_sheet.txt",ios::app);
                        myfile<<p2score;
                        myfile<<in;
                        myfile.close();
                        
                   }   
                    break;
                    
                    
        }
      
    }
    ifstream obj("score_sheet.txt");
    obj.getline(arr,500);
    cout<<"scores are:\n"<<arr<<endl;
    obj.close();
    return 0;
}  

