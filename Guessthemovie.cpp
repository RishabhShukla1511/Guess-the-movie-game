#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

int count_num_of_words(string str)
{
    int cnt=1;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==' ')
            cnt++;
        else
            continue;
    }
    return cnt;
}

int is_accessed(bool arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        if(arr[i]==false)
          return 0;
    }
    return 1;
}

int game_beginner(string films_name[])
{
    srand(time(0));
    int a= rand()%25;
    string b=films_name[a],m;
    a = count_num_of_words(b);
    cout << "The number of words in the movie is " << a << '\n';
    a=b.size();
    int h=a;
    bool arr[a];
    memset(arr,false,a);
    for(int i=0;i<b.size();i++)
    {
      if(b[i]==' ')
        arr[i]=true;
    }
    while(h--)
      m+="_ ";
    for(int i=0;i<a;i++)
    {
        if(b[i]==' ')
            {
              cout << "  ";
              m[i]=' ';
            }
        else
            {
              cout << "_ ";
              m[i]='_';
              m[i+1]=' ';
            }
    }
    cout << '\n';
    a=10;
    int d=0,z=0;
    while(a>0)
    {
      z++;
        cout << "Guess a letter\n";
        char c;
        cin >> c;
        int k=0;
        system("cls");
        for(int i=0;i<b.size();i++)
        {
          if(b[i]==c || b[i]==tolower(c))
          {
            m[i]=tolower(c);
            arr[i]=true;
            k=1;
          }
          if(z%2==0)
            system("color 5");
          else
            system("color 6");
          if(int(m[i])>=97 && int(m[i])<=122)
            cout << m[i];
          else
            cout << m[i] << " ";
        }
          if(is_accessed(arr,b.size()))
          {
            cout << "\nYou won! :}";
            d=1;
            break;
          }
        if(d==1)
          break;
        if(k==0)
          a--;
        cout << "\n\nYou have " << a << " points left\n";
    }
    if(d!=1)
      {
        cout << "You lost :{\nWell the movie was: " << b;
      }
    cout << "\n\nGame over\nWould you like to play another game(y/n)";
    char c;
    cin >> c;
    if(c=='y' || c=='Y')
      return 1;
    else
      return 0;
}

int main()
{
    string films_name[] = {"the shawshank redemption",
    "the godfather",
    "the dark knight",
    "schindler's list",
    "pulp fiction",
    "the lord of the rings",
    "the good the bad and the ugly",
    "fight club",
    "the lord of the rings",
    "forrest gump","star wars",
    "inception","the lord of the rings",
    "the matrix",
    "samurai",
    "star wars",
    "city of god",
    "the silence of the lambs",
    "batman begins",
    "die hard",
    "chinatown",
    "room",
    "dunkirk",
    "fargo",
    "no country for old men"};
    int v=1;
    while(v)
    {
      system("cls");
      system("color 3");
      cout << "                                     *******************************Guess The Name Of The Movie begins!!!!*******************************\n\n";
      cout << "1. How to play?\n2. Start\n";
      cout << "Enter your choice\n";
      int a;
      char c;
      cin >> a;
      switch(a)
      {
          case 1: cout << "This game is about guessing the name of the movie.\n";
                  cout << "You have 10 points to begin with.You make a guess of the letters in the movie\nif the guessed letter matches with any of the letter in the movie you get pretty close to guess the movie.\n";
                  cout << "You lose 1 point for each wrong guess.\nThe game gets over if you lose all your points.\n";
                  cout << "Now would you like to begin the game :\nPress n to exit or any other key to continue : ";
                  cin >> c;
                  if(c=='n' || c=='N')
                    break;
          case 2: system("cls");
                  v=game_beginner(films_name);
                  break;
          default: cout << "OOPS!! invalid choice";
      }
      if(c=='n' || c=='N')
      {
        cout << "Hope you come back again.\n";
        cout << "******************************HAVE A GOOD DAY******************************";
        break;
      }
    }
}
