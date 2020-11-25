#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Screen
 {
    private:
    int r,p_r;
    vector<vector<char>>seats;

    unordered_set<int>ais;

    public:
        Screen (vector<string>& vect)
         {
            this->r = stoi(vect[2]);
            this->p_r = stoi(vect[3]);

            for(int i=0;i<this->r;i++)
                this->seats.pb(vector<char>(p_r,'E'));
        
            for(int i=4;i<vect.size();i+=2)
                this->ais.insert(stoi(vect[i]));
    
            cout<<"success\n";
        }

        void vacant(int r)
         {
            for (int i=0; i<this->p_r; i++)
             {
                if(this->seats[r][i]=='E')
                    cout<<i+1<<" ";
            }
            cout<<"\n";
        }

        void book(vector<string>& line)
         {
            int r=stoi(line[2]);

            for(int i=3;i<line.size();i++)
            {
                if(this->seats[r][stoi(line[i])-1]!='E')
                {
                     cout<<"failure\n";
                     return ;
                }
            }

             for(int i=3;i<line.size();i++)
              this->seats[r][stoi(line[i])-1]='F';

            cout<<"success\n";
        }


        void suggest(vector<string>& v)
        {
            int req=stoi(v[2]);
            int ro=stoi(v[3]);
            int s=stoi(v[4]);

            bool l=false,r=false;

            vector<int>ans;
            
            if(s-req+1<1)
                l=true;

            if(l==false)
            {
                int a=s-req+1;
                for(int i=a;i<s;i++)
                {
                    if(this->ais.find(i)!=this->ais.end() or this->seats[ro][i-1]=='F')
                    {
                        l=true;
                        break;
                    }
                    else
                        ans.pb(i);
                }
            }

            if(l==false)
            {
                ans.pb(s);
                for(int i=0;i<ans.size();i++)
                    cout<<ans[i]<<" ";
            }
            else
            {

            if(s+req-1>this->r)
                r=true;

            if(r==false)
            {
                ans.resize(0);
                int a=s+req-1;

                for(int i=a;i>=s;i--)
                {
                    if(this->ais.find(i)!=this->ais.end() || this->seats[ro][i-1]=='F')
                    {
                        r=true;
                        break;
                    }
                    else
                        ans.pb(i);
                }
            }

            if(r and l)
                cout<<"none";
            else
            {
                for(int i=ans.size()-1;i>=0;i--)
                    cout<<ans[i]<<' ';
            }

            }

            cout<<'\n';
        }
};


int main()
{
    map<string, Screen*> mp;


    string h;
    getline(cin,h);
    int t=stoi(h);

    while(t--)
     {
        string str;
        getline (cin, str);

        vector<string> line;

        string word = "";
        for (int i=0;i<str.length();i++)
        {
            char c=str[i];

            if (c==' ') 
            {
                line.push_back(word);
                word = "";
            }
            else
               word+=c;
        }
        line.push_back(word);

        

        if (line[0] == "add-screen")
        {
            if(mp.find(line[1])==mp.end())
                mp[line[1]] = new Screen(line);
            else
                cout<<"failure\n";
        }

        else if (line[0] == "get-unreserved-seats")
        {
            if(mp.find(line[1])!=mp.end())
                 mp[line[1]]->vacant(stoi(line[2]));
             else
                cout<<"failure\n";               
        }
        else if (line[0] == "suggest-contiguous-seats")
        {
            if(mp.find(line[1])!=mp.end())
                mp[line[1]]->suggest(line);
            else
                cout<<"failure\n";
        }
        else if (line[0] == "reserve-seat") 
        {

            if(mp.find(line[1])!=mp.end())
                mp[line[1]]->book(line);
            else
                cout<<"failure\n";
        }
        

    }
    return 0;
}
