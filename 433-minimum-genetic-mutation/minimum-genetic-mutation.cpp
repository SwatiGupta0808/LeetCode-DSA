class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        queue<pair<string,int>> q;
        q.push({startGene,0});

        unordered_set<string> st(bank.begin(),bank.end());
        st.erase(startGene);
        vector<char> al={'A','C','G','T'};

        while(!q.empty())
        {
            string word= q.front().first;
            int count=q.front().second;
            q.pop();
            if(word==endGene)   return count;
            for(int i=0;i<word.size();i++)
            {
                char original=word[i];
                for(int j=0;j<4;j++)
                {
                    word[i]=al[j];
                    if(st.find(word)!=st.end())
                    {
                        q.push({word,count+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }

        }
        return -1;
    }
};