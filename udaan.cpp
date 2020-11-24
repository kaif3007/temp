#include <bits/stdc++.h>
using namespace std;
class Screen
 {
    int row, seat_per_row;
    vector<vector<char>>seats;
    unordered_set<int>aisle;

    public:
        Screen (vector<string> vect)
         {
            row = stoi(vect[2]);
            seat_per_row = stoi(vect[3]);
            for(int i=0;i<row;i++)
                seats.push_back(vector<char>(seat_per_row,'E'));
        
            for(int i=4;i<vect.size();i++)
            {
                if(i%2==0)
                aisle.insert(stoi(vect[i]));
                
            }
            cout<<"success\n";
        }

        void vacant(int r)
         {
            for (int i=0; i<seat_per_row; i++)
             {
                if(seats[r][i]=='E')
                    cout<<i+1<<" ";
            }
            cout<<"\n";
        }

        void book(vector<string>& line)
         {
            int r=stoi(line[2]);

            for(int i=3;i<line.size();i++)
            {
                if(seats[r][stoi(line[i])-1]!='E')
                {
                     cout<<"failure\n";
                     return ;
                }
            }

             for(int i=3;i<line.size();i++)
              seats[r][stoi(line[i])-1]='B';
            cout<<"success\n";
        }


        void suggest(vector<string>v)
        {
            int seats_req=stoi(v[2]);
            int row_no=stoi(v[3]);
            int origin=stoi(v[4]);
            bool left=false,right=false;
            vector<int>ans;
            if(origin-seats_req+1<1)
                left=true;

            if(!left)
            {
                int a=origin-seats_req+1;
                for(int i=a;i<origin;i++)
                {
                    if(aisle.find(i)!=aisle.end() || seats[row_no][i-1]=='B')
                    {
                        left=true;
                        break;
                    }
                    else
                        ans.push_back(i);
                }
            }
            if(!left)
            {
                ans.push_back(origin);
                for(int i=0;i<ans.size();i++)
                    cout<<ans[i]<<' ';
            }
            else{
            if(origin+seats_req-1>row)
                right=true;
            if(!right)
            {
                ans.clear();
                int a=origin+seats_req-1;
                for(int i=a;i>=origin;i--)
                {
                    if(aisle.find(i)!=aisle.end() || seats[row_no][i-1]=='B')
                    {
                        right=true;
                        break;
                    }
                    else
                        ans.push_back(i);
                }
            }
            if(right && left)
                cout<<"none";
            else
            {
                reverse(ans.begin(),ans.end());
                for(int i=0;i<ans.size();i++)
                    cout<<ans[i]<<' ';
            }
            }
            cout<<'\n';
        }
};

vector<string> words(string str) {
    string word = "";
    vector<string> st;
    for (auto x : str) {
        if (x == ' ') {
            st.push_back(word);
            word = "";
        }
        else
           word = word + x;
    }
    st.push_back(word);
    return st;
}
int main()
{
    map<string, Screen*> mp;
    vector<string> line;
    string str;
    int t;cin>>t;
    for(int i=0;i<=t;i++) {
        getline (cin, str);
        line = words(str);
        if (line[0] == "add-screen"){
            if(mp.find(line[1])!=mp.end())
                cout<<"failure"<<'\n';
            else
                mp[line[1]] = new Screen(line);
        }
        else if (line[0] == "get-unreserved-seats") {
            if(mp.find(line[1])==mp.end())
                cout<<"failure"<<'\n';
            else
                mp[line[1]]->vacant(stoi(line[2]));
        }
        else if (line[0] == "reserve-seat") {
            if(mp.find(line[1])==mp.end())
                cout<<"failure"<<'\n';
            else
                mp[line[1]]->book(line);
        }
        else if (line[0] == "suggest-contiguous-seats") {
            if(mp.find(line[1])==mp.end())
                cout<<"failure"<<'\n';
            else
                mp[line[1]]->suggest(line);
        }

    }
    return 0;
}
